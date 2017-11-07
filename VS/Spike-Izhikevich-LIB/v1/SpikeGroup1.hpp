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
#include <memory> // for make_unique, unique_ptr

#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"
#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"
#include "../../Spike-Tools-LIB/timing.ipp"

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SpikeNetwork1.hpp"

namespace spike
{
	namespace v1
	{
		template <typename SpikeNetwork_i>
		class SpikeGroup1
		{
		public:
			using SpikeNetwork = SpikeNetwork_i;

			static const size_t Ne = SpikeNetwork::Ne;
			static const size_t Ni = SpikeNetwork::Ni;
			static const Delay D = SpikeNetwork::D;

			static const size_t nNeurons = SpikeNetwork::nNeurons;
			static const size_t N = SpikeNetwork::N;

			SpikeGroup1() = default;

			virtual ~SpikeGroup1() = default;

			void findPolychronousGroups_Izhikevich(
				const std::shared_ptr<SpikeNetwork>& networkState,
				const std::shared_ptr<PolyChronousGroups>& groups)
			{
				const PermutationIndexIterator end;
				GroupId groupId = 0;

				for (NeuronId seedNeuron = 0; seedNeuron < Ne; ++seedNeuron)
				{

					// 1] Given a seed neuron, select all pathways that point to this seed neuron and 
					// that have an efficacy larger than minEfficacyGroup
					int pre2Size = 0; // number of neurons that feed into seedNeuron with a weight larger than C_rel
					for (unsigned int i = 0; i < networkState->pre_size_[seedNeuron]; ++i)
					{
						const Weight2 weight = *networkState->s_pre_[seedNeuron][i];
						if (weight > spike::v1::constant::minEfficacyGroup)
						{
							this->pre2_[pre2Size] = networkState->pre_[seedNeuron][i];
							pre2Size++;
						}
					}
					//	std::cout << "NetworkLifV1::polychronous_Orginal() seedNeuron " << seedNeuron << " has " << N_my_pre << " incoming pathways (to neurons with an efficacy larger than " << C_rel << ")" << std::endl;

					//2] If size of the set of selected pathways to that point to seedNeuron is smaller than 3, break out of the loop;
					if (pre2Size < spike::v1::constant::group_width)
					{
						break; // impossible to find a group (with minimal width) if seedNeuron has too little relevant incoming pathways.
					}

					for (PermutationIndexIterator it = PermutationIndexIterator(pre2Size, spike::v1::constant::group_width); it != end; ++it)
					{
						const std::vector<unsigned int>& anchorPathwayIndex = *it;

						this->nFirings2 = 0; // empty the array of fired neurons
						memset(this->nPathways, 0, sizeof(int)*spike::v1::constant::polylenmax);	// set nPathways to zero;

						//1] Initialize the pathways such that the three selected pathways deliver their spike at the same time
						const Delay Dmax = getLargestDelay(anchorPathwayIndex, this->pre2_); // find the largest delay of the three archor pathways

						for (int i = 0; i < spike::v1::constant::group_width; ++i)
						{
							this->layer[i] = 1; // anchor neurons are in layer 1
							const Pre pre2 = this->pre2_[anchorPathwayIndex[i]];
							const Ms fireTime = Dmax - pre2.delay;
							this->updatePathways(networkState, fireTime, pre2.origin);
						}

						//2] given the current pathways, see what new activity emerges
						this->simulateGroup_Izhikevich(networkState);

						//3] If the number of neurons that has fired is over a certain threshold, store the relevant links
						if (this->nFirings2 > (2 * spike::v1::constant::group_width))
						{
							// fill the links with data
							this->updateLinks();

							if (this->groupHasSufficientSize_Izhikevich())
							{
								std::cout << "NetworkLifV1::polychronous_Izhikevich() found group: seedNeuron " << seedNeuron << ", groupId = " << groupId << ", nFirings2 = " << this->nFirings2 << ", T=" << this->firings2_[this->nFirings2 - 1].time << "\n";

								const auto group = std::make_shared<PolyChronousGroup>(groupId);

								for (int i = 0; i < spike::v1::constant::group_width; ++i)
								{
									const Pre pre2 = this->pre2_[anchorPathwayIndex[i]];
									const Ms fireTime = Dmax - pre2.delay;
									group->addAnchorFiring(Firing(fireTime, pre2.origin));
								}
								for (int i = 0; i < this->nFirings2; ++i)
								{
									group->addRegularFiring(this->firings2_[i]);
								}
								for (int i = 0; i < this->nLinks; ++i)
								{
									group->addLink(this->links[i]);
								}
								groups->add(std::move(group));
								groupId++;
							}
						}
					}
					const double time = ::tools::timing::get_elapsed_mcycles();
					std::cout << "NetworkLifV1::polychronous_Izhikevich(): seedNeuron " << seedNeuron << ": time usage: " << time << " ms" << std::endl;
				}
				std::cout << "\nnumber of groups found " << groupId << "\n";
			}

