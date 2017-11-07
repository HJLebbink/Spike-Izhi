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

#include <memory>	// for std::shared_ptr
#include <ctime>	// for clock


#include "../../Spike-DataSet-LIB/SpikeCaseFast.hpp"
#include "../../Spike-DataSet-LIB/SpikeStream.hpp"

#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"
#include "../../Spike-Tools-LIB/SpikeRuntimeOptions.hpp"

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SpikeNetwork1.hpp"
#include "../../Spike-Izhikevich-LIB/v1/PolyChronousGroups.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SampleScore.hpp"


/*
1a] train network on random input current
1b] train network on injected spikes from case data

2a] for every case find groups 
*/
namespace spike
{
	namespace v1
	{

		static const int matchQuorum = 7; // minimum number of spikes to define that a group has been found in spike behaviour
		static int counterSpikeAnalysis = 0; //TODO: why is this a global (static) variable?

		template <typename SpikeNetwork>
		class SpikeAnalysis
		{
		public:

			using Topology = typename SpikeNetwork::Topology;

			static const size_t nNeurons = SpikeNetwork::nNeurons;
			static const size_t N = Topology::N;


			SpikeAnalysis() = default;
			~SpikeAnalysis() = default;

			const SampleScore analyse(
				const std::shared_ptr<SpikeNetwork>& spikeNetwork,
				const std::shared_ptr<SpikeStream<Topology>>& spikeStream,
				const std::shared_ptr<const PolyChronousGroups>& groups,
				const SpikeRuntimeOptions& spikeRuntimeOptions)
			{
				const time_t timeInMs_SpikeAnalysis = clock();
				const std::vector<CaseId> caseIds = spikeStream->getCaseIds();
				SampleScore sampleScore(caseIds);

				//2] calculate the statistics for the different cases
				for (const CaseId& caseId : caseIds)
				{
					const auto spikeCaseData = spikeStream->getSpikeCase(caseId);
					if (!spikeCaseData->areAllNeuronsRandom())
					{
						this->calcStatistics_private(sampleScore, spikeNetwork, spikeStream->getRandomSpikeCase(), spikeCaseData, groups, spikeRuntimeOptions);
					}
				}
				std::cout << "SpikeAnalysis::analyse() passed time " << (float(clock() - timeInMs_SpikeAnalysis) / 1000) << " sec" << std::endl;
				return sampleScore;
			}

			const SampleScore analyseNoGroupsMnist(
				const std::shared_ptr<SpikeNetwork>& spikeNetwork,
				const std::shared_ptr<SpikeStream<Topology>>& spikeStream,
				const SpikeRuntimeOptions& spikeRuntimeOptions)
			{
				const time_t timeInMs_SpikeAnalysis = clock();
				const std::vector<CaseId> caseIds = spikeStream->getCaseIds();
				SampleScore sampleScore(caseIds);

				//2] calculate the statistics for the different cases
				for (const CaseId& caseId : caseIds)
				{
					const auto spikeCaseData = spikeStream->getSpikeCase(caseId);
					if (!spikeCaseData->areAllNeuronsRandom())
					{
						this->calcStatistics_private_noGroupsMnist(sampleScore, spikeNetwork, spikeStream->getRandomSpikeCase(), spikeCaseData, spikeRuntimeOptions);
					}
				}
				std::cout << "SpikeAnalysis::analyse() passed time " << (float(clock() - timeInMs_SpikeAnalysis) / 1000) << " sec" << std::endl;
				return sampleScore;
			}

		private:

			SpikeSet1Sec<Ms> sampleData_;
			SpikeSet1Sec<Ms> spikeDataDebug_;

			//void loadSpikeData(const int minute);

