#ifndef SUM_TRAITS_HPP
#define SUM_TRAITS_HPP

template <typename T>
class SumTraits {
	public:
		using SumValue = T;
};

template <>
class SumTraits<char> {
	public:
		using Sumvalue = int;
};
#endif

