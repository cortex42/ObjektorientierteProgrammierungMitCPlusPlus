#include "stack.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

int main(){	
    Stack stack;
    
	for(;;){
		std::cout << "UPN: ";

		std::string input;

		std::getline(std::cin, input);

		std::istringstream iss(input);
		std::vector<std::string> tokens;

		for (std::string each; std::getline(iss, each, ' '); tokens.push_back(each)) {}

		for(size_t i = 0; i < tokens.size(); ++i) {
			std::cout << "Token: " << tokens[i] << std::endl;
			double number;
			bool isNumber = false;
			
			try{
			    number = std::stod(tokens[i]);
			    isNumber = true;
			    stack.push(number);
			} catch (const std::invalid_argument& ia) {
			    // not a number
			}
			
			if(tokens[i].size() == 1 && !isNumber){
			    double op1, op2, result;
			    
    			switch(*(tokens[i].c_str())){
    			    case '+':
    			        op2 = stack.pop();
    			        op1 = stack.pop();
    			        
    			        result = op1 + op2;
    			    
    			        stack.push(result);
    			        break;
    			    case '-':
    			        op2 = stack.pop();
    			        op1 = stack.pop();
    			        
    			        result = op1 - op2;
    			        
    			        stack.push(result);
    			        break;
    			    case '*':
    			        op2 = stack.pop();
    			        op1 = stack.pop();
    			        
    			        result = op1 * op2;
    			        
    			        stack.push(result);
    			        break;
    			    case '/':
    			        op2 = stack.pop();
    			        op1 = stack.pop();
    			        
    			        result = op1 / op2;
    			    
    			        stack.push(result);
    			        break;
    			    default:
    			        std::cout << "unknown operator: " << tokens[i].c_str() << std::endl;
    			        break;
    			}
			}
		}
		
		while(!stack.isEmpty()){
		    std::cout << stack.pop() << std::endl;
		}
		
	}
	return 0;
}