			//getMatch_private:: calculate 
			bool getMatch_private(
				const std::shared_ptr<const PolyChronousGroup>& group,
				const SpikeSet1Sec<Ms>& spikeData,
				const SpikeSet1Sec<Ms>& spikeDataDebug,
				const CaseId sampleCaseId,
				const SpikeRuntimeOptions& spikeRuntimeOptions)
			{
				const std::set<Firing> groupFiringsVector = group->getRegularFirings();

				const std::vector<NeuronId> firingNeuronId = spikeData.getFiringNeuronId();
				const std::vector<Ms> firingTime = spikeData.getFiringTime();

				const int * const beginPosPtr = spikeData.getTimePosBegin().data();
				const std::vector<int> endPosVector = spikeData.getTimePosEnd();
				const int * const endPosPtr = endPosVector.data();
				const unsigned int endPosPtrSize = static_cast<unsigned int>(endPosVector.size());


				const Ms searchRange = spikeRuntimeOptions.getTimeRoundingIntervalInMs();
				Ms timeOfLastSpikeMatch = 0;

				int match = 0;

				for (const Firing& groupFiring : groupFiringsVector)
				{

					if (groupFiring.time > timeOfLastSpikeMatch + 35)
					{
						//std::cout << "SpikeAnalysis::getMatch() period of silence, not change of match; firingTime=" << firingTime << "; timeOfLastSpikeMatch=" << timeOfLastSpikeMatch << std::endl;
						return false;
					}
					else
					{
						//	std::cout << "SpikeAnalysis::getMatch() no silence; firingTime=" << firingTime << "; timeOfLastSpikeMatch=" << timeOfLastSpikeMatch << std::endl;
					}

					if (checkPos(
						groupFiring.time,
						searchRange,
						groupFiring.neuronId,
						firingNeuronId,
						firingTime,
						beginPosPtr,
						endPosPtr,
						endPosPtrSize))
					{

						match++;
						timeOfLastSpikeMatch = groupFiring.time;


						//	std::cout << "SpikeAnalysis::getMatch() matchCount=" << match << "; neuronId=" << groupFiring.neuronId << "; time=" << groupFiring.time << std::endl;

						if (match >= matchQuorum)
						{
							std::cout << "SpikeAnalysis::getMatch(): found group " << group->getGroupId() << " (case " << group->getCaseId() << ") in sample with case " << sampleCaseId << "; match=" << match << std::endl;

							std::stringstream filename1;
							filename1 << tempDir << "/Temp/" << "matchSpikeData." << counterSpikeAnalysis;
							spikeData.saveToFile(filename1.str());

							std::stringstream filename2;
							filename2 << tempDir << "/Temp/" << "matchSpikeDataDebug." << counterSpikeAnalysis;
							spikeDataDebug.saveToFile(filename2.str());

							std::stringstream filename3;
							filename3 << tempDir << "/Temp/" << "matchGroupData." << counterSpikeAnalysis;
							group->saveToFile(filename3.str());

							std::stringstream filename4;
							filename4 << tempDir << "/Temp/" << "matchGroupMatch." << counterSpikeAnalysis;
							group->saveGroupMatch(filename4.str(), spikeData);

							counterSpikeAnalysis++;

							// we found a match, we can exist this method
							return true;
						}

					}
				}
				return false;
			}

			void calcStatistics_private(
				SampleScore& sampleScore,
				const std::shared_ptr<SpikeNetwork>& spikeNetwork,
				const std::shared_ptr<const SpikeCaseFast>& spikeCaseRandom,
				const std::shared_ptr<const SpikeCaseFast>& spikeCaseData,
				const std::shared_ptr<const PolyChronousGroups>& groups,
				const SpikeRuntimeOptions& spikeRuntimeOptions)
			{
				const std::vector<GroupId> groupIds = groups->getGroupIds();
				const CaseId sampleCaseId = spikeCaseData->getCaseId();
				//std::cout << "GroupMatch::calcStatistics(); going to sample from case " << caseId << std::endl;

				for (unsigned int sampleCount = 0; sampleCount < spikeRuntimeOptions.getNumberOfSamples(); sampleCount++)
				{
					if (sampleCount % 100 == 0)
					{
						std::cout << "SpikeAnalysis::calcStatistics_private(); sampleCount=" << sampleCount << std::endl;
					}
					//1] sample the network
					spikeNetwork->sampleOneCase(
						spikeCaseRandom,
						spikeCaseData,
						this->sampleData_,
						this->spikeDataDebug_);

					sampleScore.incSampleCount(sampleCaseId);

					//3] find which groups are present in the recorded (sampled) spikes
					for (const GroupId& groupId : groupIds)
					{

						const bool hasMatch = this->getMatch_private(
							groups->getGroup(groupId),
							this->sampleData_,
							this->spikeDataDebug_,
							sampleCaseId,
							spikeRuntimeOptions);

						if (hasMatch)
						{
							const CaseId matchedCaseId = groups->getGroup(groupId)->getCaseId();
							sampleScore.add(sampleCaseId, matchedCaseId);
						}
					}
				}
			}

