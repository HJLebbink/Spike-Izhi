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

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <memory>	// for std::shared_ptr

#define _USE_SSE2

#include "../Spike-Tools-LIB/timing.ipp"
#include "../Spike-Tools-LIB/SpikeTypes.hpp"

#include "../Spike-DataSet-LIB/DataSetFactory.hpp"
#include "../Spike-DataSet-LIB/DataSetBackendTxt.hpp"
#include "../Spike-DataSet-LIB/SpikeStream.hpp"
#include "../Spike-DataSet-LIB/SpikeStreamFactory.hpp"
#include "../Spike-DataSet-LIB/SpikeDataSet.hpp"
#include "../Spike-DataSet-LIB/TranslationsFactory.hpp"

#include "../../Spike-Izhikevich-LIB/Topology.hpp"
#include "../../Spike-Izhikevich-LIB/PermutationIndexIterator.hpp"

#include "../../Spike-Izhikevich-LIB/v1/SpikeNetwork1.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SpikeGroup1.hpp"
#include "../../Spike-Izhikevich-LIB/v1/PolyChronousGroup.hpp"
#include "../../Spike-Izhikevich-LIB/v1/PolyChronousGroups.hpp"
#include "../../Spike-Izhikevich-LIB/v1/SpikeAnalysis.hpp"
#include "../../Spike-Izhikevich-LIB/v1/Search_Network_Config.hpp"

#include "../../Spike-Izhikevich-LIB/v2/Network2.hpp"
#include "../../Spike-Izhikevich-LIB/v2/TopologyGenerator.hpp"

#include "../../Spike-Izhikevich-LIB/v4/Network4.hpp"
#include "../../Spike-Izhikevich-LIB/v4/SpikeDataSetMatlab4.hpp"

using namespace ::spike;
using namespace ::spike::tools;
using namespace ::spike::v2;

template <typename Topology>
std::shared_ptr<SpikeStream<Topology>> loadMnistSpikeStream(
	const SpikeRuntimeOptions& spikeRuntimeOptions)
{
	const auto spikeStream = std::make_shared<SpikeStream<Topology>>(spikeRuntimeOptions);

	std::vector<NeuronId> neuronIds;
	for (const NeuronId& neuronId : Topology::iterator_AllNeurons()) {
		neuronIds.push_back(neuronId);
	}

	//1] create one random case
	const Ms caseTailSilenceInMs = 0;
	const Ms randomCaseDurationInMs = spikeRuntimeOptions.getRandomCaseDurationInMs();
	const CaseId nextCaseId = CaseId(0);
	const CaseLabel caseLabel = NO_CASE_LABEL;
	const auto spikeCase = std::make_shared<SpikeCaseFast>(nextCaseId, caseLabel, neuronIds, randomCaseDurationInMs, caseTailSilenceInMs);
	spikeCase->setAllNeuronsRandomSpikeHz(spikeRuntimeOptions.getRandomSpikeHz());
	spikeStream->add(std::move(spikeCase));

	//2.1 get the file name
	//const std::string spikeDataSetFilename = "C:/Data/mnist data/14x14/SpikeDataSetMnist-test-only10-14x14.txt";
	const std::string spikeDataSetFilename = "C:/Data/mnist data/28x28/SpikeDataSetMnist-test-only10-28x28.txt";
	std::cout << "Main::loadMnistSpikeStream:: load SpikeDataSet from file " << spikeDataSetFilename << std::endl;

	//2.2 load the spike data
	const auto spikeDataSet = std::make_shared<SpikeDataSet<>>();
	spikeDataSet->loadFromFile(spikeDataSetFilename);

	//2.3 add the spike data to the stream
	spikeStream->addSpikeDataSet(spikeDataSet);

	return spikeStream;
}

