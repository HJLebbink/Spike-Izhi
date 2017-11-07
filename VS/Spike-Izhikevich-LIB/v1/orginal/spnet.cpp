// SPNET: Spiking neural network with axonal conduction delays and STDP
// Created by Eugene M. Izhikevich, May 17, 2004, San Diego, CA
// Saves spiking data each second in file spikes.dat
// To plot spikes, use MATLAB code: load spikes.dat;plot(spikes(:,1),spikes(:,2),'.');
#include <stdio.h>  // for printf
#include <stdlib.h> // for rand
#include <iostream> // for cout
#include <math.h>
#include <ctime>	// for clock


#define getrandom(max1) ((rand()%(int)((max1)))) // random integer between 0 and max-1
												
const	int		Ne = 800;		// excitatory neurons			
const	int		Ni = 200;		// inhibitory neurons				 
const	int		N  = Ne+Ni;		// total number of neurons	
const	int		M  = 100;		// the number of synapses per neuron 
const	int		D  = 20;		// maximal axonal conduction delay
const	float	sm = 10.0;		// maximal synaptic strength

int		post[N][M];				// indeces of postsynaptic neurons
float	s[N][M], sd[N][M];		// matrix of synaptic weights and their derivatives
short	delays_length[N][D];	// distribution of delays
short	delays[N][D][M];		// arrangement of delays   

int		n_pre[N];				// presynaptic information
int		i_pre[N][3*M];			// presynaptic information
int		d_pre[N][3*M];			// presynaptic information

float	*sd_pre[N][3*M];		// presynaptic weights

float	ltp[N][1001+D];			// STDP functions 
float   ltd[N];					// STDP functions 

float	a[N], d[N];				// neuronal dynamics parameters
float	v[N], u[N];				// activity variables
int		n_firings;				// the number of fired neurons 
const int n_firings_max = 100*N;	// upper limit on the number of fired neurons per sec
int		firings[n_firings_max][2]; // indeces and timings of spikes