			void findPolychronousGroups_Lebbink(
				const std::shared_ptr<const SpikeNetwork>& networkState,
				const std::shared_ptr<PolyChronousGroups>& groups)
			{

				const std::vector<CaseId> caseIds = networkState->spikeStream_->getCaseIds();
				const unsigned int maxSeedGroupSize = 4;
				const PermutationIndexIterator end;
				GroupId groupId = 0;


				for (unsigned int seedGroupSize = 3; seedGroupSize <= maxSeedGroupSize; seedGroupSize++)
				{
					std::cout << "NetworkLifV1::findPolychronousGroups_Lebbink() groupSize = " << seedGroupSize << std::endl;

					for (const CaseId& caseId : caseIds)
					{
						const std::shared_ptr<const SpikeCaseFast> spikeCase = networkState->spikeStream_->getSpikeCase(caseId);
						if (!spikeCase->areAllNeuronsRandom())
						{
							::tools::reset_and_start_timer();

							//1] 
							//DEBUG_BREAK(); //TODO the following line does not compile
							//const std::vector<Firing> spikeDataVector = spikeCase->getSpikesVector();
							const std::vector<Firing> spikeDataVector;// = spikeCase->getSpikesVector();
							const unsigned int nSpikes = static_cast<unsigned int>(spikeDataVector.size());

							if (nSpikes < seedGroupSize)
							{
								std::cout << "NetworkLifV1::findPolychronousGroups_Lebbink: only " << nSpikes << " spikes in case " << caseId << ", needed " << seedGroupSize << std::endl;
							}
							else
							{
								for (PermutationIndexIterator it(PermutationIndexIterator(nSpikes, seedGroupSize)); it != end; ++it)
								{
									const std::vector<unsigned int>& spikeDataIndex = *it;

									//0] clear the pathways
									this->nFirings2 = 0; // empty the array of fired neurons
									memset(this->nPathways, 0, sizeof(int)*spike::v1::constant::polylenmax);	// set nPathways to zero;

									//1] init the pathways 
									for (unsigned int i = 0; i < seedGroupSize; i++)
									{
										const Firing firing = spikeDataVector[spikeDataIndex[i]];
										//std::cout << "time=" << firing.time << "; neuronId=" << firing.neuronId << std::endl;
										this->updatePathways(networkState, firing.time, firing.neuronId);
									}

									//2] given the current pathways, see what new activity emerges
									this->simulateGroup_Lebbink(networkState);

									//3] If the number of neurons that has fired is over a certain threshold, store the relevant links
									if (this->nFirings2 > 13)
									{
										// fill the links with data
										this->updateLinks();

										if (this->groupHasSufficientSize_Lebbink(seedGroupSize))
										{

											auto group = std::make_shared<PolyChronousGroup>(groupId);
											for (unsigned int i = 0; i < seedGroupSize; i++)
											{
												group->addAnchorFiring(spikeDataVector[spikeDataIndex[i]]);
											}
											for (int i = 0; i < this->nFirings2; i++)
											{
												const Firing firing = this->firings2[i];
												if (!group->isAnchorFiring(firing))
												{
													group->addRegularFiring(firing);
												}
											}
											for (int i = 0; i < this->nLinks; i++)
											{
												group->addLink(this->links[i]);
											}
											group->setCaseId(spikeCase->getCaseId());

											groups->add(std::move(group));
											//polyChronousGroup->saveToFile(tempDir + "/Groups", "group");

											groupId++;
											std::cout << "NetworkLifV1::findPolychronousGroups_Lebbink() found group: seedSize = " << seedGroupSize << "; caseId " << caseId << ", groupId = " << groupId << ", nFirings2 = " << this->nFirings2 << ", T=" << this->firings2[this->nFirings2 - 1].time << std::endl;
										}
									}
								}
							}
							const double time = ::tools::get_elapsed_mcycles();
							std::cout << "NetworkLifV1::findPolychronousGroups_Lebbink(): caseId " << caseId << ": time usage: " << time << " ms" << std::endl;
						} // else: case is random: do nothing
					}// end for case
				}
				std::cout << "NetworkLifV1::findPolychronousGroups_Lebbink(): number of groups found " << groupId << "\n";
			}

		private:

			int			nPathways[spike::v1::constant::polylenmax]; // number of pathways
			Pathway		pathway[spike::v1::constant::polylenmax][N];

			int			nLinks;
			Link		links[2 * spike::v1::constant::group_width*spike::v1::constant::polylenmax];

			int			nFirings2; // number of elements in firings2
			Firing		firings2_[spike::v1::constant::polylenmax];
			int			layer[spike::v1::constant::polylenmax];