template <typename Topology>
std::shared_ptr<SpikeStream<Topology>> loadSpikeStreamFromDataSet(
	const unsigned int nCases,
	const SpikeRuntimeOptions& spikeRuntimeOptions)
{
	/// PARAMETERS
	const bool createRandomSpikeStream = false;

	const bool createRandomSpikeDataSet = false;
	const bool loadSpikeDataSet = false;

	const bool createRandomDataSet = true;
	const bool loadDataSet = false;

	const bool createRandomTranslation = true;
	const bool loadTranslation = false;
	
	const std::string spikeDataSetTrainFilename = sourceDir + "/14x14/SpikeDataSetMnist-test-only10-train-14x14.txt";
	const std::string dataSetFilename = tempDir + "/Topology/dataSet.txt";
	const std::string translationsFilename = tempDir + "/Topology/translation.txt";

	const std::string spikeDataSetFilename_new = tempDir + "/Topology/spikeDataSet_new.txt";
	const std::string spikeDataSetFilename_components = tempDir + "/Topology/spikeDataSet_components.txt";
	const std::string dataSetFilename_new = tempDir + "/Topology/dataSet_new.txt";
	const std::string translationsFilename_new = tempDir + "/Topology/translation_new.txt";

	/// CODE

	//1] create the neuronIds
	std::vector<NeuronId> neuronIds;
	for (const NeuronId& neuronId : Topology::iterator_AllNeurons()) {
		neuronIds.push_back(neuronId);
	}

	if (createRandomSpikeStream) {
		std::cout << "Main:: generating a random SpikeStream." << std::endl;
		const bool createRandomCase = true;
		const auto spikeStream = SpikeStreamFactory<Topology>::createRandomSpikeStream(nCases, createRandomCase, neuronIds, spikeRuntimeOptions);
		return spikeStream;
	} else { //create spikeStream from its components
		const auto spikeStream = std::make_shared<SpikeStream<Topology>>(spikeRuntimeOptions);
		std::shared_ptr<SpikeDataSet<MyDataType>> spikeDataSet;
		std::shared_ptr<DataSet<DataSetBackendTxt<MyDataType>, MyDataType>> dataSet;
		std::shared_ptr<Translations<MyDataType>> translations;

		if (createRandomSpikeDataSet) {
			std::cout << "Main:: generating a random SpikeDataSet." << std::endl;
			//spikeDataSet = createRandomSpikeDataSet();
			//spikeDataSet.saveToFile(spikeDataSetFilename_new);
			throw 1;
		} else if (loadSpikeDataSet) {
			std::cout << "Main:: load a SpikeDataSet from file " << spikeDataSetTrainFilename << std::endl;
			spikeDataSet = std::make_shared<SpikeDataSet<MyDataType>>();
			spikeDataSet->loadFromFile(spikeDataSetTrainFilename);

			// create one random case
			const CaseId nextCaseId = CaseId(static_cast<CaseIdType>(dataSet->getNumberOfCases()));
			const CaseLabel caseLabel = CaseLabel(static_cast<CaseLabelType>(nextCaseId.val));
			const auto spikeCase = std::make_shared<SpikeCaseFast>(nextCaseId, caseLabel, neuronIds, spikeRuntimeOptions.getRandomCaseDurationInMs(), 0);
			spikeCase->setAllNeuronsRandomSpikeHz(0);
			spikeStream->add(std::move(spikeCase));
		} else { // create SpikeDataSet from its components
			std::cout << "Main:: create a SpikeDataSet from its components." << std::endl;
			if (createRandomDataSet) {
				std::cout << "Main:: generate a random DataSet." << std::endl;
				const unsigned int nVariables = 3;
				const unsigned int maxValue = 5;
				const float percentageOfMissingValues = 0;

				Options<MyDataType> dataSetOptions;
				dataSetOptions.setMissingValue(99999);

				dataSet = std::make_shared<DataSet<DataSetBackendTxt<MyDataType>, MyDataType>>(DataSetFactory::createRandomDataSet<DataSetBackendTxt<MyDataType>, MyDataType>(
					nVariables, nCases, maxValue, percentageOfMissingValues, dataSetOptions));

				// optional: save to file
				dataSet->saveToFile(dataSetFilename_new);

				// create one random case
				const CaseId nextCaseId = CaseId(static_cast<CaseIdType>(dataSet->getNumberOfCases()));
				const CaseLabel caseLabel = CaseLabel(static_cast<CaseLabelType>(nextCaseId.val));
				const auto spikeCase = std::make_shared<SpikeCaseFast>(nextCaseId, caseLabel, neuronIds, spikeRuntimeOptions.getRandomCaseDurationInMs(), spikeRuntimeOptions.getCaseTailSilenceInMs());
				spikeCase->setAllNeuronsRandomSpikeHz(0);
				spikeStream->add(std::move(spikeCase));
			} else if (loadDataSet) {
				std::cout << "Main:: load a DataSet from file " << dataSetFilename << std::endl;
				dataSet->loadFromFile(dataSetFilename);

				// create one random case
				const CaseId nextCaseId = CaseId(static_cast<CaseIdType>(dataSet->getNumberOfCases()));
				const CaseLabel caseLabel = CaseLabel(static_cast<CaseLabelType>(nextCaseId.val));
				const auto spikeCase = std::make_shared<SpikeCaseFast>(nextCaseId, caseLabel, neuronIds, spikeRuntimeOptions.getRandomCaseDurationInMs(), 0);
				spikeCase->setAllNeuronsRandomSpikeHz(0);
				spikeStream->add(std::move(spikeCase));
			} else { // create dataSet from its components
				std::cout << "Main:: INVALID configuration for DataSet" << std::endl;
				throw std::runtime_error("Main:: INVALID configuration for DataSet");
			}
			if (createRandomTranslation) {
				std::cout << "Main:: generate a random Translation." << std::endl;
				translations = TranslationsFactory::createRandomStrategy2<MyDataType>(dataSet, spikeRuntimeOptions);
				translations->saveToFile(translationsFilename_new);
				//translations->loadFromFile(translationsFilename_new);
				//translations->saveToFile("C:/Temp/Spike/A/translation_new2.txt");
			} else if (loadTranslation) {
				std::cout << "Main:: load a Translation from file " << translationsFilename << std::endl;
				translations->loadFromFile(translationsFilename);
			} else { // create dataSet from its components
				std::cout << "Main:: INVALID configuration Translation" << std::endl;
				throw std::runtime_error("Main:: INVALID configuration for Translation");
			}
			spikeDataSet->load(dataSet, translations);

			//todo set the classifications
			//spikeDataSet.setClassificationLabel(caseId, classificationLabel);
			//throw 1;

			// optional: save to file
			spikeDataSet->saveToFile(spikeDataSetFilename_components);
		}
		spikeStream->addSpikeDataSet(spikeDataSet);
		return spikeStream;
	}
}

