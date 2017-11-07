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
#include <sstream>
#include <bitset>
#include <array>
#include <vector>
#include <atomic>

#include <immintrin.h>
#include <intrin.h> // for _BitScanForward

#include "assert.ipp"
#include "bit.ipp"


namespace tools
{
	namespace intrin
	{
		using namespace ::tools::assert;

		namespace priv
		{

			/******************************************
			* get
			*******************************************/
			inline unsigned long long get_u64(const __m128i& V, const size_t i)
			{
				assert_msg(i < 2, "");
				union
				{
					__m128i v;
					unsigned long long a[2];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline float get_f32(const __m128& V, const size_t i)
			{
				assert_msg(i < 4, "");
				union
				{
					__m128 v;
					float a[4];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline int get_i32(const __m128i& V, const size_t i)
			{
				assert_msg(i < 4, "");
				union
				{
					__m128i v;
					int a[4];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline unsigned int get_u32(const __m128i& V, const size_t i)
			{
				assert_msg(i < 4, "");
				union
				{
					__m128i v;
					unsigned int a[4];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline short get_i16(const __m128i& V, const size_t i)
			{
				assert_msg(i < 8, "");
				union
				{
					__m128i v;
					short a[8];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline short get_i16(const __m64& V, const size_t i)
			{
				assert_msg(i < 4, "");
				union
				{
					__m64 v;
					short a[4];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline unsigned short get_u16(const __m128i& V, const size_t i)
			{
				assert_msg(i < 8, "");
				union
				{
					__m128i v;
					unsigned short a[8];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline unsigned char get_u8(const __m128i& V, const size_t i)
			{
				assert_msg(i < 16, "");
				union
				{
					__m128i v;
					unsigned char a[16];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			inline unsigned char get_u8(const __m128& V, const size_t i)
			{
				assert_msg(i < 16, "");
				union
				{
					__m128 v;
					unsigned char a[16];
				} converter;
				converter.v = V;
				return converter.a[i];
			}
			/*	inline unsigned char get_u8(const __m256i V, const size_t i)
			{
			assert_msg(i < 32, "");
			union
			{
			__m256i v;
			unsigned char a[32];
			} converter;
			converter.v = V;
			return converter.a[i];
			}
			*/	inline signed char get_i8(const __m128i& V, const size_t i)
			{
				assert_msg(i < 16, "");
				union
				{
					__m128i v;
					signed char a[16];
				} converter;
				converter.v = V;
				return converter.a[i];
			}


			/******************************************
			* set
			*******************************************/
			inline void set_u8(__m128i& v, const size_t i, const unsigned char d)
			{
				assert_msg(i < 16, "");
				union
				{
					__m128i v;
					unsigned char a[16];
				} converter;
				converter.v = v;
				converter.a[i] = d;
				v = converter.v;
			}
			inline void set_u16(__m128i& v, const size_t i, const unsigned short d)
			{
				assert_msg(i < 8, "");
				union
				{
					__m128i v;
					unsigned short a[8];
				} converter;
				converter.v = v;
				converter.a[i] = d;
				v = converter.v;
			}
			inline void set_u32(__m128i& v, const size_t i, const unsigned int d)
			{
				assert_msg(i < 4, "");

				union
				{
					__m128i v;
					unsigned int a[4];
				} converter;
				converter.v = v;
				converter.a[i] = d;
				v = converter.v;
			}
			inline void set_u64(__m128i& v, const size_t i, const unsigned long long d)
			{
				assert_msg(i < 2, "");

				union
				{
					__m128i v;
					unsigned long long a[2];
				} converter;
				converter.v = v;
				converter.a[i] = d;
				v = converter.v;
			}


			/******************************************
			* set to zero
			*******************************************/

			template <typename T>
			inline void setToZero(T& i)
			{
				i = 0;
			}
			inline void setToZero(__m128i& i)
			{
				i = _mm_setzero_si128();
			}

			template <size_t S>
			inline void setToZero(std::array<__m128i, S>& vec)
			{
				std::fill(vec.begin(), vec.end(), _mm_setzero_si128());
			}

			inline void setToZero(std::vector<__m128i>& vec)
			{
				std::fill(vec.begin(), vec.end(), _mm_setzero_si128());
			}
		}

		const bool USE_POPCNT_INSTRUCTION = true;

		bool BSF(unsigned long * Index, unsigned long Mask)
		{
			#ifdef _MSC_VER
			return _BitScanForward(Index, Mask) != 0;
			#else
			if (Mask == 0)
			{
				return false;
			}
			else
			{
				*Index = static_cast<unsigned long>(__builtin_ctz(Mask));
				return true;
			}
			#endif
		}

		__inline void _mm_store_epi32(int * ptr, __m128i val)
		{
			_mm_store_si128(reinterpret_cast<__m128i * const>(ptr), val);
		}
		__inline __m128i _mm_load_epi32(const int * ptr)
		{
			return _mm_load_si128(reinterpret_cast<const __m128i * const>(ptr));
		}
		__inline __m128i _mm_ror_epi32(__m128i _A)
		{
			return _mm_shuffle_epi32(_A, ((0 << 6) | (3 << 4) | (2 << 2) | (1 << 0))); //ror rotate right
		}
		__inline bool _mm_test_has_ones(__m128 _A, __m128i mask)
		{
			return _mm_testz_si128(mask, _mm_castps_si128(_A)) == 0;
		}
		__inline bool _mm_test_has_zeros(__m128i _A, __m128i mask)
		{
			return _mm_testc_si128(_A, mask) == 0;
			//return _mm_test_all_ones(_A) == 0;
		}

		#ifdef _MSC_VER
		#pragma warning (disable:4700)
		#endif
		__inline __m128i _mm_setones_si128()
		{
			__m128i dummy;
			//#if _DEBUG
			dummy = _mm_setzero_si128();
			//#endif

			return _mm_cmpeq_epi32(dummy, dummy);
			#ifdef _MSC_VER
			#pragma warning (default:4700)
			#endif
		}

		inline unsigned int xor2(const unsigned int d0, const unsigned int d1)
		{
			return d0 ^ d1;
		}
		inline __m128i xor2(const __m128i d0, const __m128i d1)
		{
			return _mm_xor_si128(d0, d1);
		}
		/*
		inline __m256i xor_(const __m256i d0, const __m256i d1) {
		return _mm256_xor_si256(d0, d1);
		}
		*/
		inline size_t nextSetBit_Reference(unsigned int n)
		{
			// for testing purposes return the sum
			size_t sum = 0;
			for (size_t i = 0; i < 32; ++i)
			{
				if ((n >> i) & 0x1)
				{
					sum += i;
				}
			}
			return sum;
		}


		inline size_t nextSetBit_Fast1(unsigned int n)
		{
			// method used in Rbm; for testing purposes return the sum
			size_t sum = 0;
			if (n == static_cast<unsigned int>(0x1 << 31))
			{	// this because it is possible to do n >>= 32
				sum = 31;	// i = 31
			}
			else
			{
				unsigned int wIndex = 0;
				for (unsigned long i; BSF(&i, n); (wIndex++, n >>= ++i))
				{
					wIndex += i;
					sum += wIndex;
				}
			}
			return sum;
		}

		inline size_t nextSetBit_Fast2(unsigned int n)
		{
			// for testing purposes return the sum
			size_t sum = 0;
			unsigned long i;
			while (n != 0)
			{
				BSF(&i, n);
				n &= (n - 1);
				sum += i;
			}
			return sum;
		}

		inline size_t nextSetBit_Slow1(unsigned int n)
		{
			// for testing purposes return the sum
			// this method is excruciatinly slow because the _bittestandreset generates a memory reference.

			size_t sum = 0;
			unsigned long i;
			while (n != 0)
			{
				BSF(&i, n);

				//DEBUG_BREAK();
				//_bittestandreset(&n, i);
				sum += i;
			}
			return sum;
		}

		inline unsigned int hammingWeight_Reference(const unsigned short eq1)
		{
			unsigned int count = 0;
			for (int i = 0; i < 16; ++i)
			{
				if ((eq1 >> i) & 0x1) count++;
			}
			#ifdef _MSC_VER
			__assume(count <= 16);
			#endif
			return count;
		}
		inline size_t hammingWeight_Fast2(unsigned int n)
		{
			// twice faster than hammingWeight_Fast1
			size_t c; // c accumulates the total bits set in n
			for (c = 0; n; ++c)
			{
				n &= n - 1; // clear the least significant bit set
			}
			#ifdef _MSC_VER
			__assume(c <= 32);
			#endif
			return c;
		}
		inline size_t hammingWeight_Fast_64(unsigned long long n)
		{
			// twice faster than hammingWeight_Fast1
			//__debugbreak();
			size_t c; // c accumulates the total bits set in n
			for (c = 0; n; ++c)
			{
				n &= n - 1; // clear the least significant bit set
			}
			#ifdef _MSC_VER
			__assume(c <= 64);
			#endif
			return c;
		}

		inline unsigned int hammingWeight_Fast1(unsigned int i)
		{
			i = i - ((i >> 1) & 0x55555555);
			i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
			return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
		}

		inline size_t countBits(const unsigned int eq1)
		{
			if (USE_POPCNT_INSTRUCTION)
			{
				#ifdef _MSC_VER
				return static_cast<size_t>(__popcnt(eq1));
				#else
				return static_cast<size_t>(__builtin_popcount(eq1));
				#endif
			}
			else
			{
				return static_cast<size_t>(hammingWeight_Fast2(eq1));
			}
		}

		inline size_t countBits(const unsigned long long eq1)
		{
			if (USE_POPCNT_INSTRUCTION)
			{
				#ifdef _MSC_VER
				return static_cast<size_t>(__popcnt64(eq1));
				#else
				return static_cast<size_t>(__builtin_popcountll(eq1));
				#endif
			}
			else
			{
				return static_cast<size_t>(hammingWeight_Fast_64(eq1));
			}
		}

		inline size_t countSetBits(const void * const ptr, const size_t nBitsToCount)
		{
			size_t sum = 0;
			//TODO: can be much faster with bitCount
			for (size_t i = 0; i < nBitsToCount; ++i)
			{
				if (::tools::bit::getBit(ptr, i))
				{
					sum++;
				}
			}
			return sum;
		}

		template <typename Alloc>
		inline size_t countSetBits(const std::vector<unsigned long long, Alloc>& d, const size_t nBitsToCount)
		{
			return countSetBits(d.data(), nBitsToCount);
		}


		inline bool isAllZeros(const __m128i xmm)
		{
			return _mm_movemask_epi8(_mm_cmpeq_epi8(xmm, _mm_setzero_si128())) == 0xFFFF;
		}

		inline bool isAllOnes(const __m128i xmm)
		{
			return _mm_movemask_epi8(_mm_cmpeq_epi8(xmm, _mm_setzero_si128())) == 0xFFFF;
		}

		inline std::string toString_f32(const __m128 i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 4; ++j) stringStream << priv::get_f32(i, j) << " ";
			return stringStream.str();
		}
		inline std::string toString_u32(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 4; ++j) stringStream << priv::get_u32(i, j) << " ";
			return stringStream.str();
		}
		inline std::string toString_i32(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 4; ++j) stringStream << priv::get_i32(i, j) << " ";
			return stringStream.str();
		}

		inline std::string toString_i16(const __m64 i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 4; ++j) stringStream << priv::get_i16(i, j) << " ";
			return stringStream.str();
		}
		inline std::string toString_u16(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 8; ++j) stringStream << priv::get_u16(i, j) << " ";
			return stringStream.str();
		}

		inline std::string toString_u8(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 16; ++j) stringStream << static_cast<int>(priv::get_u8(i, j)) << " ";
			return stringStream.str();
		}
		inline std::string toString_u8(const __m128 i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 16; ++j) stringStream << static_cast<int>(priv::get_u8(i, j)) << " ";
			return stringStream.str();
		}
		/*	inline std::string toString_u8(const __m256i i)
		{
		std::ostringstream stringStream;
		for (size_t j = 0; j < 32; ++j) stringStream << static_cast<int>(i.m256i_u8[j]) << " ";
		return stringStream.str();
		}
		*/
		inline std::string toString_i8(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 16; ++j) stringStream << static_cast<int>(priv::get_i8(i, j)) << " ";
			return stringStream.str();
		}

		inline std::string toBinary_u8(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 16; ++j) stringStream << std::bitset<8>(priv::get_u8(i, j)) << " ";
			return stringStream.str();
		}
		/*	inline std::string toBinary_u8(const __m256i i)
		{
		std::ostringstream stringStream;
		for (size_t j = 0; j < 32; ++j) stringStream << std::bitset<8>(get_u8(i, j)) << " ";
		return stringStream.str();
		}
		*/
		inline std::string toBinary_u32(const __m128i i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 4; ++j) stringStream << std::bitset<32>(priv::get_u32(i, j)) << " ";
			return stringStream.str();
		}
		inline std::string toBinary_u8(const __m128 i)
		{
			std::ostringstream stringStream;
			for (size_t j = 0; j < 16; ++j) stringStream << std::bitset<8>(priv::get_u8(i, j)) << " ";
			return stringStream.str();
		}


		template <size_t NBITS>
		inline std::string toBinary(const unsigned long long i)
		{
			std::ostringstream stringStream;
			std::bitset<NBITS> x(i);
			stringStream << x;
			return stringStream.str();
		}
		template <typename Alloc>
		inline std::string toBinary(const std::vector<unsigned long long, Alloc>& v)
		{
			std::ostringstream stringStream;
			for (size_t pos2 = 0; pos2 < v.size(); ++pos2)
			{
				stringStream << ::tools::toBinary<64>(v[pos2]) << " ";
			}
			return stringStream.str();
		}
		inline std::string toBinary(const __m128i i)
		{
			return toBinary_u8(i);
		}
		inline std::string toBinary(const float floatVar)
		{
			#ifdef _MSC_VER
			int fl = *(int*)&floatVar;
			std::ostringstream stringStream;
			for (int i = 31; i >= 0; --i)
			{
				if (i == 22) stringStream << ":";
				stringStream << ((((1 << i) & fl) != 0) ? "1" : "0");
			}
			return stringStream.str();
			#else
			//DEBUG_BREAK();
			return "";
			#endif
		}
		inline std::string toBinary(const double doubleVar)
		{
			#ifdef _MSC_VER
			long long fl = *(long long*)&doubleVar;
			std::ostringstream stringStream;
			for (int i = 63; i >= 0; --i)
			{
				if (i == 51) stringStream << ":";
				stringStream << ((((1ull << i) & fl) != 0) ? "1" : "0");
			}
			return stringStream.str();
			#else
			//DEBUG_BREAK();
			return "";
			#endif
		}

		inline void set_u32(__m128i& v, const unsigned int * const d)
		{
			//__debugbreak();
			//if (v.m128i_u64[1] != v2.m128i_u64[1])
			if (true)
			{
				v = _mm_set_epi32(static_cast<int>(d[3]), static_cast<int>(d[2]), static_cast<int>(d[1]), static_cast<int>(d[0]));
			}
			else
			{
				const __m128i * const dPtr = reinterpret_cast<const __m128i * const>(d);
				v = _mm_load_si128(dPtr);
			}
			//__debugbreak();
		}


		inline void set_u8(__m128i& v, const size_t i, const unsigned char d)
		{
			assert_msg(i < 16, "");
			union
			{
				__m128i v;
				unsigned char a[16];
			} converter;
			converter.v = v;
			converter.a[i] = d;
			v = converter.v;
		}


		inline void set_u32(__m128i& v, const size_t i, const unsigned int d)
		{
			//__m128i v2 = v;
			//v2.m128i_u32[i] = d;

			//__debugbreak();
			assert_msg(i < 4, "");


			if (false)
			{
				#ifdef _MSC_VER
				v.m128i_u32[i] = d;
				#endif
			}
			else if (false)
			{

				const __m128i mask = _mm_cmpeq_epi32(_mm_set1_epi32(static_cast<int>(i)), _mm_set_epi32(3, 2, 1, 0));
				//std::cout << "mask:" << ::tools::toBinary_u32(mask) << std::endl;
				__m128i data = _mm_set1_epi32(static_cast<int>(d));
				//std::cout << "data1:" << ::tools::toBinary_u32(data) << std::endl;
				data = _mm_and_si128(data, mask);
				//std::cout << "data2:" << ::tools::toBinary_u32(data) << std::endl;
				v = _mm_andnot_si128(mask, v);
				//std::cout << "v:" << ::tools::toBinary_u32(v) << std::endl;
				v = _mm_or_si128(v, data);
				//std::cout << "v:" << ::tools::toBinary_u32(v) << std::endl;
			}
			else
			{
				union
				{
					__m128i v;
					unsigned int a[4];
				} converter;
				converter.v = v;
				converter.a[i] = d;
				v = converter.v;
			}
			//if (v.m128i_u64[0] != v2.m128i_u64[0]) __debugbreak();
			//if (v.m128i_u64[1] != v2.m128i_u64[1]) __debugbreak();

			//__debugbreak();
		}

		inline static size_t popcnt1(const unsigned long long i)
		{
			return countBits(i);
		}

		inline static size_t popcnt1(const __m128i i)
		{
			return
				popcnt1(static_cast<unsigned long long>(priv::get_u64(i, 0))) +
				popcnt1(static_cast<unsigned long long>(priv::get_u64(i, 1)));
		}

		template <class T>
		inline static unsigned int popcnt1(const std::vector<T>& i)
		{
			unsigned int c = 0;
			for (const T t : i) c += popcnt1(t);
			return c;
		}
		/*
		template <typename T, size_t C>
		inline static unsigned int popcnt1(const std::array<T, C>& a) {
		unsigned int c = 0;
		for (size_t i = 0; i < C; ++i) c += popcnt1(a[i]);
		return c;
		}
		*/
		inline static __m128i popcnt4(const __m128i a, const __m128i b, const __m128i c, const __m128i d)
		{
			//__debugbreak();
			return _mm_add_epi32(
				_mm_setr_epi32(
					static_cast<int>(popcnt1(priv::get_u64(a, 1))),
					static_cast<int>(popcnt1(priv::get_u64(b, 1))),
					static_cast<int>(popcnt1(priv::get_u64(c, 1))),
					static_cast<int>(popcnt1(priv::get_u64(d, 1)))),
				_mm_setr_epi32(
					static_cast<int>(popcnt1(priv::get_u64(a, 0))),
					static_cast<int>(popcnt1(priv::get_u64(b, 0))),
					static_cast<int>(popcnt1(priv::get_u64(c, 0))),
					static_cast<int>(popcnt1(priv::get_u64(d, 0))))
			);
			//__debugbreak();
		}
		template<bool T>
		inline static __m128i popcnt4(const __m128i a, const __m128i b, const __m128i c, const __m128i d, const __m128i tailMask)
		{
			if (T)
			{
				return popcnt4(_mm_and_si128(a, tailMask), _mm_and_si128(b, tailMask), _mm_and_si128(c, tailMask), _mm_and_si128(d, tailMask));
			}
			return popcnt4(a, b, c, d);
		}

		inline static __m128i popcnt3(const __m128i a, const __m128i b, const __m128i c)
		{
			//__debugbreak();

			return _mm_add_epi32(
				_mm_setr_epi32(
					static_cast<int>(popcnt1(priv::get_u64(a, 1))),
					static_cast<int>(popcnt1(priv::get_u64(b, 1))),
					static_cast<int>(popcnt1(priv::get_u64(c, 1))), 0),
				_mm_setr_epi32(
					static_cast<int>(popcnt1(priv::get_u64(a, 0))),
					static_cast<int>(popcnt1(priv::get_u64(b, 0))),
					static_cast<int>(popcnt1(priv::get_u64(c, 0))), 0)
			);
		}
		inline static __m128i popcnt3(const unsigned long long a, const unsigned long long b, const unsigned long long c)
		{
			return _mm_setr_epi32(
				static_cast<int>(popcnt1(a)),
				static_cast<int>(popcnt1(b)),
				static_cast<int>(popcnt1(c)), 0);
		}
		template<bool T>
		inline static __m128i popcnt3(const __m128i a, const __m128i b, const __m128i c, const __m128i tailMask)
		{
			if (T)
			{
				return popcnt3(_mm_and_si128(a, tailMask), _mm_and_si128(b, tailMask), _mm_and_si128(c, tailMask));
			}
			return popcnt3(a, b, c);
		}


		inline static unsigned int sum(const __m128i a)
		{
			const __m128i b = _mm_hadd_epi32(a, a);
			const __m128i c = _mm_hadd_epi32(b, b);
			return priv::get_u32(c, 0);
		}

		inline static unsigned int sum(const __m128i a, const __m128i b)
		{
			return sum(_mm_add_epi32(a, b));
		}

		inline static unsigned int sum(const __m128i a, const __m128i b, const __m128i c, const __m128i d)
		{
			return sum(_mm_add_epi32(_mm_add_epi32(a, b), _mm_add_epi32(c, d)));
		}
	}
}
