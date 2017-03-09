#include "Trie.hpp"

int main() {
	// default constructor
	Trie<std::string> trie1;
	
	// copy constructor
	Trie<std::string> trie2(trie1);
	
	// assignment
	Trie<std::string> trie3;
	trie3 = trie2;
	
	
	// add something
	std::string test_string("world");
	trie1.add("hello", &test_string);
}