			Pre			pre2_[spike::v1::constant::maxPreCounter];

			void simulateGroup_Izhikevich(const std::shared_ptr<SpikeNetwork>& networkState)
			{
				networkState->initVoltageVariables();	// initialize the voltage of the neurons

				Ms t_last = D + D + spike::v1::constant::latency + 1; // initialize the time window in which groups are sought.
				Ms time = 0;

				while ((time < t_last) && (this->nFirings2 < spike::v1::constant::polylenmax))
				{ // if the time is up, or if too many neurons have fired, stop looking for more neurons in this group

//1] Reset the input current;
					memset(networkState->inputCurrent_, 0, sizeof(float)*N);

					//2] Calculate the amount of input current that results from the current pathways
					for (int p = 0; p < this->nPathways[time]; ++p)
					{ // loop over all pathways that deliver a spike at time time
						const NeuronId postNeuronId = this->pathway[time][p].destination;
						networkState->inputCurrent_[postNeuronId] += this->pathway[time][p].weight;
					}
					//3] Calculate the voltage of the neurons
					networkState->updateState();

					//4] Check if the neuron is fired
					for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
					{
						const bool neuronCanFire = (networkState->v_[neuronId] >= spike::v1::constant::firingThreshold);
						if (neuronCanFire)
						{
							networkState->v_[neuronId] = networkState->c_[neuronId];
							networkState->u_[neuronId] += networkState->d_[neuronId];

							if (this->nFirings2 < spike::v1::constant::polylenmax)
							{ // if too many neurons have fired, ignore this neurons
								this->updatePathways(networkState, time, neuronId);

								// update the time window in which groups are sought.
								if (t_last < (time + D + 2))
								{
									t_last = time + D + 2;
									if (t_last > (spike::v1::constant::polylenmax - D - 1))
									{
										t_last = spike::v1::constant::polylenmax - D - 1;
									}
								}
							}
						}
					}
					time++;
				} // end of the while loop
			}

			void simulateGroup_Lebbink(const std::shared_ptr<SpikeNetwork>& networkState)
			{
				networkState->initVoltageVariables();	// initialize the voltage of the neurons

				Ms t_last = D + D + spike::v1::constant::latency + 1; // initialize the time window in which groups are sought.
				Ms time = 0;

				while ((time < t_last) && (this->nFirings2 < spike::v1::constant::polylenmax))
				{ // if the time is up, or if too many neurons have fired, stop looking for more neurons in this group

//1] Reset the input current;
					memset(networkState->inputCurrent_, 0, sizeof(float)*N);

					//2] Calculate the amount of input current that results from the current pathways
					for (int p = 0; p < this->nPathways[time]; p++)
					{ // loop over all pathways that deliver a spike at time time
						const NeuronId postNeuronId = this->pathway[time][p].destination;
						networkState->inputCurrent_[postNeuronId] += this->pathway[time][p].weight;
					}
					//3] Calculate the voltage of the neurons
					networkState->updateState();

					//4] Check if the neuron is fired
					for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
					{
						const bool neuronCanFire = (networkState->v[neuronId] >= spike::v1::constant::firingThreshold);
						if (neuronCanFire)
						{
							networkState->v[neuronId] = -65.0f;
							networkState->u[neuronId] += networkState->d[neuronId];

							if (this->nFirings2 < spike::v1::constant::polylenmax)
							{ // if too many neurons have fired, ignore this neurons
								this->updatePathways(networkState, time, neuronId);

								// update the time window in which groups are sought.
								if (t_last < (time + D + 2))
								{
									t_last = time + D + 2;
									if (t_last > (spike::v1::constant::polylenmax - D - 1))
									{
										t_last = spike::v1::constant::polylenmax - D - 1;
									}
								}
							}
						}
					}
					time++;
				} // end of the while loop
			}

			bool groupHasSufficientSize_Izhikevich()
			{
				// find the maximal layer in the link data
				int layerMax = 0;
				for (int j = 0; j < this->nLinks; ++j)
				{
					if (layerMax < this->links[j].layer)
					{
						layerMax = this->links[j].layer;
					}
				}
				if (layerMax < spike::v1::constant::min_group_path)
				{
					//		std::cout << "NetworkLifV1::groupHasSufficientSize() layerMax=" << layerMax << std::endl;
					return false;
				}

				// count how many of the links are used
				for (int i = 0; i < spike::v1::constant::group_width; ++i)
				{
					int used = 0;
					for (int j = 0; j < this->nLinks; ++j)
					{
						if ((this->links[j].origin == this->firings2_[i].neuronId) &&
							(this->links[j].destination < Ne))
						{
							used++;
						}
					}
					if (used == 0)
					{
						std::cout << "NetworkLifV1::groupHasSufficientSize_Izhikevich(): ERROR. NeuronId " << this->firings2_[i].neuronId << " at time " << this->firings2_[i].time << " is not used" << std::endl; throw 1;
					}
					if (used == 1)
					{
						return false;
					}
				}
				return true;
			}

