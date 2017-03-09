#include "Trie.hpp"

void visit(const std::string &word) {
    std::cout << word << std::endl;
}

int main() {
    // default constructor
    Trie<std::string> trie1;

    // copy constructor
    Trie<std::string> trie2(trie1);

    // assignment
    Trie<std::string> trie3;
    trie3 = trie2;


    // add something
    std::string test_string_world("world");
    std::string test_string_foo("foo");
    trie1.add("hello", test_string_world);
    std::cout << trie1.count() << std::endl;
    trie1.add("hell", test_string_foo);
    std::cout << trie1.count() << std::endl;

    // visit
    trie1.visit("hell", visit);

    // replace
    trie1.add("hell", std::string("bar"));
    std::cout << trie1.count() << std::endl;
    trie1.visit("hell", visit);

    // todo check with valgrind
}
