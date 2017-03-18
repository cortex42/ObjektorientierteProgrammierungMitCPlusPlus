#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <cassert>
#include <iostream>
#include <memory>

static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

template<typename T>
class Trie {
public:
    Trie() : node{std::make_shared<Node>()} { std::cout << "default constructor" << std::endl; }

    Trie(const Trie &other) : node{std::make_shared<Node>(*other.node)} {
        std::cout << "copy constructor" << std::endl;
    }

    ~Trie() {
        std::cout << "destructor" << std::endl;
    }

    friend void swap(Trie &first, Trie &other) {
        std::swap(first.node, other.node);
    }

    Trie &operator=(Trie other) {
        std::cout << "assignment" << std::endl;
        swap(*this, other);
        return *this;
    }

    void add(const std::string &key, T object) {
        if (key.length() == 0) {
            node->object = object;
            node->has_object = true;
        } else {
            char c = key[0];

            assert((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));

            if (c >= 'A' && c <= 'Z') {
                c += 32; // convert upper to lower case
            }

            if (!node->subTries[c]) {
                node->subTries[c] = std::make_shared<Trie>();
            }

            node->subTries[c]->add(key.substr(1), object);
        }
    }

    std::size_t count() const {
        std::size_t sum = 0;

        if (node->has_object) { sum++; };

        for (const char &c : alphabet) {
            if (node->subTries[c]) {
                sum += node->subTries[c]->count();
            }
        }

        return sum;
    }

    template<typename Visitor>
    void visit(const std::string &key, Visitor visitor) const {
        if (key.length() == 0) {
            visitObjects(visitor);
        } else {
            char c = key[0];

            assert((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));

            if (c >= 'A' && c <= 'Z') {
                c += 32; // convert upper to lower case
            }

            if (!node->subTries[c]) {
                return;
            } else {
                node->subTries[c]->visit(key.substr(1), visitor);
            }
        }
    }

private:
    struct Node;

public:

    class Pointer {
    public:
        Pointer(std::shared_ptr<Node> root) : node_ptr{root} {};

        bool defined() const {
            return node_ptr != nullptr;
        }

        bool descend(const char &c) {
            node_ptr = node_ptr->subTries.at(c)->node;

            return defined();
        }

        bool exists() const {
            return node_ptr->has_object;
        }

        const T &operator*() const {
            return node_ptr->object;
        }

        class Iterator {
        public:
            Iterator(std::map<char, std::shared_ptr<Trie>> &map, char c) : c{c}, map{map} {}

            bool operator!=(const Iterator &other) const {
                return getTrieAtKey() != other.getTrieAtKey();
            }

            Iterator &operator++() {
                while (c <= 'z') {
                    c++;
                    if (getTrieAtKey()) {
                        break;
                    }
                }

                return *this;
            }

            char operator*() const {
                return c;
            }

        private:
            const std::shared_ptr<Trie> getTrieAtKey() const {
                if (c <= 'z') {
                    return map.at(c);
                }

                return nullptr;
            }

            char c;
            std::map<char, std::shared_ptr<Trie>> &map;
        };

        Iterator begin() {
            return Iterator(node_ptr->subTries, 'a');
        }

        Iterator end() {
            return Iterator(node_ptr->subTries, 'z' + 1);
        }

    private:
        std::shared_ptr<Node> node_ptr;
    };

    Pointer descend() {
        return Pointer{node};
    }


private:
    template<typename Visitor>
    void visitObjects(Visitor visitor) const {
        if (node->has_object) { visitor(node->object); };

        for (const char &c : alphabet) {
            if (node->subTries[c]) {
                node->subTries[c]->visitObjects(visitor);
            }
        }
    }

    struct Node {
        T object;
        bool has_object;
        std::map<char, std::shared_ptr<Trie>> subTries;

        Node() : object{}, has_object{false} {
            for (const char &c : alphabet) {
                subTries[c] = nullptr;
            }
        }

        Node(const Node &other) : object{other.object}, has_object{other.has_object} {
            for (const char &c : alphabet) {
                subTries[c] = other.subTries.at(c);
            }
        }

        ~Node() {
        }
    };

    std::shared_ptr<Node> node;
};

#endif // TRIE_H
