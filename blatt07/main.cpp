#include "Trie.hpp"

int main() {
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