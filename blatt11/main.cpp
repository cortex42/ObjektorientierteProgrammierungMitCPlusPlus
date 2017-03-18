#include <iostream>
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


    Trie<std::string> trie;
    trie.add("a", "a");
    trie.add("ab", "ab");
    trie.add("abc", "abc");
    trie.add("abcd", "abcd");
    std::cout << trie.count() << std::endl;

    std::string key("abcd");

    Trie<std::string>::Pointer ptr = trie.descend();
    if (ptr.defined()) {
        for (char ch : key) {
            if (!ptr.descend(ch)) break;
            if (ptr.exists()) {
                std::cout << *ptr << std::endl;
            }
        }
    }

    // test Iterator
    trie.add("b", "b");
    trie.add("m", "m");
    trie.add("z", "z");
    ptr = trie.descend();

    if (ptr.defined()) {
        std::cout << "continuation possible with: ";
        for (char ch : ptr) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}