void run_Izhikevich_v1_original_experiment()
{
	std::cout << "Main:: run_Izhikevich_v1_experiment." << std::endl;

	const unsigned int trainTimeInSec = 1 * 24 * 60 * 60;

	const unsigned int nExcitatoryNeurons = 800;
	const unsigned int nInhibitoryNeurons = 200;
	const unsigned int nSensorNeurons = 0;
	const unsigned int nMotorNeurons = 0;

	const SynapseLength M = 100;		// the number of outgoing pathways (synapses per neuron)
	const Delay D = 20;					// maximal axonal conduction delay

	using SpikeNetwork = SpikeNetwork1 < Topology < nExcitatoryNeurons, nInhibitoryNeurons, M, D, nSensorNeurons, nMotorNeurons > >;
	using SpikeNetworkGroup = SpikeGroup1 < SpikeNetwork >;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setCaseDurationInMs(0);
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(50);
	spikeRuntimeOptions.setRandomSpikeHz(1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(100);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/v1/Spikes/Train");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/v1/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/v1/State");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/v1/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-izhikevich");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-izhikevich");
	spikeRuntimeOptions.setFilenamePrefix_State("state-izhikevich");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-izhikevich");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(0 * 1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);

	// group finding options
	spikeRuntimeOptions.setTimeRoundingIntervalInMs(2);

	//1] create spike stream
	std::cout << "Main:: generating a random SpikeStream." << std::endl;
	std::vector<NeuronId> neuronIds;
	const unsigned int nNeurons = SpikeNetwork::nNeurons;
	neuronIds.reserve(nNeurons);
	for (NeuronId neuronId = 0; neuronId < nNeurons; ++neuronId)
	{
		neuronIds.push_back(neuronId);
	}
	const unsigned int nCases = 0;
	const bool createRandomCase = true;
	const auto spikeStream = SpikeStreamFactory<SpikeNetwork::Topology>::createRandomSpikeStream(nCases, createRandomCase, neuronIds, spikeRuntimeOptions);
	//std::cout << spikeStream->toString() << std::endl;

	//2 create topology
	const auto topology = std::make_shared<SpikeNetwork::Topology>();
	if (false)
	{
		//topology->load_Izhikevich_Original();
		//topology->saveToFile(tempDir + "/Topology/topology_start_izhikevich_1.txt");
		topology->loadFromFile(tempDir + "/topology-izhikevich.train.32400.txt");
	}
	else
	{
		topology->load_Izhikevich_new();
		//topology->saveToFile(tempDir + "/Topology/topology_start_izhikevich_2.txt");
	}

	//std::cout << topology->connectivityOverview() << std::endl;

	//3 create spike network
	const auto spikeNetwork = std::make_shared<SpikeNetwork>(spikeRuntimeOptions);
	spikeNetwork->setTopology(topology);

	//4] train the topology
	spikeNetwork->setSpikeStream(spikeStream);

	const bool performTrain = true;
	if (performTrain)
	{
		const bool useConfusionMatrix = false;
		const bool plotProgress = true;
		spikeNetwork->train(trainTimeInSec, useConfusionMatrix, plotProgress);
	}

	const bool performGroupSearch = true;
	if (performGroupSearch)
	{
		const bool useGroupBasedPerformance = true;
		if (useGroupBasedPerformance)
		{
			//5] find the groups in the topology
			auto groups = std::make_shared<PolyChronousGroups>();

			const bool loadGroupsFromFile = false;
			if (loadGroupsFromFile)
			{
				groups->loadFromFile(tempDir + "/v1/Group/group");
			}
			else
			{ // find groups in the current topology
				spikeNetwork->setSpikeStream(spikeStream);
				const auto spikeNetworkGroup = std::make_shared<SpikeNetworkGroup>();

				spikeNetworkGroup->findPolychronousGroups_Izhikevich(spikeNetwork, groups);
				//spikeNetworkGroup->findPolychronousGroups_Lebbink(spikeNetwork, groups);
				groups->saveToFile(tempDir + "/v1/Group/group");
			}
			std::cout << groups->getOverview() << std::endl;

			//6] scan the spike data for occurances of the groups
			const bool performSamples = false;
			if (performSamples)
			{
				spikeRuntimeOptions.setStartUpTimeInMs(500);
				spikeRuntimeOptions.setSampleTimeInMs(groups->getLongestLength() + 10); // longest length plus some extra spikes of 10 ms
				if ((spikeRuntimeOptions.getSampleTimeInMs() + spikeRuntimeOptions.getStartUpTimeInMs()) > 1000)
				{
					spikeRuntimeOptions.setSampleTimeInMs(1000 - spikeRuntimeOptions.getStartUpTimeInMs());
				}

				const auto spikeAnalysis = std::make_shared<SpikeAnalysis<SpikeNetwork>>();
				const SampleScore sampleScore = spikeAnalysis->analyse(spikeNetwork, spikeStream, groups, spikeRuntimeOptions);
				std::cout << sampleScore.toString() << std::endl;
			}
		}
		else
		{
			//6] scan the spike data for occurances of the groups
			const bool performSamples = true;
			if (performSamples)
			{
				spikeRuntimeOptions.setStartUpTimeInMs(0);
				spikeRuntimeOptions.setSampleTimeInMs(200);

				const auto spikeAnalysis = std::make_shared<SpikeAnalysis<SpikeNetwork>>();
				const SampleScore sampleScore = spikeAnalysis->analyseNoGroupsMnist(spikeNetwork, spikeStream, spikeRuntimeOptions);
				std::cout << sampleScore.toString() << std::endl;
			}
		}
	}
}

