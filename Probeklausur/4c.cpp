#include <vector>
#include <iostream>

int main() {
	std::vector<double> a{1,2,3,4,5,6};

	for(std::vector<double>::iterator it = a.begin(); it != a.end(); ++it) {
		*it *= 2;
		std::cout << *it << "\n";
	}

	return 0;
}

