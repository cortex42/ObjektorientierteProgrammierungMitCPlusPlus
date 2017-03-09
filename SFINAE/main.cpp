#include "range.hpp"
#include <iostream>

// allow range only for int and unsigned int

/*
template<typename T> struct is_integer{};
template<> struct is_integer<int> {
	using type = IntegralRange<int>;
};
template<> struct is_integer<unsigned int> {
	using type = IntegralRange<unsigned int>;
};

template<typename T>
typename is_integer<T>::type
range(T begin_val, T end_val) {
	return IntegralRange<T>(begin_val, end_val);
};
*/

// better
/*
template<typename T> struct is_integer : public std::false_type{};
template<> struct is_integer<int> : public std::true_type{};
template<> struct is_integer<unsigned int> : public std::true_type{};

template<typename T>
typename std::enable_if<
	is_integer<T>::value, // boolean-valued condition
	IntegralRange<T> // wanted type, if correct
>::type // is the wanted type, if correct
range(T begin_val, T end_val) {
	return IntegralRange<T>(begin_val, end_val);
}
*/

// even better

template<typename T>
typename std::enable_if<
	std::is_integral<T>::value, // boolean-valued condition
	IntegralRange<T> // wanted type, if correct
>::type // is the wanted type, if correct, if not then there is no "type" => exclusion per SFINAE
range(T begin_val, T end_val) {
	return IntegralRange<T>(begin_val, end_val);
}

int main() {
	IntegralRange<unsigned int> intrange = range(1u, 10u);
	
	for(auto i = intrange.begin(); i != intrange.end(); ++i) {
		std::cout << *i << std::endl;
	}
}