void run_Izhikevich_v1_MNIST_experiment()
{
	std::cout << "Main:: run_Izhikevich_v1_MNIST_experiment." << std::endl;

	const unsigned int trainTimeInSec = 10 * 24 * 60 * 60;

	const unsigned int nExcitatoryNeurons = 800;
	const unsigned int nInhibitoryNeurons = 200;
	//const unsigned int nSensorNeurons = 14*14;
	const unsigned int nSensorNeurons = 28 * 28;
	const unsigned int nMotorNeurons = 10;

	const SynapseLength M = 100;		// the number of outgoing pathways (synapses per neuron)
	const Delay D = 20;					// maximal axonal conduction delay

	using SpikeNetwork = SpikeNetwork1 < Topology < nExcitatoryNeurons, nInhibitoryNeurons, M, D, nSensorNeurons, nMotorNeurons > >;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(00);
	spikeRuntimeOptions.setRandomSpikeHz(0.1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(100);
	spikeRuntimeOptions.setCaseTailSilenceInMs(0);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/v1-mnist/Spikes/Train");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/v1-mnist/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/v1-mnist/State");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/v1-mnist/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-mnist");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-mnist");
	spikeRuntimeOptions.setFilenamePrefix_State("state-mnist");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-mnist");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(1 * 60 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);


	//1] create topology
	const auto topology = std::make_shared<SpikeNetwork::Topology>();
	if (true) {
		topology->load_mnist28x28();
		//topology->saveToFile(tempDir + "/topology/topology-mnist.start.txt");
	} else {
		topology->loadFromFile(tempDir + "/topology/topology-mnist.train.540.txt");
	}
	//std::cout << topology->connectivityOverview() << std::endl;


	//2] create spike network
	const auto spikeNetwork = std::make_shared<SpikeNetwork>(spikeRuntimeOptions);
	spikeNetwork->setTopology(topology);

	//3] create spike stream
	const auto stream = loadMnistSpikeStream<SpikeNetwork::Topology>(spikeRuntimeOptions);
	spikeNetwork->setSpikeStream(stream);

	//4] train the network
	const bool useConfusionMatrix = true;
	const bool plotProgress = true;
	spikeNetwork->train(trainTimeInSec, useConfusionMatrix, plotProgress);
}

