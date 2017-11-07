#pragma once

const	int		Ne = 1600;		// excitatory neurons			
const	int		Ni = 400;		// inhibitory neurons				 
const	int		N  = Ne+Ni;		// total number of neurons	
const	int		M  = 100;		// the number of synapses per neuron 
const	int		D  = 20;		// maximal axonal conduction delay
const	float	sm = 10.0;		// maximal synaptic strength
const   int     n_firings_max = 100*N;	// upper limit on the number of fired neurons per sec
const   bool    dumpSpikeToFile = true;


class NetworkLifOriginal {
public:
	NetworkLifOriginal(void);
	~NetworkLifOriginal(void);

	void initialize();
	void train(int seconds);

private:

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
	int		firings[n_firings_max][2]; // indeces and timings of spikes
};

