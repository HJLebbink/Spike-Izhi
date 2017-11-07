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
#include <sstream>	// for ostringstream
#include <vector>

//#include "../../../Tools/Tools-Lib/src/MetaTemplateTools.hpp"

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"
#include "../../Spike-Izhikevich-LIB/Topology.hpp"


namespace spike
{
	namespace v2
	{
		using namespace spike::v1;

		template <typename Topology>
		class TopologyGenerator
		{
		public:

			// constructor
			TopologyGenerator() = delete;

			// constructor
			TopologyGenerator(const Topology topology)
				: topology_(topology)
			{
			}

			void saveToFile(const std::string& filename)
			{
				// mutex to protect file access
				//static std::mutex mutex;

				// lock mutex before accessing file
				//std::lock_guard<std::mutex> lock(mutex);

				// create the directory
				const std::string tree = ::tools::file::getDirectory(filename);
				if (!::tools::file::mkdirTree(tree))
				{
					std::cerr << "DataSetBackendTxt::saveToFileBackend(): Unable to create directory " << tree << std::endl;
					throw std::runtime_error("unable to create directory");
				}

				// try to open file
				std::ofstream outputFile(filename); //fstream is a proper RAII object, it does close automatically at the end of the scope
				if (!outputFile.is_open())
				{
					std::cerr << "Topology::saveToFile(): Unable to open file " << filename << std::endl;
					throw std::runtime_error("Unable to open file");
				}
				else
				{
					//std::cout << "Topology::saveToFile(): Opening file " << filename << std::endl;
					std::ostringstream oss;

					oss << "#pragma once" << std::endl;
					oss << "#include <array>" << std::endl;
					oss << "#include <vector>" << std::endl;
					oss << "#include \"../../Spike-Tools-LIB/SpikeTypes.hpp\"" << std::endl;
					oss << "namespace NeuronsNs{" << std::endl;
					oss << "	using namespace SpikeNs;" << std::endl;
					this->generateNeuronStructs(oss);
					oss << "}" << std::endl;
					oss << "namespace SpikeNs{" << std::endl;
					oss << "	using namespace NeuronsNs;" << std::endl;
					this->generateTopologyStruct(oss);
					oss << "}" << std::endl;

					outputFile << oss.str();
				}
			}

		private:

			Topology topology_;

			template <typename T>
			void addInitList(std::ostringstream& oss, const T& t) const
			{
				if (t.empty())
				{
					oss << "{{}};";
				}
				else
				{
					oss << "{{" << t[0];
					for (size_t i = 1; i < t.size(); ++i)
					{
						oss << "," << t[i];
					}
					oss << "}};";
				}
			}

			void addPathway(std::ostringstream& oss, const Synapse s, const NeuronId neuronId2, const Delay delay) const
			{
				oss << "			ic.add<" << neuronId2 << "," << delay << ">(t,w2[" << static_cast<int>(s) << "]);" << std::endl;
			}