void run_Izhikevich_v1_id4x4_experiment()
{
	//DEBUG_BREAK(); // this code does not work

	std::cout << "Main:: run_id4x4_experiment." << std::endl;

	const unsigned int trainTimeInSec = 1 * 1 * 10 * 60;

	const unsigned int nExcitatoryNeurons = 800;
	const unsigned int nInhibitoryNeurons = 200;
	const unsigned int nSensorNeurons = 4 * 50;
	const unsigned int nMotorNeurons = 4 * 50;

	const SynapseLength M = 100;		// the number of outgoing pathways (synapses per neuron)
	const Delay D = 20;					// maximal axonal conduction delay

	using SpikeNetwork = SpikeNetwork1 < Topology < nExcitatoryNeurons, nInhibitoryNeurons, M, D, nSensorNeurons, nMotorNeurons > >;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(00);
	spikeRuntimeOptions.setRandomSpikeHz(0.1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(100);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/Spikes/Train");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/State");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-id4");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-id4");
	spikeRuntimeOptions.setFilenamePrefix_State("state-id4");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-i4");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(0 * 60 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);


	//1] create topology
	const auto topology = std::make_shared<SpikeNetwork::Topology>();
	if (true) {
		//topology->load_id<4,50>();
		//topology->saveToFile(tempDir + "/topology/topology-id4.start.txt");
	} else {
		topology->loadFromFile(tempDir + "/topology/topology-id.train.540.txt");
	}
	//std::cout << topology->connectivityOverview() << std::endl;


	//2] create spike network
	const auto spikeNetwork = std::make_shared<SpikeNetwork>(spikeRuntimeOptions);
	spikeNetwork->setTopology(topology);

	//3] create spike stream
	const auto stream = loadMnistSpikeStream<SpikeNetwork::Topology>(spikeRuntimeOptions);
	spikeNetwork->setSpikeStream(stream);

	//4] train the network
	const bool useConfusionMatrix = true;
	const bool plotProgress = true;
	spikeNetwork->train(trainTimeInSec, useConfusionMatrix, plotProgress);
}

