#include <stdio.h>	// for printf
#include <stdlib.h>	// for malloc
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <iostream>


#define rand01 (0.9999999*double(rand())/RAND_MAX) 
				
#define getrandom(max1) (((rand())%(max1))) // random integer between 0 and max-1
	  


//There are two implementations of polychronous group search algorithm here.
// The old one is event-trigered (very fast). 
// The new one is activity-trigered (slow, but more precise).
// By default, the new definition is used. Uncomment the line below to use the old one.

//#define old_definition_of_polychronous 

const	int		nSynapses = 100;		// the number of synapses per neuron
const	int	    max_delay=20;			// maximal axonal conduction delay	
const	int		Ne =800;				//% excitatory neurons
const	int		Ni =200;				//% inhibitory neurons
const	int		n_neurons = Ne+Ni;		//% total neuron N=Ne+Ni;
const	double	C_max=10;		

const	int	group_width=3;	// initial width of polychronous groups
const   int	min_group_path = 7;			// minimal length of a group
const   int	min_group_time = 40;		// minimal duration of a group (ms)

double	a[n_neurons];					// content of a is constant
double  d[n_neurons];					// content of d is constant
int		post[n_neurons][nSynapses];		// post synaptic neuronID (cannot be removed) 

double	s[n_neurons][nSynapses];		// synaptic weights
double  sd[n_neurons][nSynapses];		// derivatives of synaptic weights

short	delays[n_neurons][max_delay][nSynapses];	//
short	delays_length[n_neurons][max_delay];  //

int		N_pre[n_neurons];
int     I_pre[n_neurons][3*nSynapses];
int     D_pre[n_neurons][3*nSynapses];	   //

double	*s_pre[n_neurons][3*nSynapses];
double  *sd_pre[n_neurons][3*nSynapses];
double	LTP[n_neurons][1001+max_delay];
double  LTD[n_neurons];		  //

double	v[n_neurons];
double  u[n_neurons];	  //

int		N_firings;
const int N_firings_max=100000;
int		firings[N_firings_max][2];

void initialize() {	

//	a=[0.02*ones(Ne,1);    0.1*ones(Ni,1)];
	for (int i=0; i<Ne; i++) a[i]=0.02;		// a is not changed afterwards
	for (int i=Ne; i<n_neurons; i++) a[i]=0.1;

//	d=[   8*ones(Ne,1);      2*ones(Ni,1)];
	for (int i=0; i<Ne; i++) d[i]=8;		// d is not changed afterwards
	for (int i=Ne; i<n_neurons; i++) d[i]=2;

//	post=ceil([Ne+Ni*rand(Ne,M*Ni/N),Ne*rand(Ne,M*Ne/N);Ne*rand(Ni,M)]); 
	for (int i=0; i<Ne; i++) {
		for (int j=0; j<nSynapses; j++) {
			int exists;
			int r;
			do {
				exists = 0;
				r = int(floor(n_neurons*rand01));
				if (r == i) {
					exists = 1;  
				}
				for (int k=0; k<j; k++) {
					if (post[i][k] == r) {
						exists = 1;
					}
				}
			} while (exists == 1);
			post[i][j]=r;
		}
	}
	for (int i=Ne; i<n_neurons; i++) {
		for (int j=0; j<nSynapses; j++) {
			int exists;
			int r;
			do {
				exists = 0;
				r = int(floor(Ne*rand01));
				for (int k=0; k<j; k++) {
					if (post[i][k] == r) exists = 1;
				}
			}
			while (exists == 1);
			post[i][j]=r; 
		}
	}
//	s=[6*ones(Ne,M);-5*ones(Ni,M)];     % initial synaptic weights
	for (int i=0; i<Ne; i++) {
		for (int j=0; j<nSynapses; j++) s[i][j]=6;
	}
	for (int i=Ne; i<n_neurons; i++) {
		for (int j=0; j<nSynapses; j++) s[i][j]=-5;
	}
//	sd=zeros(N,M);                      % derivatives of synaptic weights
  	for (int i=0; i<n_neurons; i++) {
		for (int j=0; j<nSynapses; j++) sd[i][j]=0;
	}
//	for i=1:N
  	for (int i=0; i<n_neurons; i++) {
		short ind=0;

//		if i<=Ne
		if (i<Ne) {
//			for j=1:D
//            delays{i,j}=M/D*(j-1)+(1:M/D);
//			end;
			for (int j=0; j<max_delay; j++) {	
				delays_length[i][j]=nSynapses/max_delay;
				for (int k=0; k<delays_length[i][j]; k++) {
					delays[i][j][k]=ind++;
				}
			}
		}
//		else
//        delays{i,1}=1:M;
//		end;
		else {
			for (int j=0; j<max_delay; j++) {
				delays_length[i][j]=0;
			}
			delays_length[i][0]=nSynapses;
			for (int k=0; k<delays_length[i][0]; k++) {
				delays[i][0][k]=ind++;
			}
		}
	}
	
//		pre{i} = find(post==i & s>0);     % Indeces of pre excitatory neurons
//		aux{i} = N*(D-1-ceil(ceil(pre{i}/N)/(M/D))) + 1+mod(pre{i}-1,N);
  	for (int i=0; i<n_neurons; i++) {
		N_pre[i]=0;
		for (int j=0; j<Ne; j++) {
			for (int k=0; k<nSynapses; k++) {
				if (post[j][k] == i) {
					I_pre[i][N_pre[i]]=j;
					for (int dd=0; dd<max_delay; dd++) {
						for (int jj=0; jj<delays_length[j][dd]; jj++) {
							if (post[j][delays[j][dd][jj]]==i) D_pre[i][N_pre[i]]=dd;
						}
					}
					s_pre[i][N_pre[i]]=&s[j][k];
					sd_pre[i][N_pre[i]++]=&sd[j][k];
				}
			}
		}
	}

//	LTP = zeros(N,1001+D);
	for (int i=0; i<n_neurons; i++) {
		for (int j=0; j<1+max_delay; j++) {
			LTP[i][j]=0;
		}
	}

//	LTD = zeros(N,1);
	for (int i=0; i<n_neurons; i++)	{
		LTD[i]=0;
	}
//	v = -65+10*rand(N,1);               % initial values for v
	for (int i=0; i<n_neurons; i++)	{
		v[i]=-65+10*rand01;
	}
//	u = 0.2.*v;                         % initial values for u
	for (int i=0; i<n_neurons; i++)	{
		u[i]=0.2*v[i];
	}
//	firings=[-D 0];                     % spike timings
	N_firings=1;
	firings[0][0]=-max_delay;
	firings[0][1]=0;
}



