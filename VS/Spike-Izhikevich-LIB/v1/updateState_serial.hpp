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

#include <stdio.h>		// for printf // stdio functions are used since C++ streams aren't necessarily thread safe
//#include <intrin.h>		// needed for compiler intrinsics
#include <array>

#include "../../Spike-Tools-LIB/SpikeSet1Sec.hpp"
#include "../../Spike-Tools-LIB/Constants.hpp"

#include "../../Spike-Izhikevich-LIB/SpikeTypesIzhikevich.hpp"


namespace spike
{
	namespace v1
	{

		static inline int ltpIndex(const int neuronId, const int time, const int N)
		{
			return (time * N) + neuronId;
		}

		template <size_t nNeurons>
		static inline void updateState_X64_Blitz(float v[], float u[], const float ic[], const float is[], const float a[])
		{
			for (size_t i = 0; i < nNeurons; ++i)
			{
				const float tt = 140 - u[i] + (is[i] * ic[i]);
				//const float tt = 140 - u[i] + ic[i];

				v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // for numerical stability
				v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // time step is 0.5 ms

				u[i] += a[i] * ((0.2f * v[i]) - u[i]);
			}
		}

		template <size_t nNeurons>
		static inline void updateState_X64(float v[], float u[], const float ic[], const float is[], const float a[], const float b[])
		{
			//__debugbreak();
			//#pragma loop(hint_parallel(4))
			for (size_t i = 0; i < nNeurons; ++i)
			{

				BOOST_ASSERT_MSG_HJ(!std::isfinite(v[i]), "v[" << i << "] is not finite");
				BOOST_ASSERT_MSG_HJ(!std::isfinite(u[i]), "u[" << i << "] is not finite");

				//const float tt = 140 - u[i] + (is[i] * ic[i]);
				const float tt = 140 - u[i] + ic[i];

				v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // for numerical stability
				v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // time step is 0.5 ms

				u[i] += a[i] * ((b[i] * v[i]) - u[i]);

				if (u[i] > 50)
				{
					u[i] = 50;
				}
				if (v[i] > 100)
				{
					v[i] = 100;
				}
			}
		}

		template <size_t N, size_t D>
		static inline void updateStdp_X64(const unsigned int t, float ltd[N], float ltp[N][1001 + D])
		{
			for (unsigned int i = 0; i < N; ++i)
			{
				ltd[i] *= 0.95f;
				ltp[i][t + D + 1] = 0.95f * ltp[i][t + D];
			}
		}

		template <size_t nNeurons>
		static inline void updateState_Sse(float v[], float u[], const float ic[], const float is[], const float a[], const float b[])
		{

			const __m128 c1 = _mm_set1_ps(0.5f);
			const __m128 c2 = _mm_set1_ps(0.04f);
			const __m128 c3 = _mm_set1_ps(5.0f);
			const __m128 c4 = _mm_set1_ps(140.0f);

			for (size_t i = 0; i < nNeurons; i += 4)
			{

				const __m128 ici = _mm_load_ps(&ic[i]);
				//const __m128 isi = _mm_load_ps(&is[i]);

				__m128 vi = _mm_load_ps(&v[i]);
				__m128 ui = _mm_load_ps(&u[i]);

				// + 140 - u[i] + (is[i] * ic[i])
				//	const __m128 tt = _mm_add_ps(_mm_sub_ps(_mm_mul_ps(isi, ici), ui), c4);

				// + 140 - u[i] + ic[i]
				const __m128 tt = _mm_add_ps(_mm_sub_ps(ici, ui), c4);

				//////////////////////////////////////////
				//	v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // for numerical stability
				const __m128 x1a = _mm_mul_ps(vi, c2);
				const __m128 x2a = _mm_add_ps(x1a, c3);
				const __m128 x3a = _mm_mul_ps(x2a, vi);
				const __m128 x4a = _mm_add_ps(x3a, tt);
				const __m128 x5a = _mm_mul_ps(x4a, c1);
				vi = _mm_add_ps(x5a, vi);

				//////////////////////////////////////////
				//	v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + tt); // time step is 0.5 ms
				const __m128 x1b = _mm_mul_ps(vi, c2);
				const __m128 x2b = _mm_add_ps(x1b, c3);
				const __m128 x3b = _mm_mul_ps(x2b, vi);
				const __m128 x4b = _mm_add_ps(x3b, tt);
				const __m128 x5b = _mm_mul_ps(x4b, c1);
				vi = _mm_add_ps(x5b, vi);

				//////////////////////////////////////////
				//	u[i] += a[i] * ((b[i] * v[i]) - u[i]);
				const __m128 bi = _mm_load_ps(&b[i]);
				const __m128 y1 = _mm_mul_ps(vi, bi);
				const __m128 y2 = _mm_sub_ps(y1, ui);

				const __m128 ai = _mm_load_ps(&a[i]);
				const __m128 y3 = _mm_mul_ps(y2, ai);
				ui = _mm_add_ps(y3, ui);

				/*
				BOOST_ASSERT_MSG_HJ(std::isfinite(vi.m128_f32[0]), "v[" << i << "][0] = " << vi.m128_f32[0] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(vi.m128_f32[1]), "v[" << i << "][1] = " << vi.m128_f32[1] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(vi.m128_f32[2]), "v[" << i << "][2] = " << vi.m128_f32[2] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(vi.m128_f32[3]), "v[" << i << "][3] = " << vi.m128_f32[3] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(ui.m128_f32[0]), "u[" << i << "][0] = " << ui.m128_f32[0] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(ui.m128_f32[1]), "u[" << i << "][1] = " << ui.m128_f32[1] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(ui.m128_f32[2]), "u[" << i << "][2] = " << ui.m128_f32[2] << " is not finite");
				BOOST_ASSERT_MSG_HJ(std::isfinite(ui.m128_f32[3]), "u[" << i << "][3] = " << ui.m128_f32[3] << " is not finite");
				*/
				_mm_store_ps(&v[i], vi);
				_mm_store_ps(&u[i], ui);
			}
		}

