#include "stack.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(){	

	for(;;){
		std::cout << "UPN: ";

		std::string input;

		std::getline(std::cin, input);

		std::istringstream iss(input);
		std::vector<std::string> tokens;

		for (std::string each; std::getline(iss, each, ' '); tokens.push_back(each)) {}

		for(size_t i = 0; i < tokens.size(); ++i) {
			std::cout << tokens[i] << std::endl;
		}
	}
	return 0;
}