//--------------------------------------------------------------
int			N_polychronous;

const double C_rel = 0.95*C_max;
const int	polylenmax = n_neurons;

int			N_postspikes[polylenmax];
int		    I_postspikes[polylenmax][n_neurons];
int         J_postspikes[polylenmax][n_neurons];
int         D_postspikes[polylenmax][n_neurons];
int         L_postspikes[polylenmax][n_neurons];

double		C_postspikes[polylenmax][n_neurons];
int			N_links;
int			links[2*group_width*polylenmax][4];

int			group[polylenmax];
int			t_fired[polylenmax];
int			layer[polylenmax];

int			gr3[group_width];
int			tf3[group_width];

int			I_my_pre[3*nSynapses]; 
int 	    D_my_pre[3*nSynapses]; 

int			N_fired; // necessary here


const	int	latency = max_delay; // maximum latency 

//--------------------------------------------------------------
void	polychronous(int nnum) {

	int N_my_pre = 0;
	for (int i=0; i<N_pre[nnum]; i++) {
		if (*s_pre[nnum][i] > C_rel) {
			I_my_pre[N_my_pre]=I_pre[nnum][i];
			D_my_pre[N_my_pre]=D_pre[nnum][i];
			N_my_pre++;
		}
	}
	if (N_my_pre<group_width) {
		return;
	}
	int npre[group_width];
	for (int i=0; i<group_width; i++) {
		npre[i]=i;
	}
	while (true) {
		int Dmax=0;
		int timing;
		for (int i=0; i<group_width; i++) {
			if (Dmax < D_my_pre[npre[i]]) Dmax=D_my_pre[npre[i]];
		}
		for (int i=0; i<group_width; i++) {
			group[i]=I_my_pre[npre[i]];
			t_fired[i] = Dmax-D_my_pre[npre[i]];
			layer[i]=1;
			
			for (int dd=0; dd<max_delay; dd++) { 
				for (int j=0; j<delays_length[group[i]][dd]; j++) {
					int p = post[group[i]][delays[group[i]][dd][j]];
					if ((s[group[i]][delays[group[i]][dd][j]] > C_rel) & (dd>=D_my_pre[npre[i]])) {
						timing = t_fired[i]+dd+1;
						J_postspikes[timing][N_postspikes[timing]]=group[i];				// presynaptic
						D_postspikes[timing][N_postspikes[timing]]=dd;						// delay
						C_postspikes[timing][N_postspikes[timing]]=s[group[i]][delays[group[i]][dd][j]];	// syn weight
						I_postspikes[timing][N_postspikes[timing]++]=p;						// index of post target	
					}
				}
			}
		}
		
		double v[n_neurons]; // warning this v shadows the v defined elsewhere
		double u[n_neurons]; // warning this u shadows the v defined elsewhere
		double I[n_neurons];
		
		for (int i=0; i<n_neurons; i++) {
			v[i]=-70; 
			u[i]=0.2*v[i]; 
			I[i]=0;
		}

		N_links = 0;
		N_fired = group_width; // N_fired cannot be const because N_fired++ somewhere else
		int t_last = max_delay+max_delay+latency+1;
		int t=-1;
		while ((++t<t_last) & (N_fired < polylenmax)) {
			for (int p=0; p<N_postspikes[t]; p++) {
				I[I_postspikes[t][p]] += C_postspikes[t][p]; 
			}
		  	for (int i=0; i<n_neurons; i++) {
				v[i]+=0.5*((0.04*v[i]+5)*v[i]+140-u[i]+I[i]);
				v[i]+=0.5*((0.04*v[i]+5)*v[i]+140-u[i]+I[i]);
				u[i]+=a[i]*(0.2*v[i]-u[i]);
				I[i]=0;
			}
			for (int i=0; i<n_neurons; i++) {
				if (v[i] >= 30) {
					v[i] = -65;
					u[i] += d[i];

					if (N_fired < polylenmax) {
						t_fired[N_fired]= t;
						group[N_fired++]=i;
						for (int dd=0; dd<max_delay; dd++) {
							for (int j=0; j<delays_length[i][dd]; j++) {
								if ((s[i][delays[i][dd][j]] > C_rel) | (i>=Ne)) {
									timing = t+dd+1;
									J_postspikes[timing][N_postspikes[timing]]=i;				// presynaptic
									D_postspikes[timing][N_postspikes[timing]]=dd;				// delay
			//						L_postspikes[timing][N_postspikes[timing]]=NL+1;			// layer
									C_postspikes[timing][N_postspikes[timing]]=s[i][delays[i][dd][j]];	   // syn weight
									I_postspikes[timing][N_postspikes[timing]++]=post[i][delays[i][dd][j]];// index of post target	
								}
							}
						}
						if (t_last < timing+1) {
							t_last = timing+1;
							if (t_last > polylenmax-max_delay-1) {
								t_last = polylenmax-max_delay-1;
							}
						}
					}
				}
			}
		}
		if (N_fired>2*group_width) {
			N_links=0;
			int L_max=0;
			for (int i=group_width; i<N_fired; i++) {
				layer[i]=0;
				for (int p=t_fired[i]; (p>t_fired[i]-latency) & (p>=0); p--) {
					for (int j=0; j<N_postspikes[p]; j++) {
						if ((I_postspikes[p][j]==group[i]) & (J_postspikes[p][j]<Ne)) {
							for (int k=0; k<i; k++) {
								if ((group[k]==J_postspikes[p][j]) & (layer[k]+1>layer[i])) {
									layer[i]=layer[k]+1; 
								}
							}
							links[N_links][0]=J_postspikes[p][j];
							links[N_links][1]=I_postspikes[p][j];
							links[N_links][2]=D_postspikes[p][j];
							links[N_links++][3]=layer[i];
							if (L_max < layer[i]) {
								L_max = layer[i];
							}
						}
					}
				}
			}						 
			int discard = 0;
			int	used[group_width];
			for (int i=0; i<group_width; i++) {
				used[i]=0;
				for (int j=0;j<N_links;j++) {
					if ((links[j][0] == group[i]) & (links[j][1] < Ne)) {
						used[i]++;
					}
				}
				if (used[i] == 1) {
					discard = 1;
				}
			}
//			if ((discard == 0) & (t_fired[N_fired-1] > min_group_time) )  { // (L_max >= min_group_path))
			if ((discard == 0) & (L_max >= min_group_path)) {

				for (int i=0; i<group_width; i++) {
					gr3[i]=group[i]; 
					tf3[i]=t_fired[i];
				}

				N_polychronous++;
				std::cout << "\ni= " << nnum << ", N_polychronous= " << N_polychronous << ", N_fired = " << N_fired << ", L_max = " << L_max << ", T=" << t_fired[N_fired-1];
			}
		}
  		for (int dd=Dmax; dd<t_last; dd++) {
			N_postspikes[dd]=0;
		}
		if (t_last == polylenmax-max_delay) {
			for (int dd=t_last; dd<polylenmax; dd++) {
				N_postspikes[dd]=0;
			}
		}
		int i=1;
		while (++npre[group_width-i] > N_my_pre-i) {
			if (++i > group_width) {
				return; 
			}
		}
		while (i>1) {
			npre[group_width-i+1]=npre[group_width-i]+1; 
			i--;
		}
	}	
}

 
//--------------------------------------------------------------
void all_polychronous() {

	N_polychronous=0;
   	for (int i=0; i<polylenmax; i++) {
		N_postspikes[i]=0;
	}
	for (int i=0; i<Ne; i++) {
		polychronous(i);
	}
	std::cout << "\nN_polychronous=" << N_polychronous << "\n";
}


