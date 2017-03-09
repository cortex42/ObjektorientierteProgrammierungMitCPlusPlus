#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <cassert>
#include <iostream>

static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

template<typename T>
class Trie {
    public:
        Trie() : node{ new Node() } { std::cout << "default constructor" << std::endl; }
        Trie(const Trie& other) : node { new Node(*other.node) } { std::cout << "copy constructor" << std::endl; }
        ~Trie() {
            delete node;
            node = nullptr;
            std::cout << "destructor" << std::endl;
        }

	friend void swap(Trie& first, Trie& other) {
                std::swap(first.node, other.node);
        }

        Trie& operator=(Trie other) {
            std::cout << "assignment" << std::endl;
	    swap(*this, other);
	    return *this;
	}

        void add(const std::string& key, const T* object) {
		if(key.length() == 0) {
			node->object = object;
		}else{
			char c = key[0];

			assert((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));

			if(c >= 'A' && c <= 'Z'){
				c += 32; // convert upper to lower case
			}

			if(!node->subTries[c]) {
				node->subTries[c] = new Trie();
			}	
				
			node->subTries[c]->add(key.substr(1), object);
		}
		
	}
	
        std::size_t count() const {
		std::size_t sum = 0;

		for(const char& c : alphabet) {
			if(node->subTries[c]) {
				sum += node->subTries[c]->count();
			}
		}

		return sum;
	}

        template<typename Visitor>
        void visit(const std::string& key, Visitor visitor) const {
		// todo
	}

    private:
	struct Node {
	    const T* object; // pointer to constant data
            std::map<char,Trie*> subTries;

            Node() : object{nullptr} {
                for(const char& c : alphabet) {
                    subTries[c] = nullptr;
                }
            }

            Node(const Node& other) : object { other.object } {
                for(const char& c : alphabet) {
                    subTries[c] = other.subTries.at(c);
                }
            }

            ~Node() {
                delete object;
                object = nullptr;
                for(const char& c : alphabet) {
                    delete subTries[c];
                    subTries[c] = nullptr;
                }
            }
        };
	Node* node;
};

#endif // TRIE_H