void run_Izhikevich_v1_Search_Network_Config_experiment()
{
	std::cout << "Main:: run_Search_Network_Config_experiment." << std::endl;

	const unsigned int nExcitatoryNeurons = 800;
	const unsigned int nInhibitoryNeurons = 200;
	const SynapseLength M = 100;		// the number of outgoing pathways (synapses per neuron)
	const Delay D = 20;					// maximal axonal conduction delay

	using SpikeNetwork = SpikeNetwork1 < Topology < nExcitatoryNeurons, nInhibitoryNeurons, M, D > >;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(0);
	spikeRuntimeOptions.setRandomSpikeHz(0.1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(100);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/Spikes/Train");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/State");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-search");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-search");
	spikeRuntimeOptions.setFilenamePrefix_State("state-search");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-search");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 1);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(0 * 60 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);


	const auto searchNetworkConfig = std::make_shared<Search_Network_Config<SpikeNetwork>>(spikeRuntimeOptions);

	searchNetworkConfig->run();
}

void run_Izhikevich_v1_Masquelier_experiment()
{
	std::cout << "Main:: run_Izhikevich_v1_Masquelier_experiment." << std::endl;

	const unsigned int trainTimeInSec = 1 * 1 * 10 * 60;

	const unsigned int nExcitatoryNeurons = 2000;
	const unsigned int nInhibitoryNeurons = 3;
	const SynapseLength M = nInhibitoryNeurons;		// the number of outgoing pathways (synapses per neuron)
	const Delay D = 20;								// maximal axonal conduction delay

	using SpikeNetwork = SpikeNetwork1 < Topology < nExcitatoryNeurons, nInhibitoryNeurons, M, D > >;
	using TopologyX = SpikeNetwork::Topology;

	const unsigned int nCases = nInhibitoryNeurons;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setCaseDurationInMs(50);//only used when cases are generated...
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(50);
	spikeRuntimeOptions.setRandomSpikeHz(0.5);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(100);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/v1-masq/Spikes");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/v1-masq/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/v1-masq/State");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/v1-masq/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-masquelier");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-masquelier");
	spikeRuntimeOptions.setFilenamePrefix_State("state-masquelier");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-masquelier");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(1 * 1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);

	//1] create spike stream

	//SpikeSetLarge spikeSet;
	//spikeSet.loadFromFile("C:/Data/spike data/afferent.hj.rand000.txt");
	//spikeSet.saveToFile("C:/Data/spike data/afferent.hj.rand000.b.txt");


	const auto spikeStream = loadSpikeStreamFromDataSet<TopologyX>(nCases, spikeRuntimeOptions);
	//std::cout << spikeStream->toString() << std::endl;

	//2] create topology and spike network
	const auto topology = std::make_shared<TopologyX>();
	if (true) {
		topology->load_Masquelier();
	} else {
		topology->loadFromFile(sourceDir + "/14x14/topology/topology_mnist14x14.1296000.txt");
	}

	//3] create spike network
	const auto spikeNetwork = std::make_shared<SpikeNetwork>(spikeRuntimeOptions);
	spikeNetwork->setTopology(topology);
	spikeNetwork->setSpikeStream(spikeStream);

	//4] train the topology
	const bool useConfusionMatrix = false;
	const bool plotProgress = true;
	spikeNetwork->train(trainTimeInSec, useConfusionMatrix, plotProgress);
}

