// The MIT License (MIT)
//
// Copyright (c) 2017 Henk-Jan Lebbink
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>	// for ostringstream

#include "../../Spike-Tools-LIB/Constants.hpp"

#include "../../Spike-Tools-LIB/NeuronIdRange.hpp"
#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"

namespace spike 
{
	namespace v1 
	{
		using namespace spike::tools;

		template <size_t Ne_i, size_t Ni_i, SynapseLength M_i, Delay D_i, size_t Ns_i = 0, size_t Nm_i = 0 >
		class Topology
		{
		public:
			static constexpr size_t Ne = Ne_i;
			static constexpr size_t Ni = Ni_i;
			static constexpr size_t Ns = Ns_i;
			static constexpr size_t Nm = Nm_i;
			static constexpr SynapseLength M = M_i;
			static constexpr Delay D = D_i;

			static constexpr size_t nNeurons = Ne + Ni + Ns + Nm;
			static constexpr size_t N = nNeurons + (((nNeurons & 0b11) == 0) ? 0 : 4); // needed for sse alignment

			static constexpr size_t Ne_start = 0;
			static constexpr size_t Ne_end = Ne;
			static constexpr size_t Ni_start = Ne_end;
			static constexpr size_t Ni_end = Ne_end + Ni;
			static constexpr size_t Nm_start = Ni_end;
			static constexpr size_t Nm_end = Ni_end + Nm;
			static constexpr size_t Ns_start = Nm_end;
			static constexpr size_t Ns_end = Nm_end + Ns;


			~Topology() = default;
			Topology() = default;

			void load_Izhikevich_Original()
			{
				// unchanced method from Izhikevich: somewhat inefficient method.
				if (Ne != 800) std::cerr << "load_Izhikevich_Original(): warning: original experiment had 800 excitatory neurons. currently " << Ne << std::endl;
				if (Ni != 200) std::cerr << "load_Izhikevich_Original(): warning: original experiment had 200 inhibitory neurons. currently " << Ni << std::endl;
				if (M != 100) std::cerr << "load_Izhikevich_Original(): warning: original experiment had 100 synapses per neurons. currently " << M << std::endl;
				if (Ns != 0)  std::cerr << "load_Izhikevich_new(): warning: original experiment had 0 sensory neurons. currently " << Ns << std::endl;
				if (Nm != 0)  std::cerr << "load_Izhikevich_new(): warning: original experiment had 0 motor neurons. currently " << Nm << std::endl;

				if (M > Ne) {
					std::cerr << "load_Izhikevich_Original(): error: not enough neurons (" << Ne << ") for inhibitory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (M > (Ne + Ni)) {
					std::cerr << "load_Izhikevich_Original(): error: not enough neurons (" << (Ne + Ni) << ")  for excitatory pathways (" << M << ")" << std::endl; throw 1;
				}

				this->clearPathways(); // clear this topology, make it empty

				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId) {
					if (neuronId < Ne) {
						this->a_[neuronId] = 0.02f;// RS type
						this->b_[neuronId] = 0.2f;
						this->c_[neuronId] = -65.0f;
						this->d_[neuronId] = 8.0f; // RS type
						this->trainRate_[neuronId] = 1.0f;
						this->inputScaling_[neuronId] = 1.0f;
					} else {
						this->a_[neuronId] = 0.1f; // FS type
						this->b_[neuronId] = 0.2f;
						this->c_[neuronId] = -65.0f;
						this->d_[neuronId] = 2.0f; // FS type
						this->trainRate_[neuronId] = 0.0f;
						this->inputScaling_[neuronId] = 1.0f;
					}
				}

				NeuronId * const post = new NeuronId[N*M]; // indeces of postsynaptic neurons
				short * const synapse_length = new short[N*D];	// distribution of delays
				Synapse * const synapse = new Synapse[N*D*M];

				// init which neurons are connected, ie which pathways exists.
				bool exists;
				NeuronId randomNeuronId;
				for (NeuronId neuronId = 0; neuronId < nNeurons; neuronId++) {
					for (Synapse s = 0; s < M; s++) {
						do {
							randomNeuronId = static_cast<NeuronId>((neuronId < Ne) ? ::tools::getRandomInt_excl(nNeurons) : ::tools::getRandomInt_excl(Ne));
							exists = (randomNeuronId == neuronId);	// no self-synapses 
							for (int k = 0; k < s; k++) {
								if (post[(neuronId * M) + k] == randomNeuronId) {
									exists = true;	// synapse already exists
								}
							}
						} while (exists);
						post[(neuronId*M) + s] = randomNeuronId;
					}
				}
				// init delays
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId) {
					Synapse s = 0;
					if (neuronId < Ne) { // neuron is an excitatory neuron
						const int maxIndex = M / D;		// uniform distribution of excitatory synaptic delays
						for (Delay delay = 0; delay < D; delay++) {
							synapse_length[(neuronId * D) + delay] = maxIndex;
							for (int j = 0; j < maxIndex; j++) {
								synapse[(((neuronId * D) + delay)*M) + j] = s;
								s++;
							}
						}
					} else { // neuron is an inhibitory neuron
						const int maxIndex = M;
						for (Delay delay = 0; delay < D; delay++) {
							synapse_length[(neuronId * D) + delay] = (delay == 0) ? maxIndex : 0; // all inhibitory delays are 1 ms
						}
						for (int j = 0; j < maxIndex; j++) {
							synapse[(((neuronId * D) + 0)*M) + j] = s;
							s++;
						}
					}
				}

				for (NeuronId neuronId1 = 0; neuronId1 < nNeurons; ++neuronId1) {
					for (Delay delay = 0; delay < D; delay++) {
						for (int j = 0; j < synapse_length[(neuronId1 * D) + delay]; j++) {
							const Synapse s = synapse[(((neuronId1 * D) + delay)*M) + j];
							const NeuronId neuronId2 = post[(neuronId1 * M) + s];
							const float weight = (float)((neuronId1 < Ne) ? 6 : -5);
							this->addPathway(neuronId1, neuronId2, delay, weight);
						}
					}
				}