void initialize() {

	//srand(time(NULL));
	srand(12345);
	
	for (int i=0; i<Ne; i++) a[i]=0.02;// RS type
	for (int i=Ne; i<N; i++) a[i]=0.1; // FS type

	for (int i=0; i<Ne; i++) d[i]=8.0; // RS type
	for (int i=Ne; i<N; i++) d[i]=2.0; // FS type

	for (int neuronId=0; neuronId<N; neuronId++) {
		for (int synapse=0; synapse<M; synapse++) {
			bool exists;
			int randomNeuronId;
			do {
				randomNeuronId = (neuronId<Ne) ? getrandom(N) : getrandom(Ne);
				exists = (randomNeuronId == neuronId);	// no self-synapses 
				for (int k=0; k<synapse; k++) {
					if (post[neuronId][k] == randomNeuronId) {
						exists = true;	// synapse already exists
					}
				}
			} while (exists);
			post[neuronId][synapse] = randomNeuronId;
		}
	}
	for (int i=0; i<Ne; i++)	for (int j=0;j<M;j++) s[i][j]=6.0;  // initial exc. synaptic weights
	for (int i=Ne; i<N; i++)	for (int j=0;j<M;j++) s[i][j]=-5.0; // inhibitory synaptic weights
  	for (int i=0; i<N; i++)		for (int j=0;j<M;j++) sd[i][j]=0.0; // synaptic derivatives 
  	for (int neuronId=0; neuronId<N; neuronId++) {
		short ind=0;
		if (neuronId < Ne) {
			for (int delay=0; delay<D; delay++) {
				const int maxSynapse = M/D;		// uniform distribution of exc. synaptic delays
				delays_length[neuronId][delay] = maxSynapse;	
				for (int synapse=0; synapse<maxSynapse; synapse++) {
					delays[neuronId][delay][synapse] = ind;
					ind++;
				}
			}
		} else {
			const int maxSynapse = M;
			for (int delay=0; delay<D; delay++) {
				delays_length[neuronId][delay] = (delay == 0) ? maxSynapse : 0; // all inhibitory delays are 1 ms
			}
			for (int synapse=0; synapse<maxSynapse; synapse++) {
				delays[neuronId][0][synapse] = ind;
				ind++;
			}
		}
	}
  	for (int neuronId=0; neuronId<N; neuronId++) {
		int length = 0;
		for (int neuronId2=0; neuronId2<Ne; neuronId2++) {
			for (int synapse=0; synapse<M; synapse++) {
				if (post[neuronId2][synapse] == neuronId) {			// find all presynaptic neurons 
					i_pre[neuronId][length] = neuronId2;			// add this neuron to the list
					for (int delay=0; delay<D; delay++) {			// find the delay
						for (int j=0; j<delays_length[neuronId2][delay]; j++) {
							if (post[neuronId2][delays[neuronId2][delay][j]] == neuronId) {
								d_pre[neuronId][length] = delay;
							}
						}
					}
//					s_pre[neuronId][length] = &s[neuronId2][synapse];	// pointer to the synaptic weight	
					sd_pre[neuronId][length] = &sd[neuronId2][synapse];	// pointer to the derivative
					length++;
				}
			}
		}	
		n_pre[neuronId] = length;
	}
	for (int i=0; i<N; i++) for (int j=0; j<1+D; j++) ltp[i][j] = 0.0;
	for (int i=0; i<N; i++) ltd[i] = 0.0;
	for (int i=0; i<N; i++) v[i] = -65.0;		// initial values for v
	for (int i=0; i<N; i++) u[i] = 0.2f*v[i];	// initial values for u

	n_firings = 1;		// spike timings
	firings[0][0] = -D;	// put a dummy spike at -D for simulation efficiency 
	firings[0][1] = 0;	// index of the dummy spike
}
//int main(int /*argc*/, char* /*argv[]*/) {
void run() {

	float	I[N];
	FILE	*fs;

	initialize();	// assign connections, weights, etc. 
	
	clock_t timeInMs = clock();
	for (int sec=0; sec<=1*60; sec++) {		// simulation of 1 day
		if ((sec%60==0) && (sec > 0)) {
			std::cout << "time taken for 1 min: " << ((float)(clock()-timeInMs)/1000) << " sec." << std::endl;
			timeInMs = clock();
		}
		for (int t=0; t<1000; t++) {			// simulation of 1 sec
			for (int neuronId=0; neuronId<N; neuronId++) I[neuronId] = 0.0;	// reset the input 
			for (int k=0; k<N/1000; k++) I[getrandom(N)] = 20.0;			// random thalamic input 
			for (int neuronId=0; neuronId<N; neuronId++) {
				if (v[neuronId] >= 30) {				// did it fire?
					v[neuronId] = -65.0;				// voltage reset
					u[neuronId] += d[neuronId];			// recovery variable reset
					
					ltp[neuronId][t+D] = 0.1;		
					ltd[neuronId] = 0.12;
					
					for (int j=0; j<n_pre[neuronId]; j++) {

						const int neuronId2 = i_pre[neuronId][j];
						const int time2 = t + D - d_pre[neuronId][j] - 1;
						*sd_pre[neuronId][j] += ltp[neuronId2][time2];// this spike was after pre-synaptic spikes
					}
					firings[n_firings  ][0] = t;
					firings[n_firings++][1] = neuronId;
					if (n_firings == n_firings_max) {
						std::cout << "Two many spikes at t=" << t << " (ignoring all)";
						n_firings=1;
					}
				}
			}
			int k=n_firings;
			while (t-firings[--k][0] < D) { // --k means that k is first decremented, and then firings[k] retrieved.
				const int neuronId2 = firings[k][1];
				const int delay = t-firings[k][0];

				for (int j=0; j<delays_length[neuronId2][delay]; j++) {
					const int synapse = delays[neuronId2][delay][j];
					const int neuronId3 = post[neuronId2][synapse]; 
					I[neuronId3] += s[neuronId2][synapse];
					if (neuronId2 < Ne) { // this spike is before postsynaptic spikes
						sd[neuronId2][synapse] -= ltd[neuronId3];
					}
				}
			}
			for (int i=0; i<N; i++) {
				v[i] += 0.5f * ((0.04f * v[i] + 5) * v[i] + 140 - u[i] + I[i]); // for numerical stability
				v[i] += 0.5f * ((0.04f * v[i] + 5) * v[i] + 140 - u[i] + I[i]); // time step is 0.5 ms
				u[i] += a[i] * (0.2f * v[i] - u[i]);
				ltp[i][t+D+1] = 0.95f * ltp[i][t+D];
				ltd[i] *= 0.95f;
			}
		} // end of 1000 ms loop

		std::cout << "sec=" << sec << ", firing rate=" << float(n_firings)/N << "\n";
   		fs = fopen("spikes.dat","w");
		for (int i=1; i<n_firings; i++) {
			if (firings[i][0] >= 0) {
				fprintf(fs, "%d  %d\n", firings[i][0], firings[i][1]);
			}
		}
		fclose(fs);

		for (int i=0; i<N; i++) {		// prepare for the next sec
			for (int j=0; j<D+1; j++) {
				ltp[i][j] = ltp[i][1000+j];
			}
		}
		int k = n_firings-1;
		while (1000-firings[k][0]<D) k--;
		for (int i=1; i<n_firings-k; i++) {
			firings[i][0] = firings[k+i][0]-1000;
			firings[i][1] = firings[k+i][1];
		}
		n_firings = n_firings-k;

		for (int i=0; i<Ne; i++) { // modify only exc connections
			for (int j=0; j<M; j++) {
				s[i][j] += 0.01f + sd[i][j];
				if (s[i][j] > sm) s[i][j] = sm;
				if (s[i][j] < 0) s[i][j] = 0.0;

				sd[i][j] *= 0.9f;			
			}
		}
	}

	printf("-------------------\n");
	std::cout << "Press RETURN to finish: " << std::endl;

	#if _DEBUG
		_CrtDumpMemoryLeaks();
	#endif
	getchar();
}