			void calcStatistics_private_noGroupsMnist(
				SampleScore& sampleScore,
				const std::shared_ptr<SpikeNetwork>& spikeNetwork,
				const std::shared_ptr<const SpikeCaseFast>& spikeCaseRandom,
				const std::shared_ptr<const SpikeCaseFast>& spikeCaseData,
				const SpikeRuntimeOptions& spikeRuntimeOptions)
			{
				const CaseId sampleCaseId = spikeCaseData->getCaseId();
				std::cout << "GroupMatch::calcStatistics(); going to sample from case " << sampleCaseId << std::endl;

				const double sampleDurationInSeconds = static_cast<double>(spikeRuntimeOptions.getSampleTimeInMs()) / 1000;

				for (unsigned int sampleCount = 0; sampleCount < spikeRuntimeOptions.getNumberOfSamples(); sampleCount++)
				{
					if (sampleCount % 100 == 0)
					{
						std::cout << "SpikeAnalysis::calcStatistics_private_noGroupsMnist(); sampleCount=" << sampleCount << std::endl;
					}
					//1] sample the network
					spikeNetwork->sampleOneCase(
						spikeCaseRandom,
						spikeCaseData,
						this->sampleData_,
						this->spikeDataDebug_);

					sampleScore.incSampleCount(sampleCaseId);

					//2] find which output variable spikes are present in the recorded (sampled) spikes
					for (unsigned int outputLabel = 0; outputLabel < 10; outputLabel++)
					{
						const NeuronId neuronId = static_cast<NeuronId>((28 * 28) + outputLabel);

						const double hz = static_cast<float>(this->sampleData_.getNumberOfFirings(neuronId)) / sampleDurationInSeconds;
						std::cout << "calcStatistics_private_noGroupsMnist(): hz of label " << outputLabel << ": " << hz << " hz" << std::endl;
					}
				}
			}

			/*
			return true if the privided neuron fires at the provided time in the provided spike data
			*/
			__inline bool checkPos(
				const Ms timeIn,
				const Ms searchRange,
				const NeuronId neuronId,
				const std::vector<NeuronId>& spikeNeuronIdArray,
				const std::vector<Ms>& spikeTimeArray,
				const int * const beginPos,
				const int * const endPos,
				const unsigned int endPosSize)
			{
				Ms minTime = timeIn - searchRange;
				Ms maxTime = timeIn + searchRange;

				if (minTime < 0) minTime = 0;
				if (static_cast<unsigned int>(maxTime) >= endPosSize) maxTime = static_cast<Ms>(endPosSize - 1);

				for (int j = beginPos[minTime]; j <= endPos[maxTime]; ++j)
				{
					#if _DEBUG
					const int spikeTime = spikeTimeArray[j];
					if (!((spikeTime >= minTime) && (spikeTime <= maxTime)))
					{
						std::cerr << "SpikeAnalysis::checkPos() beginPos[minTime=" << minTime << "]=" << beginPos[minTime] << "; endPos[maxTime=" << maxTime << "]=" << endPos[maxTime] << "; spikeTimeArray[" << j << "]=" << spikeTime << std::endl;
						throw 1;
					}
					#endif
					if (spikeNeuronIdArray[j] == neuronId)
					{
						return true;
					}
				}
				return false;
			}
		};
	}
}