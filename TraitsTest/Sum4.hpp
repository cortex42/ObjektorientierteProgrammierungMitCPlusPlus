#ifndef SUM4_HPP
#define SUM4_HPP

#include "SumTraits.hpp"

template<typename ST, typename T>
inline typename ST::SumValue sum(const T* begin, const T* end) {
	using SumValue = typename ST::SumValue;
	auto result = SumValue();
	
	for(auto it = begin; it < end; ++it) {
		result += *it;
	}

	return result;
}

template<typename T>
inline typename SumTraits<T>::SumValue sum(const T* begin, const T* end) {
	return sum<SumTraits<T>, T>(begin, end);
}

#endif //SUM4_HPP