				for (NeuronId neuronId1 = 0; neuronId1 < nNeurons; ++neuronId1) {
					this->inputScaling_[neuronId1] = 1;
				}

				// house keeping
				delete[] post;
				delete[] synapse_length;
				delete[] synapse;
			}

			void load_Izhikevich_new()
			{
				// this method results in the same topology as loadTopology_Izhikevich_Original.
				if (Ne != 800) std::cerr << "load_Izhikevich_new(): warning: original experiment had 800 excitatory neurons. currently " << Ne << std::endl;
				if (Ni != 200) std::cerr << "load_Izhikevich_new(): warning: original experiment had 200 inhibitory neurons. currently " << Ni << std::endl;
				if (M != 100) std::cerr << "load_Izhikevich_new(): warning: original experiment had 100 synapses per neurons. currently " << M << std::endl;
				if (Ns != 0)  std::cerr << "load_Izhikevich_new(): warning: original experiment had 0 sensory neurons. currently " << Ns << std::endl;
				if (Nm != 0)  std::cerr << "load_Izhikevich_new(): warning: original experiment had 0 motor neurons. currently " << Nm << std::endl;

				if (M > Ne) {
					std::cerr << "load_Izhikevich_new(): error: not enough neurons (" << Ne << ") for inhibitory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (M > (Ne + Ni)) {
					std::cerr << "load_Izhikevich_new(): error: not enough neurons (" << (Ne + Ni) << ")  for excitatory pathways (" << M << ")" << std::endl; throw 1;
				}

				const Delay minDelay = 1; // original Izhikevich experiment minDelay = 0;

				this->clearPathways(); // clear this topology, make it empty

				// 2] neurons from exc1 have s pathways to neurons from exc1 or inh;
				// 4] neurons from inh have s pathways to neurons from exc1 (and not inh);

				std::vector<NeuronId> exc_neurons;
				std::vector<NeuronId> inh_neurons;
				std::vector<NeuronId> all_neurons;

				for (const NeuronId neuronId : Topology::iterator_ExcitatoryNeurons()) {
					all_neurons.push_back(neuronId);
					exc_neurons.push_back(neuronId);
					this->a_[neuronId] = 0.02f;// RS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f; // RS type
					this->trainRate_[neuronId] = 1.0f;
				}

				for (const NeuronId neuronId : Topology::iterator_InhibitoryNeurons()) {
					all_neurons.push_back(neuronId);
					inh_neurons.push_back(neuronId);
					this->a_[neuronId] = 0.1f; // FS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 2.0f; // FS type
					this->trainRate_[neuronId] = 0.0f;
				}

				std::vector<NeuronId> alreadyUseNeuronIds;

				for (const NeuronId neuronId1 : exc_neurons) {

					Synapse s = 0;
					alreadyUseNeuronIds.clear();
					alreadyUseNeuronIds.push_back(neuronId1);

					// 2] neurons from exc1 have M pathways to neurons from exc1 or inh;
					while (s < M) {
						const NeuronId neuronId2 = this->getRandomNeuronId(all_neurons, alreadyUseNeuronIds);
						alreadyUseNeuronIds.push_back(neuronId2);
						const Delay delay = ((s%D) < minDelay) ? minDelay : (s%D);
						const float weight = 6;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						s++;
					}
				}

				for (const NeuronId neuronId1 : inh_neurons) {

					Synapse s = 0;
					alreadyUseNeuronIds.clear();
					alreadyUseNeuronIds.push_back(neuronId1);

					// 4] neurons from inh have M pathways to neurons from exc1 (and not inh);
					while (s < M) {
						const NeuronId neuronId2 = getRandomNeuronId(exc_neurons, alreadyUseNeuronIds);

						alreadyUseNeuronIds.push_back(neuronId2);
						const Delay delay = minDelay;
						const float weight = -6;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						s++;
					}
				}
			}

			void load_Masquelier()
			{
				if (Ne != 2000) std::cerr << "load_Masquelier(): warning: original experiment had 2000 excitatory neurons. currently " << Ne << std::endl;
				if (Ni != 3) std::cerr << "load_Masquelier(): warning: original experiment had 3 inhibitory neurons. currently " << Ni << std::endl;

				this->clearPathways(); // clear this topology, make it empty

				std::vector<NeuronId> exc_neurons;
				std::vector<NeuronId> inh_neurons;

				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId) {
					if (neuronId < Ne) {
						exc_neurons.push_back(neuronId);
						this->a_[neuronId] = 0.02f;// RS type
						this->b_[neuronId] = 0.2f;
						this->c_[neuronId] = -65.0f;
						this->d_[neuronId] = 0.0f; //8.0f; RS type
						this->trainRate_[neuronId] = 1.0f;

					} else if (neuronId < (Ne + Ni)) {
						inh_neurons.push_back(neuronId);
						//std::cout << "neuron " << neuronId << " is an inh neuron" << std::endl;
						this->a_[neuronId] = 0.1f; // FS type
						this->b_[neuronId] = 0.2f;
						this->c_[neuronId] = -65.0f;
						this->d_[neuronId] = 4.0f; //2.0f; FS type
						this->trainRate_[neuronId] = 0.0f;
					}
				}

				// 1] every neuron from exc1 has a pathway to all neurons from inh1;
				// 2] every neuron from inh has a pathway to all neurons from inh;

				for (const NeuronId& neuronId_exc1 : exc_neurons) {

					// 1] every neuron from exc1 has a pathway (with random efficacy, random delay) to all neurons from inh1;
					for (const NeuronId& neuronId_inh : inh_neurons) {
						const Delay delay = 1;// static_cast<Delay>(::tools::getRandomInt_excl<1, D>());
						const unsigned int minWeight = 2;
						const unsigned int maxWeight = static_cast<unsigned int>(std::roundl(spike::v1::constant::maxEfficacy));
						const float weight = static_cast<float>(::tools::random::rand_int32(minWeight, maxWeight));
						this->addPathway(neuronId_exc1, neuronId_inh, delay, weight);
					}
				}