void run_Izhikevich_v2_MNIST_experiment()
{
	std::cout << "Main:: run_MNIST_Network2_experiment." << std::endl;

	const Delay maxDelay = 20;
	const SynapseLength M = 100;

	const size_t Ns = 28 * 28;
	const size_t Nm = 10;
	const size_t Ne = 800 + Ns;
	const size_t Ni = 200;
	using TopologyX = Topology < Ne, Ni, M, maxDelay, Ns, Nm > ;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setCaseDurationInMs(50);//only used when cases are generated...
	spikeRuntimeOptions.setCaseTailSilenceInMs(150);
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(0);
	spikeRuntimeOptions.setRandomSpikeHz(1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(4);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/v2-masq/Spikes");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/v2-masq/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/v2-masq/State");
	spikeRuntimeOptions.setFilenamePath_WeightDelta(tempDir + "/v2-masq/WeightDelta");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/v2-masq/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-code2");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-code2");
	spikeRuntimeOptions.setFilenamePrefix_State("state-code2");
	spikeRuntimeOptions.setFilenamePrefix_WeightDelta("weightDelta-code2");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-code2");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(0 * 1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_WeightDelta(0 * 1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);

	const unsigned int trainTimeInSec = 1 * 1 * 1 * 60;

	//1] create topology
	const auto topology = std::make_shared<TopologyX>();
	//topology->load_mnist28x28();
	topology->load_mnist2();
	//std::cout << topology->connectivityOverview() << std::endl;

	//2] create spike network
	const auto spikeNetwork = std::make_shared<Network2<TopologyX>>(spikeRuntimeOptions);
	spikeNetwork->setTopology(topology);

	//3] create spike stream
	const auto stream = loadMnistSpikeStream<TopologyX>(spikeRuntimeOptions);
	spikeNetwork->setSpikeStream(stream);

	//4] train the network
	const bool useConfusionMatrix = true;
	const bool plotProgress = true;
	spikeNetwork->train(trainTimeInSec, useConfusionMatrix, plotProgress);
}

void run_Izhikevich_v4_experiment()
{
	std::cout << "Main:: run_Izhikevich_v4_experiment." << std::endl;

	const Delay maxDelay = 20;
	const SynapseLength M = 100;

	const size_t Ns = 0;
	const size_t Nm = 0;
	const size_t Ne = 800;
	const size_t Ni = 200;
	using TopologyX = Topology < Ne, Ni, M, maxDelay, Ns, Nm >;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setCaseDurationInMs(50);//only used when cases are generated...
	spikeRuntimeOptions.setCaseTailSilenceInMs(150);
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(0);
	spikeRuntimeOptions.setRandomSpikeHz(1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(4);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/v4/Spikes");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/v4/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/v4/State");
	spikeRuntimeOptions.setFilenamePath_WeightDelta(tempDir + "/v4/WeightDelta");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/v4/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-v4");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-v4");
	spikeRuntimeOptions.setFilenamePrefix_State("state-v4");
	spikeRuntimeOptions.setFilenamePrefix_WeightDelta("weightDelta-v4");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-v4");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(1 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_State(0 * 1 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(0 * 1 * 60 * 60);
	spikeRuntimeOptions.setDumpIntervalInSec_WeightDelta(0 * 1 * 1 * 1);
	spikeRuntimeOptions.setDumpIntervalInSec_Group(0 * 1 * 60);

	const unsigned int trainTimeInSec = 1 * 1 * 60 * 60;

	const size_t nSubMs = 10;

	//1] create topology
	const auto topology = std::make_shared<TopologyX>();
	topology->load_Izhikevich_new();

	spike::v4::Network4<TopologyX, nSubMs> spikeNetwork4(spikeRuntimeOptions);
	spikeNetwork4.setTopology(topology);

	//4] train the network
	const bool useConfusionMatrix = false;
	const bool plotProgress = true;
	spikeNetwork4.run(trainTimeInSec, useConfusionMatrix, plotProgress);

}

