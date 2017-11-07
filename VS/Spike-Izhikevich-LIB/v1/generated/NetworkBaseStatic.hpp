#pragma once
#include <array>
#include <vector>
#include "../../Spike-Tools-LIB/SpikeTypes.hpp"
namespace NeuronsNs{
	using namespace SpikeNs;
	struct N0 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N0::incommingNeuronsD0;
				case 1: return N0::incommingNeuronsD1;
				case 2: return N0::incommingNeuronsD2;
				case 3: return N0::incommingNeuronsD3;
				case 4: return N0::incommingNeuronsD4;
				case 5: return N0::incommingNeuronsD5;
				case 6: return N0::incommingNeuronsD6;
				case 7: return N0::incommingNeuronsD7;
				case 8: return N0::incommingNeuronsD8;
				case 9: return N0::incommingNeuronsD9;
				case 10: return N0::incommingNeuronsD10;
				case 11: return N0::incommingNeuronsD11;
				case 12: return N0::incommingNeuronsD12;
				case 13: return N0::incommingNeuronsD13;
				case 14: return N0::incommingNeuronsD14;
				case 15: return N0::incommingNeuronsD15;
				case 16: return N0::incommingNeuronsD16;
				case 17: return N0::incommingNeuronsD17;
				case 18: return N0::incommingNeuronsD18;
				case 19: return N0::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{84,64,95,25,28,5,77,13,72,4,59,43,32,34,76,66,16,75,49,18}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(0);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N0::incommingNeuronsD0 = {{4,81,82,86,91,96,98}};
	const std::vector<NeuronId> N0::incommingNeuronsD1 = {{58,76}};
	const std::vector<NeuronId> N0::incommingNeuronsD2 = {{68}};
	const std::vector<NeuronId> N0::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD5 = {{20}};
	const std::vector<NeuronId> N0::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD9 = {{54}};
	const std::vector<NeuronId> N0::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD11 = {{12}};
	const std::vector<NeuronId> N0::incommingNeuronsD12 = {{1}};
	const std::vector<NeuronId> N0::incommingNeuronsD13 = {{14}};
	const std::vector<NeuronId> N0::incommingNeuronsD14 = {{51}};
	const std::vector<NeuronId> N0::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD17 = {{63,72}};
	const std::vector<NeuronId> N0::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N0::incommingNeuronsD19 = {{}};
	struct N1 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N1::incommingNeuronsD0;
				case 1: return N1::incommingNeuronsD1;
				case 2: return N1::incommingNeuronsD2;
				case 3: return N1::incommingNeuronsD3;
				case 4: return N1::incommingNeuronsD4;
				case 5: return N1::incommingNeuronsD5;
				case 6: return N1::incommingNeuronsD6;
				case 7: return N1::incommingNeuronsD7;
				case 8: return N1::incommingNeuronsD8;
				case 9: return N1::incommingNeuronsD9;
				case 10: return N1::incommingNeuronsD10;
				case 11: return N1::incommingNeuronsD11;
				case 12: return N1::incommingNeuronsD12;
				case 13: return N1::incommingNeuronsD13;
				case 14: return N1::incommingNeuronsD14;
				case 15: return N1::incommingNeuronsD15;
				case 16: return N1::incommingNeuronsD16;
				case 17: return N1::incommingNeuronsD17;
				case 18: return N1::incommingNeuronsD18;
				case 19: return N1::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{25,18,84,36,85,88,28,69,68,12,81,70,0,16,24,63,2,74,89,9}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(1);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N1::incommingNeuronsD0 = {{86,95}};
	const std::vector<NeuronId> N1::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD4 = {{23}};
	const std::vector<NeuronId> N1::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD6 = {{59}};
	const std::vector<NeuronId> N1::incommingNeuronsD7 = {{58}};
	const std::vector<NeuronId> N1::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD9 = {{18}};
	const std::vector<NeuronId> N1::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD11 = {{15,37}};
	const std::vector<NeuronId> N1::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD14 = {{5,78}};
	const std::vector<NeuronId> N1::incommingNeuronsD15 = {{51}};
	const std::vector<NeuronId> N1::incommingNeuronsD16 = {{9}};
	const std::vector<NeuronId> N1::incommingNeuronsD17 = {{25}};
	const std::vector<NeuronId> N1::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N1::incommingNeuronsD19 = {{22}};
	struct N2 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N2::incommingNeuronsD0;
				case 1: return N2::incommingNeuronsD1;
				case 2: return N2::incommingNeuronsD2;
				case 3: return N2::incommingNeuronsD3;
				case 4: return N2::incommingNeuronsD4;
				case 5: return N2::incommingNeuronsD5;
				case 6: return N2::incommingNeuronsD6;
				case 7: return N2::incommingNeuronsD7;
				case 8: return N2::incommingNeuronsD8;
				case 9: return N2::incommingNeuronsD9;
				case 10: return N2::incommingNeuronsD10;
				case 11: return N2::incommingNeuronsD11;
				case 12: return N2::incommingNeuronsD12;
				case 13: return N2::incommingNeuronsD13;
				case 14: return N2::incommingNeuronsD14;
				case 15: return N2::incommingNeuronsD15;
				case 16: return N2::incommingNeuronsD16;
				case 17: return N2::incommingNeuronsD17;
				case 18: return N2::incommingNeuronsD18;
				case 19: return N2::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{24,46,7,4,37,18,80,57,60,93,48,47,87,30,91,51,39,67,62,54}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(2);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N2::incommingNeuronsD0 = {{65,81,83,85,91,95}};
	const std::vector<NeuronId> N2::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD3 = {{16}};
	const std::vector<NeuronId> N2::incommingNeuronsD4 = {{36}};
	const std::vector<NeuronId> N2::incommingNeuronsD5 = {{71}};
	const std::vector<NeuronId> N2::incommingNeuronsD6 = {{20,49}};
	const std::vector<NeuronId> N2::incommingNeuronsD7 = {{25,32,52}};
	const std::vector<NeuronId> N2::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD9 = {{4,38}};
	const std::vector<NeuronId> N2::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD11 = {{11,62}};
	const std::vector<NeuronId> N2::incommingNeuronsD12 = {{9}};
	const std::vector<NeuronId> N2::incommingNeuronsD13 = {{22,50}};
	const std::vector<NeuronId> N2::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD16 = {{1,30,47}};
	const std::vector<NeuronId> N2::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N2::incommingNeuronsD19 = {{7,58}};
	struct N3 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N3::incommingNeuronsD0;
				case 1: return N3::incommingNeuronsD1;
				case 2: return N3::incommingNeuronsD2;
				case 3: return N3::incommingNeuronsD3;
				case 4: return N3::incommingNeuronsD4;
				case 5: return N3::incommingNeuronsD5;
				case 6: return N3::incommingNeuronsD6;
				case 7: return N3::incommingNeuronsD7;
				case 8: return N3::incommingNeuronsD8;
				case 9: return N3::incommingNeuronsD9;
				case 10: return N3::incommingNeuronsD10;
				case 11: return N3::incommingNeuronsD11;
				case 12: return N3::incommingNeuronsD12;
				case 13: return N3::incommingNeuronsD13;
				case 14: return N3::incommingNeuronsD14;
				case 15: return N3::incommingNeuronsD15;
				case 16: return N3::incommingNeuronsD16;
				case 17: return N3::incommingNeuronsD17;
				case 18: return N3::incommingNeuronsD18;
				case 19: return N3::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{93,40,28,13,31,52,7,36,27,25,92,88,90,84,57,14,47,70,58,56}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(3);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N3::incommingNeuronsD0 = {{20,42,80,83,89,90,91,97,98,99}};
	const std::vector<NeuronId> N3::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD2 = {{12}};
	const std::vector<NeuronId> N3::incommingNeuronsD3 = {{52}};
	const std::vector<NeuronId> N3::incommingNeuronsD4 = {{21,27,41,73}};
	const std::vector<NeuronId> N3::incommingNeuronsD5 = {{9}};
	const std::vector<NeuronId> N3::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD8 = {{44}};
	const std::vector<NeuronId> N3::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD10 = {{7,40}};
	const std::vector<NeuronId> N3::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD12 = {{29}};
	const std::vector<NeuronId> N3::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD14 = {{15,72}};
	const std::vector<NeuronId> N3::incommingNeuronsD15 = {{45}};
	const std::vector<NeuronId> N3::incommingNeuronsD16 = {{65}};
	const std::vector<NeuronId> N3::incommingNeuronsD17 = {{19,33}};
	const std::vector<NeuronId> N3::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N3::incommingNeuronsD19 = {{}};
	struct N4 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N4::incommingNeuronsD0;
				case 1: return N4::incommingNeuronsD1;
				case 2: return N4::incommingNeuronsD2;
				case 3: return N4::incommingNeuronsD3;
				case 4: return N4::incommingNeuronsD4;
				case 5: return N4::incommingNeuronsD5;
				case 6: return N4::incommingNeuronsD6;
				case 7: return N4::incommingNeuronsD7;
				case 8: return N4::incommingNeuronsD8;
				case 9: return N4::incommingNeuronsD9;
				case 10: return N4::incommingNeuronsD10;
				case 11: return N4::incommingNeuronsD11;
				case 12: return N4::incommingNeuronsD12;
				case 13: return N4::incommingNeuronsD13;
				case 14: return N4::incommingNeuronsD14;
				case 15: return N4::incommingNeuronsD15;
				case 16: return N4::incommingNeuronsD16;
				case 17: return N4::incommingNeuronsD17;
				case 18: return N4::incommingNeuronsD18;
				case 19: return N4::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{0,60,20,7,86,37,68,30,64,2,47,31,95,11,74,56,80,14,28,6}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(4);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N4::incommingNeuronsD0 = {{96,97,98}};
	const std::vector<NeuronId> N4::incommingNeuronsD1 = {{10,55}};
	const std::vector<NeuronId> N4::incommingNeuronsD2 = {{42}};
	const std::vector<NeuronId> N4::incommingNeuronsD3 = {{2}};
	const std::vector<NeuronId> N4::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD6 = {{74}};
	const std::vector<NeuronId> N4::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD9 = {{0}};
	const std::vector<NeuronId> N4::incommingNeuronsD10 = {{25}};
	const std::vector<NeuronId> N4::incommingNeuronsD11 = {{60}};
	const std::vector<NeuronId> N4::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD14 = {{23}};
	const std::vector<NeuronId> N4::incommingNeuronsD15 = {{12}};
	const std::vector<NeuronId> N4::incommingNeuronsD16 = {{57}};
	const std::vector<NeuronId> N4::incommingNeuronsD17 = {{30}};
	const std::vector<NeuronId> N4::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N4::incommingNeuronsD19 = {{}};
	struct N5 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N5::incommingNeuronsD0;
				case 1: return N5::incommingNeuronsD1;
				case 2: return N5::incommingNeuronsD2;
				case 3: return N5::incommingNeuronsD3;
				case 4: return N5::incommingNeuronsD4;
				case 5: return N5::incommingNeuronsD5;
				case 6: return N5::incommingNeuronsD6;
				case 7: return N5::incommingNeuronsD7;
				case 8: return N5::incommingNeuronsD8;
				case 9: return N5::incommingNeuronsD9;
				case 10: return N5::incommingNeuronsD10;
				case 11: return N5::incommingNeuronsD11;
				case 12: return N5::incommingNeuronsD12;
				case 13: return N5::incommingNeuronsD13;
				case 14: return N5::incommingNeuronsD14;
				case 15: return N5::incommingNeuronsD15;
				case 16: return N5::incommingNeuronsD16;
				case 17: return N5::incommingNeuronsD17;
				case 18: return N5::incommingNeuronsD18;
				case 19: return N5::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{43,70,9,19,32,90,8,34,92,68,63,98,39,47,1,45,73,14,78,80}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(5);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N5::incommingNeuronsD0 = {{81,88,94}};
	const std::vector<NeuronId> N5::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N5::incommingNeuronsD2 = {{44}};
	const std::vector<NeuronId> N5::incommingNeuronsD3 = {{35}};
	const std::vector<NeuronId> N5::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N5::incommingNeuronsD5 = {{0}};
	const std::vector<NeuronId> N5::incommingNeuronsD6 = {{70}};
	const std::vector<NeuronId> N5::incommingNeuronsD7 = {{30}};
	const std::vector<NeuronId> N5::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N5::incommingNeuronsD9 = {{39}};
	const std::vector<NeuronId> N5::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N5::incommingNeuronsD11 = {{63}};
	const std::vector<NeuronId> N5::incommingNeuronsD12 = {{48}};
	const std::vector<NeuronId> N5::incommingNeuronsD13 = {{57,66}};
	const std::vector<NeuronId> N5::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N5::incommingNeuronsD15 = {{15}};
	const std::vector<NeuronId> N5::incommingNeuronsD16 = {{40}};
	const std::vector<NeuronId> N5::incommingNeuronsD17 = {{32}};
	const std::vector<NeuronId> N5::incommingNeuronsD18 = {{21}};
	const std::vector<NeuronId> N5::incommingNeuronsD19 = {{}};
	struct N6 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N6::incommingNeuronsD0;
				case 1: return N6::incommingNeuronsD1;
				case 2: return N6::incommingNeuronsD2;
				case 3: return N6::incommingNeuronsD3;
				case 4: return N6::incommingNeuronsD4;
				case 5: return N6::incommingNeuronsD5;
				case 6: return N6::incommingNeuronsD6;
				case 7: return N6::incommingNeuronsD7;
				case 8: return N6::incommingNeuronsD8;
				case 9: return N6::incommingNeuronsD9;
				case 10: return N6::incommingNeuronsD10;
				case 11: return N6::incommingNeuronsD11;
				case 12: return N6::incommingNeuronsD12;
				case 13: return N6::incommingNeuronsD13;
				case 14: return N6::incommingNeuronsD14;
				case 15: return N6::incommingNeuronsD15;
				case 16: return N6::incommingNeuronsD16;
				case 17: return N6::incommingNeuronsD17;
				case 18: return N6::incommingNeuronsD18;
				case 19: return N6::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{86,23,97,7,89,73,34,43,48,47,96,63,61,9,99,28,36,70,27,91}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(6);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N6::incommingNeuronsD0 = {{33,86,87,95,97}};
	const std::vector<NeuronId> N6::incommingNeuronsD1 = {{12,54}};
	const std::vector<NeuronId> N6::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD3 = {{14}};
	const std::vector<NeuronId> N6::incommingNeuronsD4 = {{22,30,74}};
	const std::vector<NeuronId> N6::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD6 = {{56}};
	const std::vector<NeuronId> N6::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD10 = {{27,35}};
	const std::vector<NeuronId> N6::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD12 = {{47,79}};
	const std::vector<NeuronId> N6::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD14 = {{18,37}};
	const std::vector<NeuronId> N6::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD16 = {{58,76}};
	const std::vector<NeuronId> N6::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N6::incommingNeuronsD18 = {{13,25}};
	const std::vector<NeuronId> N6::incommingNeuronsD19 = {{4}};
	struct N7 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N7::incommingNeuronsD0;
				case 1: return N7::incommingNeuronsD1;
				case 2: return N7::incommingNeuronsD2;
				case 3: return N7::incommingNeuronsD3;
				case 4: return N7::incommingNeuronsD4;
				case 5: return N7::incommingNeuronsD5;
				case 6: return N7::incommingNeuronsD6;
				case 7: return N7::incommingNeuronsD7;
				case 8: return N7::incommingNeuronsD8;
				case 9: return N7::incommingNeuronsD9;
				case 10: return N7::incommingNeuronsD10;
				case 11: return N7::incommingNeuronsD11;
				case 12: return N7::incommingNeuronsD12;
				case 13: return N7::incommingNeuronsD13;
				case 14: return N7::incommingNeuronsD14;
				case 15: return N7::incommingNeuronsD15;
				case 16: return N7::incommingNeuronsD16;
				case 17: return N7::incommingNeuronsD17;
				case 18: return N7::incommingNeuronsD18;
				case 19: return N7::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{26,87,84,92,23,43,15,88,89,47,3,39,27,12,22,24,29,77,56,2}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(7);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N7::incommingNeuronsD0 = {{37,68,80,86,87,90,93}};
	const std::vector<NeuronId> N7::incommingNeuronsD1 = {{57}};
	const std::vector<NeuronId> N7::incommingNeuronsD2 = {{2}};
	const std::vector<NeuronId> N7::incommingNeuronsD3 = {{4,6}};
	const std::vector<NeuronId> N7::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD5 = {{22}};
	const std::vector<NeuronId> N7::incommingNeuronsD6 = {{3}};
	const std::vector<NeuronId> N7::incommingNeuronsD7 = {{21}};
	const std::vector<NeuronId> N7::incommingNeuronsD8 = {{47}};
	const std::vector<NeuronId> N7::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD11 = {{67}};
	const std::vector<NeuronId> N7::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD15 = {{19,77}};
	const std::vector<NeuronId> N7::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N7::incommingNeuronsD18 = {{73}};
	const std::vector<NeuronId> N7::incommingNeuronsD19 = {{}};
	struct N8 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N8::incommingNeuronsD0;
				case 1: return N8::incommingNeuronsD1;
				case 2: return N8::incommingNeuronsD2;
				case 3: return N8::incommingNeuronsD3;
				case 4: return N8::incommingNeuronsD4;
				case 5: return N8::incommingNeuronsD5;
				case 6: return N8::incommingNeuronsD6;
				case 7: return N8::incommingNeuronsD7;
				case 8: return N8::incommingNeuronsD8;
				case 9: return N8::incommingNeuronsD9;
				case 10: return N8::incommingNeuronsD10;
				case 11: return N8::incommingNeuronsD11;
				case 12: return N8::incommingNeuronsD12;
				case 13: return N8::incommingNeuronsD13;
				case 14: return N8::incommingNeuronsD14;
				case 15: return N8::incommingNeuronsD15;
				case 16: return N8::incommingNeuronsD16;
				case 17: return N8::incommingNeuronsD17;
				case 18: return N8::incommingNeuronsD18;
				case 19: return N8::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{47,20,26,68,17,76,12,58,77,78,22,80,61,45,48,38,84,18,69,11}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(8);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N8::incommingNeuronsD0 = {{85,88,90,91,95,99}};
	const std::vector<NeuronId> N8::incommingNeuronsD1 = {{18,21}};
	const std::vector<NeuronId> N8::incommingNeuronsD2 = {{58}};
	const std::vector<NeuronId> N8::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD6 = {{5,16,37,71}};
	const std::vector<NeuronId> N8::incommingNeuronsD7 = {{33}};
	const std::vector<NeuronId> N8::incommingNeuronsD8 = {{22}};
	const std::vector<NeuronId> N8::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD10 = {{56}};
	const std::vector<NeuronId> N8::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD12 = {{26}};
	const std::vector<NeuronId> N8::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD16 = {{14}};
	const std::vector<NeuronId> N8::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N8::incommingNeuronsD18 = {{54}};
	const std::vector<NeuronId> N8::incommingNeuronsD19 = {{74}};
	struct N9 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N9::incommingNeuronsD0;
				case 1: return N9::incommingNeuronsD1;
				case 2: return N9::incommingNeuronsD2;
				case 3: return N9::incommingNeuronsD3;
				case 4: return N9::incommingNeuronsD4;
				case 5: return N9::incommingNeuronsD5;
				case 6: return N9::incommingNeuronsD6;
				case 7: return N9::incommingNeuronsD7;
				case 8: return N9::incommingNeuronsD8;
				case 9: return N9::incommingNeuronsD9;
				case 10: return N9::incommingNeuronsD10;
				case 11: return N9::incommingNeuronsD11;
				case 12: return N9::incommingNeuronsD12;
				case 13: return N9::incommingNeuronsD13;
				case 14: return N9::incommingNeuronsD14;
				case 15: return N9::incommingNeuronsD15;
				case 16: return N9::incommingNeuronsD16;
				case 17: return N9::incommingNeuronsD17;
				case 18: return N9::incommingNeuronsD18;
				case 19: return N9::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{91,18,81,75,27,3,73,97,25,23,39,21,2,88,11,24,1,43,74,53}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(9);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N9::incommingNeuronsD0 = {{82,83,93,94,99}};
	const std::vector<NeuronId> N9::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD2 = {{5}};
	const std::vector<NeuronId> N9::incommingNeuronsD3 = {{10,49,55}};
	const std::vector<NeuronId> N9::incommingNeuronsD4 = {{12}};
	const std::vector<NeuronId> N9::incommingNeuronsD5 = {{43}};
	const std::vector<NeuronId> N9::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD10 = {{47,75}};
	const std::vector<NeuronId> N9::incommingNeuronsD11 = {{31,40}};
	const std::vector<NeuronId> N9::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD13 = {{6}};
	const std::vector<NeuronId> N9::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N9::incommingNeuronsD17 = {{28}};
	const std::vector<NeuronId> N9::incommingNeuronsD18 = {{39}};
	const std::vector<NeuronId> N9::incommingNeuronsD19 = {{1}};
	struct N10 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N10::incommingNeuronsD0;
				case 1: return N10::incommingNeuronsD1;
				case 2: return N10::incommingNeuronsD2;
				case 3: return N10::incommingNeuronsD3;
				case 4: return N10::incommingNeuronsD4;
				case 5: return N10::incommingNeuronsD5;
				case 6: return N10::incommingNeuronsD6;
				case 7: return N10::incommingNeuronsD7;
				case 8: return N10::incommingNeuronsD8;
				case 9: return N10::incommingNeuronsD9;
				case 10: return N10::incommingNeuronsD10;
				case 11: return N10::incommingNeuronsD11;
				case 12: return N10::incommingNeuronsD12;
				case 13: return N10::incommingNeuronsD13;
				case 14: return N10::incommingNeuronsD14;
				case 15: return N10::incommingNeuronsD15;
				case 16: return N10::incommingNeuronsD16;
				case 17: return N10::incommingNeuronsD17;
				case 18: return N10::incommingNeuronsD18;
				case 19: return N10::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{57,4,61,9,84,99,68,90,53,86,43,76,46,44,37,94,52,25,92,60}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(10);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N10::incommingNeuronsD0 = {{77,81,86,89,99}};
	const std::vector<NeuronId> N10::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD3 = {{36,66}};
	const std::vector<NeuronId> N10::incommingNeuronsD4 = {{39}};
	const std::vector<NeuronId> N10::incommingNeuronsD5 = {{23}};
	const std::vector<NeuronId> N10::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD11 = {{73}};
	const std::vector<NeuronId> N10::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD13 = {{25}};
	const std::vector<NeuronId> N10::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N10::incommingNeuronsD17 = {{29}};
	const std::vector<NeuronId> N10::incommingNeuronsD18 = {{68}};
	const std::vector<NeuronId> N10::incommingNeuronsD19 = {{}};
	struct N11 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N11::incommingNeuronsD0;
				case 1: return N11::incommingNeuronsD1;
				case 2: return N11::incommingNeuronsD2;
				case 3: return N11::incommingNeuronsD3;
				case 4: return N11::incommingNeuronsD4;
				case 5: return N11::incommingNeuronsD5;
				case 6: return N11::incommingNeuronsD6;
				case 7: return N11::incommingNeuronsD7;
				case 8: return N11::incommingNeuronsD8;
				case 9: return N11::incommingNeuronsD9;
				case 10: return N11::incommingNeuronsD10;
				case 11: return N11::incommingNeuronsD11;
				case 12: return N11::incommingNeuronsD12;
				case 13: return N11::incommingNeuronsD13;
				case 14: return N11::incommingNeuronsD14;
				case 15: return N11::incommingNeuronsD15;
				case 16: return N11::incommingNeuronsD16;
				case 17: return N11::incommingNeuronsD17;
				case 18: return N11::incommingNeuronsD18;
				case 19: return N11::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{63,30,16,79,65,40,81,76,20,88,34,2,37,33,12,80,15,67,62,23}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(11);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N11::incommingNeuronsD0 = {{80,83,88,90,93,94,96,98,99}};
	const std::vector<NeuronId> N11::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD5 = {{34}};
	const std::vector<NeuronId> N11::incommingNeuronsD6 = {{55,64}};
	const std::vector<NeuronId> N11::incommingNeuronsD7 = {{78}};
	const std::vector<NeuronId> N11::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD9 = {{31}};
	const std::vector<NeuronId> N11::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD11 = {{24}};
	const std::vector<NeuronId> N11::incommingNeuronsD12 = {{66,67}};
	const std::vector<NeuronId> N11::incommingNeuronsD13 = {{4,52}};
	const std::vector<NeuronId> N11::incommingNeuronsD14 = {{9}};
	const std::vector<NeuronId> N11::incommingNeuronsD15 = {{62,79}};
	const std::vector<NeuronId> N11::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N11::incommingNeuronsD19 = {{8}};
	struct N12 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N12::incommingNeuronsD0;
				case 1: return N12::incommingNeuronsD1;
				case 2: return N12::incommingNeuronsD2;
				case 3: return N12::incommingNeuronsD3;
				case 4: return N12::incommingNeuronsD4;
				case 5: return N12::incommingNeuronsD5;
				case 6: return N12::incommingNeuronsD6;
				case 7: return N12::incommingNeuronsD7;
				case 8: return N12::incommingNeuronsD8;
				case 9: return N12::incommingNeuronsD9;
				case 10: return N12::incommingNeuronsD10;
				case 11: return N12::incommingNeuronsD11;
				case 12: return N12::incommingNeuronsD12;
				case 13: return N12::incommingNeuronsD13;
				case 14: return N12::incommingNeuronsD14;
				case 15: return N12::incommingNeuronsD15;
				case 16: return N12::incommingNeuronsD16;
				case 17: return N12::incommingNeuronsD17;
				case 18: return N12::incommingNeuronsD18;
				case 19: return N12::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{51,6,3,31,9,48,77,70,53,94,73,0,88,80,99,4,20,29,49,90}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(12);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N12::incommingNeuronsD0 = {{80,84,86,89,90,93,99}};
	const std::vector<NeuronId> N12::incommingNeuronsD1 = {{22,49}};
	const std::vector<NeuronId> N12::incommingNeuronsD2 = {{36}};
	const std::vector<NeuronId> N12::incommingNeuronsD3 = {{46,79}};
	const std::vector<NeuronId> N12::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N12::incommingNeuronsD5 = {{16}};
	const std::vector<NeuronId> N12::incommingNeuronsD6 = {{8}};
	const std::vector<NeuronId> N12::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N12::incommingNeuronsD8 = {{21}};
	const std::vector<NeuronId> N12::incommingNeuronsD9 = {{1,17}};
	const std::vector<NeuronId> N12::incommingNeuronsD10 = {{43,64}};
	const std::vector<NeuronId> N12::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N12::incommingNeuronsD12 = {{18,41}};
	const std::vector<NeuronId> N12::incommingNeuronsD13 = {{7,60}};
	const std::vector<NeuronId> N12::incommingNeuronsD14 = {{11}};
	const std::vector<NeuronId> N12::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N12::incommingNeuronsD16 = {{34}};
	const std::vector<NeuronId> N12::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N12::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N12::incommingNeuronsD19 = {{}};
	struct N13 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N13::incommingNeuronsD0;
				case 1: return N13::incommingNeuronsD1;
				case 2: return N13::incommingNeuronsD2;
				case 3: return N13::incommingNeuronsD3;
				case 4: return N13::incommingNeuronsD4;
				case 5: return N13::incommingNeuronsD5;
				case 6: return N13::incommingNeuronsD6;
				case 7: return N13::incommingNeuronsD7;
				case 8: return N13::incommingNeuronsD8;
				case 9: return N13::incommingNeuronsD9;
				case 10: return N13::incommingNeuronsD10;
				case 11: return N13::incommingNeuronsD11;
				case 12: return N13::incommingNeuronsD12;
				case 13: return N13::incommingNeuronsD13;
				case 14: return N13::incommingNeuronsD14;
				case 15: return N13::incommingNeuronsD15;
				case 16: return N13::incommingNeuronsD16;
				case 17: return N13::incommingNeuronsD17;
				case 18: return N13::incommingNeuronsD18;
				case 19: return N13::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{42,95,84,99,46,32,43,55,50,27,52,54,88,62,34,89,61,41,6,66}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(13);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N13::incommingNeuronsD0 = {{61,81,83,92,96}};
	const std::vector<NeuronId> N13::incommingNeuronsD1 = {{26}};
	const std::vector<NeuronId> N13::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD3 = {{3}};
	const std::vector<NeuronId> N13::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD5 = {{79}};
	const std::vector<NeuronId> N13::incommingNeuronsD6 = {{15,42,78}};
	const std::vector<NeuronId> N13::incommingNeuronsD7 = {{0}};
	const std::vector<NeuronId> N13::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD9 = {{47,64}};
	const std::vector<NeuronId> N13::incommingNeuronsD10 = {{77}};
	const std::vector<NeuronId> N13::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD12 = {{57}};
	const std::vector<NeuronId> N13::incommingNeuronsD13 = {{24}};
	const std::vector<NeuronId> N13::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD17 = {{75}};
	const std::vector<NeuronId> N13::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N13::incommingNeuronsD19 = {{72}};
	struct N14 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N14::incommingNeuronsD0;
				case 1: return N14::incommingNeuronsD1;
				case 2: return N14::incommingNeuronsD2;
				case 3: return N14::incommingNeuronsD3;
				case 4: return N14::incommingNeuronsD4;
				case 5: return N14::incommingNeuronsD5;
				case 6: return N14::incommingNeuronsD6;
				case 7: return N14::incommingNeuronsD7;
				case 8: return N14::incommingNeuronsD8;
				case 9: return N14::incommingNeuronsD9;
				case 10: return N14::incommingNeuronsD10;
				case 11: return N14::incommingNeuronsD11;
				case 12: return N14::incommingNeuronsD12;
				case 13: return N14::incommingNeuronsD13;
				case 14: return N14::incommingNeuronsD14;
				case 15: return N14::incommingNeuronsD15;
				case 16: return N14::incommingNeuronsD16;
				case 17: return N14::incommingNeuronsD17;
				case 18: return N14::incommingNeuronsD18;
				case 19: return N14::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{57,64,78,6,53,68,51,50,45,37,91,34,99,0,67,20,8,65,31,80}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(14);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N14::incommingNeuronsD0 = {{80,84,92}};
	const std::vector<NeuronId> N14::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD2 = {{31}};
	const std::vector<NeuronId> N14::incommingNeuronsD3 = {{43}};
	const std::vector<NeuronId> N14::incommingNeuronsD4 = {{40}};
	const std::vector<NeuronId> N14::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD6 = {{51}};
	const std::vector<NeuronId> N14::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD8 = {{64,70}};
	const std::vector<NeuronId> N14::incommingNeuronsD9 = {{45}};
	const std::vector<NeuronId> N14::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD11 = {{38,65}};
	const std::vector<NeuronId> N14::incommingNeuronsD12 = {{53}};
	const std::vector<NeuronId> N14::incommingNeuronsD13 = {{63}};
	const std::vector<NeuronId> N14::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD15 = {{3}};
	const std::vector<NeuronId> N14::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD17 = {{4,5,21,49}};
	const std::vector<NeuronId> N14::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N14::incommingNeuronsD19 = {{16}};
	struct N15 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N15::incommingNeuronsD0;
				case 1: return N15::incommingNeuronsD1;
				case 2: return N15::incommingNeuronsD2;
				case 3: return N15::incommingNeuronsD3;
				case 4: return N15::incommingNeuronsD4;
				case 5: return N15::incommingNeuronsD5;
				case 6: return N15::incommingNeuronsD6;
				case 7: return N15::incommingNeuronsD7;
				case 8: return N15::incommingNeuronsD8;
				case 9: return N15::incommingNeuronsD9;
				case 10: return N15::incommingNeuronsD10;
				case 11: return N15::incommingNeuronsD11;
				case 12: return N15::incommingNeuronsD12;
				case 13: return N15::incommingNeuronsD13;
				case 14: return N15::incommingNeuronsD14;
				case 15: return N15::incommingNeuronsD15;
				case 16: return N15::incommingNeuronsD16;
				case 17: return N15::incommingNeuronsD17;
				case 18: return N15::incommingNeuronsD18;
				case 19: return N15::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{76,39,97,96,61,82,13,88,17,37,53,1,79,42,3,5,74,99,18,87}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(15);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N15::incommingNeuronsD0 = {{26,80,86,89,97,98}};
	const std::vector<NeuronId> N15::incommingNeuronsD1 = {{43}};
	const std::vector<NeuronId> N15::incommingNeuronsD2 = {{23,70}};
	const std::vector<NeuronId> N15::incommingNeuronsD3 = {{47,65,69}};
	const std::vector<NeuronId> N15::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD6 = {{7,17}};
	const std::vector<NeuronId> N15::incommingNeuronsD7 = {{45,50}};
	const std::vector<NeuronId> N15::incommingNeuronsD8 = {{27,56}};
	const std::vector<NeuronId> N15::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD10 = {{29,57,73}};
	const std::vector<NeuronId> N15::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD13 = {{46}};
	const std::vector<NeuronId> N15::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD16 = {{11,21,67}};
	const std::vector<NeuronId> N15::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N15::incommingNeuronsD19 = {{51}};
	struct N16 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N16::incommingNeuronsD0;
				case 1: return N16::incommingNeuronsD1;
				case 2: return N16::incommingNeuronsD2;
				case 3: return N16::incommingNeuronsD3;
				case 4: return N16::incommingNeuronsD4;
				case 5: return N16::incommingNeuronsD5;
				case 6: return N16::incommingNeuronsD6;
				case 7: return N16::incommingNeuronsD7;
				case 8: return N16::incommingNeuronsD8;
				case 9: return N16::incommingNeuronsD9;
				case 10: return N16::incommingNeuronsD10;
				case 11: return N16::incommingNeuronsD11;
				case 12: return N16::incommingNeuronsD12;
				case 13: return N16::incommingNeuronsD13;
				case 14: return N16::incommingNeuronsD14;
				case 15: return N16::incommingNeuronsD15;
				case 16: return N16::incommingNeuronsD16;
				case 17: return N16::incommingNeuronsD17;
				case 18: return N16::incommingNeuronsD18;
				case 19: return N16::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{53,23,85,2,99,12,8,69,24,67,72,74,52,59,27,58,96,37,89,14}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(16);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N16::incommingNeuronsD0 = {{85,88,91,92,96,98}};
	const std::vector<NeuronId> N16::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD2 = {{11}};
	const std::vector<NeuronId> N16::incommingNeuronsD3 = {{77}};
	const std::vector<NeuronId> N16::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD5 = {{52}};
	const std::vector<NeuronId> N16::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD10 = {{53}};
	const std::vector<NeuronId> N16::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD13 = {{1}};
	const std::vector<NeuronId> N16::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD15 = {{30,56}};
	const std::vector<NeuronId> N16::incommingNeuronsD16 = {{0,25,36}};
	const std::vector<NeuronId> N16::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N16::incommingNeuronsD18 = {{46}};
	const std::vector<NeuronId> N16::incommingNeuronsD19 = {{60,64}};
	struct N17 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N17::incommingNeuronsD0;
				case 1: return N17::incommingNeuronsD1;
				case 2: return N17::incommingNeuronsD2;
				case 3: return N17::incommingNeuronsD3;
				case 4: return N17::incommingNeuronsD4;
				case 5: return N17::incommingNeuronsD5;
				case 6: return N17::incommingNeuronsD6;
				case 7: return N17::incommingNeuronsD7;
				case 8: return N17::incommingNeuronsD8;
				case 9: return N17::incommingNeuronsD9;
				case 10: return N17::incommingNeuronsD10;
				case 11: return N17::incommingNeuronsD11;
				case 12: return N17::incommingNeuronsD12;
				case 13: return N17::incommingNeuronsD13;
				case 14: return N17::incommingNeuronsD14;
				case 15: return N17::incommingNeuronsD15;
				case 16: return N17::incommingNeuronsD16;
				case 17: return N17::incommingNeuronsD17;
				case 18: return N17::incommingNeuronsD18;
				case 19: return N17::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{28,47,57,64,63,94,15,86,72,12,85,51,71,82,76,89,43,61,73,95}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(17);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N17::incommingNeuronsD0 = {{80,85,88,90,93,95,97}};
	const std::vector<NeuronId> N17::incommingNeuronsD1 = {{63}};
	const std::vector<NeuronId> N17::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N17::incommingNeuronsD3 = {{39}};
	const std::vector<NeuronId> N17::incommingNeuronsD4 = {{8}};
	const std::vector<NeuronId> N17::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N17::incommingNeuronsD6 = {{33}};
	const std::vector<NeuronId> N17::incommingNeuronsD7 = {{28}};
	const std::vector<NeuronId> N17::incommingNeuronsD8 = {{15,37,57}};
	const std::vector<NeuronId> N17::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N17::incommingNeuronsD10 = {{38,46,50}};
	const std::vector<NeuronId> N17::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N17::incommingNeuronsD12 = {{34}};
	const std::vector<NeuronId> N17::incommingNeuronsD13 = {{76}};
	const std::vector<NeuronId> N17::incommingNeuronsD14 = {{29}};
	const std::vector<NeuronId> N17::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N17::incommingNeuronsD16 = {{70}};
	const std::vector<NeuronId> N17::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N17::incommingNeuronsD18 = {{59}};
	const std::vector<NeuronId> N17::incommingNeuronsD19 = {{}};
	struct N18 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N18::incommingNeuronsD0;
				case 1: return N18::incommingNeuronsD1;
				case 2: return N18::incommingNeuronsD2;
				case 3: return N18::incommingNeuronsD3;
				case 4: return N18::incommingNeuronsD4;
				case 5: return N18::incommingNeuronsD5;
				case 6: return N18::incommingNeuronsD6;
				case 7: return N18::incommingNeuronsD7;
				case 8: return N18::incommingNeuronsD8;
				case 9: return N18::incommingNeuronsD9;
				case 10: return N18::incommingNeuronsD10;
				case 11: return N18::incommingNeuronsD11;
				case 12: return N18::incommingNeuronsD12;
				case 13: return N18::incommingNeuronsD13;
				case 14: return N18::incommingNeuronsD14;
				case 15: return N18::incommingNeuronsD15;
				case 16: return N18::incommingNeuronsD16;
				case 17: return N18::incommingNeuronsD17;
				case 18: return N18::incommingNeuronsD18;
				case 19: return N18::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{84,8,88,53,75,83,25,82,38,1,54,45,12,89,6,33,20,59,58,61}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(18);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N18::incommingNeuronsD0 = {{63,64,83,91,95,99}};
	const std::vector<NeuronId> N18::incommingNeuronsD1 = {{1,9}};
	const std::vector<NeuronId> N18::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD3 = {{59}};
	const std::vector<NeuronId> N18::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD5 = {{2,37}};
	const std::vector<NeuronId> N18::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD12 = {{23,44}};
	const std::vector<NeuronId> N18::incommingNeuronsD13 = {{41}};
	const std::vector<NeuronId> N18::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N18::incommingNeuronsD15 = {{33,71}};
	const std::vector<NeuronId> N18::incommingNeuronsD16 = {{22}};
	const std::vector<NeuronId> N18::incommingNeuronsD17 = {{8,34}};
	const std::vector<NeuronId> N18::incommingNeuronsD18 = {{15,48}};
	const std::vector<NeuronId> N18::incommingNeuronsD19 = {{0}};
	struct N19 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N19::incommingNeuronsD0;
				case 1: return N19::incommingNeuronsD1;
				case 2: return N19::incommingNeuronsD2;
				case 3: return N19::incommingNeuronsD3;
				case 4: return N19::incommingNeuronsD4;
				case 5: return N19::incommingNeuronsD5;
				case 6: return N19::incommingNeuronsD6;
				case 7: return N19::incommingNeuronsD7;
				case 8: return N19::incommingNeuronsD8;
				case 9: return N19::incommingNeuronsD9;
				case 10: return N19::incommingNeuronsD10;
				case 11: return N19::incommingNeuronsD11;
				case 12: return N19::incommingNeuronsD12;
				case 13: return N19::incommingNeuronsD13;
				case 14: return N19::incommingNeuronsD14;
				case 15: return N19::incommingNeuronsD15;
				case 16: return N19::incommingNeuronsD16;
				case 17: return N19::incommingNeuronsD17;
				case 18: return N19::incommingNeuronsD18;
				case 19: return N19::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{34,76,51,44,71,43,42,57,96,54,31,45,36,79,98,7,69,3,81,39}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(19);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N19::incommingNeuronsD0 = {{80,81,85,87,90}};
	const std::vector<NeuronId> N19::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N19::incommingNeuronsD2 = {{76}};
	const std::vector<NeuronId> N19::incommingNeuronsD3 = {{5,28}};
	const std::vector<NeuronId> N19::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N19::incommingNeuronsD5 = {{53}};
	const std::vector<NeuronId> N19::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N19::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N19::incommingNeuronsD8 = {{52,63,68}};
	const std::vector<NeuronId> N19::incommingNeuronsD9 = {{50}};
	const std::vector<NeuronId> N19::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N19::incommingNeuronsD11 = {{59}};
	const std::vector<NeuronId> N19::incommingNeuronsD12 = {{25}};
	const std::vector<NeuronId> N19::incommingNeuronsD13 = {{74}};
	const std::vector<NeuronId> N19::incommingNeuronsD14 = {{30,48,58}};
	const std::vector<NeuronId> N19::incommingNeuronsD15 = {{61}};
	const std::vector<NeuronId> N19::incommingNeuronsD16 = {{35}};
	const std::vector<NeuronId> N19::incommingNeuronsD17 = {{55}};
	const std::vector<NeuronId> N19::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N19::incommingNeuronsD19 = {{33}};
	struct N20 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N20::incommingNeuronsD0;
				case 1: return N20::incommingNeuronsD1;
				case 2: return N20::incommingNeuronsD2;
				case 3: return N20::incommingNeuronsD3;
				case 4: return N20::incommingNeuronsD4;
				case 5: return N20::incommingNeuronsD5;
				case 6: return N20::incommingNeuronsD6;
				case 7: return N20::incommingNeuronsD7;
				case 8: return N20::incommingNeuronsD8;
				case 9: return N20::incommingNeuronsD9;
				case 10: return N20::incommingNeuronsD10;
				case 11: return N20::incommingNeuronsD11;
				case 12: return N20::incommingNeuronsD12;
				case 13: return N20::incommingNeuronsD13;
				case 14: return N20::incommingNeuronsD14;
				case 15: return N20::incommingNeuronsD15;
				case 16: return N20::incommingNeuronsD16;
				case 17: return N20::incommingNeuronsD17;
				case 18: return N20::incommingNeuronsD18;
				case 19: return N20::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{3,68,92,45,50,0,2,53,77,96,65,44,58,48,27,32,43,24,40,23}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(20);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N20::incommingNeuronsD0 = {{54,80,84,85,91,92,94,95,99}};
	const std::vector<NeuronId> N20::incommingNeuronsD1 = {{8,51}};
	const std::vector<NeuronId> N20::incommingNeuronsD2 = {{4,49}};
	const std::vector<NeuronId> N20::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N20::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N20::incommingNeuronsD5 = {{28}};
	const std::vector<NeuronId> N20::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N20::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N20::incommingNeuronsD8 = {{11,35}};
	const std::vector<NeuronId> N20::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N20::incommingNeuronsD10 = {{41}};
	const std::vector<NeuronId> N20::incommingNeuronsD11 = {{61}};
	const std::vector<NeuronId> N20::incommingNeuronsD12 = {{46}};
	const std::vector<NeuronId> N20::incommingNeuronsD13 = {{58}};
	const std::vector<NeuronId> N20::incommingNeuronsD14 = {{62}};
	const std::vector<NeuronId> N20::incommingNeuronsD15 = {{14}};
	const std::vector<NeuronId> N20::incommingNeuronsD16 = {{12,18}};
	const std::vector<NeuronId> N20::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N20::incommingNeuronsD18 = {{30,71}};
	const std::vector<NeuronId> N20::incommingNeuronsD19 = {{}};
	struct N21 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N21::incommingNeuronsD0;
				case 1: return N21::incommingNeuronsD1;
				case 2: return N21::incommingNeuronsD2;
				case 3: return N21::incommingNeuronsD3;
				case 4: return N21::incommingNeuronsD4;
				case 5: return N21::incommingNeuronsD5;
				case 6: return N21::incommingNeuronsD6;
				case 7: return N21::incommingNeuronsD7;
				case 8: return N21::incommingNeuronsD8;
				case 9: return N21::incommingNeuronsD9;
				case 10: return N21::incommingNeuronsD10;
				case 11: return N21::incommingNeuronsD11;
				case 12: return N21::incommingNeuronsD12;
				case 13: return N21::incommingNeuronsD13;
				case 14: return N21::incommingNeuronsD14;
				case 15: return N21::incommingNeuronsD15;
				case 16: return N21::incommingNeuronsD16;
				case 17: return N21::incommingNeuronsD17;
				case 18: return N21::incommingNeuronsD18;
				case 19: return N21::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{41,8,52,33,3,31,91,7,12,49,77,94,29,43,85,92,15,14,5,45}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(21);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N21::incommingNeuronsD0 = {{98}};
	const std::vector<NeuronId> N21::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD7 = {{61}};
	const std::vector<NeuronId> N21::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD9 = {{79}};
	const std::vector<NeuronId> N21::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD11 = {{9,30,45,49,76}};
	const std::vector<NeuronId> N21::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD13 = {{78}};
	const std::vector<NeuronId> N21::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N21::incommingNeuronsD19 = {{}};
	struct N22 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N22::incommingNeuronsD0;
				case 1: return N22::incommingNeuronsD1;
				case 2: return N22::incommingNeuronsD2;
				case 3: return N22::incommingNeuronsD3;
				case 4: return N22::incommingNeuronsD4;
				case 5: return N22::incommingNeuronsD5;
				case 6: return N22::incommingNeuronsD6;
				case 7: return N22::incommingNeuronsD7;
				case 8: return N22::incommingNeuronsD8;
				case 9: return N22::incommingNeuronsD9;
				case 10: return N22::incommingNeuronsD10;
				case 11: return N22::incommingNeuronsD11;
				case 12: return N22::incommingNeuronsD12;
				case 13: return N22::incommingNeuronsD13;
				case 14: return N22::incommingNeuronsD14;
				case 15: return N22::incommingNeuronsD15;
				case 16: return N22::incommingNeuronsD16;
				case 17: return N22::incommingNeuronsD17;
				case 18: return N22::incommingNeuronsD18;
				case 19: return N22::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{57,12,76,93,6,7,59,89,8,36,88,68,40,2,84,24,18,71,73,1}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(22);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N22::incommingNeuronsD0 = {{55,81,84,92,99}};
	const std::vector<NeuronId> N22::incommingNeuronsD1 = {{41}};
	const std::vector<NeuronId> N22::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD3 = {{33}};
	const std::vector<NeuronId> N22::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD8 = {{23}};
	const std::vector<NeuronId> N22::incommingNeuronsD9 = {{77}};
	const std::vector<NeuronId> N22::incommingNeuronsD10 = {{8,44}};
	const std::vector<NeuronId> N22::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD12 = {{70}};
	const std::vector<NeuronId> N22::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD14 = {{7}};
	const std::vector<NeuronId> N22::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD17 = {{27}};
	const std::vector<NeuronId> N22::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N22::incommingNeuronsD19 = {{36}};
	struct N23 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N23::incommingNeuronsD0;
				case 1: return N23::incommingNeuronsD1;
				case 2: return N23::incommingNeuronsD2;
				case 3: return N23::incommingNeuronsD3;
				case 4: return N23::incommingNeuronsD4;
				case 5: return N23::incommingNeuronsD5;
				case 6: return N23::incommingNeuronsD6;
				case 7: return N23::incommingNeuronsD7;
				case 8: return N23::incommingNeuronsD8;
				case 9: return N23::incommingNeuronsD9;
				case 10: return N23::incommingNeuronsD10;
				case 11: return N23::incommingNeuronsD11;
				case 12: return N23::incommingNeuronsD12;
				case 13: return N23::incommingNeuronsD13;
				case 14: return N23::incommingNeuronsD14;
				case 15: return N23::incommingNeuronsD15;
				case 16: return N23::incommingNeuronsD16;
				case 17: return N23::incommingNeuronsD17;
				case 18: return N23::incommingNeuronsD18;
				case 19: return N23::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{31,25,15,61,1,10,83,98,22,67,35,46,18,30,4,38,37,60,68,77}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(23);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N23::incommingNeuronsD0 = {{34,59,81,85,96,97,98}};
	const std::vector<NeuronId> N23::incommingNeuronsD1 = {{6,16,33}};
	const std::vector<NeuronId> N23::incommingNeuronsD2 = {{57}};
	const std::vector<NeuronId> N23::incommingNeuronsD3 = {{61}};
	const std::vector<NeuronId> N23::incommingNeuronsD4 = {{7,37}};
	const std::vector<NeuronId> N23::incommingNeuronsD5 = {{55}};
	const std::vector<NeuronId> N23::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD7 = {{27}};
	const std::vector<NeuronId> N23::incommingNeuronsD8 = {{36}};
	const std::vector<NeuronId> N23::incommingNeuronsD9 = {{9}};
	const std::vector<NeuronId> N23::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N23::incommingNeuronsD17 = {{24}};
	const std::vector<NeuronId> N23::incommingNeuronsD18 = {{58}};
	const std::vector<NeuronId> N23::incommingNeuronsD19 = {{11,20}};
	struct N24 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N24::incommingNeuronsD0;
				case 1: return N24::incommingNeuronsD1;
				case 2: return N24::incommingNeuronsD2;
				case 3: return N24::incommingNeuronsD3;
				case 4: return N24::incommingNeuronsD4;
				case 5: return N24::incommingNeuronsD5;
				case 6: return N24::incommingNeuronsD6;
				case 7: return N24::incommingNeuronsD7;
				case 8: return N24::incommingNeuronsD8;
				case 9: return N24::incommingNeuronsD9;
				case 10: return N24::incommingNeuronsD10;
				case 11: return N24::incommingNeuronsD11;
				case 12: return N24::incommingNeuronsD12;
				case 13: return N24::incommingNeuronsD13;
				case 14: return N24::incommingNeuronsD14;
				case 15: return N24::incommingNeuronsD15;
				case 16: return N24::incommingNeuronsD16;
				case 17: return N24::incommingNeuronsD17;
				case 18: return N24::incommingNeuronsD18;
				case 19: return N24::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{50,96,67,35,30,39,97,59,70,28,95,11,87,13,34,76,65,23,29,57}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(24);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N24::incommingNeuronsD0 = {{2,82,85,87,88,89,96}};
	const std::vector<NeuronId> N24::incommingNeuronsD1 = {{53}};
	const std::vector<NeuronId> N24::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD4 = {{38}};
	const std::vector<NeuronId> N24::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD6 = {{39,48}};
	const std::vector<NeuronId> N24::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD8 = {{16,71}};
	const std::vector<NeuronId> N24::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD10 = {{79}};
	const std::vector<NeuronId> N24::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD13 = {{40,47}};
	const std::vector<NeuronId> N24::incommingNeuronsD14 = {{1,44,69}};
	const std::vector<NeuronId> N24::incommingNeuronsD15 = {{7,9,22,59}};
	const std::vector<NeuronId> N24::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD17 = {{20}};
	const std::vector<NeuronId> N24::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N24::incommingNeuronsD19 = {{}};
	struct N25 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N25::incommingNeuronsD0;
				case 1: return N25::incommingNeuronsD1;
				case 2: return N25::incommingNeuronsD2;
				case 3: return N25::incommingNeuronsD3;
				case 4: return N25::incommingNeuronsD4;
				case 5: return N25::incommingNeuronsD5;
				case 6: return N25::incommingNeuronsD6;
				case 7: return N25::incommingNeuronsD7;
				case 8: return N25::incommingNeuronsD8;
				case 9: return N25::incommingNeuronsD9;
				case 10: return N25::incommingNeuronsD10;
				case 11: return N25::incommingNeuronsD11;
				case 12: return N25::incommingNeuronsD12;
				case 13: return N25::incommingNeuronsD13;
				case 14: return N25::incommingNeuronsD14;
				case 15: return N25::incommingNeuronsD15;
				case 16: return N25::incommingNeuronsD16;
				case 17: return N25::incommingNeuronsD17;
				case 18: return N25::incommingNeuronsD18;
				case 19: return N25::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{81,89,84,97,69,35,57,2,90,78,4,67,19,10,98,79,16,1,6,29}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(25);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N25::incommingNeuronsD0 = {{1,81,82,86,91,92}};
	const std::vector<NeuronId> N25::incommingNeuronsD1 = {{23}};
	const std::vector<NeuronId> N25::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N25::incommingNeuronsD3 = {{0}};
	const std::vector<NeuronId> N25::incommingNeuronsD4 = {{35}};
	const std::vector<NeuronId> N25::incommingNeuronsD5 = {{56}};
	const std::vector<NeuronId> N25::incommingNeuronsD6 = {{18,27}};
	const std::vector<NeuronId> N25::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N25::incommingNeuronsD8 = {{9,28}};
	const std::vector<NeuronId> N25::incommingNeuronsD9 = {{3}};
	const std::vector<NeuronId> N25::incommingNeuronsD10 = {{71}};
	const std::vector<NeuronId> N25::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N25::incommingNeuronsD12 = {{63}};
	const std::vector<NeuronId> N25::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N25::incommingNeuronsD14 = {{50,60}};
	const std::vector<NeuronId> N25::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N25::incommingNeuronsD16 = {{64}};
	const std::vector<NeuronId> N25::incommingNeuronsD17 = {{10,36}};
	const std::vector<NeuronId> N25::incommingNeuronsD18 = {{38}};
	const std::vector<NeuronId> N25::incommingNeuronsD19 = {{}};
	struct N26 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N26::incommingNeuronsD0;
				case 1: return N26::incommingNeuronsD1;
				case 2: return N26::incommingNeuronsD2;
				case 3: return N26::incommingNeuronsD3;
				case 4: return N26::incommingNeuronsD4;
				case 5: return N26::incommingNeuronsD5;
				case 6: return N26::incommingNeuronsD6;
				case 7: return N26::incommingNeuronsD7;
				case 8: return N26::incommingNeuronsD8;
				case 9: return N26::incommingNeuronsD9;
				case 10: return N26::incommingNeuronsD10;
				case 11: return N26::incommingNeuronsD11;
				case 12: return N26::incommingNeuronsD12;
				case 13: return N26::incommingNeuronsD13;
				case 14: return N26::incommingNeuronsD14;
				case 15: return N26::incommingNeuronsD15;
				case 16: return N26::incommingNeuronsD16;
				case 17: return N26::incommingNeuronsD17;
				case 18: return N26::incommingNeuronsD18;
				case 19: return N26::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{15,13,40,33,49,66,34,75,97,35,56,31,8,88,46,59,98,43,79,81}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(26);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N26::incommingNeuronsD0 = {{7,52,83,88,89}};
	const std::vector<NeuronId> N26::incommingNeuronsD1 = {{69}};
	const std::vector<NeuronId> N26::incommingNeuronsD2 = {{8,35}};
	const std::vector<NeuronId> N26::incommingNeuronsD3 = {{45}};
	const std::vector<NeuronId> N26::incommingNeuronsD4 = {{55}};
	const std::vector<NeuronId> N26::incommingNeuronsD5 = {{41,63}};
	const std::vector<NeuronId> N26::incommingNeuronsD6 = {{76}};
	const std::vector<NeuronId> N26::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD17 = {{64}};
	const std::vector<NeuronId> N26::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N26::incommingNeuronsD19 = {{73}};
	struct N27 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N27::incommingNeuronsD0;
				case 1: return N27::incommingNeuronsD1;
				case 2: return N27::incommingNeuronsD2;
				case 3: return N27::incommingNeuronsD3;
				case 4: return N27::incommingNeuronsD4;
				case 5: return N27::incommingNeuronsD5;
				case 6: return N27::incommingNeuronsD6;
				case 7: return N27::incommingNeuronsD7;
				case 8: return N27::incommingNeuronsD8;
				case 9: return N27::incommingNeuronsD9;
				case 10: return N27::incommingNeuronsD10;
				case 11: return N27::incommingNeuronsD11;
				case 12: return N27::incommingNeuronsD12;
				case 13: return N27::incommingNeuronsD13;
				case 14: return N27::incommingNeuronsD14;
				case 15: return N27::incommingNeuronsD15;
				case 16: return N27::incommingNeuronsD16;
				case 17: return N27::incommingNeuronsD17;
				case 18: return N27::incommingNeuronsD18;
				case 19: return N27::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{30,69,42,96,3,46,25,23,15,37,6,68,59,99,62,63,56,22,84,40}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(27);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N27::incommingNeuronsD0 = {{80,84,92,97}};
	const std::vector<NeuronId> N27::incommingNeuronsD1 = {{44}};
	const std::vector<NeuronId> N27::incommingNeuronsD2 = {{38,64}};
	const std::vector<NeuronId> N27::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD4 = {{9,69}};
	const std::vector<NeuronId> N27::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD8 = {{3}};
	const std::vector<NeuronId> N27::incommingNeuronsD9 = {{13}};
	const std::vector<NeuronId> N27::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD12 = {{7,56,76}};
	const std::vector<NeuronId> N27::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD14 = {{16,20,55}};
	const std::vector<NeuronId> N27::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD16 = {{62}};
	const std::vector<NeuronId> N27::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N27::incommingNeuronsD18 = {{6}};
	const std::vector<NeuronId> N27::incommingNeuronsD19 = {{45,49,67}};
	struct N28 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N28::incommingNeuronsD0;
				case 1: return N28::incommingNeuronsD1;
				case 2: return N28::incommingNeuronsD2;
				case 3: return N28::incommingNeuronsD3;
				case 4: return N28::incommingNeuronsD4;
				case 5: return N28::incommingNeuronsD5;
				case 6: return N28::incommingNeuronsD6;
				case 7: return N28::incommingNeuronsD7;
				case 8: return N28::incommingNeuronsD8;
				case 9: return N28::incommingNeuronsD9;
				case 10: return N28::incommingNeuronsD10;
				case 11: return N28::incommingNeuronsD11;
				case 12: return N28::incommingNeuronsD12;
				case 13: return N28::incommingNeuronsD13;
				case 14: return N28::incommingNeuronsD14;
				case 15: return N28::incommingNeuronsD15;
				case 16: return N28::incommingNeuronsD16;
				case 17: return N28::incommingNeuronsD17;
				case 18: return N28::incommingNeuronsD18;
				case 19: return N28::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{91,85,96,19,57,20,48,17,25,67,82,72,52,42,39,44,78,9,47,43}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(28);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N28::incommingNeuronsD0 = {{17,80,81,84,87,90,94}};
	const std::vector<NeuronId> N28::incommingNeuronsD1 = {{73}};
	const std::vector<NeuronId> N28::incommingNeuronsD2 = {{3}};
	const std::vector<NeuronId> N28::incommingNeuronsD3 = {{30,53}};
	const std::vector<NeuronId> N28::incommingNeuronsD4 = {{0}};
	const std::vector<NeuronId> N28::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD6 = {{1}};
	const std::vector<NeuronId> N28::incommingNeuronsD7 = {{35}};
	const std::vector<NeuronId> N28::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD9 = {{24}};
	const std::vector<NeuronId> N28::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD13 = {{62}};
	const std::vector<NeuronId> N28::incommingNeuronsD14 = {{42}};
	const std::vector<NeuronId> N28::incommingNeuronsD15 = {{6}};
	const std::vector<NeuronId> N28::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N28::incommingNeuronsD18 = {{4}};
	const std::vector<NeuronId> N28::incommingNeuronsD19 = {{}};
	struct N29 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N29::incommingNeuronsD0;
				case 1: return N29::incommingNeuronsD1;
				case 2: return N29::incommingNeuronsD2;
				case 3: return N29::incommingNeuronsD3;
				case 4: return N29::incommingNeuronsD4;
				case 5: return N29::incommingNeuronsD5;
				case 6: return N29::incommingNeuronsD6;
				case 7: return N29::incommingNeuronsD7;
				case 8: return N29::incommingNeuronsD8;
				case 9: return N29::incommingNeuronsD9;
				case 10: return N29::incommingNeuronsD10;
				case 11: return N29::incommingNeuronsD11;
				case 12: return N29::incommingNeuronsD12;
				case 13: return N29::incommingNeuronsD13;
				case 14: return N29::incommingNeuronsD14;
				case 15: return N29::incommingNeuronsD15;
				case 16: return N29::incommingNeuronsD16;
				case 17: return N29::incommingNeuronsD17;
				case 18: return N29::incommingNeuronsD18;
				case 19: return N29::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{67,45,30,97,99,57,77,38,84,33,15,47,3,51,17,39,68,10,53,41}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(29);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N29::incommingNeuronsD0 = {{81,82,83,91,93,95,99}};
	const std::vector<NeuronId> N29::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N29::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N29::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N29::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N29::incommingNeuronsD5 = {{67}};
	const std::vector<NeuronId> N29::incommingNeuronsD6 = {{44}};
	const std::vector<NeuronId> N29::incommingNeuronsD7 = {{63}};
	const std::vector<NeuronId> N29::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N29::incommingNeuronsD9 = {{51}};
	const std::vector<NeuronId> N29::incommingNeuronsD10 = {{58}};
	const std::vector<NeuronId> N29::incommingNeuronsD11 = {{43}};
	const std::vector<NeuronId> N29::incommingNeuronsD12 = {{21,50}};
	const std::vector<NeuronId> N29::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N29::incommingNeuronsD14 = {{32}};
	const std::vector<NeuronId> N29::incommingNeuronsD15 = {{34}};
	const std::vector<NeuronId> N29::incommingNeuronsD16 = {{7,49}};
	const std::vector<NeuronId> N29::incommingNeuronsD17 = {{12}};
	const std::vector<NeuronId> N29::incommingNeuronsD18 = {{24}};
	const std::vector<NeuronId> N29::incommingNeuronsD19 = {{25,42}};
	struct N30 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N30::incommingNeuronsD0;
				case 1: return N30::incommingNeuronsD1;
				case 2: return N30::incommingNeuronsD2;
				case 3: return N30::incommingNeuronsD3;
				case 4: return N30::incommingNeuronsD4;
				case 5: return N30::incommingNeuronsD5;
				case 6: return N30::incommingNeuronsD6;
				case 7: return N30::incommingNeuronsD7;
				case 8: return N30::incommingNeuronsD8;
				case 9: return N30::incommingNeuronsD9;
				case 10: return N30::incommingNeuronsD10;
				case 11: return N30::incommingNeuronsD11;
				case 12: return N30::incommingNeuronsD12;
				case 13: return N30::incommingNeuronsD13;
				case 14: return N30::incommingNeuronsD14;
				case 15: return N30::incommingNeuronsD15;
				case 16: return N30::incommingNeuronsD16;
				case 17: return N30::incommingNeuronsD17;
				case 18: return N30::incommingNeuronsD18;
				case 19: return N30::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{53,66,67,28,6,68,71,5,41,89,91,21,78,65,19,16,2,4,20,94}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(30);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N30::incommingNeuronsD0 = {{27,85,86,91,93,94,97,98}};
	const std::vector<NeuronId> N30::incommingNeuronsD1 = {{11}};
	const std::vector<NeuronId> N30::incommingNeuronsD2 = {{29}};
	const std::vector<NeuronId> N30::incommingNeuronsD3 = {{48}};
	const std::vector<NeuronId> N30::incommingNeuronsD4 = {{24}};
	const std::vector<NeuronId> N30::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD7 = {{4,54}};
	const std::vector<NeuronId> N30::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD9 = {{73}};
	const std::vector<NeuronId> N30::incommingNeuronsD10 = {{62}};
	const std::vector<NeuronId> N30::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD12 = {{59}};
	const std::vector<NeuronId> N30::incommingNeuronsD13 = {{2,23}};
	const std::vector<NeuronId> N30::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N30::incommingNeuronsD19 = {{76}};
	struct N31 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N31::incommingNeuronsD0;
				case 1: return N31::incommingNeuronsD1;
				case 2: return N31::incommingNeuronsD2;
				case 3: return N31::incommingNeuronsD3;
				case 4: return N31::incommingNeuronsD4;
				case 5: return N31::incommingNeuronsD5;
				case 6: return N31::incommingNeuronsD6;
				case 7: return N31::incommingNeuronsD7;
				case 8: return N31::incommingNeuronsD8;
				case 9: return N31::incommingNeuronsD9;
				case 10: return N31::incommingNeuronsD10;
				case 11: return N31::incommingNeuronsD11;
				case 12: return N31::incommingNeuronsD12;
				case 13: return N31::incommingNeuronsD13;
				case 14: return N31::incommingNeuronsD14;
				case 15: return N31::incommingNeuronsD15;
				case 16: return N31::incommingNeuronsD16;
				case 17: return N31::incommingNeuronsD17;
				case 18: return N31::incommingNeuronsD18;
				case 19: return N31::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{37,51,14,67,44,60,41,94,56,11,49,9,98,76,54,46,59,81,63,32}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(31);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N31::incommingNeuronsD0 = {{23,84,87,88,92,95}};
	const std::vector<NeuronId> N31::incommingNeuronsD1 = {{78}};
	const std::vector<NeuronId> N31::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD3 = {{12}};
	const std::vector<NeuronId> N31::incommingNeuronsD4 = {{3}};
	const std::vector<NeuronId> N31::incommingNeuronsD5 = {{21,36}};
	const std::vector<NeuronId> N31::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD7 = {{77}};
	const std::vector<NeuronId> N31::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD10 = {{19}};
	const std::vector<NeuronId> N31::incommingNeuronsD11 = {{4,26}};
	const std::vector<NeuronId> N31::incommingNeuronsD12 = {{65}};
	const std::vector<NeuronId> N31::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD14 = {{38}};
	const std::vector<NeuronId> N31::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD16 = {{52}};
	const std::vector<NeuronId> N31::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N31::incommingNeuronsD18 = {{14}};
	const std::vector<NeuronId> N31::incommingNeuronsD19 = {{}};
	struct N32 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N32::incommingNeuronsD0;
				case 1: return N32::incommingNeuronsD1;
				case 2: return N32::incommingNeuronsD2;
				case 3: return N32::incommingNeuronsD3;
				case 4: return N32::incommingNeuronsD4;
				case 5: return N32::incommingNeuronsD5;
				case 6: return N32::incommingNeuronsD6;
				case 7: return N32::incommingNeuronsD7;
				case 8: return N32::incommingNeuronsD8;
				case 9: return N32::incommingNeuronsD9;
				case 10: return N32::incommingNeuronsD10;
				case 11: return N32::incommingNeuronsD11;
				case 12: return N32::incommingNeuronsD12;
				case 13: return N32::incommingNeuronsD13;
				case 14: return N32::incommingNeuronsD14;
				case 15: return N32::incommingNeuronsD15;
				case 16: return N32::incommingNeuronsD16;
				case 17: return N32::incommingNeuronsD17;
				case 18: return N32::incommingNeuronsD18;
				case 19: return N32::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{60,61,56,36,38,53,37,2,45,40,66,68,35,81,29,90,46,5,96,80}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(32);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N32::incommingNeuronsD0 = {{57,82,84,87,90,91,99}};
	const std::vector<NeuronId> N32::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD4 = {{5}};
	const std::vector<NeuronId> N32::incommingNeuronsD5 = {{13}};
	const std::vector<NeuronId> N32::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD11 = {{70}};
	const std::vector<NeuronId> N32::incommingNeuronsD12 = {{0}};
	const std::vector<NeuronId> N32::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD14 = {{40}};
	const std::vector<NeuronId> N32::incommingNeuronsD15 = {{20,42}};
	const std::vector<NeuronId> N32::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N32::incommingNeuronsD17 = {{51}};
	const std::vector<NeuronId> N32::incommingNeuronsD18 = {{35,49,53,75}};
	const std::vector<NeuronId> N32::incommingNeuronsD19 = {{31}};
	struct N33 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N33::incommingNeuronsD0;
				case 1: return N33::incommingNeuronsD1;
				case 2: return N33::incommingNeuronsD2;
				case 3: return N33::incommingNeuronsD3;
				case 4: return N33::incommingNeuronsD4;
				case 5: return N33::incommingNeuronsD5;
				case 6: return N33::incommingNeuronsD6;
				case 7: return N33::incommingNeuronsD7;
				case 8: return N33::incommingNeuronsD8;
				case 9: return N33::incommingNeuronsD9;
				case 10: return N33::incommingNeuronsD10;
				case 11: return N33::incommingNeuronsD11;
				case 12: return N33::incommingNeuronsD12;
				case 13: return N33::incommingNeuronsD13;
				case 14: return N33::incommingNeuronsD14;
				case 15: return N33::incommingNeuronsD15;
				case 16: return N33::incommingNeuronsD16;
				case 17: return N33::incommingNeuronsD17;
				case 18: return N33::incommingNeuronsD18;
				case 19: return N33::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{6,23,49,22,92,60,17,8,75,98,38,71,81,91,50,18,61,3,93,19}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(33);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N33::incommingNeuronsD0 = {{56,84,87,93,97}};
	const std::vector<NeuronId> N33::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD3 = {{21,26}};
	const std::vector<NeuronId> N33::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD6 = {{38,52}};
	const std::vector<NeuronId> N33::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD9 = {{29,42}};
	const std::vector<NeuronId> N33::incommingNeuronsD10 = {{39}};
	const std::vector<NeuronId> N33::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD13 = {{11}};
	const std::vector<NeuronId> N33::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD15 = {{18}};
	const std::vector<NeuronId> N33::incommingNeuronsD16 = {{59}};
	const std::vector<NeuronId> N33::incommingNeuronsD17 = {{37,46}};
	const std::vector<NeuronId> N33::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N33::incommingNeuronsD19 = {{68}};
	struct N34 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N34::incommingNeuronsD0;
				case 1: return N34::incommingNeuronsD1;
				case 2: return N34::incommingNeuronsD2;
				case 3: return N34::incommingNeuronsD3;
				case 4: return N34::incommingNeuronsD4;
				case 5: return N34::incommingNeuronsD5;
				case 6: return N34::incommingNeuronsD6;
				case 7: return N34::incommingNeuronsD7;
				case 8: return N34::incommingNeuronsD8;
				case 9: return N34::incommingNeuronsD9;
				case 10: return N34::incommingNeuronsD10;
				case 11: return N34::incommingNeuronsD11;
				case 12: return N34::incommingNeuronsD12;
				case 13: return N34::incommingNeuronsD13;
				case 14: return N34::incommingNeuronsD14;
				case 15: return N34::incommingNeuronsD15;
				case 16: return N34::incommingNeuronsD16;
				case 17: return N34::incommingNeuronsD17;
				case 18: return N34::incommingNeuronsD18;
				case 19: return N34::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{23,57,58,72,78,11,56,66,89,55,81,54,17,95,99,29,12,18,79,40}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(34);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N34::incommingNeuronsD0 = {{19,80,82,85,88,90,94}};
	const std::vector<NeuronId> N34::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N34::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N34::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N34::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N34::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N34::incommingNeuronsD6 = {{6,26}};
	const std::vector<NeuronId> N34::incommingNeuronsD7 = {{5}};
	const std::vector<NeuronId> N34::incommingNeuronsD8 = {{59,61}};
	const std::vector<NeuronId> N34::incommingNeuronsD9 = {{76}};
	const std::vector<NeuronId> N34::incommingNeuronsD10 = {{11}};
	const std::vector<NeuronId> N34::incommingNeuronsD11 = {{14}};
	const std::vector<NeuronId> N34::incommingNeuronsD12 = {{77}};
	const std::vector<NeuronId> N34::incommingNeuronsD13 = {{0,75}};
	const std::vector<NeuronId> N34::incommingNeuronsD14 = {{13,24,65}};
	const std::vector<NeuronId> N34::incommingNeuronsD15 = {{48}};
	const std::vector<NeuronId> N34::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N34::incommingNeuronsD17 = {{40,42,70}};
	const std::vector<NeuronId> N34::incommingNeuronsD18 = {{57}};
	const std::vector<NeuronId> N34::incommingNeuronsD19 = {{43}};
	struct N35 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N35::incommingNeuronsD0;
				case 1: return N35::incommingNeuronsD1;
				case 2: return N35::incommingNeuronsD2;
				case 3: return N35::incommingNeuronsD3;
				case 4: return N35::incommingNeuronsD4;
				case 5: return N35::incommingNeuronsD5;
				case 6: return N35::incommingNeuronsD6;
				case 7: return N35::incommingNeuronsD7;
				case 8: return N35::incommingNeuronsD8;
				case 9: return N35::incommingNeuronsD9;
				case 10: return N35::incommingNeuronsD10;
				case 11: return N35::incommingNeuronsD11;
				case 12: return N35::incommingNeuronsD12;
				case 13: return N35::incommingNeuronsD13;
				case 14: return N35::incommingNeuronsD14;
				case 15: return N35::incommingNeuronsD15;
				case 16: return N35::incommingNeuronsD16;
				case 17: return N35::incommingNeuronsD17;
				case 18: return N35::incommingNeuronsD18;
				case 19: return N35::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{82,70,26,5,25,77,74,28,20,60,6,83,85,99,87,54,19,93,32,73}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(35);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N35::incommingNeuronsD0 = {{38,81,87,93,95}};
	const std::vector<NeuronId> N35::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD2 = {{69}};
	const std::vector<NeuronId> N35::incommingNeuronsD3 = {{24}};
	const std::vector<NeuronId> N35::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD5 = {{25,75}};
	const std::vector<NeuronId> N35::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD7 = {{55}};
	const std::vector<NeuronId> N35::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD9 = {{26}};
	const std::vector<NeuronId> N35::incommingNeuronsD10 = {{23,72}};
	const std::vector<NeuronId> N35::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD12 = {{32}};
	const std::vector<NeuronId> N35::incommingNeuronsD13 = {{73}};
	const std::vector<NeuronId> N35::incommingNeuronsD14 = {{41}};
	const std::vector<NeuronId> N35::incommingNeuronsD15 = {{63}};
	const std::vector<NeuronId> N35::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N35::incommingNeuronsD18 = {{40}};
	const std::vector<NeuronId> N35::incommingNeuronsD19 = {{50}};
	struct N36 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N36::incommingNeuronsD0;
				case 1: return N36::incommingNeuronsD1;
				case 2: return N36::incommingNeuronsD2;
				case 3: return N36::incommingNeuronsD3;
				case 4: return N36::incommingNeuronsD4;
				case 5: return N36::incommingNeuronsD5;
				case 6: return N36::incommingNeuronsD6;
				case 7: return N36::incommingNeuronsD7;
				case 8: return N36::incommingNeuronsD8;
				case 9: return N36::incommingNeuronsD9;
				case 10: return N36::incommingNeuronsD10;
				case 11: return N36::incommingNeuronsD11;
				case 12: return N36::incommingNeuronsD12;
				case 13: return N36::incommingNeuronsD13;
				case 14: return N36::incommingNeuronsD14;
				case 15: return N36::incommingNeuronsD15;
				case 16: return N36::incommingNeuronsD16;
				case 17: return N36::incommingNeuronsD17;
				case 18: return N36::incommingNeuronsD18;
				case 19: return N36::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{42,45,12,10,2,31,73,55,23,41,70,97,43,48,80,95,16,25,65,22}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(36);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N36::incommingNeuronsD0 = {{88,89,90,94}};
	const std::vector<NeuronId> N36::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N36::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N36::incommingNeuronsD3 = {{1,32}};
	const std::vector<NeuronId> N36::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N36::incommingNeuronsD5 = {{44,50}};
	const std::vector<NeuronId> N36::incommingNeuronsD6 = {{60}};
	const std::vector<NeuronId> N36::incommingNeuronsD7 = {{3,41}};
	const std::vector<NeuronId> N36::incommingNeuronsD8 = {{67,74}};
	const std::vector<NeuronId> N36::incommingNeuronsD9 = {{22,63}};
	const std::vector<NeuronId> N36::incommingNeuronsD10 = {{61}};
	const std::vector<NeuronId> N36::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N36::incommingNeuronsD12 = {{19}};
	const std::vector<NeuronId> N36::incommingNeuronsD13 = {{72}};
	const std::vector<NeuronId> N36::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N36::incommingNeuronsD15 = {{49}};
	const std::vector<NeuronId> N36::incommingNeuronsD16 = {{6}};
	const std::vector<NeuronId> N36::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N36::incommingNeuronsD18 = {{47}};
	const std::vector<NeuronId> N36::incommingNeuronsD19 = {{56}};
	struct N37 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N37::incommingNeuronsD0;
				case 1: return N37::incommingNeuronsD1;
				case 2: return N37::incommingNeuronsD2;
				case 3: return N37::incommingNeuronsD3;
				case 4: return N37::incommingNeuronsD4;
				case 5: return N37::incommingNeuronsD5;
				case 6: return N37::incommingNeuronsD6;
				case 7: return N37::incommingNeuronsD7;
				case 8: return N37::incommingNeuronsD8;
				case 9: return N37::incommingNeuronsD9;
				case 10: return N37::incommingNeuronsD10;
				case 11: return N37::incommingNeuronsD11;
				case 12: return N37::incommingNeuronsD12;
				case 13: return N37::incommingNeuronsD13;
				case 14: return N37::incommingNeuronsD14;
				case 15: return N37::incommingNeuronsD15;
				case 16: return N37::incommingNeuronsD16;
				case 17: return N37::incommingNeuronsD17;
				case 18: return N37::incommingNeuronsD18;
				case 19: return N37::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{7,41,43,44,23,18,8,83,17,79,66,1,84,94,6,82,87,33,39,49}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(37);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N37::incommingNeuronsD0 = {{31,46,81,87,89,96,97,99}};
	const std::vector<NeuronId> N37::incommingNeuronsD1 = {{71}};
	const std::vector<NeuronId> N37::incommingNeuronsD2 = {{56}};
	const std::vector<NeuronId> N37::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N37::incommingNeuronsD4 = {{2,53}};
	const std::vector<NeuronId> N37::incommingNeuronsD5 = {{4,39}};
	const std::vector<NeuronId> N37::incommingNeuronsD6 = {{32,50}};
	const std::vector<NeuronId> N37::incommingNeuronsD7 = {{79}};
	const std::vector<NeuronId> N37::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N37::incommingNeuronsD9 = {{14,15,27}};
	const std::vector<NeuronId> N37::incommingNeuronsD10 = {{65}};
	const std::vector<NeuronId> N37::incommingNeuronsD11 = {{75}};
	const std::vector<NeuronId> N37::incommingNeuronsD12 = {{11,55}};
	const std::vector<NeuronId> N37::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N37::incommingNeuronsD14 = {{10}};
	const std::vector<NeuronId> N37::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N37::incommingNeuronsD16 = {{23,69}};
	const std::vector<NeuronId> N37::incommingNeuronsD17 = {{16}};
	const std::vector<NeuronId> N37::incommingNeuronsD18 = {{44}};
	const std::vector<NeuronId> N37::incommingNeuronsD19 = {{}};
	struct N38 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N38::incommingNeuronsD0;
				case 1: return N38::incommingNeuronsD1;
				case 2: return N38::incommingNeuronsD2;
				case 3: return N38::incommingNeuronsD3;
				case 4: return N38::incommingNeuronsD4;
				case 5: return N38::incommingNeuronsD5;
				case 6: return N38::incommingNeuronsD6;
				case 7: return N38::incommingNeuronsD7;
				case 8: return N38::incommingNeuronsD8;
				case 9: return N38::incommingNeuronsD9;
				case 10: return N38::incommingNeuronsD10;
				case 11: return N38::incommingNeuronsD11;
				case 12: return N38::incommingNeuronsD12;
				case 13: return N38::incommingNeuronsD13;
				case 14: return N38::incommingNeuronsD14;
				case 15: return N38::incommingNeuronsD15;
				case 16: return N38::incommingNeuronsD16;
				case 17: return N38::incommingNeuronsD17;
				case 18: return N38::incommingNeuronsD18;
				case 19: return N38::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{35,68,27,76,24,75,33,59,74,2,17,14,84,69,31,99,44,72,25,66}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(38);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N38::incommingNeuronsD0 = {{83,84,85,93}};
	const std::vector<NeuronId> N38::incommingNeuronsD1 = {{77}};
	const std::vector<NeuronId> N38::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD3 = {{40,63}};
	const std::vector<NeuronId> N38::incommingNeuronsD4 = {{32,66}};
	const std::vector<NeuronId> N38::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD7 = {{29,73}};
	const std::vector<NeuronId> N38::incommingNeuronsD8 = {{18}};
	const std::vector<NeuronId> N38::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD10 = {{33}};
	const std::vector<NeuronId> N38::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD12 = {{49}};
	const std::vector<NeuronId> N38::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD14 = {{75}};
	const std::vector<NeuronId> N38::incommingNeuronsD15 = {{8,23}};
	const std::vector<NeuronId> N38::incommingNeuronsD16 = {{74}};
	const std::vector<NeuronId> N38::incommingNeuronsD17 = {{58}};
	const std::vector<NeuronId> N38::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N38::incommingNeuronsD19 = {{55}};
	struct N39 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N39::incommingNeuronsD0;
				case 1: return N39::incommingNeuronsD1;
				case 2: return N39::incommingNeuronsD2;
				case 3: return N39::incommingNeuronsD3;
				case 4: return N39::incommingNeuronsD4;
				case 5: return N39::incommingNeuronsD5;
				case 6: return N39::incommingNeuronsD6;
				case 7: return N39::incommingNeuronsD7;
				case 8: return N39::incommingNeuronsD8;
				case 9: return N39::incommingNeuronsD9;
				case 10: return N39::incommingNeuronsD10;
				case 11: return N39::incommingNeuronsD11;
				case 12: return N39::incommingNeuronsD12;
				case 13: return N39::incommingNeuronsD13;
				case 14: return N39::incommingNeuronsD14;
				case 15: return N39::incommingNeuronsD15;
				case 16: return N39::incommingNeuronsD16;
				case 17: return N39::incommingNeuronsD17;
				case 18: return N39::incommingNeuronsD18;
				case 19: return N39::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{61,43,83,17,10,37,24,71,44,5,33,79,82,88,85,58,76,64,9,78}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(39);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N39::incommingNeuronsD0 = {{80,81,87,90,92}};
	const std::vector<NeuronId> N39::incommingNeuronsD1 = {{15,60,70}};
	const std::vector<NeuronId> N39::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N39::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N39::incommingNeuronsD4 = {{44}};
	const std::vector<NeuronId> N39::incommingNeuronsD5 = {{24}};
	const std::vector<NeuronId> N39::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N39::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N39::incommingNeuronsD8 = {{51}};
	const std::vector<NeuronId> N39::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N39::incommingNeuronsD10 = {{9}};
	const std::vector<NeuronId> N39::incommingNeuronsD11 = {{7,69}};
	const std::vector<NeuronId> N39::incommingNeuronsD12 = {{5}};
	const std::vector<NeuronId> N39::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N39::incommingNeuronsD14 = {{28}};
	const std::vector<NeuronId> N39::incommingNeuronsD15 = {{29,40}};
	const std::vector<NeuronId> N39::incommingNeuronsD16 = {{2,66}};
	const std::vector<NeuronId> N39::incommingNeuronsD17 = {{68}};
	const std::vector<NeuronId> N39::incommingNeuronsD18 = {{37}};
	const std::vector<NeuronId> N39::incommingNeuronsD19 = {{19}};
	struct N40 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N40::incommingNeuronsD0;
				case 1: return N40::incommingNeuronsD1;
				case 2: return N40::incommingNeuronsD2;
				case 3: return N40::incommingNeuronsD3;
				case 4: return N40::incommingNeuronsD4;
				case 5: return N40::incommingNeuronsD5;
				case 6: return N40::incommingNeuronsD6;
				case 7: return N40::incommingNeuronsD7;
				case 8: return N40::incommingNeuronsD8;
				case 9: return N40::incommingNeuronsD9;
				case 10: return N40::incommingNeuronsD10;
				case 11: return N40::incommingNeuronsD11;
				case 12: return N40::incommingNeuronsD12;
				case 13: return N40::incommingNeuronsD13;
				case 14: return N40::incommingNeuronsD14;
				case 15: return N40::incommingNeuronsD15;
				case 16: return N40::incommingNeuronsD16;
				case 17: return N40::incommingNeuronsD17;
				case 18: return N40::incommingNeuronsD18;
				case 19: return N40::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{76,41,74,38,14,47,44,93,64,81,3,9,87,24,32,39,5,34,35,65}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(40);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N40::incommingNeuronsD0 = {{80,81,82,83,86,88,95,96}};
	const std::vector<NeuronId> N40::incommingNeuronsD1 = {{3}};
	const std::vector<NeuronId> N40::incommingNeuronsD2 = {{26}};
	const std::vector<NeuronId> N40::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N40::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N40::incommingNeuronsD5 = {{11,62}};
	const std::vector<NeuronId> N40::incommingNeuronsD6 = {{63}};
	const std::vector<NeuronId> N40::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N40::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N40::incommingNeuronsD9 = {{32,74}};
	const std::vector<NeuronId> N40::incommingNeuronsD10 = {{49,66}};
	const std::vector<NeuronId> N40::incommingNeuronsD11 = {{50}};
	const std::vector<NeuronId> N40::incommingNeuronsD12 = {{22}};
	const std::vector<NeuronId> N40::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N40::incommingNeuronsD14 = {{64}};
	const std::vector<NeuronId> N40::incommingNeuronsD15 = {{69}};
	const std::vector<NeuronId> N40::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N40::incommingNeuronsD17 = {{48}};
	const std::vector<NeuronId> N40::incommingNeuronsD18 = {{20}};
	const std::vector<NeuronId> N40::incommingNeuronsD19 = {{27,34}};
	struct N41 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N41::incommingNeuronsD0;
				case 1: return N41::incommingNeuronsD1;
				case 2: return N41::incommingNeuronsD2;
				case 3: return N41::incommingNeuronsD3;
				case 4: return N41::incommingNeuronsD4;
				case 5: return N41::incommingNeuronsD5;
				case 6: return N41::incommingNeuronsD6;
				case 7: return N41::incommingNeuronsD7;
				case 8: return N41::incommingNeuronsD8;
				case 9: return N41::incommingNeuronsD9;
				case 10: return N41::incommingNeuronsD10;
				case 11: return N41::incommingNeuronsD11;
				case 12: return N41::incommingNeuronsD12;
				case 13: return N41::incommingNeuronsD13;
				case 14: return N41::incommingNeuronsD14;
				case 15: return N41::incommingNeuronsD15;
				case 16: return N41::incommingNeuronsD16;
				case 17: return N41::incommingNeuronsD17;
				case 18: return N41::incommingNeuronsD18;
				case 19: return N41::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{79,22,54,91,3,26,96,36,89,58,20,99,12,18,35,92,93,59,82,74}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(41);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N41::incommingNeuronsD0 = {{21,70,80,82,96,97,99}};
	const std::vector<NeuronId> N41::incommingNeuronsD1 = {{37,40}};
	const std::vector<NeuronId> N41::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD3 = {{78}};
	const std::vector<NeuronId> N41::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD6 = {{31,54}};
	const std::vector<NeuronId> N41::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD8 = {{30,62}};
	const std::vector<NeuronId> N41::incommingNeuronsD9 = {{36,57}};
	const std::vector<NeuronId> N41::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD16 = {{53}};
	const std::vector<NeuronId> N41::incommingNeuronsD17 = {{13}};
	const std::vector<NeuronId> N41::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N41::incommingNeuronsD19 = {{29,52}};
	struct N42 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N42::incommingNeuronsD0;
				case 1: return N42::incommingNeuronsD1;
				case 2: return N42::incommingNeuronsD2;
				case 3: return N42::incommingNeuronsD3;
				case 4: return N42::incommingNeuronsD4;
				case 5: return N42::incommingNeuronsD5;
				case 6: return N42::incommingNeuronsD6;
				case 7: return N42::incommingNeuronsD7;
				case 8: return N42::incommingNeuronsD8;
				case 9: return N42::incommingNeuronsD9;
				case 10: return N42::incommingNeuronsD10;
				case 11: return N42::incommingNeuronsD11;
				case 12: return N42::incommingNeuronsD12;
				case 13: return N42::incommingNeuronsD13;
				case 14: return N42::incommingNeuronsD14;
				case 15: return N42::incommingNeuronsD15;
				case 16: return N42::incommingNeuronsD16;
				case 17: return N42::incommingNeuronsD17;
				case 18: return N42::incommingNeuronsD18;
				case 19: return N42::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{3,93,4,87,51,66,13,83,47,33,55,71,90,92,28,32,79,34,72,29}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(42);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N42::incommingNeuronsD0 = {{13,36,81,87,92,93,97}};
	const std::vector<NeuronId> N42::incommingNeuronsD1 = {{56,61}};
	const std::vector<NeuronId> N42::incommingNeuronsD2 = {{27,45}};
	const std::vector<NeuronId> N42::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD4 = {{78}};
	const std::vector<NeuronId> N42::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD6 = {{19,79}};
	const std::vector<NeuronId> N42::incommingNeuronsD7 = {{51}};
	const std::vector<NeuronId> N42::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD10 = {{59}};
	const std::vector<NeuronId> N42::incommingNeuronsD11 = {{57}};
	const std::vector<NeuronId> N42::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD13 = {{15,28,43}};
	const std::vector<NeuronId> N42::incommingNeuronsD14 = {{67,74}};
	const std::vector<NeuronId> N42::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N42::incommingNeuronsD19 = {{}};
	struct N43 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N43::incommingNeuronsD0;
				case 1: return N43::incommingNeuronsD1;
				case 2: return N43::incommingNeuronsD2;
				case 3: return N43::incommingNeuronsD3;
				case 4: return N43::incommingNeuronsD4;
				case 5: return N43::incommingNeuronsD5;
				case 6: return N43::incommingNeuronsD6;
				case 7: return N43::incommingNeuronsD7;
				case 8: return N43::incommingNeuronsD8;
				case 9: return N43::incommingNeuronsD9;
				case 10: return N43::incommingNeuronsD10;
				case 11: return N43::incommingNeuronsD11;
				case 12: return N43::incommingNeuronsD12;
				case 13: return N43::incommingNeuronsD13;
				case 14: return N43::incommingNeuronsD14;
				case 15: return N43::incommingNeuronsD15;
				case 16: return N43::incommingNeuronsD16;
				case 17: return N43::incommingNeuronsD17;
				case 18: return N43::incommingNeuronsD18;
				case 19: return N43::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{58,15,54,14,49,9,55,83,75,66,12,29,48,42,74,56,59,47,76,34}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(43);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N43::incommingNeuronsD0 = {{5,79,80,84,90,91}};
	const std::vector<NeuronId> N43::incommingNeuronsD1 = {{39}};
	const std::vector<NeuronId> N43::incommingNeuronsD2 = {{37}};
	const std::vector<NeuronId> N43::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD5 = {{7,19}};
	const std::vector<NeuronId> N43::incommingNeuronsD6 = {{13}};
	const std::vector<NeuronId> N43::incommingNeuronsD7 = {{6}};
	const std::vector<NeuronId> N43::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD10 = {{10,60,67}};
	const std::vector<NeuronId> N43::incommingNeuronsD11 = {{0}};
	const std::vector<NeuronId> N43::incommingNeuronsD12 = {{36}};
	const std::vector<NeuronId> N43::incommingNeuronsD13 = {{21}};
	const std::vector<NeuronId> N43::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD16 = {{17,20,68}};
	const std::vector<NeuronId> N43::incommingNeuronsD17 = {{9,26,65,71}};
	const std::vector<NeuronId> N43::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N43::incommingNeuronsD19 = {{28}};
	struct N44 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N44::incommingNeuronsD0;
				case 1: return N44::incommingNeuronsD1;
				case 2: return N44::incommingNeuronsD2;
				case 3: return N44::incommingNeuronsD3;
				case 4: return N44::incommingNeuronsD4;
				case 5: return N44::incommingNeuronsD5;
				case 6: return N44::incommingNeuronsD6;
				case 7: return N44::incommingNeuronsD7;
				case 8: return N44::incommingNeuronsD8;
				case 9: return N44::incommingNeuronsD9;
				case 10: return N44::incommingNeuronsD10;
				case 11: return N44::incommingNeuronsD11;
				case 12: return N44::incommingNeuronsD12;
				case 13: return N44::incommingNeuronsD13;
				case 14: return N44::incommingNeuronsD14;
				case 15: return N44::incommingNeuronsD15;
				case 16: return N44::incommingNeuronsD16;
				case 17: return N44::incommingNeuronsD17;
				case 18: return N44::incommingNeuronsD18;
				case 19: return N44::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{70,27,5,85,39,36,29,54,3,56,22,72,18,47,24,67,59,62,37,97}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(44);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N44::incommingNeuronsD0 = {{94,97}};
	const std::vector<NeuronId> N44::incommingNeuronsD1 = {{68}};
	const std::vector<NeuronId> N44::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD3 = {{19,37,54}};
	const std::vector<NeuronId> N44::incommingNeuronsD4 = {{31}};
	const std::vector<NeuronId> N44::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD6 = {{40,45}};
	const std::vector<NeuronId> N44::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD8 = {{39}};
	const std::vector<NeuronId> N44::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD11 = {{20,64,72}};
	const std::vector<NeuronId> N44::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD13 = {{10}};
	const std::vector<NeuronId> N44::incommingNeuronsD14 = {{73}};
	const std::vector<NeuronId> N44::incommingNeuronsD15 = {{28}};
	const std::vector<NeuronId> N44::incommingNeuronsD16 = {{38}};
	const std::vector<NeuronId> N44::incommingNeuronsD17 = {{61,62}};
	const std::vector<NeuronId> N44::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N44::incommingNeuronsD19 = {{}};
	struct N45 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N45::incommingNeuronsD0;
				case 1: return N45::incommingNeuronsD1;
				case 2: return N45::incommingNeuronsD2;
				case 3: return N45::incommingNeuronsD3;
				case 4: return N45::incommingNeuronsD4;
				case 5: return N45::incommingNeuronsD5;
				case 6: return N45::incommingNeuronsD6;
				case 7: return N45::incommingNeuronsD7;
				case 8: return N45::incommingNeuronsD8;
				case 9: return N45::incommingNeuronsD9;
				case 10: return N45::incommingNeuronsD10;
				case 11: return N45::incommingNeuronsD11;
				case 12: return N45::incommingNeuronsD12;
				case 13: return N45::incommingNeuronsD13;
				case 14: return N45::incommingNeuronsD14;
				case 15: return N45::incommingNeuronsD15;
				case 16: return N45::incommingNeuronsD16;
				case 17: return N45::incommingNeuronsD17;
				case 18: return N45::incommingNeuronsD18;
				case 19: return N45::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{47,62,42,26,53,84,44,15,55,14,65,21,77,48,99,3,73,67,71,27}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(45);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N45::incommingNeuronsD0 = {{85,87,88,91,95,98}};
	const std::vector<NeuronId> N45::incommingNeuronsD1 = {{29,36}};
	const std::vector<NeuronId> N45::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD3 = {{20}};
	const std::vector<NeuronId> N45::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD5 = {{74}};
	const std::vector<NeuronId> N45::incommingNeuronsD6 = {{53}};
	const std::vector<NeuronId> N45::incommingNeuronsD7 = {{76}};
	const std::vector<NeuronId> N45::incommingNeuronsD8 = {{14,32}};
	const std::vector<NeuronId> N45::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD11 = {{18,19,66}};
	const std::vector<NeuronId> N45::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD13 = {{8}};
	const std::vector<NeuronId> N45::incommingNeuronsD14 = {{59}};
	const std::vector<NeuronId> N45::incommingNeuronsD15 = {{5}};
	const std::vector<NeuronId> N45::incommingNeuronsD16 = {{46}};
	const std::vector<NeuronId> N45::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N45::incommingNeuronsD19 = {{21}};
	struct N46 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N46::incommingNeuronsD0;
				case 1: return N46::incommingNeuronsD1;
				case 2: return N46::incommingNeuronsD2;
				case 3: return N46::incommingNeuronsD3;
				case 4: return N46::incommingNeuronsD4;
				case 5: return N46::incommingNeuronsD5;
				case 6: return N46::incommingNeuronsD6;
				case 7: return N46::incommingNeuronsD7;
				case 8: return N46::incommingNeuronsD8;
				case 9: return N46::incommingNeuronsD9;
				case 10: return N46::incommingNeuronsD10;
				case 11: return N46::incommingNeuronsD11;
				case 12: return N46::incommingNeuronsD12;
				case 13: return N46::incommingNeuronsD13;
				case 14: return N46::incommingNeuronsD14;
				case 15: return N46::incommingNeuronsD15;
				case 16: return N46::incommingNeuronsD16;
				case 17: return N46::incommingNeuronsD17;
				case 18: return N46::incommingNeuronsD18;
				case 19: return N46::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{37,94,87,12,83,57,91,53,72,58,17,97,20,15,85,50,45,33,16,80}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(46);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N46::incommingNeuronsD0 = {{47,76,84,88,89,90,92,96,97,98}};
	const std::vector<NeuronId> N46::incommingNeuronsD1 = {{2}};
	const std::vector<NeuronId> N46::incommingNeuronsD2 = {{67}};
	const std::vector<NeuronId> N46::incommingNeuronsD3 = {{71}};
	const std::vector<NeuronId> N46::incommingNeuronsD4 = {{13}};
	const std::vector<NeuronId> N46::incommingNeuronsD5 = {{27,59}};
	const std::vector<NeuronId> N46::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD11 = {{23}};
	const std::vector<NeuronId> N46::incommingNeuronsD12 = {{10}};
	const std::vector<NeuronId> N46::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD14 = {{26}};
	const std::vector<NeuronId> N46::incommingNeuronsD15 = {{31}};
	const std::vector<NeuronId> N46::incommingNeuronsD16 = {{32}};
	const std::vector<NeuronId> N46::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N46::incommingNeuronsD18 = {{77}};
	const std::vector<NeuronId> N46::incommingNeuronsD19 = {{}};
	struct N47 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N47::incommingNeuronsD0;
				case 1: return N47::incommingNeuronsD1;
				case 2: return N47::incommingNeuronsD2;
				case 3: return N47::incommingNeuronsD3;
				case 4: return N47::incommingNeuronsD4;
				case 5: return N47::incommingNeuronsD5;
				case 6: return N47::incommingNeuronsD6;
				case 7: return N47::incommingNeuronsD7;
				case 8: return N47::incommingNeuronsD8;
				case 9: return N47::incommingNeuronsD9;
				case 10: return N47::incommingNeuronsD10;
				case 11: return N47::incommingNeuronsD11;
				case 12: return N47::incommingNeuronsD12;
				case 13: return N47::incommingNeuronsD13;
				case 14: return N47::incommingNeuronsD14;
				case 15: return N47::incommingNeuronsD15;
				case 16: return N47::incommingNeuronsD16;
				case 17: return N47::incommingNeuronsD17;
				case 18: return N47::incommingNeuronsD18;
				case 19: return N47::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{46,86,96,15,91,85,66,62,7,13,9,88,6,24,59,89,2,70,36,68}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(47);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N47::incommingNeuronsD0 = {{8,45,58,84,89}};
	const std::vector<NeuronId> N47::incommingNeuronsD1 = {{17}};
	const std::vector<NeuronId> N47::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD5 = {{40,77}};
	const std::vector<NeuronId> N47::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD8 = {{42,55}};
	const std::vector<NeuronId> N47::incommingNeuronsD9 = {{6,7}};
	const std::vector<NeuronId> N47::incommingNeuronsD10 = {{4}};
	const std::vector<NeuronId> N47::incommingNeuronsD11 = {{2,29}};
	const std::vector<NeuronId> N47::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD13 = {{5,44}};
	const std::vector<NeuronId> N47::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N47::incommingNeuronsD15 = {{67}};
	const std::vector<NeuronId> N47::incommingNeuronsD16 = {{3}};
	const std::vector<NeuronId> N47::incommingNeuronsD17 = {{43,60}};
	const std::vector<NeuronId> N47::incommingNeuronsD18 = {{28,65}};
	const std::vector<NeuronId> N47::incommingNeuronsD19 = {{}};
	struct N48 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N48::incommingNeuronsD0;
				case 1: return N48::incommingNeuronsD1;
				case 2: return N48::incommingNeuronsD2;
				case 3: return N48::incommingNeuronsD3;
				case 4: return N48::incommingNeuronsD4;
				case 5: return N48::incommingNeuronsD5;
				case 6: return N48::incommingNeuronsD6;
				case 7: return N48::incommingNeuronsD7;
				case 8: return N48::incommingNeuronsD8;
				case 9: return N48::incommingNeuronsD9;
				case 10: return N48::incommingNeuronsD10;
				case 11: return N48::incommingNeuronsD11;
				case 12: return N48::incommingNeuronsD12;
				case 13: return N48::incommingNeuronsD13;
				case 14: return N48::incommingNeuronsD14;
				case 15: return N48::incommingNeuronsD15;
				case 16: return N48::incommingNeuronsD16;
				case 17: return N48::incommingNeuronsD17;
				case 18: return N48::incommingNeuronsD18;
				case 19: return N48::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{53,83,52,30,95,71,24,55,82,79,74,50,5,76,19,34,57,40,18,67}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(48);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N48::incommingNeuronsD0 = {{84,85,87}};
	const std::vector<NeuronId> N48::incommingNeuronsD1 = {{52}};
	const std::vector<NeuronId> N48::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD5 = {{12,65}};
	const std::vector<NeuronId> N48::incommingNeuronsD6 = {{28}};
	const std::vector<NeuronId> N48::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD8 = {{6}};
	const std::vector<NeuronId> N48::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD10 = {{2}};
	const std::vector<NeuronId> N48::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD12 = {{43,61}};
	const std::vector<NeuronId> N48::incommingNeuronsD13 = {{20,36,45,51}};
	const std::vector<NeuronId> N48::incommingNeuronsD14 = {{8}};
	const std::vector<NeuronId> N48::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD17 = {{76,78}};
	const std::vector<NeuronId> N48::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N48::incommingNeuronsD19 = {{}};
	struct N49 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N49::incommingNeuronsD0;
				case 1: return N49::incommingNeuronsD1;
				case 2: return N49::incommingNeuronsD2;
				case 3: return N49::incommingNeuronsD3;
				case 4: return N49::incommingNeuronsD4;
				case 5: return N49::incommingNeuronsD5;
				case 6: return N49::incommingNeuronsD6;
				case 7: return N49::incommingNeuronsD7;
				case 8: return N49::incommingNeuronsD8;
				case 9: return N49::incommingNeuronsD9;
				case 10: return N49::incommingNeuronsD10;
				case 11: return N49::incommingNeuronsD11;
				case 12: return N49::incommingNeuronsD12;
				case 13: return N49::incommingNeuronsD13;
				case 14: return N49::incommingNeuronsD14;
				case 15: return N49::incommingNeuronsD15;
				case 16: return N49::incommingNeuronsD16;
				case 17: return N49::incommingNeuronsD17;
				case 18: return N49::incommingNeuronsD18;
				case 19: return N49::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{99,12,20,9,55,81,2,95,80,51,40,21,38,54,61,36,29,14,32,27}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(49);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N49::incommingNeuronsD0 = {{53,82,84,85,89,91,93}};
	const std::vector<NeuronId> N49::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD2 = {{33}};
	const std::vector<NeuronId> N49::incommingNeuronsD3 = {{62,72}};
	const std::vector<NeuronId> N49::incommingNeuronsD4 = {{26,43,50}};
	const std::vector<NeuronId> N49::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD6 = {{65}};
	const std::vector<NeuronId> N49::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD9 = {{21,66}};
	const std::vector<NeuronId> N49::incommingNeuronsD10 = {{31}};
	const std::vector<NeuronId> N49::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD12 = {{71}};
	const std::vector<NeuronId> N49::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N49::incommingNeuronsD17 = {{69}};
	const std::vector<NeuronId> N49::incommingNeuronsD18 = {{0,12,78}};
	const std::vector<NeuronId> N49::incommingNeuronsD19 = {{37}};
	struct N50 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N50::incommingNeuronsD0;
				case 1: return N50::incommingNeuronsD1;
				case 2: return N50::incommingNeuronsD2;
				case 3: return N50::incommingNeuronsD3;
				case 4: return N50::incommingNeuronsD4;
				case 5: return N50::incommingNeuronsD5;
				case 6: return N50::incommingNeuronsD6;
				case 7: return N50::incommingNeuronsD7;
				case 8: return N50::incommingNeuronsD8;
				case 9: return N50::incommingNeuronsD9;
				case 10: return N50::incommingNeuronsD10;
				case 11: return N50::incommingNeuronsD11;
				case 12: return N50::incommingNeuronsD12;
				case 13: return N50::incommingNeuronsD13;
				case 14: return N50::incommingNeuronsD14;
				case 15: return N50::incommingNeuronsD15;
				case 16: return N50::incommingNeuronsD16;
				case 17: return N50::incommingNeuronsD17;
				case 18: return N50::incommingNeuronsD18;
				case 19: return N50::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{83,73,89,58,49,36,37,15,70,19,17,40,29,2,25,93,52,66,51,35}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(50);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N50::incommingNeuronsD0 = {{24,81,89,92,94}};
	const std::vector<NeuronId> N50::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD4 = {{20,70}};
	const std::vector<NeuronId> N50::incommingNeuronsD5 = {{68}};
	const std::vector<NeuronId> N50::incommingNeuronsD6 = {{77}};
	const std::vector<NeuronId> N50::incommingNeuronsD7 = {{14}};
	const std::vector<NeuronId> N50::incommingNeuronsD8 = {{13}};
	const std::vector<NeuronId> N50::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD11 = {{48}};
	const std::vector<NeuronId> N50::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD14 = {{33}};
	const std::vector<NeuronId> N50::incommingNeuronsD15 = {{46}};
	const std::vector<NeuronId> N50::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N50::incommingNeuronsD19 = {{}};
	struct N51 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N51::incommingNeuronsD0;
				case 1: return N51::incommingNeuronsD1;
				case 2: return N51::incommingNeuronsD2;
				case 3: return N51::incommingNeuronsD3;
				case 4: return N51::incommingNeuronsD4;
				case 5: return N51::incommingNeuronsD5;
				case 6: return N51::incommingNeuronsD6;
				case 7: return N51::incommingNeuronsD7;
				case 8: return N51::incommingNeuronsD8;
				case 9: return N51::incommingNeuronsD9;
				case 10: return N51::incommingNeuronsD10;
				case 11: return N51::incommingNeuronsD11;
				case 12: return N51::incommingNeuronsD12;
				case 13: return N51::incommingNeuronsD13;
				case 14: return N51::incommingNeuronsD14;
				case 15: return N51::incommingNeuronsD15;
				case 16: return N51::incommingNeuronsD16;
				case 17: return N51::incommingNeuronsD17;
				case 18: return N51::incommingNeuronsD18;
				case 19: return N51::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{55,20,89,80,96,75,14,42,39,29,90,54,94,48,0,1,95,32,69,15}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(51);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N51::incommingNeuronsD0 = {{12,80,86,88,89,91,92,96,98}};
	const std::vector<NeuronId> N51::incommingNeuronsD1 = {{31}};
	const std::vector<NeuronId> N51::incommingNeuronsD2 = {{19}};
	const std::vector<NeuronId> N51::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD4 = {{42}};
	const std::vector<NeuronId> N51::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD6 = {{14,57,58}};
	const std::vector<NeuronId> N51::incommingNeuronsD7 = {{53}};
	const std::vector<NeuronId> N51::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD9 = {{49}};
	const std::vector<NeuronId> N51::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD11 = {{17}};
	const std::vector<NeuronId> N51::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD13 = {{29}};
	const std::vector<NeuronId> N51::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD15 = {{2}};
	const std::vector<NeuronId> N51::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N51::incommingNeuronsD17 = {{79}};
	const std::vector<NeuronId> N51::incommingNeuronsD18 = {{50}};
	const std::vector<NeuronId> N51::incommingNeuronsD19 = {{}};
	struct N52 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N52::incommingNeuronsD0;
				case 1: return N52::incommingNeuronsD1;
				case 2: return N52::incommingNeuronsD2;
				case 3: return N52::incommingNeuronsD3;
				case 4: return N52::incommingNeuronsD4;
				case 5: return N52::incommingNeuronsD5;
				case 6: return N52::incommingNeuronsD6;
				case 7: return N52::incommingNeuronsD7;
				case 8: return N52::incommingNeuronsD8;
				case 9: return N52::incommingNeuronsD9;
				case 10: return N52::incommingNeuronsD10;
				case 11: return N52::incommingNeuronsD11;
				case 12: return N52::incommingNeuronsD12;
				case 13: return N52::incommingNeuronsD13;
				case 14: return N52::incommingNeuronsD14;
				case 15: return N52::incommingNeuronsD15;
				case 16: return N52::incommingNeuronsD16;
				case 17: return N52::incommingNeuronsD17;
				case 18: return N52::incommingNeuronsD18;
				case 19: return N52::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{26,48,78,3,72,16,33,2,19,89,59,79,99,11,73,77,31,66,67,41}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(52);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N52::incommingNeuronsD0 = {{85,92,93,94,97}};
	const std::vector<NeuronId> N52::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD2 = {{21,48,66,79}};
	const std::vector<NeuronId> N52::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD5 = {{3}};
	const std::vector<NeuronId> N52::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD7 = {{67,68}};
	const std::vector<NeuronId> N52::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD10 = {{13,54}};
	const std::vector<NeuronId> N52::incommingNeuronsD11 = {{77}};
	const std::vector<NeuronId> N52::incommingNeuronsD12 = {{16,28}};
	const std::vector<NeuronId> N52::incommingNeuronsD13 = {{69}};
	const std::vector<NeuronId> N52::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD15 = {{73}};
	const std::vector<NeuronId> N52::incommingNeuronsD16 = {{10,50}};
	const std::vector<NeuronId> N52::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N52::incommingNeuronsD18 = {{72}};
	const std::vector<NeuronId> N52::incommingNeuronsD19 = {{}};
	struct N53 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N53::incommingNeuronsD0;
				case 1: return N53::incommingNeuronsD1;
				case 2: return N53::incommingNeuronsD2;
				case 3: return N53::incommingNeuronsD3;
				case 4: return N53::incommingNeuronsD4;
				case 5: return N53::incommingNeuronsD5;
				case 6: return N53::incommingNeuronsD6;
				case 7: return N53::incommingNeuronsD7;
				case 8: return N53::incommingNeuronsD8;
				case 9: return N53::incommingNeuronsD9;
				case 10: return N53::incommingNeuronsD10;
				case 11: return N53::incommingNeuronsD11;
				case 12: return N53::incommingNeuronsD12;
				case 13: return N53::incommingNeuronsD13;
				case 14: return N53::incommingNeuronsD14;
				case 15: return N53::incommingNeuronsD15;
				case 16: return N53::incommingNeuronsD16;
				case 17: return N53::incommingNeuronsD17;
				case 18: return N53::incommingNeuronsD18;
				case 19: return N53::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{49,24,96,28,37,19,45,51,56,92,16,66,14,79,65,72,41,77,32,83}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(53);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N53::incommingNeuronsD0 = {{16,30,48,83,85,87,88,94}};
	const std::vector<NeuronId> N53::incommingNeuronsD1 = {{74}};
	const std::vector<NeuronId> N53::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD3 = {{18}};
	const std::vector<NeuronId> N53::incommingNeuronsD4 = {{14,45}};
	const std::vector<NeuronId> N53::incommingNeuronsD5 = {{32}};
	const std::vector<NeuronId> N53::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD7 = {{20,46,57,62}};
	const std::vector<NeuronId> N53::incommingNeuronsD8 = {{10,12}};
	const std::vector<NeuronId> N53::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD10 = {{15,76}};
	const std::vector<NeuronId> N53::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD16 = {{72}};
	const std::vector<NeuronId> N53::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N53::incommingNeuronsD18 = {{29}};
	const std::vector<NeuronId> N53::incommingNeuronsD19 = {{9}};
	struct N54 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N54::incommingNeuronsD0;
				case 1: return N54::incommingNeuronsD1;
				case 2: return N54::incommingNeuronsD2;
				case 3: return N54::incommingNeuronsD3;
				case 4: return N54::incommingNeuronsD4;
				case 5: return N54::incommingNeuronsD5;
				case 6: return N54::incommingNeuronsD6;
				case 7: return N54::incommingNeuronsD7;
				case 8: return N54::incommingNeuronsD8;
				case 9: return N54::incommingNeuronsD9;
				case 10: return N54::incommingNeuronsD10;
				case 11: return N54::incommingNeuronsD11;
				case 12: return N54::incommingNeuronsD12;
				case 13: return N54::incommingNeuronsD13;
				case 14: return N54::incommingNeuronsD14;
				case 15: return N54::incommingNeuronsD15;
				case 16: return N54::incommingNeuronsD16;
				case 17: return N54::incommingNeuronsD17;
				case 18: return N54::incommingNeuronsD18;
				case 19: return N54::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{20,6,75,44,87,60,41,30,59,0,52,92,63,80,99,65,95,57,8,70}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(54);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N54::incommingNeuronsD0 = {{82,83,85,86,92,93,99}};
	const std::vector<NeuronId> N54::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N54::incommingNeuronsD2 = {{41,43}};
	const std::vector<NeuronId> N54::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N54::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N54::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N54::incommingNeuronsD6 = {{73}};
	const std::vector<NeuronId> N54::incommingNeuronsD7 = {{44}};
	const std::vector<NeuronId> N54::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N54::incommingNeuronsD9 = {{19}};
	const std::vector<NeuronId> N54::incommingNeuronsD10 = {{18}};
	const std::vector<NeuronId> N54::incommingNeuronsD11 = {{13,34,51,58}};
	const std::vector<NeuronId> N54::incommingNeuronsD12 = {{69}};
	const std::vector<NeuronId> N54::incommingNeuronsD13 = {{49}};
	const std::vector<NeuronId> N54::incommingNeuronsD14 = {{31,76}};
	const std::vector<NeuronId> N54::incommingNeuronsD15 = {{35,75}};
	const std::vector<NeuronId> N54::incommingNeuronsD16 = {{55}};
	const std::vector<NeuronId> N54::incommingNeuronsD17 = {{67}};
	const std::vector<NeuronId> N54::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N54::incommingNeuronsD19 = {{2}};
	struct N55 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N55::incommingNeuronsD0;
				case 1: return N55::incommingNeuronsD1;
				case 2: return N55::incommingNeuronsD2;
				case 3: return N55::incommingNeuronsD3;
				case 4: return N55::incommingNeuronsD4;
				case 5: return N55::incommingNeuronsD5;
				case 6: return N55::incommingNeuronsD6;
				case 7: return N55::incommingNeuronsD7;
				case 8: return N55::incommingNeuronsD8;
				case 9: return N55::incommingNeuronsD9;
				case 10: return N55::incommingNeuronsD10;
				case 11: return N55::incommingNeuronsD11;
				case 12: return N55::incommingNeuronsD12;
				case 13: return N55::incommingNeuronsD13;
				case 14: return N55::incommingNeuronsD14;
				case 15: return N55::incommingNeuronsD15;
				case 16: return N55::incommingNeuronsD16;
				case 17: return N55::incommingNeuronsD17;
				case 18: return N55::incommingNeuronsD18;
				case 19: return N55::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{22,4,82,9,26,23,11,35,47,68,58,99,37,66,27,80,54,19,89,38}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(55);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N55::incommingNeuronsD0 = {{51,80,82}};
	const std::vector<NeuronId> N55::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD4 = {{49,67}};
	const std::vector<NeuronId> N55::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD6 = {{43}};
	const std::vector<NeuronId> N55::incommingNeuronsD7 = {{13,36,48}};
	const std::vector<NeuronId> N55::incommingNeuronsD8 = {{45}};
	const std::vector<NeuronId> N55::incommingNeuronsD9 = {{34,56}};
	const std::vector<NeuronId> N55::incommingNeuronsD10 = {{42}};
	const std::vector<NeuronId> N55::incommingNeuronsD11 = {{68}};
	const std::vector<NeuronId> N55::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N55::incommingNeuronsD19 = {{}};
	struct N56 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N56::incommingNeuronsD0;
				case 1: return N56::incommingNeuronsD1;
				case 2: return N56::incommingNeuronsD2;
				case 3: return N56::incommingNeuronsD3;
				case 4: return N56::incommingNeuronsD4;
				case 5: return N56::incommingNeuronsD5;
				case 6: return N56::incommingNeuronsD6;
				case 7: return N56::incommingNeuronsD7;
				case 8: return N56::incommingNeuronsD8;
				case 9: return N56::incommingNeuronsD9;
				case 10: return N56::incommingNeuronsD10;
				case 11: return N56::incommingNeuronsD11;
				case 12: return N56::incommingNeuronsD12;
				case 13: return N56::incommingNeuronsD13;
				case 14: return N56::incommingNeuronsD14;
				case 15: return N56::incommingNeuronsD15;
				case 16: return N56::incommingNeuronsD16;
				case 17: return N56::incommingNeuronsD17;
				case 18: return N56::incommingNeuronsD18;
				case 19: return N56::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{33,42,37,63,69,25,6,95,15,55,8,83,27,67,82,16,81,74,78,36}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(56);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N56::incommingNeuronsD0 = {{90,91,98}};
	const std::vector<NeuronId> N56::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD2 = {{32}};
	const std::vector<NeuronId> N56::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD6 = {{34}};
	const std::vector<NeuronId> N56::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD8 = {{31,53}};
	const std::vector<NeuronId> N56::incommingNeuronsD9 = {{44}};
	const std::vector<NeuronId> N56::incommingNeuronsD10 = {{26}};
	const std::vector<NeuronId> N56::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N56::incommingNeuronsD15 = {{4,43,68}};
	const std::vector<NeuronId> N56::incommingNeuronsD16 = {{27}};
	const std::vector<NeuronId> N56::incommingNeuronsD17 = {{73,77}};
	const std::vector<NeuronId> N56::incommingNeuronsD18 = {{7,69}};
	const std::vector<NeuronId> N56::incommingNeuronsD19 = {{3}};
	struct N57 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N57::incommingNeuronsD0;
				case 1: return N57::incommingNeuronsD1;
				case 2: return N57::incommingNeuronsD2;
				case 3: return N57::incommingNeuronsD3;
				case 4: return N57::incommingNeuronsD4;
				case 5: return N57::incommingNeuronsD5;
				case 6: return N57::incommingNeuronsD6;
				case 7: return N57::incommingNeuronsD7;
				case 8: return N57::incommingNeuronsD8;
				case 9: return N57::incommingNeuronsD9;
				case 10: return N57::incommingNeuronsD10;
				case 11: return N57::incommingNeuronsD11;
				case 12: return N57::incommingNeuronsD12;
				case 13: return N57::incommingNeuronsD13;
				case 14: return N57::incommingNeuronsD14;
				case 15: return N57::incommingNeuronsD15;
				case 16: return N57::incommingNeuronsD16;
				case 17: return N57::incommingNeuronsD17;
				case 18: return N57::incommingNeuronsD18;
				case 19: return N57::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{32,7,23,86,77,82,51,53,17,41,15,42,13,5,78,99,4,60,34,72}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(57);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N57::incommingNeuronsD0 = {{10,14,22,85,93,96}};
	const std::vector<NeuronId> N57::incommingNeuronsD1 = {{34}};
	const std::vector<NeuronId> N57::incommingNeuronsD2 = {{17}};
	const std::vector<NeuronId> N57::incommingNeuronsD3 = {{75}};
	const std::vector<NeuronId> N57::incommingNeuronsD4 = {{28,65}};
	const std::vector<NeuronId> N57::incommingNeuronsD5 = {{29,46}};
	const std::vector<NeuronId> N57::incommingNeuronsD6 = {{25}};
	const std::vector<NeuronId> N57::incommingNeuronsD7 = {{2,19}};
	const std::vector<NeuronId> N57::incommingNeuronsD8 = {{73}};
	const std::vector<NeuronId> N57::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N57::incommingNeuronsD10 = {{78}};
	const std::vector<NeuronId> N57::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N57::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N57::incommingNeuronsD13 = {{71}};
	const std::vector<NeuronId> N57::incommingNeuronsD14 = {{3}};
	const std::vector<NeuronId> N57::incommingNeuronsD15 = {{60}};
	const std::vector<NeuronId> N57::incommingNeuronsD16 = {{48}};
	const std::vector<NeuronId> N57::incommingNeuronsD17 = {{54}};
	const std::vector<NeuronId> N57::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N57::incommingNeuronsD19 = {{24}};
	struct N58 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N58::incommingNeuronsD0;
				case 1: return N58::incommingNeuronsD1;
				case 2: return N58::incommingNeuronsD2;
				case 3: return N58::incommingNeuronsD3;
				case 4: return N58::incommingNeuronsD4;
				case 5: return N58::incommingNeuronsD5;
				case 6: return N58::incommingNeuronsD6;
				case 7: return N58::incommingNeuronsD7;
				case 8: return N58::incommingNeuronsD8;
				case 9: return N58::incommingNeuronsD9;
				case 10: return N58::incommingNeuronsD10;
				case 11: return N58::incommingNeuronsD11;
				case 12: return N58::incommingNeuronsD12;
				case 13: return N58::incommingNeuronsD13;
				case 14: return N58::incommingNeuronsD14;
				case 15: return N58::incommingNeuronsD15;
				case 16: return N58::incommingNeuronsD16;
				case 17: return N58::incommingNeuronsD17;
				case 18: return N58::incommingNeuronsD18;
				case 19: return N58::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{47,0,8,77,63,74,51,1,79,66,29,54,73,20,19,99,6,38,23,2}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(58);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N58::incommingNeuronsD0 = {{43,75,86,89,90,91,96}};
	const std::vector<NeuronId> N58::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD2 = {{34}};
	const std::vector<NeuronId> N58::incommingNeuronsD3 = {{50,70}};
	const std::vector<NeuronId> N58::incommingNeuronsD4 = {{64}};
	const std::vector<NeuronId> N58::incommingNeuronsD5 = {{61}};
	const std::vector<NeuronId> N58::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD7 = {{8}};
	const std::vector<NeuronId> N58::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD9 = {{41,46,67}};
	const std::vector<NeuronId> N58::incommingNeuronsD10 = {{55}};
	const std::vector<NeuronId> N58::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD12 = {{20}};
	const std::vector<NeuronId> N58::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD15 = {{16,39}};
	const std::vector<NeuronId> N58::incommingNeuronsD16 = {{63}};
	const std::vector<NeuronId> N58::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N58::incommingNeuronsD18 = {{3,18}};
	const std::vector<NeuronId> N58::incommingNeuronsD19 = {{}};
	struct N59 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N59::incommingNeuronsD0;
				case 1: return N59::incommingNeuronsD1;
				case 2: return N59::incommingNeuronsD2;
				case 3: return N59::incommingNeuronsD3;
				case 4: return N59::incommingNeuronsD4;
				case 5: return N59::incommingNeuronsD5;
				case 6: return N59::incommingNeuronsD6;
				case 7: return N59::incommingNeuronsD7;
				case 8: return N59::incommingNeuronsD8;
				case 9: return N59::incommingNeuronsD9;
				case 10: return N59::incommingNeuronsD10;
				case 11: return N59::incommingNeuronsD11;
				case 12: return N59::incommingNeuronsD12;
				case 13: return N59::incommingNeuronsD13;
				case 14: return N59::incommingNeuronsD14;
				case 15: return N59::incommingNeuronsD15;
				case 16: return N59::incommingNeuronsD16;
				case 17: return N59::incommingNeuronsD17;
				case 18: return N59::incommingNeuronsD18;
				case 19: return N59::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{23,81,76,18,70,46,1,64,34,95,42,19,30,96,45,24,33,68,17,67}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(59);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N59::incommingNeuronsD0 = {{74,81,86,94,95}};
	const std::vector<NeuronId> N59::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD2 = {{73}};
	const std::vector<NeuronId> N59::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD6 = {{22}};
	const std::vector<NeuronId> N59::incommingNeuronsD7 = {{24,38}};
	const std::vector<NeuronId> N59::incommingNeuronsD8 = {{54}};
	const std::vector<NeuronId> N59::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD10 = {{0,52}};
	const std::vector<NeuronId> N59::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD12 = {{27}};
	const std::vector<NeuronId> N59::incommingNeuronsD13 = {{16}};
	const std::vector<NeuronId> N59::incommingNeuronsD14 = {{47}};
	const std::vector<NeuronId> N59::incommingNeuronsD15 = {{26}};
	const std::vector<NeuronId> N59::incommingNeuronsD16 = {{31,43,44}};
	const std::vector<NeuronId> N59::incommingNeuronsD17 = {{18,41}};
	const std::vector<NeuronId> N59::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N59::incommingNeuronsD19 = {{61}};
	struct N60 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N60::incommingNeuronsD0;
				case 1: return N60::incommingNeuronsD1;
				case 2: return N60::incommingNeuronsD2;
				case 3: return N60::incommingNeuronsD3;
				case 4: return N60::incommingNeuronsD4;
				case 5: return N60::incommingNeuronsD5;
				case 6: return N60::incommingNeuronsD6;
				case 7: return N60::incommingNeuronsD7;
				case 8: return N60::incommingNeuronsD8;
				case 9: return N60::incommingNeuronsD9;
				case 10: return N60::incommingNeuronsD10;
				case 11: return N60::incommingNeuronsD11;
				case 12: return N60::incommingNeuronsD12;
				case 13: return N60::incommingNeuronsD13;
				case 14: return N60::incommingNeuronsD14;
				case 15: return N60::incommingNeuronsD15;
				case 16: return N60::incommingNeuronsD16;
				case 17: return N60::incommingNeuronsD17;
				case 18: return N60::incommingNeuronsD18;
				case 19: return N60::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{72,39,91,92,85,93,36,89,88,79,43,4,99,12,25,57,94,47,83,16}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(60);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N60::incommingNeuronsD0 = {{32,82,84,88,89,92,94,95,97}};
	const std::vector<NeuronId> N60::incommingNeuronsD1 = {{4}};
	const std::vector<NeuronId> N60::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD4 = {{79}};
	const std::vector<NeuronId> N60::incommingNeuronsD5 = {{31,33,54}};
	const std::vector<NeuronId> N60::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD8 = {{2,72}};
	const std::vector<NeuronId> N60::incommingNeuronsD9 = {{35}};
	const std::vector<NeuronId> N60::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD17 = {{23,57}};
	const std::vector<NeuronId> N60::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N60::incommingNeuronsD19 = {{10}};
	struct N61 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N61::incommingNeuronsD0;
				case 1: return N61::incommingNeuronsD1;
				case 2: return N61::incommingNeuronsD2;
				case 3: return N61::incommingNeuronsD3;
				case 4: return N61::incommingNeuronsD4;
				case 5: return N61::incommingNeuronsD5;
				case 6: return N61::incommingNeuronsD6;
				case 7: return N61::incommingNeuronsD7;
				case 8: return N61::incommingNeuronsD8;
				case 9: return N61::incommingNeuronsD9;
				case 10: return N61::incommingNeuronsD10;
				case 11: return N61::incommingNeuronsD11;
				case 12: return N61::incommingNeuronsD12;
				case 13: return N61::incommingNeuronsD13;
				case 14: return N61::incommingNeuronsD14;
				case 15: return N61::incommingNeuronsD15;
				case 16: return N61::incommingNeuronsD16;
				case 17: return N61::incommingNeuronsD17;
				case 18: return N61::incommingNeuronsD18;
				case 19: return N61::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{13,42,63,23,70,58,98,21,34,87,36,20,48,72,71,19,66,44,97,59}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(61);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N61::incommingNeuronsD0 = {{39,89,91,93,99}};
	const std::vector<NeuronId> N61::incommingNeuronsD1 = {{32}};
	const std::vector<NeuronId> N61::incommingNeuronsD2 = {{10}};
	const std::vector<NeuronId> N61::incommingNeuronsD3 = {{23}};
	const std::vector<NeuronId> N61::incommingNeuronsD4 = {{15}};
	const std::vector<NeuronId> N61::incommingNeuronsD5 = {{64}};
	const std::vector<NeuronId> N61::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD7 = {{69}};
	const std::vector<NeuronId> N61::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD12 = {{6,8,72}};
	const std::vector<NeuronId> N61::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD14 = {{49}};
	const std::vector<NeuronId> N61::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD16 = {{13,33,71}};
	const std::vector<NeuronId> N61::incommingNeuronsD17 = {{17}};
	const std::vector<NeuronId> N61::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N61::incommingNeuronsD19 = {{18,75}};
	struct N62 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N62::incommingNeuronsD0;
				case 1: return N62::incommingNeuronsD1;
				case 2: return N62::incommingNeuronsD2;
				case 3: return N62::incommingNeuronsD3;
				case 4: return N62::incommingNeuronsD4;
				case 5: return N62::incommingNeuronsD5;
				case 6: return N62::incommingNeuronsD6;
				case 7: return N62::incommingNeuronsD7;
				case 8: return N62::incommingNeuronsD8;
				case 9: return N62::incommingNeuronsD9;
				case 10: return N62::incommingNeuronsD10;
				case 11: return N62::incommingNeuronsD11;
				case 12: return N62::incommingNeuronsD12;
				case 13: return N62::incommingNeuronsD13;
				case 14: return N62::incommingNeuronsD14;
				case 15: return N62::incommingNeuronsD15;
				case 16: return N62::incommingNeuronsD16;
				case 17: return N62::incommingNeuronsD17;
				case 18: return N62::incommingNeuronsD18;
				case 19: return N62::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{94,85,78,49,71,40,72,53,41,73,30,2,88,28,20,11,27,44,67,87}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(62);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N62::incommingNeuronsD0 = {{81,86,88,90,92,93,96,98}};
	const std::vector<NeuronId> N62::incommingNeuronsD1 = {{45}};
	const std::vector<NeuronId> N62::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD4 = {{77}};
	const std::vector<NeuronId> N62::incommingNeuronsD5 = {{78}};
	const std::vector<NeuronId> N62::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD7 = {{47}};
	const std::vector<NeuronId> N62::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD13 = {{13}};
	const std::vector<NeuronId> N62::incommingNeuronsD14 = {{27}};
	const std::vector<NeuronId> N62::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N62::incommingNeuronsD17 = {{44,74}};
	const std::vector<NeuronId> N62::incommingNeuronsD18 = {{2,11}};
	const std::vector<NeuronId> N62::incommingNeuronsD19 = {{}};
	struct N63 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N63::incommingNeuronsD0;
				case 1: return N63::incommingNeuronsD1;
				case 2: return N63::incommingNeuronsD2;
				case 3: return N63::incommingNeuronsD3;
				case 4: return N63::incommingNeuronsD4;
				case 5: return N63::incommingNeuronsD5;
				case 6: return N63::incommingNeuronsD6;
				case 7: return N63::incommingNeuronsD7;
				case 8: return N63::incommingNeuronsD8;
				case 9: return N63::incommingNeuronsD9;
				case 10: return N63::incommingNeuronsD10;
				case 11: return N63::incommingNeuronsD11;
				case 12: return N63::incommingNeuronsD12;
				case 13: return N63::incommingNeuronsD13;
				case 14: return N63::incommingNeuronsD14;
				case 15: return N63::incommingNeuronsD15;
				case 16: return N63::incommingNeuronsD16;
				case 17: return N63::incommingNeuronsD17;
				case 18: return N63::incommingNeuronsD18;
				case 19: return N63::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{18,17,81,38,79,26,40,29,19,36,89,5,25,14,99,35,58,0,82,85}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(63);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N63::incommingNeuronsD0 = {{11,82,83,89,91,94,96,99}};
	const std::vector<NeuronId> N63::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD2 = {{61}};
	const std::vector<NeuronId> N63::incommingNeuronsD3 = {{56}};
	const std::vector<NeuronId> N63::incommingNeuronsD4 = {{17,58}};
	const std::vector<NeuronId> N63::incommingNeuronsD5 = {{69}};
	const std::vector<NeuronId> N63::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD7 = {{66}};
	const std::vector<NeuronId> N63::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD10 = {{5}};
	const std::vector<NeuronId> N63::incommingNeuronsD11 = {{6}};
	const std::vector<NeuronId> N63::incommingNeuronsD12 = {{54}};
	const std::vector<NeuronId> N63::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD15 = {{1,27}};
	const std::vector<NeuronId> N63::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N63::incommingNeuronsD18 = {{31}};
	const std::vector<NeuronId> N63::incommingNeuronsD19 = {{70,79}};
	struct N64 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N64::incommingNeuronsD0;
				case 1: return N64::incommingNeuronsD1;
				case 2: return N64::incommingNeuronsD2;
				case 3: return N64::incommingNeuronsD3;
				case 4: return N64::incommingNeuronsD4;
				case 5: return N64::incommingNeuronsD5;
				case 6: return N64::incommingNeuronsD6;
				case 7: return N64::incommingNeuronsD7;
				case 8: return N64::incommingNeuronsD8;
				case 9: return N64::incommingNeuronsD9;
				case 10: return N64::incommingNeuronsD10;
				case 11: return N64::incommingNeuronsD11;
				case 12: return N64::incommingNeuronsD12;
				case 13: return N64::incommingNeuronsD13;
				case 14: return N64::incommingNeuronsD14;
				case 15: return N64::incommingNeuronsD15;
				case 16: return N64::incommingNeuronsD16;
				case 17: return N64::incommingNeuronsD17;
				case 18: return N64::incommingNeuronsD18;
				case 19: return N64::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{18,74,27,76,58,61,11,81,14,13,12,44,77,84,40,92,25,26,69,16}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(64);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N64::incommingNeuronsD0 = {{86,91,94,96}};
	const std::vector<NeuronId> N64::incommingNeuronsD1 = {{0,14}};
	const std::vector<NeuronId> N64::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD3 = {{17}};
	const std::vector<NeuronId> N64::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD5 = {{72}};
	const std::vector<NeuronId> N64::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD7 = {{59}};
	const std::vector<NeuronId> N64::incommingNeuronsD8 = {{4,40}};
	const std::vector<NeuronId> N64::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD11 = {{71}};
	const std::vector<NeuronId> N64::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD13 = {{65}};
	const std::vector<NeuronId> N64::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD17 = {{39,66}};
	const std::vector<NeuronId> N64::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N64::incommingNeuronsD19 = {{}};
	struct N65 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N65::incommingNeuronsD0;
				case 1: return N65::incommingNeuronsD1;
				case 2: return N65::incommingNeuronsD2;
				case 3: return N65::incommingNeuronsD3;
				case 4: return N65::incommingNeuronsD4;
				case 5: return N65::incommingNeuronsD5;
				case 6: return N65::incommingNeuronsD6;
				case 7: return N65::incommingNeuronsD7;
				case 8: return N65::incommingNeuronsD8;
				case 9: return N65::incommingNeuronsD9;
				case 10: return N65::incommingNeuronsD10;
				case 11: return N65::incommingNeuronsD11;
				case 12: return N65::incommingNeuronsD12;
				case 13: return N65::incommingNeuronsD13;
				case 14: return N65::incommingNeuronsD14;
				case 15: return N65::incommingNeuronsD15;
				case 16: return N65::incommingNeuronsD16;
				case 17: return N65::incommingNeuronsD17;
				case 18: return N65::incommingNeuronsD18;
				case 19: return N65::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{2,98,78,15,57,48,49,76,79,90,37,14,31,64,34,92,3,43,47,72}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(65);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N65::incommingNeuronsD0 = {{82,83,90,93,95,96,99}};
	const std::vector<NeuronId> N65::incommingNeuronsD1 = {{72}};
	const std::vector<NeuronId> N65::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD4 = {{11}};
	const std::vector<NeuronId> N65::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD10 = {{20,45}};
	const std::vector<NeuronId> N65::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N65::incommingNeuronsD13 = {{30}};
	const std::vector<NeuronId> N65::incommingNeuronsD14 = {{53}};
	const std::vector<NeuronId> N65::incommingNeuronsD15 = {{54}};
	const std::vector<NeuronId> N65::incommingNeuronsD16 = {{24,77}};
	const std::vector<NeuronId> N65::incommingNeuronsD17 = {{14}};
	const std::vector<NeuronId> N65::incommingNeuronsD18 = {{36,79}};
	const std::vector<NeuronId> N65::incommingNeuronsD19 = {{40}};
	struct N66 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N66::incommingNeuronsD0;
				case 1: return N66::incommingNeuronsD1;
				case 2: return N66::incommingNeuronsD2;
				case 3: return N66::incommingNeuronsD3;
				case 4: return N66::incommingNeuronsD4;
				case 5: return N66::incommingNeuronsD5;
				case 6: return N66::incommingNeuronsD6;
				case 7: return N66::incommingNeuronsD7;
				case 8: return N66::incommingNeuronsD8;
				case 9: return N66::incommingNeuronsD9;
				case 10: return N66::incommingNeuronsD10;
				case 11: return N66::incommingNeuronsD11;
				case 12: return N66::incommingNeuronsD12;
				case 13: return N66::incommingNeuronsD13;
				case 14: return N66::incommingNeuronsD14;
				case 15: return N66::incommingNeuronsD15;
				case 16: return N66::incommingNeuronsD16;
				case 17: return N66::incommingNeuronsD17;
				case 18: return N66::incommingNeuronsD18;
				case 19: return N66::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{83,76,52,10,38,86,92,63,67,49,40,45,11,5,90,89,39,64,84,69}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(66);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N66::incommingNeuronsD0 = {{83,95,96,98}};
	const std::vector<NeuronId> N66::incommingNeuronsD1 = {{30}};
	const std::vector<NeuronId> N66::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N66::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N66::incommingNeuronsD4 = {{68}};
	const std::vector<NeuronId> N66::incommingNeuronsD5 = {{26,42,76}};
	const std::vector<NeuronId> N66::incommingNeuronsD6 = {{47}};
	const std::vector<NeuronId> N66::incommingNeuronsD7 = {{34,72}};
	const std::vector<NeuronId> N66::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N66::incommingNeuronsD9 = {{43,58}};
	const std::vector<NeuronId> N66::incommingNeuronsD10 = {{32,37}};
	const std::vector<NeuronId> N66::incommingNeuronsD11 = {{53}};
	const std::vector<NeuronId> N66::incommingNeuronsD12 = {{74}};
	const std::vector<NeuronId> N66::incommingNeuronsD13 = {{55}};
	const std::vector<NeuronId> N66::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N66::incommingNeuronsD15 = {{0}};
	const std::vector<NeuronId> N66::incommingNeuronsD16 = {{61}};
	const std::vector<NeuronId> N66::incommingNeuronsD17 = {{50,52}};
	const std::vector<NeuronId> N66::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N66::incommingNeuronsD19 = {{13,38}};
	struct N67 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N67::incommingNeuronsD0;
				case 1: return N67::incommingNeuronsD1;
				case 2: return N67::incommingNeuronsD2;
				case 3: return N67::incommingNeuronsD3;
				case 4: return N67::incommingNeuronsD4;
				case 5: return N67::incommingNeuronsD5;
				case 6: return N67::incommingNeuronsD6;
				case 7: return N67::incommingNeuronsD7;
				case 8: return N67::incommingNeuronsD8;
				case 9: return N67::incommingNeuronsD9;
				case 10: return N67::incommingNeuronsD10;
				case 11: return N67::incommingNeuronsD11;
				case 12: return N67::incommingNeuronsD12;
				case 13: return N67::incommingNeuronsD13;
				case 14: return N67::incommingNeuronsD14;
				case 15: return N67::incommingNeuronsD15;
				case 16: return N67::incommingNeuronsD16;
				case 17: return N67::incommingNeuronsD17;
				case 18: return N67::incommingNeuronsD18;
				case 19: return N67::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{73,70,46,99,55,29,71,52,36,58,43,7,11,90,42,47,15,54,80,27}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(67);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N67::incommingNeuronsD0 = {{29,82,87,88,94,95,97}};
	const std::vector<NeuronId> N67::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD2 = {{24,30}};
	const std::vector<NeuronId> N67::incommingNeuronsD3 = {{31}};
	const std::vector<NeuronId> N67::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD8 = {{66}};
	const std::vector<NeuronId> N67::incommingNeuronsD9 = {{16,23,28}};
	const std::vector<NeuronId> N67::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD11 = {{25}};
	const std::vector<NeuronId> N67::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD13 = {{56}};
	const std::vector<NeuronId> N67::incommingNeuronsD14 = {{14}};
	const std::vector<NeuronId> N67::incommingNeuronsD15 = {{44}};
	const std::vector<NeuronId> N67::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N67::incommingNeuronsD17 = {{2,11,45}};
	const std::vector<NeuronId> N67::incommingNeuronsD18 = {{52,62,76}};
	const std::vector<NeuronId> N67::incommingNeuronsD19 = {{48,59,71}};
	struct N68 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N68::incommingNeuronsD0;
				case 1: return N68::incommingNeuronsD1;
				case 2: return N68::incommingNeuronsD2;
				case 3: return N68::incommingNeuronsD3;
				case 4: return N68::incommingNeuronsD4;
				case 5: return N68::incommingNeuronsD5;
				case 6: return N68::incommingNeuronsD6;
				case 7: return N68::incommingNeuronsD7;
				case 8: return N68::incommingNeuronsD8;
				case 9: return N68::incommingNeuronsD9;
				case 10: return N68::incommingNeuronsD10;
				case 11: return N68::incommingNeuronsD11;
				case 12: return N68::incommingNeuronsD12;
				case 13: return N68::incommingNeuronsD13;
				case 14: return N68::incommingNeuronsD14;
				case 15: return N68::incommingNeuronsD15;
				case 16: return N68::incommingNeuronsD16;
				case 17: return N68::incommingNeuronsD17;
				case 18: return N68::incommingNeuronsD18;
				case 19: return N68::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{7,44,0,69,66,50,82,52,19,99,75,55,97,72,87,56,43,39,10,33}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(68);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N68::incommingNeuronsD0 = {{72,82,83,86,90,99}};
	const std::vector<NeuronId> N68::incommingNeuronsD1 = {{20,38}};
	const std::vector<NeuronId> N68::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD3 = {{8}};
	const std::vector<NeuronId> N68::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD5 = {{14,30}};
	const std::vector<NeuronId> N68::incommingNeuronsD6 = {{4,10}};
	const std::vector<NeuronId> N68::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD8 = {{1}};
	const std::vector<NeuronId> N68::incommingNeuronsD9 = {{5,55}};
	const std::vector<NeuronId> N68::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD11 = {{22,27,32}};
	const std::vector<NeuronId> N68::incommingNeuronsD12 = {{78}};
	const std::vector<NeuronId> N68::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N68::incommingNeuronsD16 = {{29}};
	const std::vector<NeuronId> N68::incommingNeuronsD17 = {{59}};
	const std::vector<NeuronId> N68::incommingNeuronsD18 = {{23}};
	const std::vector<NeuronId> N68::incommingNeuronsD19 = {{47}};
	struct N69 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N69::incommingNeuronsD0;
				case 1: return N69::incommingNeuronsD1;
				case 2: return N69::incommingNeuronsD2;
				case 3: return N69::incommingNeuronsD3;
				case 4: return N69::incommingNeuronsD4;
				case 5: return N69::incommingNeuronsD5;
				case 6: return N69::incommingNeuronsD6;
				case 7: return N69::incommingNeuronsD7;
				case 8: return N69::incommingNeuronsD8;
				case 9: return N69::incommingNeuronsD9;
				case 10: return N69::incommingNeuronsD10;
				case 11: return N69::incommingNeuronsD11;
				case 12: return N69::incommingNeuronsD12;
				case 13: return N69::incommingNeuronsD13;
				case 14: return N69::incommingNeuronsD14;
				case 15: return N69::incommingNeuronsD15;
				case 16: return N69::incommingNeuronsD16;
				case 17: return N69::incommingNeuronsD17;
				case 18: return N69::incommingNeuronsD18;
				case 19: return N69::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{93,26,35,15,27,63,94,61,79,73,74,39,54,52,24,40,37,49,56,80}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(69);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N69::incommingNeuronsD0 = {{83,87,88,89,98}};
	const std::vector<NeuronId> N69::incommingNeuronsD1 = {{27}};
	const std::vector<NeuronId> N69::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD3 = {{68,73,74}};
	const std::vector<NeuronId> N69::incommingNeuronsD4 = {{25,56,72}};
	const std::vector<NeuronId> N69::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD7 = {{1,16}};
	const std::vector<NeuronId> N69::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD9 = {{78}};
	const std::vector<NeuronId> N69::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD13 = {{38}};
	const std::vector<NeuronId> N69::incommingNeuronsD14 = {{77}};
	const std::vector<NeuronId> N69::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD16 = {{19}};
	const std::vector<NeuronId> N69::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N69::incommingNeuronsD18 = {{8,51,64,70}};
	const std::vector<NeuronId> N69::incommingNeuronsD19 = {{66}};
	struct N70 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N70::incommingNeuronsD0;
				case 1: return N70::incommingNeuronsD1;
				case 2: return N70::incommingNeuronsD2;
				case 3: return N70::incommingNeuronsD3;
				case 4: return N70::incommingNeuronsD4;
				case 5: return N70::incommingNeuronsD5;
				case 6: return N70::incommingNeuronsD6;
				case 7: return N70::incommingNeuronsD7;
				case 8: return N70::incommingNeuronsD8;
				case 9: return N70::incommingNeuronsD9;
				case 10: return N70::incommingNeuronsD10;
				case 11: return N70::incommingNeuronsD11;
				case 12: return N70::incommingNeuronsD12;
				case 13: return N70::incommingNeuronsD13;
				case 14: return N70::incommingNeuronsD14;
				case 15: return N70::incommingNeuronsD15;
				case 16: return N70::incommingNeuronsD16;
				case 17: return N70::incommingNeuronsD17;
				case 18: return N70::incommingNeuronsD18;
				case 19: return N70::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{41,39,15,58,50,81,5,85,14,84,99,32,22,76,71,96,17,34,69,63}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(70);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N70::incommingNeuronsD0 = {{44,80,84,92,97,98}};
	const std::vector<NeuronId> N70::incommingNeuronsD1 = {{5,35,67}};
	const std::vector<NeuronId> N70::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD4 = {{59,61}};
	const std::vector<NeuronId> N70::incommingNeuronsD5 = {{73}};
	const std::vector<NeuronId> N70::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD7 = {{12}};
	const std::vector<NeuronId> N70::incommingNeuronsD8 = {{24,50}};
	const std::vector<NeuronId> N70::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD10 = {{36}};
	const std::vector<NeuronId> N70::incommingNeuronsD11 = {{1}};
	const std::vector<NeuronId> N70::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD17 = {{3,6,47}};
	const std::vector<NeuronId> N70::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N70::incommingNeuronsD19 = {{54}};
	struct N71 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N71::incommingNeuronsD0;
				case 1: return N71::incommingNeuronsD1;
				case 2: return N71::incommingNeuronsD2;
				case 3: return N71::incommingNeuronsD3;
				case 4: return N71::incommingNeuronsD4;
				case 5: return N71::incommingNeuronsD5;
				case 6: return N71::incommingNeuronsD6;
				case 7: return N71::incommingNeuronsD7;
				case 8: return N71::incommingNeuronsD8;
				case 9: return N71::incommingNeuronsD9;
				case 10: return N71::incommingNeuronsD10;
				case 11: return N71::incommingNeuronsD11;
				case 12: return N71::incommingNeuronsD12;
				case 13: return N71::incommingNeuronsD13;
				case 14: return N71::incommingNeuronsD14;
				case 15: return N71::incommingNeuronsD15;
				case 16: return N71::incommingNeuronsD16;
				case 17: return N71::incommingNeuronsD17;
				case 18: return N71::incommingNeuronsD18;
				case 19: return N71::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{74,37,83,46,81,2,8,96,24,82,25,64,49,57,79,18,61,43,20,67}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(71);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N71::incommingNeuronsD0 = {{73,82,84,87,93,94}};
	const std::vector<NeuronId> N71::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD4 = {{19,62}};
	const std::vector<NeuronId> N71::incommingNeuronsD5 = {{48}};
	const std::vector<NeuronId> N71::incommingNeuronsD6 = {{30,67}};
	const std::vector<NeuronId> N71::incommingNeuronsD7 = {{39}};
	const std::vector<NeuronId> N71::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD11 = {{33,42}};
	const std::vector<NeuronId> N71::incommingNeuronsD12 = {{17}};
	const std::vector<NeuronId> N71::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD14 = {{61,70}};
	const std::vector<NeuronId> N71::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N71::incommingNeuronsD17 = {{22}};
	const std::vector<NeuronId> N71::incommingNeuronsD18 = {{45}};
	const std::vector<NeuronId> N71::incommingNeuronsD19 = {{}};
	struct N72 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N72::incommingNeuronsD0;
				case 1: return N72::incommingNeuronsD1;
				case 2: return N72::incommingNeuronsD2;
				case 3: return N72::incommingNeuronsD3;
				case 4: return N72::incommingNeuronsD4;
				case 5: return N72::incommingNeuronsD5;
				case 6: return N72::incommingNeuronsD6;
				case 7: return N72::incommingNeuronsD7;
				case 8: return N72::incommingNeuronsD8;
				case 9: return N72::incommingNeuronsD9;
				case 10: return N72::incommingNeuronsD10;
				case 11: return N72::incommingNeuronsD11;
				case 12: return N72::incommingNeuronsD12;
				case 13: return N72::incommingNeuronsD13;
				case 14: return N72::incommingNeuronsD14;
				case 15: return N72::incommingNeuronsD15;
				case 16: return N72::incommingNeuronsD16;
				case 17: return N72::incommingNeuronsD17;
				case 18: return N72::incommingNeuronsD18;
				case 19: return N72::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{68,65,76,49,69,64,75,66,60,79,35,44,61,36,3,93,53,0,52,13}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(72);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N72::incommingNeuronsD0 = {{60,86,93,97,98}};
	const std::vector<NeuronId> N72::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD3 = {{34}};
	const std::vector<NeuronId> N72::incommingNeuronsD4 = {{52}};
	const std::vector<NeuronId> N72::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD6 = {{62}};
	const std::vector<NeuronId> N72::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD8 = {{0,17,46}};
	const std::vector<NeuronId> N72::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD10 = {{16}};
	const std::vector<NeuronId> N72::incommingNeuronsD11 = {{28,44}};
	const std::vector<NeuronId> N72::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD13 = {{61,68}};
	const std::vector<NeuronId> N72::incommingNeuronsD14 = {{79}};
	const std::vector<NeuronId> N72::incommingNeuronsD15 = {{53}};
	const std::vector<NeuronId> N72::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N72::incommingNeuronsD17 = {{38}};
	const std::vector<NeuronId> N72::incommingNeuronsD18 = {{42}};
	const std::vector<NeuronId> N72::incommingNeuronsD19 = {{57,65}};
	struct N73 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N73::incommingNeuronsD0;
				case 1: return N73::incommingNeuronsD1;
				case 2: return N73::incommingNeuronsD2;
				case 3: return N73::incommingNeuronsD3;
				case 4: return N73::incommingNeuronsD4;
				case 5: return N73::incommingNeuronsD5;
				case 6: return N73::incommingNeuronsD6;
				case 7: return N73::incommingNeuronsD7;
				case 8: return N73::incommingNeuronsD8;
				case 9: return N73::incommingNeuronsD9;
				case 10: return N73::incommingNeuronsD10;
				case 11: return N73::incommingNeuronsD11;
				case 12: return N73::incommingNeuronsD12;
				case 13: return N73::incommingNeuronsD13;
				case 14: return N73::incommingNeuronsD14;
				case 15: return N73::incommingNeuronsD15;
				case 16: return N73::incommingNeuronsD16;
				case 17: return N73::incommingNeuronsD17;
				case 18: return N73::incommingNeuronsD18;
				case 19: return N73::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{71,28,59,69,3,70,54,38,57,30,15,10,82,35,44,52,74,56,7,26}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(73);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N73::incommingNeuronsD0 = {{67,80,85,86}};
	const std::vector<NeuronId> N73::incommingNeuronsD1 = {{50,79}};
	const std::vector<NeuronId> N73::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD5 = {{6}};
	const std::vector<NeuronId> N73::incommingNeuronsD6 = {{9,36}};
	const std::vector<NeuronId> N73::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD9 = {{62,69}};
	const std::vector<NeuronId> N73::incommingNeuronsD10 = {{12}};
	const std::vector<NeuronId> N73::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD12 = {{58}};
	const std::vector<NeuronId> N73::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD14 = {{52}};
	const std::vector<NeuronId> N73::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD16 = {{5,45}};
	const std::vector<NeuronId> N73::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N73::incommingNeuronsD18 = {{17,22}};
	const std::vector<NeuronId> N73::incommingNeuronsD19 = {{35}};
	struct N74 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N74::incommingNeuronsD0;
				case 1: return N74::incommingNeuronsD1;
				case 2: return N74::incommingNeuronsD2;
				case 3: return N74::incommingNeuronsD3;
				case 4: return N74::incommingNeuronsD4;
				case 5: return N74::incommingNeuronsD5;
				case 6: return N74::incommingNeuronsD6;
				case 7: return N74::incommingNeuronsD7;
				case 8: return N74::incommingNeuronsD8;
				case 9: return N74::incommingNeuronsD9;
				case 10: return N74::incommingNeuronsD10;
				case 11: return N74::incommingNeuronsD11;
				case 12: return N74::incommingNeuronsD12;
				case 13: return N74::incommingNeuronsD13;
				case 14: return N74::incommingNeuronsD14;
				case 15: return N74::incommingNeuronsD15;
				case 16: return N74::incommingNeuronsD16;
				case 17: return N74::incommingNeuronsD17;
				case 18: return N74::incommingNeuronsD18;
				case 19: return N74::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{59,53,96,69,6,45,4,99,36,40,77,92,66,19,42,97,38,62,89,8}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(74);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N74::incommingNeuronsD0 = {{71,87,94,95}};
	const std::vector<NeuronId> N74::incommingNeuronsD1 = {{64}};
	const std::vector<NeuronId> N74::incommingNeuronsD2 = {{40,75}};
	const std::vector<NeuronId> N74::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD5 = {{58}};
	const std::vector<NeuronId> N74::incommingNeuronsD6 = {{35}};
	const std::vector<NeuronId> N74::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD8 = {{38}};
	const std::vector<NeuronId> N74::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD10 = {{48,69}};
	const std::vector<NeuronId> N74::incommingNeuronsD11 = {{16}};
	const std::vector<NeuronId> N74::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD14 = {{4,43}};
	const std::vector<NeuronId> N74::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N74::incommingNeuronsD16 = {{15,73}};
	const std::vector<NeuronId> N74::incommingNeuronsD17 = {{1,56}};
	const std::vector<NeuronId> N74::incommingNeuronsD18 = {{9}};
	const std::vector<NeuronId> N74::incommingNeuronsD19 = {{41}};
	struct N75 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N75::incommingNeuronsD0;
				case 1: return N75::incommingNeuronsD1;
				case 2: return N75::incommingNeuronsD2;
				case 3: return N75::incommingNeuronsD3;
				case 4: return N75::incommingNeuronsD4;
				case 5: return N75::incommingNeuronsD5;
				case 6: return N75::incommingNeuronsD6;
				case 7: return N75::incommingNeuronsD7;
				case 8: return N75::incommingNeuronsD8;
				case 9: return N75::incommingNeuronsD9;
				case 10: return N75::incommingNeuronsD10;
				case 11: return N75::incommingNeuronsD11;
				case 12: return N75::incommingNeuronsD12;
				case 13: return N75::incommingNeuronsD13;
				case 14: return N75::incommingNeuronsD14;
				case 15: return N75::incommingNeuronsD15;
				case 16: return N75::incommingNeuronsD16;
				case 17: return N75::incommingNeuronsD17;
				case 18: return N75::incommingNeuronsD18;
				case 19: return N75::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{58,99,74,57,89,35,92,78,98,83,9,37,90,34,38,54,76,13,32,61}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(75);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N75::incommingNeuronsD0 = {{82,83,84,86,90,95}};
	const std::vector<NeuronId> N75::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD2 = {{54}};
	const std::vector<NeuronId> N75::incommingNeuronsD3 = {{9}};
	const std::vector<NeuronId> N75::incommingNeuronsD4 = {{18}};
	const std::vector<NeuronId> N75::incommingNeuronsD5 = {{38,51}};
	const std::vector<NeuronId> N75::incommingNeuronsD6 = {{72}};
	const std::vector<NeuronId> N75::incommingNeuronsD7 = {{26}};
	const std::vector<NeuronId> N75::incommingNeuronsD8 = {{33,43}};
	const std::vector<NeuronId> N75::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD10 = {{68}};
	const std::vector<NeuronId> N75::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD17 = {{0}};
	const std::vector<NeuronId> N75::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N75::incommingNeuronsD19 = {{}};
	struct N76 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N76::incommingNeuronsD0;
				case 1: return N76::incommingNeuronsD1;
				case 2: return N76::incommingNeuronsD2;
				case 3: return N76::incommingNeuronsD3;
				case 4: return N76::incommingNeuronsD4;
				case 5: return N76::incommingNeuronsD5;
				case 6: return N76::incommingNeuronsD6;
				case 7: return N76::incommingNeuronsD7;
				case 8: return N76::incommingNeuronsD8;
				case 9: return N76::incommingNeuronsD9;
				case 10: return N76::incommingNeuronsD10;
				case 11: return N76::incommingNeuronsD11;
				case 12: return N76::incommingNeuronsD12;
				case 13: return N76::incommingNeuronsD13;
				case 14: return N76::incommingNeuronsD14;
				case 15: return N76::incommingNeuronsD15;
				case 16: return N76::incommingNeuronsD16;
				case 17: return N76::incommingNeuronsD17;
				case 18: return N76::incommingNeuronsD18;
				case 19: return N76::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{46,0,19,78,86,66,26,45,93,34,53,21,27,17,54,91,6,48,67,30}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(76);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N76::incommingNeuronsD0 = {{15,40,83,88,89}};
	const std::vector<NeuronId> N76::incommingNeuronsD1 = {{19,66}};
	const std::vector<NeuronId> N76::incommingNeuronsD2 = {{22,59,72}};
	const std::vector<NeuronId> N76::incommingNeuronsD3 = {{38,64}};
	const std::vector<NeuronId> N76::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD5 = {{8}};
	const std::vector<NeuronId> N76::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD7 = {{11,65}};
	const std::vector<NeuronId> N76::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD11 = {{10}};
	const std::vector<NeuronId> N76::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD13 = {{31,48,70}};
	const std::vector<NeuronId> N76::incommingNeuronsD14 = {{0,17}};
	const std::vector<NeuronId> N76::incommingNeuronsD15 = {{24}};
	const std::vector<NeuronId> N76::incommingNeuronsD16 = {{39,75,78}};
	const std::vector<NeuronId> N76::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N76::incommingNeuronsD18 = {{43}};
	const std::vector<NeuronId> N76::incommingNeuronsD19 = {{}};
	struct N77 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N77::incommingNeuronsD0;
				case 1: return N77::incommingNeuronsD1;
				case 2: return N77::incommingNeuronsD2;
				case 3: return N77::incommingNeuronsD3;
				case 4: return N77::incommingNeuronsD4;
				case 5: return N77::incommingNeuronsD5;
				case 6: return N77::incommingNeuronsD6;
				case 7: return N77::incommingNeuronsD7;
				case 8: return N77::incommingNeuronsD8;
				case 9: return N77::incommingNeuronsD9;
				case 10: return N77::incommingNeuronsD10;
				case 11: return N77::incommingNeuronsD11;
				case 12: return N77::incommingNeuronsD12;
				case 13: return N77::incommingNeuronsD13;
				case 14: return N77::incommingNeuronsD14;
				case 15: return N77::incommingNeuronsD15;
				case 16: return N77::incommingNeuronsD16;
				case 17: return N77::incommingNeuronsD17;
				case 18: return N77::incommingNeuronsD18;
				case 19: return N77::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{10,38,91,16,62,47,50,31,92,22,13,52,34,85,69,7,65,56,46,99}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(77);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N77::incommingNeuronsD0 = {{81,82,83,95,96,99}};
	const std::vector<NeuronId> N77::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD3 = {{58}};
	const std::vector<NeuronId> N77::incommingNeuronsD4 = {{57}};
	const std::vector<NeuronId> N77::incommingNeuronsD5 = {{35}};
	const std::vector<NeuronId> N77::incommingNeuronsD6 = {{0,12,29}};
	const std::vector<NeuronId> N77::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD8 = {{8,20}};
	const std::vector<NeuronId> N77::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD10 = {{21,74}};
	const std::vector<NeuronId> N77::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD12 = {{45,64}};
	const std::vector<NeuronId> N77::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD15 = {{52}};
	const std::vector<NeuronId> N77::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD17 = {{7,53}};
	const std::vector<NeuronId> N77::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N77::incommingNeuronsD19 = {{23}};
	struct N78 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N78::incommingNeuronsD0;
				case 1: return N78::incommingNeuronsD1;
				case 2: return N78::incommingNeuronsD2;
				case 3: return N78::incommingNeuronsD3;
				case 4: return N78::incommingNeuronsD4;
				case 5: return N78::incommingNeuronsD5;
				case 6: return N78::incommingNeuronsD6;
				case 7: return N78::incommingNeuronsD7;
				case 8: return N78::incommingNeuronsD8;
				case 9: return N78::incommingNeuronsD9;
				case 10: return N78::incommingNeuronsD10;
				case 11: return N78::incommingNeuronsD11;
				case 12: return N78::incommingNeuronsD12;
				case 13: return N78::incommingNeuronsD13;
				case 14: return N78::incommingNeuronsD14;
				case 15: return N78::incommingNeuronsD15;
				case 16: return N78::incommingNeuronsD16;
				case 17: return N78::incommingNeuronsD17;
				case 18: return N78::incommingNeuronsD18;
				case 19: return N78::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{82,31,99,41,42,62,13,11,98,69,57,97,68,21,1,79,76,48,49,86}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(78);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N78::incommingNeuronsD0 = {{84,87,92,97,98}};
	const std::vector<NeuronId> N78::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD2 = {{14,52,62,65}};
	const std::vector<NeuronId> N78::incommingNeuronsD3 = {{76}};
	const std::vector<NeuronId> N78::incommingNeuronsD4 = {{34}};
	const std::vector<NeuronId> N78::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD7 = {{75}};
	const std::vector<NeuronId> N78::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD9 = {{8,25}};
	const std::vector<NeuronId> N78::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD12 = {{30}};
	const std::vector<NeuronId> N78::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD14 = {{57}};
	const std::vector<NeuronId> N78::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD16 = {{28}};
	const std::vector<NeuronId> N78::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N78::incommingNeuronsD18 = {{5,56}};
	const std::vector<NeuronId> N78::incommingNeuronsD19 = {{39}};
	struct N79 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N79::incommingNeuronsD0;
				case 1: return N79::incommingNeuronsD1;
				case 2: return N79::incommingNeuronsD2;
				case 3: return N79::incommingNeuronsD3;
				case 4: return N79::incommingNeuronsD4;
				case 5: return N79::incommingNeuronsD5;
				case 6: return N79::incommingNeuronsD6;
				case 7: return N79::incommingNeuronsD7;
				case 8: return N79::incommingNeuronsD8;
				case 9: return N79::incommingNeuronsD9;
				case 10: return N79::incommingNeuronsD10;
				case 11: return N79::incommingNeuronsD11;
				case 12: return N79::incommingNeuronsD12;
				case 13: return N79::incommingNeuronsD13;
				case 14: return N79::incommingNeuronsD14;
				case 15: return N79::incommingNeuronsD15;
				case 16: return N79::incommingNeuronsD16;
				case 17: return N79::incommingNeuronsD17;
				case 18: return N79::incommingNeuronsD18;
				case 19: return N79::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{43,73,52,12,60,13,42,37,98,21,24,85,6,93,72,11,94,51,65,63}};
			const std::array<Delay, nSynapses> delays = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}};
			const std::array<float, nSynapses>& w2 = w.getWeight(79);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N79::incommingNeuronsD0 = {{41,85,89,92,94,98,99}};
	const std::vector<NeuronId> N79::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD3 = {{11}};
	const std::vector<NeuronId> N79::incommingNeuronsD4 = {{63}};
	const std::vector<NeuronId> N79::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD8 = {{58,65,69}};
	const std::vector<NeuronId> N79::incommingNeuronsD9 = {{37,48,60,72}};
	const std::vector<NeuronId> N79::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD11 = {{39,52}};
	const std::vector<NeuronId> N79::incommingNeuronsD12 = {{15}};
	const std::vector<NeuronId> N79::incommingNeuronsD13 = {{19,53}};
	const std::vector<NeuronId> N79::incommingNeuronsD14 = {{71}};
	const std::vector<NeuronId> N79::incommingNeuronsD15 = {{25,78}};
	const std::vector<NeuronId> N79::incommingNeuronsD16 = {{42}};
	const std::vector<NeuronId> N79::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N79::incommingNeuronsD18 = {{26,34}};
	const std::vector<NeuronId> N79::incommingNeuronsD19 = {{}};
	struct N80 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N80::incommingNeuronsD0;
				case 1: return N80::incommingNeuronsD1;
				case 2: return N80::incommingNeuronsD2;
				case 3: return N80::incommingNeuronsD3;
				case 4: return N80::incommingNeuronsD4;
				case 5: return N80::incommingNeuronsD5;
				case 6: return N80::incommingNeuronsD6;
				case 7: return N80::incommingNeuronsD7;
				case 8: return N80::incommingNeuronsD8;
				case 9: return N80::incommingNeuronsD9;
				case 10: return N80::incommingNeuronsD10;
				case 11: return N80::incommingNeuronsD11;
				case 12: return N80::incommingNeuronsD12;
				case 13: return N80::incommingNeuronsD13;
				case 14: return N80::incommingNeuronsD14;
				case 15: return N80::incommingNeuronsD15;
				case 16: return N80::incommingNeuronsD16;
				case 17: return N80::incommingNeuronsD17;
				case 18: return N80::incommingNeuronsD18;
				case 19: return N80::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{15,12,20,34,40,55,39,19,7,17,51,14,70,73,28,27,43,41,11,3}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(80);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N80::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD3 = {{51}};
	const std::vector<NeuronId> N80::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD6 = {{2}};
	const std::vector<NeuronId> N80::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD8 = {{49}};
	const std::vector<NeuronId> N80::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD11 = {{8}};
	const std::vector<NeuronId> N80::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD13 = {{12,54}};
	const std::vector<NeuronId> N80::incommingNeuronsD14 = {{36}};
	const std::vector<NeuronId> N80::incommingNeuronsD15 = {{11,55}};
	const std::vector<NeuronId> N80::incommingNeuronsD16 = {{4}};
	const std::vector<NeuronId> N80::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N80::incommingNeuronsD18 = {{67}};
	const std::vector<NeuronId> N80::incommingNeuronsD19 = {{5,14,32,46,69}};
	struct N81 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N81::incommingNeuronsD0;
				case 1: return N81::incommingNeuronsD1;
				case 2: return N81::incommingNeuronsD2;
				case 3: return N81::incommingNeuronsD3;
				case 4: return N81::incommingNeuronsD4;
				case 5: return N81::incommingNeuronsD5;
				case 6: return N81::incommingNeuronsD6;
				case 7: return N81::incommingNeuronsD7;
				case 8: return N81::incommingNeuronsD8;
				case 9: return N81::incommingNeuronsD9;
				case 10: return N81::incommingNeuronsD10;
				case 11: return N81::incommingNeuronsD11;
				case 12: return N81::incommingNeuronsD12;
				case 13: return N81::incommingNeuronsD13;
				case 14: return N81::incommingNeuronsD14;
				case 15: return N81::incommingNeuronsD15;
				case 16: return N81::incommingNeuronsD16;
				case 17: return N81::incommingNeuronsD17;
				case 18: return N81::incommingNeuronsD18;
				case 19: return N81::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{5,29,39,19,37,42,13,62,59,35,50,2,28,23,77,40,10,22,25,0}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(81);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N81::incommingNeuronsD0 = {{25}};
	const std::vector<NeuronId> N81::incommingNeuronsD1 = {{59}};
	const std::vector<NeuronId> N81::incommingNeuronsD2 = {{9,63}};
	const std::vector<NeuronId> N81::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N81::incommingNeuronsD4 = {{71}};
	const std::vector<NeuronId> N81::incommingNeuronsD5 = {{49,70}};
	const std::vector<NeuronId> N81::incommingNeuronsD6 = {{11}};
	const std::vector<NeuronId> N81::incommingNeuronsD7 = {{64}};
	const std::vector<NeuronId> N81::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N81::incommingNeuronsD9 = {{40}};
	const std::vector<NeuronId> N81::incommingNeuronsD10 = {{1,34}};
	const std::vector<NeuronId> N81::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N81::incommingNeuronsD12 = {{33}};
	const std::vector<NeuronId> N81::incommingNeuronsD13 = {{32}};
	const std::vector<NeuronId> N81::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N81::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N81::incommingNeuronsD16 = {{56}};
	const std::vector<NeuronId> N81::incommingNeuronsD17 = {{31}};
	const std::vector<NeuronId> N81::incommingNeuronsD18 = {{19}};
	const std::vector<NeuronId> N81::incommingNeuronsD19 = {{26}};
	struct N82 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N82::incommingNeuronsD0;
				case 1: return N82::incommingNeuronsD1;
				case 2: return N82::incommingNeuronsD2;
				case 3: return N82::incommingNeuronsD3;
				case 4: return N82::incommingNeuronsD4;
				case 5: return N82::incommingNeuronsD5;
				case 6: return N82::incommingNeuronsD6;
				case 7: return N82::incommingNeuronsD7;
				case 8: return N82::incommingNeuronsD8;
				case 9: return N82::incommingNeuronsD9;
				case 10: return N82::incommingNeuronsD10;
				case 11: return N82::incommingNeuronsD11;
				case 12: return N82::incommingNeuronsD12;
				case 13: return N82::incommingNeuronsD13;
				case 14: return N82::incommingNeuronsD14;
				case 15: return N82::incommingNeuronsD15;
				case 16: return N82::incommingNeuronsD16;
				case 17: return N82::incommingNeuronsD17;
				case 18: return N82::incommingNeuronsD18;
				case 19: return N82::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{71,77,29,34,54,68,40,65,55,63,67,49,75,25,32,0,9,24,41,60}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(82);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N82::incommingNeuronsD0 = {{35,78}};
	const std::vector<NeuronId> N82::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N82::incommingNeuronsD2 = {{55}};
	const std::vector<NeuronId> N82::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N82::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N82::incommingNeuronsD5 = {{15,57}};
	const std::vector<NeuronId> N82::incommingNeuronsD6 = {{68}};
	const std::vector<NeuronId> N82::incommingNeuronsD7 = {{18}};
	const std::vector<NeuronId> N82::incommingNeuronsD8 = {{48}};
	const std::vector<NeuronId> N82::incommingNeuronsD9 = {{71}};
	const std::vector<NeuronId> N82::incommingNeuronsD10 = {{28}};
	const std::vector<NeuronId> N82::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N82::incommingNeuronsD12 = {{39,73}};
	const std::vector<NeuronId> N82::incommingNeuronsD13 = {{17}};
	const std::vector<NeuronId> N82::incommingNeuronsD14 = {{56}};
	const std::vector<NeuronId> N82::incommingNeuronsD15 = {{37}};
	const std::vector<NeuronId> N82::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N82::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N82::incommingNeuronsD18 = {{41,63}};
	const std::vector<NeuronId> N82::incommingNeuronsD19 = {{}};
	struct N83 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N83::incommingNeuronsD0;
				case 1: return N83::incommingNeuronsD1;
				case 2: return N83::incommingNeuronsD2;
				case 3: return N83::incommingNeuronsD3;
				case 4: return N83::incommingNeuronsD4;
				case 5: return N83::incommingNeuronsD5;
				case 6: return N83::incommingNeuronsD6;
				case 7: return N83::incommingNeuronsD7;
				case 8: return N83::incommingNeuronsD8;
				case 9: return N83::incommingNeuronsD9;
				case 10: return N83::incommingNeuronsD10;
				case 11: return N83::incommingNeuronsD11;
				case 12: return N83::incommingNeuronsD12;
				case 13: return N83::incommingNeuronsD13;
				case 14: return N83::incommingNeuronsD14;
				case 15: return N83::incommingNeuronsD15;
				case 16: return N83::incommingNeuronsD16;
				case 17: return N83::incommingNeuronsD17;
				case 18: return N83::incommingNeuronsD18;
				case 19: return N83::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{13,65,76,26,63,68,11,54,75,77,38,18,53,40,29,3,2,9,66,69}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(83);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N83::incommingNeuronsD0 = {{50,66}};
	const std::vector<NeuronId> N83::incommingNeuronsD1 = {{48}};
	const std::vector<NeuronId> N83::incommingNeuronsD2 = {{39,71}};
	const std::vector<NeuronId> N83::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD4 = {{46}};
	const std::vector<NeuronId> N83::incommingNeuronsD5 = {{18}};
	const std::vector<NeuronId> N83::incommingNeuronsD6 = {{23}};
	const std::vector<NeuronId> N83::incommingNeuronsD7 = {{37,42,43}};
	const std::vector<NeuronId> N83::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD9 = {{75}};
	const std::vector<NeuronId> N83::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD11 = {{35,56}};
	const std::vector<NeuronId> N83::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N83::incommingNeuronsD18 = {{60}};
	const std::vector<NeuronId> N83::incommingNeuronsD19 = {{53}};
	struct N84 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N84::incommingNeuronsD0;
				case 1: return N84::incommingNeuronsD1;
				case 2: return N84::incommingNeuronsD2;
				case 3: return N84::incommingNeuronsD3;
				case 4: return N84::incommingNeuronsD4;
				case 5: return N84::incommingNeuronsD5;
				case 6: return N84::incommingNeuronsD6;
				case 7: return N84::incommingNeuronsD7;
				case 8: return N84::incommingNeuronsD8;
				case 9: return N84::incommingNeuronsD9;
				case 10: return N84::incommingNeuronsD10;
				case 11: return N84::incommingNeuronsD11;
				case 12: return N84::incommingNeuronsD12;
				case 13: return N84::incommingNeuronsD13;
				case 14: return N84::incommingNeuronsD14;
				case 15: return N84::incommingNeuronsD15;
				case 16: return N84::incommingNeuronsD16;
				case 17: return N84::incommingNeuronsD17;
				case 18: return N84::incommingNeuronsD18;
				case 19: return N84::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{20,48,70,38,27,12,14,71,28,32,33,60,75,46,49,47,43,31,22,78}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(84);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N84::incommingNeuronsD0 = {{0,18}};
	const std::vector<NeuronId> N84::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD2 = {{1,7,13,25}};
	const std::vector<NeuronId> N84::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD4 = {{10}};
	const std::vector<NeuronId> N84::incommingNeuronsD5 = {{45}};
	const std::vector<NeuronId> N84::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD8 = {{29}};
	const std::vector<NeuronId> N84::incommingNeuronsD9 = {{70}};
	const std::vector<NeuronId> N84::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD12 = {{37,38}};
	const std::vector<NeuronId> N84::incommingNeuronsD13 = {{3,64}};
	const std::vector<NeuronId> N84::incommingNeuronsD14 = {{22}};
	const std::vector<NeuronId> N84::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD16 = {{8}};
	const std::vector<NeuronId> N84::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N84::incommingNeuronsD18 = {{27,66}};
	const std::vector<NeuronId> N84::incommingNeuronsD19 = {{}};
	struct N85 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N85::incommingNeuronsD0;
				case 1: return N85::incommingNeuronsD1;
				case 2: return N85::incommingNeuronsD2;
				case 3: return N85::incommingNeuronsD3;
				case 4: return N85::incommingNeuronsD4;
				case 5: return N85::incommingNeuronsD5;
				case 6: return N85::incommingNeuronsD6;
				case 7: return N85::incommingNeuronsD7;
				case 8: return N85::incommingNeuronsD8;
				case 9: return N85::incommingNeuronsD9;
				case 10: return N85::incommingNeuronsD10;
				case 11: return N85::incommingNeuronsD11;
				case 12: return N85::incommingNeuronsD12;
				case 13: return N85::incommingNeuronsD13;
				case 14: return N85::incommingNeuronsD14;
				case 15: return N85::incommingNeuronsD15;
				case 16: return N85::incommingNeuronsD16;
				case 17: return N85::incommingNeuronsD17;
				case 18: return N85::incommingNeuronsD18;
				case 19: return N85::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{16,73,48,53,57,19,52,8,24,30,38,2,34,54,17,45,49,79,23,20}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(85);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N85::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD1 = {{28,62}};
	const std::vector<NeuronId> N85::incommingNeuronsD2 = {{16}};
	const std::vector<NeuronId> N85::incommingNeuronsD3 = {{44}};
	const std::vector<NeuronId> N85::incommingNeuronsD4 = {{1,60}};
	const std::vector<NeuronId> N85::incommingNeuronsD5 = {{47}};
	const std::vector<NeuronId> N85::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD7 = {{70}};
	const std::vector<NeuronId> N85::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD10 = {{17}};
	const std::vector<NeuronId> N85::incommingNeuronsD11 = {{79}};
	const std::vector<NeuronId> N85::incommingNeuronsD12 = {{35}};
	const std::vector<NeuronId> N85::incommingNeuronsD13 = {{77}};
	const std::vector<NeuronId> N85::incommingNeuronsD14 = {{21,39,46}};
	const std::vector<NeuronId> N85::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N85::incommingNeuronsD19 = {{63}};
	struct N86 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N86::incommingNeuronsD0;
				case 1: return N86::incommingNeuronsD1;
				case 2: return N86::incommingNeuronsD2;
				case 3: return N86::incommingNeuronsD3;
				case 4: return N86::incommingNeuronsD4;
				case 5: return N86::incommingNeuronsD5;
				case 6: return N86::incommingNeuronsD6;
				case 7: return N86::incommingNeuronsD7;
				case 8: return N86::incommingNeuronsD8;
				case 9: return N86::incommingNeuronsD9;
				case 10: return N86::incommingNeuronsD10;
				case 11: return N86::incommingNeuronsD11;
				case 12: return N86::incommingNeuronsD12;
				case 13: return N86::incommingNeuronsD13;
				case 14: return N86::incommingNeuronsD14;
				case 15: return N86::incommingNeuronsD15;
				case 16: return N86::incommingNeuronsD16;
				case 17: return N86::incommingNeuronsD17;
				case 18: return N86::incommingNeuronsD18;
				case 19: return N86::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{1,62,72,25,75,6,30,64,54,15,7,73,68,12,10,51,59,40,0,58}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(86);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N86::incommingNeuronsD0 = {{6}};
	const std::vector<NeuronId> N86::incommingNeuronsD1 = {{47}};
	const std::vector<NeuronId> N86::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD3 = {{57}};
	const std::vector<NeuronId> N86::incommingNeuronsD4 = {{4,76}};
	const std::vector<NeuronId> N86::incommingNeuronsD5 = {{66}};
	const std::vector<NeuronId> N86::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD7 = {{17}};
	const std::vector<NeuronId> N86::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD9 = {{10}};
	const std::vector<NeuronId> N86::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N86::incommingNeuronsD19 = {{78}};
	struct N87 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N87::incommingNeuronsD0;
				case 1: return N87::incommingNeuronsD1;
				case 2: return N87::incommingNeuronsD2;
				case 3: return N87::incommingNeuronsD3;
				case 4: return N87::incommingNeuronsD4;
				case 5: return N87::incommingNeuronsD5;
				case 6: return N87::incommingNeuronsD6;
				case 7: return N87::incommingNeuronsD7;
				case 8: return N87::incommingNeuronsD8;
				case 9: return N87::incommingNeuronsD9;
				case 10: return N87::incommingNeuronsD10;
				case 11: return N87::incommingNeuronsD11;
				case 12: return N87::incommingNeuronsD12;
				case 13: return N87::incommingNeuronsD13;
				case 14: return N87::incommingNeuronsD14;
				case 15: return N87::incommingNeuronsD15;
				case 16: return N87::incommingNeuronsD16;
				case 17: return N87::incommingNeuronsD17;
				case 18: return N87::incommingNeuronsD18;
				case 19: return N87::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{24,32,67,71,7,33,35,28,78,19,31,39,42,48,74,53,45,37,69,6}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(87);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N87::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD1 = {{7}};
	const std::vector<NeuronId> N87::incommingNeuronsD2 = {{46}};
	const std::vector<NeuronId> N87::incommingNeuronsD3 = {{42}};
	const std::vector<NeuronId> N87::incommingNeuronsD4 = {{54}};
	const std::vector<NeuronId> N87::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD9 = {{61}};
	const std::vector<NeuronId> N87::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD12 = {{2,24,40}};
	const std::vector<NeuronId> N87::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD14 = {{35,68}};
	const std::vector<NeuronId> N87::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD16 = {{37}};
	const std::vector<NeuronId> N87::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N87::incommingNeuronsD19 = {{15,62}};
	struct N88 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N88::incommingNeuronsD0;
				case 1: return N88::incommingNeuronsD1;
				case 2: return N88::incommingNeuronsD2;
				case 3: return N88::incommingNeuronsD3;
				case 4: return N88::incommingNeuronsD4;
				case 5: return N88::incommingNeuronsD5;
				case 6: return N88::incommingNeuronsD6;
				case 7: return N88::incommingNeuronsD7;
				case 8: return N88::incommingNeuronsD8;
				case 9: return N88::incommingNeuronsD9;
				case 10: return N88::incommingNeuronsD10;
				case 11: return N88::incommingNeuronsD11;
				case 12: return N88::incommingNeuronsD12;
				case 13: return N88::incommingNeuronsD13;
				case 14: return N88::incommingNeuronsD14;
				case 15: return N88::incommingNeuronsD15;
				case 16: return N88::incommingNeuronsD16;
				case 17: return N88::incommingNeuronsD17;
				case 18: return N88::incommingNeuronsD18;
				case 19: return N88::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{53,26,17,46,16,60,45,36,69,67,51,8,62,40,11,5,76,34,31,24}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(88);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N88::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD2 = {{18}};
	const std::vector<NeuronId> N88::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD5 = {{1}};
	const std::vector<NeuronId> N88::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD7 = {{7,15}};
	const std::vector<NeuronId> N88::incommingNeuronsD8 = {{60}};
	const std::vector<NeuronId> N88::incommingNeuronsD9 = {{11}};
	const std::vector<NeuronId> N88::incommingNeuronsD10 = {{22}};
	const std::vector<NeuronId> N88::incommingNeuronsD11 = {{3,47}};
	const std::vector<NeuronId> N88::incommingNeuronsD12 = {{12,13,62}};
	const std::vector<NeuronId> N88::incommingNeuronsD13 = {{9,26,39}};
	const std::vector<NeuronId> N88::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N88::incommingNeuronsD19 = {{}};
	struct N89 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N89::incommingNeuronsD0;
				case 1: return N89::incommingNeuronsD1;
				case 2: return N89::incommingNeuronsD2;
				case 3: return N89::incommingNeuronsD3;
				case 4: return N89::incommingNeuronsD4;
				case 5: return N89::incommingNeuronsD5;
				case 6: return N89::incommingNeuronsD6;
				case 7: return N89::incommingNeuronsD7;
				case 8: return N89::incommingNeuronsD8;
				case 9: return N89::incommingNeuronsD9;
				case 10: return N89::incommingNeuronsD10;
				case 11: return N89::incommingNeuronsD11;
				case 12: return N89::incommingNeuronsD12;
				case 13: return N89::incommingNeuronsD13;
				case 14: return N89::incommingNeuronsD14;
				case 15: return N89::incommingNeuronsD15;
				case 16: return N89::incommingNeuronsD16;
				case 17: return N89::incommingNeuronsD17;
				case 18: return N89::incommingNeuronsD18;
				case 19: return N89::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{49,58,60,15,12,36,51,37,3,10,63,47,50,69,26,79,61,76,24,46}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(89);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N89::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD1 = {{25}};
	const std::vector<NeuronId> N89::incommingNeuronsD2 = {{50,51}};
	const std::vector<NeuronId> N89::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD4 = {{6,75}};
	const std::vector<NeuronId> N89::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD7 = {{22,60}};
	const std::vector<NeuronId> N89::incommingNeuronsD8 = {{7,34,41}};
	const std::vector<NeuronId> N89::incommingNeuronsD9 = {{30,52}};
	const std::vector<NeuronId> N89::incommingNeuronsD10 = {{63}};
	const std::vector<NeuronId> N89::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD13 = {{18}};
	const std::vector<NeuronId> N89::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD15 = {{13,17,47,66}};
	const std::vector<NeuronId> N89::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N89::incommingNeuronsD18 = {{1,16,55,74}};
	const std::vector<NeuronId> N89::incommingNeuronsD19 = {{}};
	struct N90 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N90::incommingNeuronsD0;
				case 1: return N90::incommingNeuronsD1;
				case 2: return N90::incommingNeuronsD2;
				case 3: return N90::incommingNeuronsD3;
				case 4: return N90::incommingNeuronsD4;
				case 5: return N90::incommingNeuronsD5;
				case 6: return N90::incommingNeuronsD6;
				case 7: return N90::incommingNeuronsD7;
				case 8: return N90::incommingNeuronsD8;
				case 9: return N90::incommingNeuronsD9;
				case 10: return N90::incommingNeuronsD10;
				case 11: return N90::incommingNeuronsD11;
				case 12: return N90::incommingNeuronsD12;
				case 13: return N90::incommingNeuronsD13;
				case 14: return N90::incommingNeuronsD14;
				case 15: return N90::incommingNeuronsD15;
				case 16: return N90::incommingNeuronsD16;
				case 17: return N90::incommingNeuronsD17;
				case 18: return N90::incommingNeuronsD18;
				case 19: return N90::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{32,12,36,34,65,11,62,39,68,3,75,7,56,28,43,58,8,46,19,17}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(90);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N90::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD5 = {{5}};
	const std::vector<NeuronId> N90::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD7 = {{10}};
	const std::vector<NeuronId> N90::incommingNeuronsD8 = {{25}};
	const std::vector<NeuronId> N90::incommingNeuronsD9 = {{65}};
	const std::vector<NeuronId> N90::incommingNeuronsD10 = {{51}};
	const std::vector<NeuronId> N90::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD12 = {{3,42,75}};
	const std::vector<NeuronId> N90::incommingNeuronsD13 = {{67}};
	const std::vector<NeuronId> N90::incommingNeuronsD14 = {{66}};
	const std::vector<NeuronId> N90::incommingNeuronsD15 = {{32}};
	const std::vector<NeuronId> N90::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N90::incommingNeuronsD19 = {{12}};
	struct N91 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N91::incommingNeuronsD0;
				case 1: return N91::incommingNeuronsD1;
				case 2: return N91::incommingNeuronsD2;
				case 3: return N91::incommingNeuronsD3;
				case 4: return N91::incommingNeuronsD4;
				case 5: return N91::incommingNeuronsD5;
				case 6: return N91::incommingNeuronsD6;
				case 7: return N91::incommingNeuronsD7;
				case 8: return N91::incommingNeuronsD8;
				case 9: return N91::incommingNeuronsD9;
				case 10: return N91::incommingNeuronsD10;
				case 11: return N91::incommingNeuronsD11;
				case 12: return N91::incommingNeuronsD12;
				case 13: return N91::incommingNeuronsD13;
				case 14: return N91::incommingNeuronsD14;
				case 15: return N91::incommingNeuronsD15;
				case 16: return N91::incommingNeuronsD16;
				case 17: return N91::incommingNeuronsD17;
				case 18: return N91::incommingNeuronsD18;
				case 19: return N91::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{32,49,63,51,18,0,20,30,16,29,61,56,3,58,25,8,45,43,64,2}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(91);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N91::incommingNeuronsD0 = {{9,28}};
	const std::vector<NeuronId> N91::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD2 = {{60,77}};
	const std::vector<NeuronId> N91::incommingNeuronsD3 = {{41}};
	const std::vector<NeuronId> N91::incommingNeuronsD4 = {{47}};
	const std::vector<NeuronId> N91::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD6 = {{21,46}};
	const std::vector<NeuronId> N91::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD10 = {{14,30}};
	const std::vector<NeuronId> N91::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD13 = {{33}};
	const std::vector<NeuronId> N91::incommingNeuronsD14 = {{2}};
	const std::vector<NeuronId> N91::incommingNeuronsD15 = {{76}};
	const std::vector<NeuronId> N91::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N91::incommingNeuronsD19 = {{6}};
	struct N92 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N92::incommingNeuronsD0;
				case 1: return N92::incommingNeuronsD1;
				case 2: return N92::incommingNeuronsD2;
				case 3: return N92::incommingNeuronsD3;
				case 4: return N92::incommingNeuronsD4;
				case 5: return N92::incommingNeuronsD5;
				case 6: return N92::incommingNeuronsD6;
				case 7: return N92::incommingNeuronsD7;
				case 8: return N92::incommingNeuronsD8;
				case 9: return N92::incommingNeuronsD9;
				case 10: return N92::incommingNeuronsD10;
				case 11: return N92::incommingNeuronsD11;
				case 12: return N92::incommingNeuronsD12;
				case 13: return N92::incommingNeuronsD13;
				case 14: return N92::incommingNeuronsD14;
				case 15: return N92::incommingNeuronsD15;
				case 16: return N92::incommingNeuronsD16;
				case 17: return N92::incommingNeuronsD17;
				case 18: return N92::incommingNeuronsD18;
				case 19: return N92::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{54,62,42,16,46,31,14,22,25,27,51,60,20,52,13,70,78,50,79,39}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(92);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N92::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD2 = {{20}};
	const std::vector<NeuronId> N92::incommingNeuronsD3 = {{7,60}};
	const std::vector<NeuronId> N92::incommingNeuronsD4 = {{33}};
	const std::vector<NeuronId> N92::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD6 = {{66,75}};
	const std::vector<NeuronId> N92::incommingNeuronsD7 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD8 = {{5,77}};
	const std::vector<NeuronId> N92::incommingNeuronsD9 = {{53}};
	const std::vector<NeuronId> N92::incommingNeuronsD10 = {{3}};
	const std::vector<NeuronId> N92::incommingNeuronsD11 = {{54,74}};
	const std::vector<NeuronId> N92::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD13 = {{42}};
	const std::vector<NeuronId> N92::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD15 = {{21,41,64,65}};
	const std::vector<NeuronId> N92::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N92::incommingNeuronsD18 = {{10}};
	const std::vector<NeuronId> N92::incommingNeuronsD19 = {{}};
	struct N93 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N93::incommingNeuronsD0;
				case 1: return N93::incommingNeuronsD1;
				case 2: return N93::incommingNeuronsD2;
				case 3: return N93::incommingNeuronsD3;
				case 4: return N93::incommingNeuronsD4;
				case 5: return N93::incommingNeuronsD5;
				case 6: return N93::incommingNeuronsD6;
				case 7: return N93::incommingNeuronsD7;
				case 8: return N93::incommingNeuronsD8;
				case 9: return N93::incommingNeuronsD9;
				case 10: return N93::incommingNeuronsD10;
				case 11: return N93::incommingNeuronsD11;
				case 12: return N93::incommingNeuronsD12;
				case 13: return N93::incommingNeuronsD13;
				case 14: return N93::incommingNeuronsD14;
				case 15: return N93::incommingNeuronsD15;
				case 16: return N93::incommingNeuronsD16;
				case 17: return N93::incommingNeuronsD17;
				case 18: return N93::incommingNeuronsD18;
				case 19: return N93::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{9,17,7,57,54,52,65,29,33,62,61,11,49,72,30,42,12,38,35,71}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(93);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N93::incommingNeuronsD0 = {{3,69}};
	const std::vector<NeuronId> N93::incommingNeuronsD1 = {{42}};
	const std::vector<NeuronId> N93::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD3 = {{22}};
	const std::vector<NeuronId> N93::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD5 = {{60}};
	const std::vector<NeuronId> N93::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD7 = {{40}};
	const std::vector<NeuronId> N93::incommingNeuronsD8 = {{76}};
	const std::vector<NeuronId> N93::incommingNeuronsD9 = {{2}};
	const std::vector<NeuronId> N93::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD13 = {{79}};
	const std::vector<NeuronId> N93::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N93::incommingNeuronsD15 = {{50,72}};
	const std::vector<NeuronId> N93::incommingNeuronsD16 = {{41}};
	const std::vector<NeuronId> N93::incommingNeuronsD17 = {{35}};
	const std::vector<NeuronId> N93::incommingNeuronsD18 = {{33}};
	const std::vector<NeuronId> N93::incommingNeuronsD19 = {{}};
	struct N94 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N94::incommingNeuronsD0;
				case 1: return N94::incommingNeuronsD1;
				case 2: return N94::incommingNeuronsD2;
				case 3: return N94::incommingNeuronsD3;
				case 4: return N94::incommingNeuronsD4;
				case 5: return N94::incommingNeuronsD5;
				case 6: return N94::incommingNeuronsD6;
				case 7: return N94::incommingNeuronsD7;
				case 8: return N94::incommingNeuronsD8;
				case 9: return N94::incommingNeuronsD9;
				case 10: return N94::incommingNeuronsD10;
				case 11: return N94::incommingNeuronsD11;
				case 12: return N94::incommingNeuronsD12;
				case 13: return N94::incommingNeuronsD13;
				case 14: return N94::incommingNeuronsD14;
				case 15: return N94::incommingNeuronsD15;
				case 16: return N94::incommingNeuronsD16;
				case 17: return N94::incommingNeuronsD17;
				case 18: return N94::incommingNeuronsD18;
				case 19: return N94::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{59,52,79,71,50,74,11,44,53,63,5,34,60,30,20,67,64,28,36,9}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(94);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N94::incommingNeuronsD0 = {{62}};
	const std::vector<NeuronId> N94::incommingNeuronsD1 = {{46}};
	const std::vector<NeuronId> N94::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD5 = {{17}};
	const std::vector<NeuronId> N94::incommingNeuronsD6 = {{69}};
	const std::vector<NeuronId> N94::incommingNeuronsD7 = {{31}};
	const std::vector<NeuronId> N94::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD9 = {{12}};
	const std::vector<NeuronId> N94::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD11 = {{21}};
	const std::vector<NeuronId> N94::incommingNeuronsD12 = {{51}};
	const std::vector<NeuronId> N94::incommingNeuronsD13 = {{37}};
	const std::vector<NeuronId> N94::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD15 = {{10}};
	const std::vector<NeuronId> N94::incommingNeuronsD16 = {{60,79}};
	const std::vector<NeuronId> N94::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N94::incommingNeuronsD19 = {{30}};
	struct N95 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N95::incommingNeuronsD0;
				case 1: return N95::incommingNeuronsD1;
				case 2: return N95::incommingNeuronsD2;
				case 3: return N95::incommingNeuronsD3;
				case 4: return N95::incommingNeuronsD4;
				case 5: return N95::incommingNeuronsD5;
				case 6: return N95::incommingNeuronsD6;
				case 7: return N95::incommingNeuronsD7;
				case 8: return N95::incommingNeuronsD8;
				case 9: return N95::incommingNeuronsD9;
				case 10: return N95::incommingNeuronsD10;
				case 11: return N95::incommingNeuronsD11;
				case 12: return N95::incommingNeuronsD12;
				case 13: return N95::incommingNeuronsD13;
				case 14: return N95::incommingNeuronsD14;
				case 15: return N95::incommingNeuronsD15;
				case 16: return N95::incommingNeuronsD16;
				case 17: return N95::incommingNeuronsD17;
				case 18: return N95::incommingNeuronsD18;
				case 19: return N95::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{74,40,45,75,59,66,17,29,65,31,20,67,60,2,77,8,35,6,18,1}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(95);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N95::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD1 = {{13}};
	const std::vector<NeuronId> N95::incommingNeuronsD2 = {{0}};
	const std::vector<NeuronId> N95::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD4 = {{48}};
	const std::vector<NeuronId> N95::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD7 = {{49,56}};
	const std::vector<NeuronId> N95::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD9 = {{59}};
	const std::vector<NeuronId> N95::incommingNeuronsD10 = {{24}};
	const std::vector<NeuronId> N95::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD12 = {{4}};
	const std::vector<NeuronId> N95::incommingNeuronsD13 = {{34}};
	const std::vector<NeuronId> N95::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD15 = {{36}};
	const std::vector<NeuronId> N95::incommingNeuronsD16 = {{51,54}};
	const std::vector<NeuronId> N95::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N95::incommingNeuronsD19 = {{17}};
	struct N96 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N96::incommingNeuronsD0;
				case 1: return N96::incommingNeuronsD1;
				case 2: return N96::incommingNeuronsD2;
				case 3: return N96::incommingNeuronsD3;
				case 4: return N96::incommingNeuronsD4;
				case 5: return N96::incommingNeuronsD5;
				case 6: return N96::incommingNeuronsD6;
				case 7: return N96::incommingNeuronsD7;
				case 8: return N96::incommingNeuronsD8;
				case 9: return N96::incommingNeuronsD9;
				case 10: return N96::incommingNeuronsD10;
				case 11: return N96::incommingNeuronsD11;
				case 12: return N96::incommingNeuronsD12;
				case 13: return N96::incommingNeuronsD13;
				case 14: return N96::incommingNeuronsD14;
				case 15: return N96::incommingNeuronsD15;
				case 16: return N96::incommingNeuronsD16;
				case 17: return N96::incommingNeuronsD17;
				case 18: return N96::incommingNeuronsD18;
				case 19: return N96::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{13,65,62,41,66,16,57,51,23,0,4,63,40,46,64,77,58,11,24,37}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(96);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N96::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N96::incommingNeuronsD1 = {{24}};
	const std::vector<NeuronId> N96::incommingNeuronsD2 = {{28,47,53,74}};
	const std::vector<NeuronId> N96::incommingNeuronsD3 = {{15,27}};
	const std::vector<NeuronId> N96::incommingNeuronsD4 = {{51}};
	const std::vector<NeuronId> N96::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N96::incommingNeuronsD6 = {{41}};
	const std::vector<NeuronId> N96::incommingNeuronsD7 = {{71}};
	const std::vector<NeuronId> N96::incommingNeuronsD8 = {{19}};
	const std::vector<NeuronId> N96::incommingNeuronsD9 = {{20}};
	const std::vector<NeuronId> N96::incommingNeuronsD10 = {{6}};
	const std::vector<NeuronId> N96::incommingNeuronsD11 = {{}};
	const std::vector<NeuronId> N96::incommingNeuronsD12 = {{}};
	const std::vector<NeuronId> N96::incommingNeuronsD13 = {{59}};
	const std::vector<NeuronId> N96::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N96::incommingNeuronsD15 = {{70}};
	const std::vector<NeuronId> N96::incommingNeuronsD16 = {{16}};
	const std::vector<NeuronId> N96::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N96::incommingNeuronsD18 = {{32}};
	const std::vector<NeuronId> N96::incommingNeuronsD19 = {{}};
	struct N97 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N97::incommingNeuronsD0;
				case 1: return N97::incommingNeuronsD1;
				case 2: return N97::incommingNeuronsD2;
				case 3: return N97::incommingNeuronsD3;
				case 4: return N97::incommingNeuronsD4;
				case 5: return N97::incommingNeuronsD5;
				case 6: return N97::incommingNeuronsD6;
				case 7: return N97::incommingNeuronsD7;
				case 8: return N97::incommingNeuronsD8;
				case 9: return N97::incommingNeuronsD9;
				case 10: return N97::incommingNeuronsD10;
				case 11: return N97::incommingNeuronsD11;
				case 12: return N97::incommingNeuronsD12;
				case 13: return N97::incommingNeuronsD13;
				case 14: return N97::incommingNeuronsD14;
				case 15: return N97::incommingNeuronsD15;
				case 16: return N97::incommingNeuronsD16;
				case 17: return N97::incommingNeuronsD17;
				case 18: return N97::incommingNeuronsD18;
				case 19: return N97::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{4,67,70,27,37,23,44,78,17,46,6,52,60,42,15,3,33,72,30,41}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(97);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N97::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD1 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD2 = {{6,15}};
	const std::vector<NeuronId> N97::incommingNeuronsD3 = {{25,29}};
	const std::vector<NeuronId> N97::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD6 = {{24}};
	const std::vector<NeuronId> N97::incommingNeuronsD7 = {{9}};
	const std::vector<NeuronId> N97::incommingNeuronsD8 = {{26}};
	const std::vector<NeuronId> N97::incommingNeuronsD9 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD11 = {{36,46,78}};
	const std::vector<NeuronId> N97::incommingNeuronsD12 = {{68}};
	const std::vector<NeuronId> N97::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD14 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD15 = {{74}};
	const std::vector<NeuronId> N97::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N97::incommingNeuronsD18 = {{61}};
	const std::vector<NeuronId> N97::incommingNeuronsD19 = {{44}};
	struct N98 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N98::incommingNeuronsD0;
				case 1: return N98::incommingNeuronsD1;
				case 2: return N98::incommingNeuronsD2;
				case 3: return N98::incommingNeuronsD3;
				case 4: return N98::incommingNeuronsD4;
				case 5: return N98::incommingNeuronsD5;
				case 6: return N98::incommingNeuronsD6;
				case 7: return N98::incommingNeuronsD7;
				case 8: return N98::incommingNeuronsD8;
				case 9: return N98::incommingNeuronsD9;
				case 10: return N98::incommingNeuronsD10;
				case 11: return N98::incommingNeuronsD11;
				case 12: return N98::incommingNeuronsD12;
				case 13: return N98::incommingNeuronsD13;
				case 14: return N98::incommingNeuronsD14;
				case 15: return N98::incommingNeuronsD15;
				case 16: return N98::incommingNeuronsD16;
				case 17: return N98::incommingNeuronsD17;
				case 18: return N98::incommingNeuronsD18;
				case 19: return N98::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{70,72,69,15,30,78,23,46,16,56,11,51,0,62,79,45,4,66,3,21}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(98);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N98::incommingNeuronsD0 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD1 = {{65}};
	const std::vector<NeuronId> N98::incommingNeuronsD2 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD3 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD4 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD5 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD6 = {{61}};
	const std::vector<NeuronId> N98::incommingNeuronsD7 = {{23}};
	const std::vector<NeuronId> N98::incommingNeuronsD8 = {{75,78,79}};
	const std::vector<NeuronId> N98::incommingNeuronsD9 = {{33}};
	const std::vector<NeuronId> N98::incommingNeuronsD10 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD11 = {{5}};
	const std::vector<NeuronId> N98::incommingNeuronsD12 = {{31}};
	const std::vector<NeuronId> N98::incommingNeuronsD13 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD14 = {{19,25}};
	const std::vector<NeuronId> N98::incommingNeuronsD15 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD16 = {{26}};
	const std::vector<NeuronId> N98::incommingNeuronsD17 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N98::incommingNeuronsD19 = {{}};
	struct N99 {
		static const std::vector<NeuronId> incommingNeuronsD0;
		static const std::vector<NeuronId> incommingNeuronsD1;
		static const std::vector<NeuronId> incommingNeuronsD2;
		static const std::vector<NeuronId> incommingNeuronsD3;
		static const std::vector<NeuronId> incommingNeuronsD4;
		static const std::vector<NeuronId> incommingNeuronsD5;
		static const std::vector<NeuronId> incommingNeuronsD6;
		static const std::vector<NeuronId> incommingNeuronsD7;
		static const std::vector<NeuronId> incommingNeuronsD8;
		static const std::vector<NeuronId> incommingNeuronsD9;
		static const std::vector<NeuronId> incommingNeuronsD10;
		static const std::vector<NeuronId> incommingNeuronsD11;
		static const std::vector<NeuronId> incommingNeuronsD12;
		static const std::vector<NeuronId> incommingNeuronsD13;
		static const std::vector<NeuronId> incommingNeuronsD14;
		static const std::vector<NeuronId> incommingNeuronsD15;
		static const std::vector<NeuronId> incommingNeuronsD16;
		static const std::vector<NeuronId> incommingNeuronsD17;
		static const std::vector<NeuronId> incommingNeuronsD18;
		static const std::vector<NeuronId> incommingNeuronsD19;

		static const std::vector<NeuronId>& getIncommingNeurons(const Delay d)
		{
			switch (d) {
				case 0: return N99::incommingNeuronsD0;
				case 1: return N99::incommingNeuronsD1;
				case 2: return N99::incommingNeuronsD2;
				case 3: return N99::incommingNeuronsD3;
				case 4: return N99::incommingNeuronsD4;
				case 5: return N99::incommingNeuronsD5;
				case 6: return N99::incommingNeuronsD6;
				case 7: return N99::incommingNeuronsD7;
				case 8: return N99::incommingNeuronsD8;
				case 9: return N99::incommingNeuronsD9;
				case 10: return N99::incommingNeuronsD10;
				case 11: return N99::incommingNeuronsD11;
				case 12: return N99::incommingNeuronsD12;
				case 13: return N99::incommingNeuronsD13;
				case 14: return N99::incommingNeuronsD14;
				case 15: return N99::incommingNeuronsD15;
				case 16: return N99::incommingNeuronsD16;
				case 17: return N99::incommingNeuronsD17;
				case 18: return N99::incommingNeuronsD18;
				case 19: return N99::incommingNeuronsD19;
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		static void fire(const unsigned int t, Weights& w, IC& ic) {
			const size_t nSynapses=20;
			const std::array<NeuronId, nSynapses> neurons = {{3,41,65,77,32,37,22,68,11,63,8,20,10,9,61,12,79,54,29,18}};
			const std::array<Delay, nSynapses> delays = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			const std::array<float, nSynapses>& w2 = w.getWeight(99);
			for (size_t i = 0; i < nSynapses; ++i) {
				ic.add(neurons[i], delays[i], t, w2[i]);
			}
		}
	};
	const std::vector<NeuronId> N99::incommingNeuronsD0 = {{49}};
	const std::vector<NeuronId> N99::incommingNeuronsD1 = {{75}};
	const std::vector<NeuronId> N99::incommingNeuronsD2 = {{78}};
	const std::vector<NeuronId> N99::incommingNeuronsD3 = {{13,67}};
	const std::vector<NeuronId> N99::incommingNeuronsD4 = {{16,29}};
	const std::vector<NeuronId> N99::incommingNeuronsD5 = {{10}};
	const std::vector<NeuronId> N99::incommingNeuronsD6 = {{}};
	const std::vector<NeuronId> N99::incommingNeuronsD7 = {{74}};
	const std::vector<NeuronId> N99::incommingNeuronsD8 = {{}};
	const std::vector<NeuronId> N99::incommingNeuronsD9 = {{68}};
	const std::vector<NeuronId> N99::incommingNeuronsD10 = {{70}};
	const std::vector<NeuronId> N99::incommingNeuronsD11 = {{41,55}};
	const std::vector<NeuronId> N99::incommingNeuronsD12 = {{14,52,60}};
	const std::vector<NeuronId> N99::incommingNeuronsD13 = {{27,35}};
	const std::vector<NeuronId> N99::incommingNeuronsD14 = {{6,12,34,45,54,63}};
	const std::vector<NeuronId> N99::incommingNeuronsD15 = {{38,57,58}};
	const std::vector<NeuronId> N99::incommingNeuronsD16 = {{}};
	const std::vector<NeuronId> N99::incommingNeuronsD17 = {{15}};
	const std::vector<NeuronId> N99::incommingNeuronsD18 = {{}};
	const std::vector<NeuronId> N99::incommingNeuronsD19 = {{77}};
}
namespace SpikeNs{
	using namespace NeuronsNs;
	struct NetworkBaseStatic
	{
		static const size_t Ne = 80;
		static const size_t Ni = 20;
		static const size_t Ns = 0;
		static const size_t Nm = 0;
		static const size_t nNeurons = 100;
		static const size_t D = 20;
		static const size_t M = 20;

		const std::vector<NeuronId>& getIncommingNeurons(
			const NeuronId neuronId,
			const Delay d) const
		{
			switch (neuronId) {
				case 0: return N0::getIncommingNeurons(d);
				case 1: return N1::getIncommingNeurons(d);
				case 2: return N2::getIncommingNeurons(d);
				case 3: return N3::getIncommingNeurons(d);
				case 4: return N4::getIncommingNeurons(d);
				case 5: return N5::getIncommingNeurons(d);
				case 6: return N6::getIncommingNeurons(d);
				case 7: return N7::getIncommingNeurons(d);
				case 8: return N8::getIncommingNeurons(d);
				case 9: return N9::getIncommingNeurons(d);
				case 10: return N10::getIncommingNeurons(d);
				case 11: return N11::getIncommingNeurons(d);
				case 12: return N12::getIncommingNeurons(d);
				case 13: return N13::getIncommingNeurons(d);
				case 14: return N14::getIncommingNeurons(d);
				case 15: return N15::getIncommingNeurons(d);
				case 16: return N16::getIncommingNeurons(d);
				case 17: return N17::getIncommingNeurons(d);
				case 18: return N18::getIncommingNeurons(d);
				case 19: return N19::getIncommingNeurons(d);
				case 20: return N20::getIncommingNeurons(d);
				case 21: return N21::getIncommingNeurons(d);
				case 22: return N22::getIncommingNeurons(d);
				case 23: return N23::getIncommingNeurons(d);
				case 24: return N24::getIncommingNeurons(d);
				case 25: return N25::getIncommingNeurons(d);
				case 26: return N26::getIncommingNeurons(d);
				case 27: return N27::getIncommingNeurons(d);
				case 28: return N28::getIncommingNeurons(d);
				case 29: return N29::getIncommingNeurons(d);
				case 30: return N30::getIncommingNeurons(d);
				case 31: return N31::getIncommingNeurons(d);
				case 32: return N32::getIncommingNeurons(d);
				case 33: return N33::getIncommingNeurons(d);
				case 34: return N34::getIncommingNeurons(d);
				case 35: return N35::getIncommingNeurons(d);
				case 36: return N36::getIncommingNeurons(d);
				case 37: return N37::getIncommingNeurons(d);
				case 38: return N38::getIncommingNeurons(d);
				case 39: return N39::getIncommingNeurons(d);
				case 40: return N40::getIncommingNeurons(d);
				case 41: return N41::getIncommingNeurons(d);
				case 42: return N42::getIncommingNeurons(d);
				case 43: return N43::getIncommingNeurons(d);
				case 44: return N44::getIncommingNeurons(d);
				case 45: return N45::getIncommingNeurons(d);
				case 46: return N46::getIncommingNeurons(d);
				case 47: return N47::getIncommingNeurons(d);
				case 48: return N48::getIncommingNeurons(d);
				case 49: return N49::getIncommingNeurons(d);
				case 50: return N50::getIncommingNeurons(d);
				case 51: return N51::getIncommingNeurons(d);
				case 52: return N52::getIncommingNeurons(d);
				case 53: return N53::getIncommingNeurons(d);
				case 54: return N54::getIncommingNeurons(d);
				case 55: return N55::getIncommingNeurons(d);
				case 56: return N56::getIncommingNeurons(d);
				case 57: return N57::getIncommingNeurons(d);
				case 58: return N58::getIncommingNeurons(d);
				case 59: return N59::getIncommingNeurons(d);
				case 60: return N60::getIncommingNeurons(d);
				case 61: return N61::getIncommingNeurons(d);
				case 62: return N62::getIncommingNeurons(d);
				case 63: return N63::getIncommingNeurons(d);
				case 64: return N64::getIncommingNeurons(d);
				case 65: return N65::getIncommingNeurons(d);
				case 66: return N66::getIncommingNeurons(d);
				case 67: return N67::getIncommingNeurons(d);
				case 68: return N68::getIncommingNeurons(d);
				case 69: return N69::getIncommingNeurons(d);
				case 70: return N70::getIncommingNeurons(d);
				case 71: return N71::getIncommingNeurons(d);
				case 72: return N72::getIncommingNeurons(d);
				case 73: return N73::getIncommingNeurons(d);
				case 74: return N74::getIncommingNeurons(d);
				case 75: return N75::getIncommingNeurons(d);
				case 76: return N76::getIncommingNeurons(d);
				case 77: return N77::getIncommingNeurons(d);
				case 78: return N78::getIncommingNeurons(d);
				case 79: return N79::getIncommingNeurons(d);
				case 80: return N80::getIncommingNeurons(d);
				case 81: return N81::getIncommingNeurons(d);
				case 82: return N82::getIncommingNeurons(d);
				case 83: return N83::getIncommingNeurons(d);
				case 84: return N84::getIncommingNeurons(d);
				case 85: return N85::getIncommingNeurons(d);
				case 86: return N86::getIncommingNeurons(d);
				case 87: return N87::getIncommingNeurons(d);
				case 88: return N88::getIncommingNeurons(d);
				case 89: return N89::getIncommingNeurons(d);
				case 90: return N90::getIncommingNeurons(d);
				case 91: return N91::getIncommingNeurons(d);
				case 92: return N92::getIncommingNeurons(d);
				case 93: return N93::getIncommingNeurons(d);
				case 94: return N94::getIncommingNeurons(d);
				case 95: return N95::getIncommingNeurons(d);
				case 96: return N96::getIncommingNeurons(d);
				case 97: return N97::getIncommingNeurons(d);
				case 98: return N98::getIncommingNeurons(d);
				case 99: return N99::getIncommingNeurons(d);
				default: __assume(0);
			}
		}
		template<typename IC, typename Weights>
		void fire(
			const NeuronId n,
			const unsigned int t,
			const Weights& w,
			IC& ic) const
		{
			switch (n) {
				case 0: N0::fire(t,w,ic); break;
				case 1: N1::fire(t,w,ic); break;
				case 2: N2::fire(t,w,ic); break;
				case 3: N3::fire(t,w,ic); break;
				case 4: N4::fire(t,w,ic); break;
				case 5: N5::fire(t,w,ic); break;
				case 6: N6::fire(t,w,ic); break;
				case 7: N7::fire(t,w,ic); break;
				case 8: N8::fire(t,w,ic); break;
				case 9: N9::fire(t,w,ic); break;
				case 10: N10::fire(t,w,ic); break;
				case 11: N11::fire(t,w,ic); break;
				case 12: N12::fire(t,w,ic); break;
				case 13: N13::fire(t,w,ic); break;
				case 14: N14::fire(t,w,ic); break;
				case 15: N15::fire(t,w,ic); break;
				case 16: N16::fire(t,w,ic); break;
				case 17: N17::fire(t,w,ic); break;
				case 18: N18::fire(t,w,ic); break;
				case 19: N19::fire(t,w,ic); break;
				case 20: N20::fire(t,w,ic); break;
				case 21: N21::fire(t,w,ic); break;
				case 22: N22::fire(t,w,ic); break;
				case 23: N23::fire(t,w,ic); break;
				case 24: N24::fire(t,w,ic); break;
				case 25: N25::fire(t,w,ic); break;
				case 26: N26::fire(t,w,ic); break;
				case 27: N27::fire(t,w,ic); break;
				case 28: N28::fire(t,w,ic); break;
				case 29: N29::fire(t,w,ic); break;
				case 30: N30::fire(t,w,ic); break;
				case 31: N31::fire(t,w,ic); break;
				case 32: N32::fire(t,w,ic); break;
				case 33: N33::fire(t,w,ic); break;
				case 34: N34::fire(t,w,ic); break;
				case 35: N35::fire(t,w,ic); break;
				case 36: N36::fire(t,w,ic); break;
				case 37: N37::fire(t,w,ic); break;
				case 38: N38::fire(t,w,ic); break;
				case 39: N39::fire(t,w,ic); break;
				case 40: N40::fire(t,w,ic); break;
				case 41: N41::fire(t,w,ic); break;
				case 42: N42::fire(t,w,ic); break;
				case 43: N43::fire(t,w,ic); break;
				case 44: N44::fire(t,w,ic); break;
				case 45: N45::fire(t,w,ic); break;
				case 46: N46::fire(t,w,ic); break;
				case 47: N47::fire(t,w,ic); break;
				case 48: N48::fire(t,w,ic); break;
				case 49: N49::fire(t,w,ic); break;
				case 50: N50::fire(t,w,ic); break;
				case 51: N51::fire(t,w,ic); break;
				case 52: N52::fire(t,w,ic); break;
				case 53: N53::fire(t,w,ic); break;
				case 54: N54::fire(t,w,ic); break;
				case 55: N55::fire(t,w,ic); break;
				case 56: N56::fire(t,w,ic); break;
				case 57: N57::fire(t,w,ic); break;
				case 58: N58::fire(t,w,ic); break;
				case 59: N59::fire(t,w,ic); break;
				case 60: N60::fire(t,w,ic); break;
				case 61: N61::fire(t,w,ic); break;
				case 62: N62::fire(t,w,ic); break;
				case 63: N63::fire(t,w,ic); break;
				case 64: N64::fire(t,w,ic); break;
				case 65: N65::fire(t,w,ic); break;
				case 66: N66::fire(t,w,ic); break;
				case 67: N67::fire(t,w,ic); break;
				case 68: N68::fire(t,w,ic); break;
				case 69: N69::fire(t,w,ic); break;
				case 70: N70::fire(t,w,ic); break;
				case 71: N71::fire(t,w,ic); break;
				case 72: N72::fire(t,w,ic); break;
				case 73: N73::fire(t,w,ic); break;
				case 74: N74::fire(t,w,ic); break;
				case 75: N75::fire(t,w,ic); break;
				case 76: N76::fire(t,w,ic); break;
				case 77: N77::fire(t,w,ic); break;
				case 78: N78::fire(t,w,ic); break;
				case 79: N79::fire(t,w,ic); break;
				case 80: N80::fire(t,w,ic); break;
				case 81: N81::fire(t,w,ic); break;
				case 82: N82::fire(t,w,ic); break;
				case 83: N83::fire(t,w,ic); break;
				case 84: N84::fire(t,w,ic); break;
				case 85: N85::fire(t,w,ic); break;
				case 86: N86::fire(t,w,ic); break;
				case 87: N87::fire(t,w,ic); break;
				case 88: N88::fire(t,w,ic); break;
				case 89: N89::fire(t,w,ic); break;
				case 90: N90::fire(t,w,ic); break;
				case 91: N91::fire(t,w,ic); break;
				case 92: N92::fire(t,w,ic); break;
				case 93: N93::fire(t,w,ic); break;
				case 94: N94::fire(t,w,ic); break;
				case 95: N95::fire(t,w,ic); break;
				case 96: N96::fire(t,w,ic); break;
				case 97: N97::fire(t,w,ic); break;
				case 98: N98::fire(t,w,ic); break;
				case 99: N99::fire(t,w,ic); break;
				default: __assume(0);
			}
		}
	};
}