				for (const NeuronId& neuronId_inh : inh_neurons) {
					for (const NeuronId& neuronId_inh2 : inh_neurons) {
						if (neuronId_inh != neuronId_inh2) {
							const Delay delay = 1;
							const float weight = -1000;
							this->addPathway(neuronId_inh, neuronId_inh2, delay, weight);
						}
					}
				}
			}

			void load_Lebbink()
			{
				if (M > Ne) {
					std::cerr << "load_Lebbink(): error: not enough neurons (" << Ne << ") for inhibitory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (M > (Ne + Ni)) {
					std::cerr << "load_Lebbink(): error: not enough neurons (" << (Ne + Ni) << ")  for excitatory pathways (" << M << ")" << std::endl; throw 1;
				}

				this->clearPathways(); // clear this topology, make it empty

				std::vector<NeuronId> exc1_neurons;
				std::vector<NeuronId> exc2_neurons;
				std::vector<NeuronId> inh1_neurons;
				std::vector<NeuronId> inh2_neurons;
				std::vector<NeuronId> exc1_inh1_neurons;

				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId) {
					if (neuronId < Ne) {
						exc1_neurons.push_back(neuronId);
						exc1_inh1_neurons.push_back(neuronId);
						this->a_[neuronId] = 0.02f;// RS type
						this->b_[neuronId] = 0.2f;
						this->c_[neuronId] = -65.0f;
						this->d_[neuronId] = 8.0f; // RS type
						this->trainRate_[neuronId] = 1.0f;
	//					this->inputScaling_[neuronId] = 1.0f;

					} else if (neuronId < (Ne + Ni)) {
						inh1_neurons.push_back(neuronId);
						exc1_inh1_neurons.push_back(neuronId);
						this->a_[neuronId] = 0.1f; // FS type
						this->b_[neuronId] = 0.2f;
						this->c_[neuronId] = -65.0f;
						this->d_[neuronId] = 2.0f; // FS type
						this->trainRate_[neuronId] = 0.0f;
		//				this->inputScaling_[neuronId] = 1.0f;
					}
				}

				// 1] every neuron from exc1 has a pathway to all neurons from exc2;
				// 2] neurons from exc1 have s-nx pathways to neurons from exc1 or inh1;
				// 3] every neuron from inh1 has a pathway to all neurons from exc2;
				// 4] neurons from inh1 have s-nx pathways to neurons from exc1 (and not inh1);
				// 5] neurons from exc2 have one pathway to a neuron from inh2;
				// 6] every neurons from inh2 has pathways to all neurons from exc2;

				std::vector<NeuronId> alreadyUseNeuronIds;

				for (const NeuronId neuronId1 : exc1_neurons) {
					Synapse syn = 0;

					// 1] every neuron from exc1 has a pathway (with random efficacy, no delay) to all neurons from exc2;
					for (const NeuronId neuronId2 : exc2_neurons) {
						const Delay delay = 0;
						const unsigned int minWeight = 2;
						const unsigned int maxWeight = static_cast<unsigned int>(std::roundl(spike::v1::constant::maxEfficacy));
						const float weight = static_cast<float>(::tools::getRandomInt_incl(minWeight, maxWeight));
						this->addPathway(neuronId1, neuronId2, delay, weight);
						syn++;
					}
					// 2] neurons from exc1 have s-nx pathways (with 6 efficacy, random delay) to neurons from exc1 or inh1;
					alreadyUseNeuronIds.clear();
					alreadyUseNeuronIds.push_back(neuronId1);
					while (syn < M) {
						const NeuronId neuronId2 = this->getRandomNeuronId(exc1_inh1_neurons, alreadyUseNeuronIds);
						alreadyUseNeuronIds.push_back(neuronId2);
						const unsigned int minDelay = 0;
						const unsigned int maxDelay = static_cast<unsigned int>(D);
						const Delay delay = static_cast<Delay>(::tools::getRandomInt_excl(minDelay, maxDelay));
						const float weight = 6;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						syn++;
					}
				}

				for (const NeuronId neuronId1 : inh1_neurons) {
					Synapse syn = 0;

					// 3] every neuron from inh1 has a pathway (with random efficacy, no delay) to all neurons from exc2;
					for (NeuronId neuronId2 = 0; neuronId2 < nNeurons; ++neuronId2) {

						//DEBUG_BREAK(); //TODO
						/*
						if (this->neuronType_[neuronId2] == NeuronType::exc2) {
							const Delay delay = 0;
							const unsigned int minWeight = 2;
							const unsigned int maxWeight = static_cast<unsigned int>(std::roundl(spike::v1::constant::maxEfficacy));
							const float weight = static_cast<float>(::tools::getRandomInt_incl(minWeight, maxWeight));
							this->addPathway(neuronId1, neuronId2, delay, weight);
							syn++;
						}
						*/
					}
					// 4] neurons from inh1 have s-nx pathways (with -5 efficacy, no delay) to neurons from exc1 (and not inh1);
					alreadyUseNeuronIds.clear();
					alreadyUseNeuronIds.push_back(neuronId1);
					while (syn < M) {
						const NeuronId neuronId2 = this->getRandomNeuronId(exc1_neurons, alreadyUseNeuronIds);
						alreadyUseNeuronIds.push_back(neuronId2);
						const Delay delay = 0;
						const float weight = -5;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						syn++;
					}
				}

				for (const NeuronId neuronId1 : exc2_neurons) {
					Synapse syn = 0;

					// 5] neurons from exc2 have one pathway (with -50 efficacy, no delay) to a neuron from inh2;
					for (NeuronId neuronId2 = 0; neuronId2 < nNeurons; ++neuronId2) {
						//DEBUG_BREAK(); //TODO
						/*
						if ((this->neuronType_[neuronId2] == NeuronType::exc2) && (neuronId1 != neuronId2)) {
							const Delay delay = 0;
							const float weight = -100;
							this->addPathway(neuronId1, neuronId2, delay, weight);
						}
						*/
					}
				}

				std::cout << "load_Lebbink: nPathways loaded " << this->pathway_.size() << std::endl;
			}

			void load_mnist14x14()
			{
				load_mnist<14 * 14>();
			}

			void load_mnist28x28()
			{
				load_mnist<28 * 28>();
			}

			template <unsigned int mnistSize>
			void load_mnist()
			{
				if (M > Ne) {
					std::cerr << "Topology::load_mnist(): error: not enough neurons (" << Ne << ") for inhibitory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (M > (Ne + Ni)) {
					std::cerr << "Topology::load_mnist(): error: not enough neurons (" << (Ne + Ni) << ")  for excitatory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (Ns != mnistSize) {
					std::cerr << "Topology::load_mnist(): error: incorrect number of sensory neurons (" << Ns << "), expecting " << mnistSize << std::endl; throw 1;
				}
				if (Nm != 10) {
					std::cerr << "Topology::load_mnist(): error: incorrect number of motor neurons (" << Nm << "), expecting 10." << std::endl; throw 1;
				}

				const Delay minDelay = 1; // original Izhikevich experiment minDelay = 0;

				this->clearPathways(); // clear this topology, make it empty

				std::vector<NeuronId> exc_neurons; // excitatory
				std::vector<NeuronId> inh_neurons; // inhibitory
				std::vector<NeuronId> sensor_neurons; // input
				std::vector<NeuronId> motor_neurons; // output
				std::vector<NeuronId> exc_inh_motor_neurons; // output
				std::vector<NeuronId> exc_motor_neurons; // output

				for (const NeuronId& neuronId : Topology::iterator_ExcitatoryNeurons()) {
					exc_inh_motor_neurons.push_back(neuronId);
					exc_neurons.push_back(neuronId);
					exc_motor_neurons.push_back(neuronId);

					this->a_[neuronId] = 0.02f;// RS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f; // RS type
					this->trainRate_[neuronId] = 1.0f;
				}

				for (const NeuronId& neuronId : Topology::iterator_InhibitoryNeurons()) {
					exc_inh_motor_neurons.push_back(neuronId);
					inh_neurons.push_back(neuronId);
					this->a_[neuronId] = 0.1f; // FS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 2.0f; // FS type
					this->trainRate_[neuronId] = 0.0f;
				}

				for (const NeuronId& neuronId : Topology::iterator_MotorNeurons()) {
					motor_neurons.push_back(neuronId);
					exc_inh_motor_neurons.push_back(neuronId);
					exc_motor_neurons.push_back(neuronId);

					this->a_[neuronId] = 0.02f;
					this->b_[neuronId] = -0.1f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f; 
					this->trainRate_[neuronId] = 0.0f; // a motor neuron has not outgoing pathways and thus no weights needs to be trained
				}

				for (const NeuronId& neuronId : Topology::iterator_SensorNeurons()) {
					sensor_neurons.push_back(neuronId);
					this->a_[neuronId] = 0.02f;// RS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f; // RS type
					this->trainRate_[neuronId] = 1.0f;
				}

				std::vector<NeuronId> alreadyUseNeuronIds;

				for (const NeuronId& neuronId1 : exc_neurons) {
					alreadyUseNeuronIds.clear();
					alreadyUseNeuronIds.push_back(neuronId1);

					// 2] neurons from exc_neurons have M pathways to neurons from exc, inh or motor;
					for (Synapse s = 0; s < M; ++s) {
						const NeuronId neuronId2 = this->getRandomNeuronId(exc_inh_motor_neurons, alreadyUseNeuronIds);
						alreadyUseNeuronIds.push_back(neuronId2);
						const unsigned int maxDelay = static_cast<unsigned int>(D);
						const Delay delay = static_cast<Delay>(::tools::random::rand_int32(static_cast<unsigned int>(minDelay), maxDelay));
						const float weight = 6;
						this->addPathway(neuronId1, neuronId2, delay, weight);
					}
				}

				for (const NeuronId& neuronId1 : inh_neurons) {
					alreadyUseNeuronIds.clear();

					Synapse s = 0;

					// 4] neurons from inh_neurons have M pathways to neurons from exc1 (and not inh);
					while (s < M) {
						const NeuronId neuronId2 = getRandomNeuronId(exc_motor_neurons, alreadyUseNeuronIds);
						alreadyUseNeuronIds.push_back(neuronId2);
						const Delay delay = minDelay;
						const float weight = -5;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						s++;
					}
				}

				//for (const NeuronId neuronId1 : motor_neurons) {
					// motor neurons have no outgoing pathways
				//}

				for (const NeuronId& neuronId1 : sensor_neurons) {
					alreadyUseNeuronIds.clear();

					Synapse s = 0;

					/*
					for (const NeuronId neuronId2 : motor_neurons) {
						alreadyUseNeuronIds.push_back(neuronId2);
						const unsigned int maxDelay = static_cast<unsigned int>(D);
						const Delay delay = static_cast<Delay>(::tools::getRandomInt_excl(minDelay, maxDelay));
						const float weight = 5;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						s++;
					}
					*/
					while (s < M) {
						const NeuronId neuronId2 = getRandomNeuronId(exc_neurons, alreadyUseNeuronIds);

						alreadyUseNeuronIds.push_back(neuronId2);
						const unsigned int maxDelay = static_cast<unsigned int>(D);
						const Delay delay = static_cast<Delay>(::tools::random::rand_int32(static_cast<unsigned int>(minDelay), maxDelay));
						const float weight = 5;
						this->addPathway(neuronId1, neuronId2, delay, weight);
						s++;
					}
				}
			}

			void load_mnist2()
			{
				if (M > Ne) {
					std::cerr << "Topology::load_mnist(): error: not enough neurons (" << Ne << ") for inhibitory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (M > (Ne + Ni)) {
					std::cerr << "Topology::load_mnist(): error: not enough neurons (" << (Ne + Ni) << ") for excitatory pathways (" << M << ")" << std::endl; throw 1;
				}
				if (Ne != 800 + Ns) {
					std::cerr << "Topology::load_mnist(): error: incorrect number of exitatory neurons (" << Ne << "), expecting " << 800 + Ns << std::endl; throw 1;
				}
				if (Ns != (28 * 28)) {
					std::cerr << "Topology::load_mnist(): error: incorrect number of sensory neurons (" << Ns << "), expecting " << (28 * 28) << std::endl; throw 1;
				}
				if (Nm != 10) {
					std::cerr << "Topology::load_mnist(): error: incorrect number of motor neurons (" << Nm << "), expecting 10." << std::endl; throw 1;
				}

				const Delay minDelay = 1; // original Izhikevich experiment minDelay = 0;
				const unsigned int maxDelay = static_cast<unsigned int>(D);



				this->clearPathways(); // clear this topology, make it empty

				std::vector<NeuronId> exc_neurons; // excitatory
				std::vector<NeuronId> inh_neurons; // inhibitory
				std::vector<NeuronId> sensor_neurons; // input
				std::vector<NeuronId> motor_neurons; // output

				std::vector<NeuronId> exc1_neurons; // excitatory layer1
				std::vector<NeuronId> exc2_neurons; // excitatory layer2

				std::vector<NeuronId> exc_inh_neurons;


				unsigned int count = 0;
				for (const NeuronId& neuronId : Topology::iterator_ExcitatoryNeurons()) {
					exc_neurons.push_back(neuronId);
					exc_inh_neurons.push_back(neuronId);
					if (count < (28 * 28)) {
						exc1_neurons.push_back(neuronId);
					} else {
						exc2_neurons.push_back(neuronId);
					}
					count++;

					this->a_[neuronId] = 0.02f;// RS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f; // RS type
					this->trainRate_[neuronId] = 1.0f;
				}

				::tools::assert::assert_msg(exc1_neurons.size() == 28*28, "incorrect size");

				for (const NeuronId& neuronId : Topology::iterator_InhibitoryNeurons()) {
					inh_neurons.push_back(neuronId);
					exc_inh_neurons.push_back(neuronId);

					this->a_[neuronId] = 0.1f; // FS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 2.0f; // FS type
					this->trainRate_[neuronId] = 0.0f;
				}

				for (const NeuronId& neuronId : Topology::iterator_MotorNeurons()) {
					motor_neurons.push_back(neuronId);

					this->a_[neuronId] = 0.02f;
					this->b_[neuronId] = -0.1f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f;
					this->trainRate_[neuronId] = 0.0f; // a motor neuron has not outgoing pathways and thus no weights needs to be trained
				}

				for (const NeuronId& neuronId : Topology::iterator_SensorNeurons()) {
					sensor_neurons.push_back(neuronId);
					this->a_[neuronId] = 0.02f;// RS type
					this->b_[neuronId] = 0.2f;
					this->c_[neuronId] = -65.0f;
					this->d_[neuronId] = 8.0f; // RS type
					this->trainRate_[neuronId] = 1.0f;
				}

				std::vector<NeuronId> alreadyUseNeuronIds;

				{
					for (const NeuronId& destination : exc1_neurons) {
						const int x1 = (destination - Ne_start) / 28;
						const int y1 = (destination - Ne_start) % 28;
						//std::cout << "load_mnist2: destination " << destination << ":" << x1 << "," << y1 << std::endl;

						if (static_cast<unsigned int>((x1 * 28) + y1) != (destination - Ne_start)) //DEBUG_BREAK();

						for (int x2 = (x1 - 5); x2 < (x1 + 5); ++x2) {
							for (int y2 = (y1 - 5); y2 < (y1 + 5); ++y2) {
								if ((x2 < 0) || (x2 >= 28) || (y2 < 0) || (y2 >= 28)) {
									// do nothing
								} else {
									const NeuronId origin = static_cast<NeuronId>(Ns_start + (x2 * 28) + y2);
									const Delay delay = static_cast<Delay>(::tools::random::rand_int32(static_cast<unsigned int>(minDelay), maxDelay));
									const float weight = 5;
									//std::cout << "load_mnist2: sensor " << x2 << "," << y2 << " (" << origin << ") is maped to " << x1 << "," << y1 << " (" << destination << ")" << std::endl;
									this->addPathway(origin, destination, delay, weight);
								}
							}
						}
					}
				}
				{
					for (const NeuronId& destination : exc2_neurons) {
						alreadyUseNeuronIds.clear();
						alreadyUseNeuronIds.push_back(destination); // connot make pathway to itself

						// 2] neurons from exc_neurons have M pathways to neurons from exc2, inh or motor;
						for (Synapse s = 0; s < M; ++s) {
							const NeuronId origin = this->getRandomNeuronId(exc_inh_neurons, alreadyUseNeuronIds);
							alreadyUseNeuronIds.push_back(origin);
							const Delay delay = static_cast<Delay>(::tools::random::rand_int32(static_cast<unsigned int>(minDelay), maxDelay));
							const float weight = 6;
							this->addPathway(origin, destination, delay, weight);
						}
					}
				}
				{
					for (const NeuronId& destination : inh_neurons) {
						alreadyUseNeuronIds.clear();

						// 4] neurons from inh_neurons have M pathways to neurons from exc1 (and not inh);
						for (Synapse s = 0; s < M; ++s) {
							const NeuronId origin = this->getRandomNeuronId(exc2_neurons, alreadyUseNeuronIds);
							alreadyUseNeuronIds.push_back(origin);
							const Delay delay = minDelay;
							const float weight = -5;
							this->addPathway(origin, destination, delay, weight);
						}
					}
				}
				{
					for (const NeuronId destination:motor_neurons) {
						alreadyUseNeuronIds.clear();

						for (Synapse s = 0; s < M; ++s) {
							const NeuronId origin = this->getRandomNeuronId(exc2_neurons, alreadyUseNeuronIds);
							alreadyUseNeuronIds.push_back(origin);
							const Delay delay = static_cast<Delay>(::tools::random::rand_int32(static_cast<unsigned int>(minDelay), maxDelay));
							const float weight = 5;
							this->addPathway(origin, destination, delay, weight);
						}
					}
				}
			}

			void loadFromFile(const std::string& filename)
			{
				std::string line;
				std::ifstream inputFile(filename);
				if (!inputFile.is_open()) {
					std::cerr << "Topology::loadFromFile(): Unable to open file " << filename << std::endl;
					throw std::runtime_error("Unable to open file");
				} else {
					//std::cout << "Topology::loadFromFile(): Opening file " << filename << std::endl;
					// the first line contains "# topology <nNeurons> <nPathways>"

					const std::vector<std::string> content = ::tools::file::loadNextLineAndSplit(inputFile, ' ');
					const unsigned int nNeurons_inFile = ::tools::file::string2int(content[0]);
					const unsigned int nPathways = ::tools::file::string2int(content[1]);
					{
						for (unsigned int i = 0; i < nNeurons_inFile; ++i) {
							const std::vector<std::string> content2 = ::tools::file::loadNextLineAndSplit(inputFile, ' ');
							if (content2.size() == 7) {
								const NeuronId neuronId = static_cast<NeuronId>(::tools::file::string2int(content2[0]));
								if (neuronId >= nNeurons_inFile) {
									std::cerr << "Topology::load(): line " << line << " has incorrect content: neuronId= " << neuronId << std::endl;
									throw std::exception();
								}

								// retrieve neuron type
								this->setParameterA(neuronId, ::tools::file::string2float(content2[1]));
								this->setParameterB(neuronId, ::tools::file::string2float(content2[2]));
								this->setParameterC(neuronId, ::tools::file::string2float(content2[3]));
								this->setParameterD(neuronId, ::tools::file::string2float(content2[4]));
								this->trainRate_[neuronId] = ::tools::file::string2float(content2[5]);
								//this->inputScaling_[neuronId] = ::tools::file::string2float(content[6]);
							} else {
								std::cerr << "Topology::loadFromFile(): line " << line << " has incorrect content" << std::endl;
							}
						}
					}
					this->pathway_.clear();
					this->pathway_.reserve(nPathways);
					{
						for (unsigned int i = 0; i < nPathways; ++i) {
							const std::vector<std::string> content2 = ::tools::file::loadNextLineAndSplit(inputFile, ' ');
							if (content2.size() == 4) {
								const NeuronId neuronId1 = static_cast<NeuronId>(::tools::file::string2int(content2[0]));
								const NeuronId neuronId2 = static_cast<NeuronId>(::tools::file::string2int(content2[1]));
								const Delay delay = static_cast<Delay>(::tools::file::string2int(content2[2]));
								const float weigth = ::tools::file::string2float(content2[3]);

								if (neuronId1 >= nNeurons_inFile) std::cerr << "Topology::load(): line " << line << " has incorrect content: neuronId1= " << neuronId1 << std::endl;
								if (neuronId2 >= nNeurons_inFile) std::cerr << "Topology::load(): line " << line << " has incorrect content: neuronId2= " << neuronId2 << std::endl;
								if ((delay < 0) || (delay >= D)) std::cerr << "Topology::load(): ERROR A. line " << line << " has incorrect content: delay= " << delay << std::endl;

								this->addPathway(neuronId1, neuronId2, delay, weigth);
							} else {
								std::cerr << "Topology::loadFromFile(): ERROR B. line " << line << " has incorrect content" << std::endl;
							}
						}
					}
				}
			}

			void saveToFile(const std::string& filename) const
			{
				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree)) {
					std::cerr << "DataSetBackendTxt::saveToFileBackend(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				// try to open file
				std::ofstream outputFile(filename); //fstream is a proper RAII object, it does close automatically at the end of the scope
				if (!outputFile.is_open()) {
					std::cerr << "Topology::saveToFile(): Unable to open file " << filename << std::endl;
					throw std::runtime_error("Unable to open file");
				} else {
					//std::cout << "Topology::saveToFile(): Opening file " << filename << std::endl;
					const size_t nPathways = this->pathway_.size();

					outputFile << "# topology <nNeurons> <nPathways>" << std::endl;
					outputFile << nNeurons << " " << nPathways << std::endl;

					outputFile << "# parameter <neuronId> <a> <b> <c> <d> <trainRate> <inputScaling>" << std::endl;
					for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId) {
						const float a = this->getParameterA(neuronId);
						const float b = this->getParameterB(neuronId);
						const float c = this->getParameterC(neuronId);
						const float d = this->getParameterD(neuronId);
						const float tr = this->trainRate_[neuronId];
						const float is = this->getInputScaling(neuronId);
						outputFile << neuronId << " " << a << " " << b << " " << c << " " << d << " " << tr << " " << is << std::endl;
					}

					outputFile << "# pathway <origin> <destination> <delay> <weight>" << std::endl;
					for (unsigned int i = 0; i < nPathways; ++i) {
						outputFile << this->pathway_[i].origin << " " << this->pathway_[i].destination << " " << this->pathway_[i].delay << " " << this->pathway_[i].weight << std::endl;
					}
				}
			}

			void clearPathways()
			{
				this->pathway_.clear();
			}

			void addPathway(const Pathway& pathway)
			{
				this->pathway_.push_back(pathway);
			}

			void addPathway(Pathway&& pathway)
			{
				this->pathway_.push_back(std::move(pathway));
			}

			void addPathway(const NeuronId origin, const NeuronId destination, const Delay delay, const float weight)
			{
				Pathway pathway;
				pathway.origin = origin;
				pathway.destination = destination;
				pathway.delay = delay;
				pathway.weight = weight;
				this->addPathway(std::move(pathway));
			}

			unsigned int getNumberOfPathways() const
			{
				return static_cast<unsigned int>(this->pathway_.size());
			}

			Pathway getPathway(const unsigned int pos) const
			{
				return this->pathway_[pos];
			}

			std::vector<Pathway> getOutgoingPathways(const NeuronId neuronId) const
			{
				std::vector<Pathway> v;
				for (const Pathway p : this->pathway_) {
					if (p.origin == neuronId) {
						v.push_back(p);
					}
				}
				return v;
			}

			std::vector<Pathway> getOutgoingPathways(const NeuronId neuronId, const Delay d) const
			{
				std::vector<Pathway> v;
				for (const Pathway p : this->pathway_) {
					if ((p.origin == neuronId) && (p.delay == d)) {
						v.push_back(p);
					}
				}
				return v;
			}

			std::vector<Pathway> getIncommingPathways(const NeuronId neuronId) const
			{
				std::vector<Pathway> v;
				for (const Pathway p : this->pathway_) {
					if (p.destination == neuronId) {
						v.push_back(p);
					}
				}
				return v;
			}

			std::vector<Pathway> getIncommingPathways(const NeuronId neuronId, const Delay d) const
			{
				std::vector<Pathway> v;
				for (const Pathway p : this->pathway_) {
					if ((p.destination == neuronId)  && (p.delay == d)) {
						v.push_back(p);
					}
				}
				return v;
			}

			const std::vector<NeuronId> getNeuronIds() const
			{
				std::vector<NeuronId> neuronIds(nNeurons);
				for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId) {
					neuronIds[neuronId] = neuronId;
				}
				return neuronIds;
			}

			float getParameterA(const NeuronId neuronId) const
			{
				return this->a_[neuronId];
			}

			float getParameterB(const NeuronId neuronId) const
			{
				return this->b_[neuronId];
			}

			float getParameterC(const NeuronId neuronId) const
			{
				return this->c_[neuronId];
			}

			float getParameterD(const NeuronId neuronId) const
			{
				return this->d_[neuronId];
			}

			void setParameterA(const NeuronId neuronId, const float value)
			{
				this->a_[neuronId] = value;
			}

			void setParameterB(const NeuronId neuronId, const float value)
			{
				this->b_[neuronId] = value;
			}

			void setParameterC(const NeuronId neuronId, const float value)
			{
				this->c_[neuronId] = value;
			}

			void setParameterD(const NeuronId neuronId, const float value)
			{
				this->d_[neuronId] = value;
			}

			float getInputScaling(const NeuronId neuronId) const
			{
				return 1;// this->inputScaling_[neuronId];
			}

			float getTrainRate(const NeuronId neuronId) const
			{
				//std::cout << "getTrainRate: neuronId " << neuronId << " returns " << this->trainRate_[neuronId] << std::endl;
				return this->trainRate_[neuronId];
			}

			void setTrainRate(const NeuronId neuronId, const float value)
			{
				this->trainRate_[neuronId] = value;
			}

			void printPathway(const Pathway pathway) const
			{
				std::cout << pathway.origin << "->" << pathway.destination << " d" << pathway.delay << std::endl;
			}

			std::string connectivityOverview() const
			{
				std::ostringstream oss;

				oss << "neuronId" << 
					"\t" << "exc in\\out" << 
					"\t" << "inh in\\out" << 
					"\t" << "sensor in\\out" << 
					"\t" << "motor in\\out" << std::endl;
			
				for (const NeuronId& neuronId : iterator_AllNeurons()) {

					unsigned int outfluxExc = 0;
					unsigned int outfluxInh = 0;
					unsigned int outfluxMotor = 0;
					unsigned int outfluxSensor = 0;

					unsigned int influxExc = 0;
					unsigned int influxInh = 0;
					unsigned int influxMotor = 0;
					unsigned int influxSensor = 0;

					for (const Pathway& pathway : this->pathway_) {
						if (pathway.origin == neuronId) {
							if (isExcitatoryNeuron(pathway.destination)) {
								outfluxExc++;
							} else if (isInhibitoryNeuron(pathway.destination)) {
								outfluxInh++;
							} else if (isMotorNeuron(pathway.destination)) {
								outfluxMotor++;
							} else if (isSensorNeuron(pathway.destination)) {
								outfluxSensor++;
							} else { 
								//DEBUG_BREAK();
							}
						} else if (pathway.destination == neuronId) {
							if (isExcitatoryNeuron(pathway.origin)) {
								influxExc++;
							} else if (isInhibitoryNeuron(pathway.origin)) {
								influxInh++;
							} else if (isMotorNeuron(pathway.origin)) {
								influxMotor++;
							} else if (isSensorNeuron(pathway.origin)) {
								influxSensor++;
							} else {
								//DEBUG_BREAK();
							}
						}
					}
					oss << neuronId << 
						"\t" << influxExc << "\\" << outfluxExc << 
						"\t" << influxInh << "\\" << outfluxInh << 
						"\t" << influxSensor << "\\" << outfluxSensor << 
						"\t" << influxMotor << "\\" << outfluxMotor << std::endl;
				}
				return oss.str();
			}

			std::vector<NeuronId> getIncommingNeurons(const NeuronId neuronId) const
			{
				std::vector<NeuronId> neuronIds;
				for (const Pathway& p : this->pathway_) {
					if (p.destination == neuronId) {
						neuronIds.push_back(p.origin);
					}
				}
				return neuronIds;
			}

			std::vector<NeuronId> getIncommingNeurons(const NeuronId neuronId, const Delay d) const
			{
				std::vector<NeuronId> neuronIds;
				for (const Pathway& p : this->pathway_) {
					if ((p.destination == neuronId) && (p.delay == d)) {
						neuronIds.push_back(p.origin);
					}
				}
				return neuronIds;
			}

			std::vector<NeuronId> getOutgoingNeurons(const NeuronId neuronId) const
			{
				std::vector<NeuronId> neuronIds;
				for (const Pathway& pathway : this->pathway_) {
					if (pathway.origin == neuronId) {
						neuronIds.push_back(pathway.destination);
					}
				}
				return neuronIds;
			}

			void setWeight(const NeuronId origin, const NeuronId destination, const float weight)
			{
				for (Pathway& pathway : this->pathway_) {
					if ((pathway.origin == origin) && (pathway.destination == destination)) {
						pathway.weight = weight;
						return;
					}
				}
				std::cout << "setWeight: could not find pathway for " << origin << " -> " << destination << ". Ignoring weight update" << std::endl;
			}

			float getAverageExcitatoryWeight() const
			{
				double sum = 0;
				unsigned int counter = 0;
				for (const Pathway& pathway : this->pathway_) {
					if (pathway.origin < Ne) {
						sum += pathway.weight;
						counter++;
					}
				}
				return sum / counter;
			}

			static const NeuronIdRange<NeuronId, Ne_start, Ne_end> iterator_ExcitatoryNeurons()
			{
				return NeuronIdRange<NeuronId, Ne_start, Ne_end>();
			}
			static const NeuronIdRange<NeuronId, Ni_start, Ni_end> iterator_InhibitoryNeurons()
			{
				return NeuronIdRange<NeuronId, Ni_start, Ni_end>();
			}
			static const NeuronIdRange<NeuronId, Nm_start, Nm_end> iterator_MotorNeurons()
			{
				return NeuronIdRange<NeuronId, Nm_start, Nm_end>();
			}
			static const NeuronIdRange<NeuronId, Ns_start, Ns_end> iterator_SensorNeurons()
			{
				return NeuronIdRange<NeuronId, Ns_start, Ns_end>();
			}
			// active neurons are excitatory, sensor and motor neurons
			static const NeuronIdRange<NeuronId, Ne_start, Nm_end> iterator_ActiveNeurons()
			{
				return NeuronIdRange<NeuronId, Ne_start, Nm_end>();
			}
			static const NeuronIdRange<NeuronId, Ne_start, Ni_end> iterator_ExcInhNeurons()
			{
				return NeuronIdRange<NeuronId, Ne_start, Ni_end>();
			}
			static const NeuronIdRange<NeuronId, Ne_start, Ns_end> iterator_AllNeurons()
			{
				return NeuronIdRange<NeuronId, Ne_start, Ns_end>();
			}

			static bool isExcitatoryNeuron(const NeuronId neuronId)
			{
				return (neuronId >= Ne_start) && (neuronId < Ne_end);
			}
			static bool isInhibitoryNeuron(const NeuronId neuronId)
			{
				return (neuronId >= Ni_start) && (neuronId < Ni_end);
			}
			static bool isMotorNeuron(const NeuronId neuronId)
			{
				return (neuronId >= Nm_start) && (neuronId < Nm_end);
			}
			static bool isSensorNeuron(const NeuronId neuronId)
			{
				return (neuronId >= Ns_start) && (neuronId < Ns_end);
			}

			static NeuronId translateToSensorNeuronId(const NeuronId caseNeuronId)
			{
				const NeuronId sensorNeuronId = Ns_start + caseNeuronId;
				if (isSensorNeuron(sensorNeuronId)) {
					return sensorNeuronId;
				} else {
					std::cout << "Topology::translateToSensorNeuronId: caseNeuronId " << caseNeuronId << " is larger than number of sensor neurons Ns=" << Ns << std::endl;
					//DEBUG_BREAK();
					return sensorNeuronId;
				}
			}

			static NeuronId translateToMotorNeuronId(const CaseLabel caseLabel)
			{
				const NeuronId motorNeuronId = Nm_start + static_cast<NeuronId>(caseLabel.val);
				if (isMotorNeuron(motorNeuronId)) {
					return motorNeuronId;
				} else {
					std::cout << "Topology::translateToMotorNeuronId: caseLabel " << caseLabel.val << " is too large" << std::endl;
					//DEBUG_BREAK();
					return motorNeuronId;
				}
			}

		private:

			std::vector<Pathway> pathway_;

			float __declspec(align(4)) a_[N];
			float __declspec(align(4)) b_[N];
			float __declspec(align(4)) c_[N];
			float __declspec(align(4)) d_[N];
			//	float _MY_ALIGNMENT inputScaling_[N];
			float __declspec(align(4)) trainRate_[N];

			static NeuronId getRandomNeuronId(const std::vector<NeuronId>& allowedValues, const std::vector<NeuronId>& notAllowedValues)
			{
				unsigned int retryCounter = 0;
				NeuronId randomNeuronId;
				bool exists;
				const unsigned int largestIndex = static_cast<unsigned int>(allowedValues.size());
				do {
					unsigned int rand_index = ::tools::random::rand_int32(largestIndex-1);
					randomNeuronId = allowedValues.at(rand_index);
					exists = false;
					for (std::vector<NeuronId>::size_type i = 0; i != notAllowedValues.size(); i++) {
						if (notAllowedValues.at(i) == randomNeuronId) {
							exists = true;
							retryCounter++;
							if (retryCounter == 100000) {
								std::cout << "Topology::getRandomNeuronId: could not find a random neuronId: I've tried " << retryCounter << " times, giving up." << std::endl;
								//DEBUG_BREAK();
							}
						}
					}
				} while (exists);
				return randomNeuronId;
			}

			void check() const
			{
				// check ranges, origin and destination have to be distinct, no check on double pathways.
				for (unsigned int i = 0; i < this->getNumberOfPathways(); i++) {
					const Pathway p = this->getPathway(i);

					if (p.delay < 0) {
						std::cerr << "init(): Error: pathway " << i << " has incorrect delay " << this->pathway_[i].delay << std::endl; printPathway(this->pathway_[i]); throw 1;
					}
					if (p.delay >= D) {
						std::cerr << "Topology::check(): Error: pathway " << i << " has incorrect delay " << p.delay << std::endl; printPathway(p);  throw 1;
					}
					if (p.origin < 0) {
						std::cerr << "Topology::check(): Error: pathway " << i << " has incorrect origin " << p.origin << std::endl; printPathway(p); throw 1;
					}
					if (p.origin >= nNeurons) {
						std::cerr << "Topology::check(): Error: pathway " << i << " has incorrect origin " << p.origin << std::endl; printPathway(p); throw 1;
					}
					if (p.destination < 0) {
						std::cerr << "Topology::check(): Error: pathway " << i << " has incorrect destination " << p.destination << std::endl; printPathway(p);  throw 1;
					}
					if (p.destination >= nNeurons) {
						std::cerr << "Topology::check(): Error: pathway " << i << " has incorrect destination " << p.destination << std::endl; printPathway(p); throw 1;
					}

					if (p.origin == p.destination) {
						std::cerr << "init(): Error: pathway " << i << " has equal destination and origin " << p.destination << std::endl; printPathway(p); throw 1;
					}
				}
			}
		};
	}
}