// --------------------------------------------------------------------------
void main() {
	double	I[n_neurons];
	
	srand(0); 
	initialize();

	for (int sec=0; sec<60*60*5; sec++) {
		for (int t=0; t<1000; t++) { // simulation of 1 sec

			for (int i=0; i<n_neurons; i++) {
				I[i] = 0;
			}
			I[int(floor(n_neurons*rand01))]=20; // is this thalamic input?

			for (int i=0; i<n_neurons; i++) {
				if (v[i]>=30) {  // if v > 30 then the neuron fires
					v[i] = -65;
					u[i] += d[i];

					LTP[i][t+max_delay] = 0.1;
					LTD[i]=0.12;

					for (int j=0; j<N_pre[i]; j++) {
						*sd_pre[i][j] += LTP[I_pre[i][j]][t+max_delay-D_pre[i][j]-1];
					}

					firings[N_firings  ][0]=t; // set fire time 
					firings[N_firings++][1]=i; // set neuron id

					if (N_firings == N_firings_max) {
						std::cout << "*** Two many spikes, t=" << t << "*** (ignoring)";
						N_firings=1;
					}
				}
			}

			int k=N_firings-1; // cannot be const

			while (t-firings[k][0] < max_delay) {
				for (int j=0; j<delays_length[firings[k][1]][t-firings[k][0]]; j++) {

					const int i = post[firings[k][1]][delays[firings[k][1]][t-firings[k][0]][j]]; 
					I[i] += s[firings[k][1]][delays[firings[k][1]][t-firings[k][0]][j]];

					if (firings[k][1] < Ne) {
						sd[firings[k][1]][delays[firings[k][1]][t-firings[k][0]][j]] -= LTD[i];
					}
				}
				k--;
			}
			for (int i=0; i<n_neurons; i++) {
				v[i] += 0.5*((0.04*v[i]+5)*v[i]+140-u[i]+I[i]); // for numerical stability
				v[i] += 0.5*((0.04*v[i]+5)*v[i]+140-u[i]+I[i]); // time step is 0.5 ms
				u[i] += a[i]*(0.2*v[i]-u[i]);
				LTP[i][t+max_delay+1] = 0.95*LTP[i][t+max_delay];		// tau = 20 ms
				LTD[i] *= 0.95;		// tau = 20 ms
			}
		}
			
		for (int i=0; i<n_neurons; i++)
			for (int j=0; j<max_delay+1; j++)
			LTP[i][j]=LTP[i][1000+j];

		int k=N_firings-1;
		while (1000-firings[k][0]<max_delay) k--;
		
		for (int i=1; i<N_firings-k; i++) {
			firings[i][0]=firings[k+i][0]-1000;
			firings[i][1]=firings[k+i][1];
		}
		N_firings = N_firings-k;

		for (int i=0; i<Ne; i++) {
			for (int j=0; j<nSynapses; j++) {
				sd[i][j]*=0.9;
				s[i][j]+=0.01+sd[i][j];
				if (s[i][j]>C_max) s[i][j]=C_max;
				if (s[i][j]<0) s[i][j]=0;
			}
		}    
	}

	all_polychronous(); 
	int k=N_polychronous;
	all_polychronous(); 
}