			bool groupHasSufficientSize_Lebbink(const unsigned int seedGroupSize)
			{
				// find the maximal layer in the link data
				int layerMax = 0;
				for (int j = 0; j < this->nLinks; j++)
				{
					if (layerMax < this->links[j].layer)
					{
						layerMax = this->links[j].layer;
					}
				}
				if (layerMax < spike::v1::constant::min_group_path - 3)
				{
					//std::cout << "NetworkLifV1::groupHasSufficientSize() layerMax=" << layerMax << std::endl;
					return false;
				}

				// count how many of the links are used
				for (unsigned int i = 0; i < seedGroupSize; i++)
				{
					int used = 0;
					const NeuronId seedNeuronId = this->firings2[i].neuronId;

					for (int j = 0; j < this->nLinks; ++j)
					{
						if ((this->links[j].origin == seedNeuronId) &&
							(this->links[j].destination < Ne))
						{
							used++;
						}
					}
					if (used <= 1)
					{
						return false;
					}
				}

				return true;
			}

			void updatePathways(
				const std::shared_ptr<SpikeNetwork>& networkState,
				const Ms fireTime,
				const NeuronId firingNeuronId)
			{
				assert(firingNeuronId < nNeurons);
				assert(fireTime < 1000);

				this->firings2_[this->nFirings2].neuronId = firingNeuronId;
				this->firings2_[this->nFirings2].time = fireTime;
				this->nFirings2++;

				// thus, neuronId has fired, check for every delay (in the future) whether a synapse exists
				// with a weight larger than c_rel (c_rel is not relevant for inhibitory neurons)
				for (Delay delay = 0; delay < D; delay++)
				{
					const Ms spikeArrivalTime = fireTime + delay + 1;
					int counter = this->nPathways[spikeArrivalTime];

					for (SynapseLength j = 0; j < networkState->synapse_size_[firingNeuronId][delay]; j++)
					{
						const Synapse syn = networkState->synapse_[firingNeuronId][delay][j];
						const Weight2 weight = networkState->s_[firingNeuronId][syn];

						if ((weight > spike::v1::constant::minEfficacyGroup) || (firingNeuronId >= Ne))
						{
							//std::cout << "counter" << counter << "; firingNeuronId" << firingNeuronId << "; fireTime" << fireTime << std::endl;
							this->pathway[spikeArrivalTime][counter].origin = firingNeuronId;
							this->pathway[spikeArrivalTime][counter].destination = networkState->post_[firingNeuronId][syn];
							this->pathway[spikeArrivalTime][counter].delay = delay;
							this->pathway[spikeArrivalTime][counter].weight = weight;
							counter++;
						}
					}
					this->nPathways[spikeArrivalTime] = counter;
				}
			}

			void updateLinks()
			{ // update the links given the pathways and firings
				this->nLinks = 0;

				for (int i = spike::v1::constant::group_width; i < this->nFirings2; ++i)
				{ // start i with groupsize
					const NeuronId selectedNeuronId = this->firings2_[i].neuronId;
					const Ms selectedFireTime = this->firings2_[i].time;

					this->layer[i] = 0; // reset the layer

					for (Ms time = selectedFireTime; (time > (selectedFireTime - spike::v1::constant::latency)) && (time >= 0); --time)
					{
						for (int j = 0; j < this->nPathways[time]; ++j)
						{

							if ((this->pathway[time][j].destination == selectedNeuronId) &&
								(this->pathway[time][j].origin < Ne))
							{

								// calculate the layer for the link
								for (int k = 0; k < i; ++k)
								{
									if ((this->firings2_[k].neuronId == this->pathway[time][j].origin) &&
										((this->layer[k] + 1) > this->layer[i]))
									{
										this->layer[i] = this->layer[k] + 1;
									}
								}

								// store the data in a new links element
								this->links[this->nLinks].origin = this->pathway[time][j].origin;
								this->links[this->nLinks].destination = this->pathway[time][j].destination;
								this->links[this->nLinks].delay = this->pathway[time][j].delay;
								this->links[this->nLinks].layer = static_cast<unsigned short>(this->layer[i]);
								this->nLinks++;
							}
						}
					}
				}
			}

			Delay getLargestDelay(const std::vector<unsigned int>& anchorNeuronIndex, const Pre pre[])
			{
				Delay dMax = 0;
				for (int i = 0; i < spike::v1::constant::group_width; i++)
				{
					if (dMax < pre[anchorNeuronIndex[i]].delay)
					{
						dMax = pre[anchorNeuronIndex[i]].delay;
					}
				}
				return dMax;
			}
		};
	}
}