			void generateNeuronStruct(std::ostringstream& oss, const NeuronId neuronId, std::vector<NeuronId>& neurons, std::vector<Delay>& delays) const
			{
				oss << "	struct N" << neuronId << " {" << std::endl;

				for (size_t d = 0; d < Topology::D; ++d)
				{
					oss << "		static const std::vector<NeuronId> incommingNeuronsD" << d << ";" << std::endl;
				}
				oss << std::endl;

				oss << "		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)" << std::endl;
				oss << "		{" << std::endl;
				oss << "			switch (d) {" << std::endl;
				for (size_t d = 0; d < Topology::D; ++d)
				{
					oss << "				case " << d << ": return N" << neuronId << "::incommingNeuronsD" << d << ";" << std::endl;
				}
				oss << "				default: __assume(0);" << std::endl;

				oss << "			}" << std::endl;
				oss << "		}" << std::endl;

				if (false)
				{
					oss << "		template<typename IC, typename Weights>" << std::endl;
					oss << "		static void fire(const unsigned int t, Weights& w, IC& ic) {" << std::endl;
					oss << "			const std::array<float, " << neurons.size() << ">& w2 = w.getWeight(" << neuronId << ");" << std::endl;
					for (Synapse i = 0; i < static_cast<Synapse>(neurons.size()); ++i)
					{
						addPathway(oss, i, neurons[i], delays[i]);
					}
					oss << "		}" << std::endl;
				}
				else
				{
					oss << "		template<typename IC, typename Weights>" << std::endl;
					oss << "		static void fire(const unsigned int t, Weights& w, IC& ic) {" << std::endl;
					oss << "			const size_t nSynapses=" << neurons.size() << ";" << std::endl;
					oss << "			const std::array<NeuronId, nSynapses> neurons = ";
					this->addInitList(oss, neurons);
					oss << std::endl;

					oss << "			const std::array<Delay, nSynapses> delays = ";
					this->addInitList(oss, delays);
					oss << std::endl;

					oss << "			const std::array<float, nSynapses>& w2 = w.getWeight(" << neuronId << ");" << std::endl;

					oss << "			for (size_t i = 0; i < nSynapses; ++i) {" << std::endl;
					oss << "				ic.add(neurons[i], delays[i], t, w2[i]);" << std::endl;
					//oss << "				//w.updateWeightDiff(neurons[i], i, " << neuronId << ");" << std::endl;
					oss << "			}" << std::endl;

					oss << "		}" << std::endl;
				}

				oss << "	};" << std::endl;
				for (size_t d = 0; d < Topology::D; ++d)
				{
					oss << "	const std::vector<NeuronId> N" << neuronId << "::incommingNeuronsD" << d << " = ";
					this->addInitList(oss, this->topology_.getIncommingNeurons(neuronId, static_cast<Delay>(d)));
					oss << std::endl;
				}
			}

			void generateNeuronStructs(std::ostringstream& oss) const
			{
				for (const NeuronId neuronId : Topology::iterator_AllNeurons())
				{

					std::vector<NeuronId> neurons;
					std::vector<Delay> delays;

					for (Delay delay = 0; delay < Topology::D; ++delay)
					{
						for (const Pathway& p : this->topology_.getOutgoingPathways(neuronId, delay))
						{
							neurons.push_back(p.destination);
							delays.push_back(p.delay);
						}
					}
					generateNeuronStruct(oss, neuronId, neurons, delays);
				}
			}

			void generateTopologyStruct(std::ostringstream& oss) const
			{
				oss << "	struct NetworkBase" << std::endl;
				oss << "	{" << std::endl;
				oss << "		static const size_t Ne = " << Topology::Ne << ";" << std::endl;
				oss << "		static const size_t Ni = " << Topology::Ni << ";" << std::endl;
				oss << "		static const size_t Ns = " << Topology::Ns << ";" << std::endl;
				oss << "		static const size_t Nm = " << Topology::Nm << ";" << std::endl;
				oss << "		static const size_t nNeurons = " << Topology::nNeurons << ";" << std::endl;
				oss << "		static const size_t D = " << Topology::D << ";" << std::endl;
				oss << "		static const size_t M = " << static_cast<int>(Topology::M) << ";" << std::endl;
				oss << std::endl;

				oss << "		const std::vector<NeuronId>& getIncommingNeurons(" << std::endl;
				oss << "			const NeuronId neuronId," << std::endl;
				oss << "			const Delay d) const" << std::endl;
				oss << "		{" << std::endl;
				oss << "			switch (neuronId) {" << std::endl;
				for (NeuronId neuronId = 0; neuronId < Topology::nNeurons; ++neuronId)
				{
					oss << "				case " << neuronId << ": return N" << neuronId << "::getIncommingNeurons(d);" << std::endl;
				}
				oss << "				default: __assume(0);" << std::endl;
				oss << "			}" << std::endl;
				oss << "		}" << std::endl;

				oss << "		template<typename IC, typename Weights>" << std::endl;
				oss << "		void fire(" << std::endl;
				oss << "			const NeuronId n," << std::endl;
				oss << "			const unsigned int t," << std::endl;
				oss << "			const Weights& w," << std::endl;
				oss << "			IC& ic) const" << std::endl;
				oss << "		{" << std::endl;
				oss << "			switch (n) {" << std::endl;
				for (NeuronId neuronId = 0; neuronId < Topology::nNeurons; ++neuronId)
				{
					oss << "				case " << neuronId << ": N" << neuronId << "::fire(t,w,ic); break;" << std::endl;
				}
				oss << "				default: __assume(0);" << std::endl;
				oss << "			}" << std::endl;
				oss << "		}" << std::endl;
				oss << "	};" << std::endl;
			}
		};
	}
}