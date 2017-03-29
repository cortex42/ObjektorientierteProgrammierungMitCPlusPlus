#include <cstdlib>
#include <iostream>
#include "Sum4.hpp"

template<typename T, std::size_t N>
constexpr std::size_t dim(T (&vec) [N]) { return N; }

struct MyTraits {
	using SumValue = long long int;
};

int main() {
	int numbers[] = {2147483647, 10};
	std::cout << "sum of numbers[] = " << sum(numbers, numbers + dim(numbers)) << std::endl;

	std::cout << "sum of numbers[] = " << sum<MyTraits>(numbers, numbers + dim(numbers)) << std::endl;
}