void run_Izhikevich_v4_Masquelier_experiment()
{
	std::cout << "Main:: run_Izhikevich_v4_Masquelier_experiment." << std::endl;

	const Delay maxDelay = 20;
	const SynapseLength M = 100;

	const size_t Ns = 0;
	const size_t Nm = 0;
	const size_t Ne = 2000;
	const size_t Ni = 3;
	//const size_t nNeurons = Ns + Nm + Ne + Ni;
	using TopologyX = Topology < Ne, Ni, M, maxDelay, Ns, Nm >;

	SpikeRuntimeOptions spikeRuntimeOptions = SpikeRuntimeOptions();

	// case generation options
	spikeRuntimeOptions.setCaseDurationInMs(50);//only used when cases are generated...
	spikeRuntimeOptions.setCaseTailSilenceInMs(150);
	spikeRuntimeOptions.setRefractoryPeriodInMs(5);
	spikeRuntimeOptions.setRandomCaseDurationInMs(0);
	spikeRuntimeOptions.setRandomSpikeHz(1);
	spikeRuntimeOptions.setCorrectNeuronSpikeHz(4);

	spikeRuntimeOptions.setFilenamePath_Spikes(tempDir + "/v4-masq/Spikes");
	spikeRuntimeOptions.setFilenamePath_Topology(tempDir + "/v4-masq/Topology");
	spikeRuntimeOptions.setFilenamePath_State(tempDir + "/v4-masq/State");
	spikeRuntimeOptions.setFilenamePath_WeightDelta(tempDir + "/v4-masq/WeightDelta");
	spikeRuntimeOptions.setFilenamePath_Group(tempDir + "/v4-masq/Group");

	spikeRuntimeOptions.setFilenamePrefix_Spikes("spikes-v4");
	spikeRuntimeOptions.setFilenamePrefix_Topology("topology-v4");
	spikeRuntimeOptions.setFilenamePrefix_State("state-v4");
	spikeRuntimeOptions.setFilenamePrefix_WeightDelta("weightDelta-v4");
	spikeRuntimeOptions.setFilenamePrefix_Group("group-v4");

	spikeRuntimeOptions.setDumpIntervalInSec_Spikes(0 * 1 * 1);
	spikeRuntimeOptions.setDumpIntervalInSec_State(1 * 1 * 10);
	spikeRuntimeOptions.setDumpIntervalInSec_Topology(1 * 1 * 10);
	spikeRuntimeOptions.setDumpIntervalInSec_WeightDelta(0 * 1 * 10);

	const unsigned int trainTimeInSec = 226;

	const size_t nSubMs = 10;

	//1] create topology
	const auto topology = std::make_shared<TopologyX>();
	topology->load_Masquelier();

	spike::v4::Network4<TopologyX, nSubMs> network4(spikeRuntimeOptions);
	network4.setTopology(topology);

	const std::string spikeInputFilename = sourceDir + "/afferent.hj.rand000.mat";
	const std::string classificationFilename = sourceDir + "/classificationAll.rand000.txt";

	auto spikeDataSet = std::make_shared<spike::v4::SpikeDataSetMatlab4<Ne, nSubMs>>(spikeRuntimeOptions);
	spikeDataSet->setClassificationFilename(classificationFilename);
	spikeDataSet->load(spikeInputFilename, 400 * 1000);
	network4.setSpikeDataSet(spikeDataSet);

	//4] train the network
	const bool useConfusionMatrix = false;
	const bool plotProgress = true;
	network4.run(trainTimeInSec, useConfusionMatrix, plotProgress);
}

int main(int /*argc*/, char** /*argv[]*/)
{
	const auto start = std::chrono::system_clock::now();

	//srand(time(NULL));
	srand(12345678);

	run_Izhikevich_v1_original_experiment(); // works!
	//run_Izhikevich_v1_Masquelier_experiment(); // does not work!
	//run_Izhikevich_v1_MNIST_experiment(); // works!
	//run_Izhikevich_v1_id4x4_experiment(); // does not work!
	//run_Izhikevich_v1_Search_Network_Config_experiment();

	//run_Izhikevich_v2_MNIST_experiment();

	//run_Izhikevich_v4_experiment();
	//run_Izhikevich_v4_Masquelier_experiment();


	std::cout << "DONE: passed time = " << ::tools::timing::elapsed_time_str(start, std::chrono::system_clock::now());
	printf("\n-------------------\n");
	printf("\nPress RETURN to finish:");
	getchar();
	return 0;
}