		template <size_t N, Delay D>
		static inline void updateStdp_Sse(const unsigned int t, float ltd[N], float ltp[N][1001 + D])
		{
			for (unsigned int i = 0; i < N; i += 4)
			{
				//	ltd[i] *= 0.95f;
				_mm_store_ps(&ltd[i], _mm_mul_ps(_mm_set1_ps(0.95f), _mm_load_ps(&ltd[i])));
				//	ltp[ltpIndex(i, t+D+1)+0] = 0.95f * ltp[ltpIndex(i, t+D)+0];
				_mm_store_ps(&ltp[i][t + D + 1], _mm_mul_ps(_mm_set1_ps(0.95f), _mm_load_ps(&ltp[i][t + D])));
			}
		}

		template <size_t nNeurons>
		static inline void updateState_Avx(float v[], float u[], const float ic[], const float is[], const float a[])
		{
			for (size_t i = 0; i < nNeurons; i += 8)
			{

				const __m256 ai = _mm256_load_ps(&a[i]);
				const __m256 ici = _mm256_load_ps(&ic[i]);
				const __m256 isi = _mm256_load_ps(&is[i]);

				__m256 vi = _mm256_load_ps(&v[i]);
				__m256 ui = _mm256_load_ps(&u[i]);

				const __m256 c1 = _mm256_set1_ps(0.5f);
				const __m256 c2 = _mm256_set1_ps(0.04f);
				const __m256 c3 = _mm256_set1_ps(5.0f);
				const __m256 c4 = _mm256_set1_ps(140.0f);

				// + 140 - u[i] + (is[i] * ic[i])
				//	const __m256 tt = _mm256_add_ps(_mm256_sub_ps(_mm256_mul_ps(isi, ici), ui), c4);

				// + 140 - u[i] + ic[i]
				const __m256 tt = _mm256_add_ps(_mm256_sub_ps(ici, ui), c4);

				//////////////////////////////////////////
				//	v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + 140 - u[i] + ic[i]); // for numerical stability
				const __m256 x1a = _mm256_mul_ps(vi, c2);
				const __m256 x2a = _mm256_add_ps(x1a, c3);
				const __m256 x3a = _mm256_mul_ps(x2a, vi);
				const __m256 x4a = _mm256_add_ps(x3a, tt);
				const __m256 x5a = _mm256_mul_ps(x4a, c1);
				vi = _mm256_add_ps(x5a, vi);

				//////////////////////////////////////////
				//	v[i] += 0.5f * ((((0.04f * v[i]) + 5) * v[i]) + 140 - u[i] + ic[i]); // time step is 0.5 ms
				const __m256 x1b = _mm256_mul_ps(vi, c2);
				const __m256 x2b = _mm256_add_ps(x1b, c3);
				const __m256 x3b = _mm256_mul_ps(x2b, vi);
				const __m256 x4b = _mm256_add_ps(x3b, tt);
				const __m256 x5b = _mm256_mul_ps(x4b, c1);
				vi = _mm256_add_ps(x5b, vi);

				//////////////////////////////////////////
				//	u[i] += a[i] * ((0.2f * v[i]) - u[i]);
				const __m256 c5 = _mm256_set1_ps(0.2f);

				const __m256 y1 = _mm256_mul_ps(vi, c5);
				const __m256 y2 = _mm256_sub_ps(y1, ui);
				const __m256 y3 = _mm256_mul_ps(y2, ai);
				ui = _mm256_add_ps(y3, ui);

				_mm256_store_ps(&v[i], vi);
				_mm256_store_ps(&u[i], ui);
			}
		}

		template <size_t nNeurons, Delay D>
		static inline void updateStdp_Avx(const unsigned int t, float ltd[], float ltp[][1001 + D])
		{
			for (unsigned int i = 0; i < nNeurons; i += 8)
			{
				//	ltd[i] *= 0.95f;
				_mm256_store_ps(&ltd[i], _mm256_mul_ps(_mm256_set1_ps(0.95f), _mm256_load_ps(&ltd[i])));
				//	ltp[ltpIndex(i, t+D+1)+0] = 0.95f * ltp[ltpIndex(i, t+D)+0];
				_mm256_store_ps(&ltp[i][t + D + 1], _mm256_mul_ps(_mm256_set1_ps(0.95f), _mm256_load_ps(&ltp[i][t + D])));
			}
		}
	}
}