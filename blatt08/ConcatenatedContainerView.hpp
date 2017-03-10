//
// Created by ivo on 10.03.17.
//

#ifndef CONCATENATEDCONTAINERVIEW_HPP
#define CONCATENATEDCONTAINERVIEW_HPP

#include <iterator>
#include <iostream>

template<typename T, typename U>
class ConcatenatedContainerView {
public:
    ConcatenatedContainerView(T container1, U container2)
            : begin_iterator{container1.begin(), container1.end(), container1.begin(), container2.begin(),
                             container2.end(), container2.begin()},
              end_iterator{container1.begin(), container1.end(), container1.end(), container2.begin(), container2.end(),
                           container2.end()} {}

    template<typename V, typename W>
    class ConcatenatedIterator {
    public:
        ConcatenatedIterator(V begin_container1, V end_container1, V position_container1, W begin_container2,
                             W end_container2, W position_container2) :
                begin_container1{begin_container1}, end_container1{end_container1},
                position_container1{position_container1},
                begin_container2{begin_container2}, end_container2{end_container2},
                position_container2{position_container2} {}

        bool operator!=(const ConcatenatedIterator &other) const {
            // todo
        }

        ConcatenatedIterator &operator++() {
            if (position_container1 != end_container1) {
                position_container1++;
            } else if (position_container2 != end_container2) {
                position_container2++;
            }

            return *this;
        }

        auto
        operator*() const {
            if (position_container1 != end_container1) {
                return *position_container1;
            } else if (position_container2 != end_container2) {
                return *position_container2;
            } else {
                throw std::exception();
            }
        }

    private:
        V begin_container1, end_container1, position_container1;
        W begin_container2, end_container2, position_container2;
    };

    ConcatenatedIterator<typename T::iterator, typename U::iterator> begin() const {
        return begin_iterator;
    }

    ConcatenatedIterator<typename T::iterator, typename U::iterator> end() const {
        return end_iterator;
    }

private:
    ConcatenatedIterator<typename T::iterator, typename U::iterator> begin_iterator, end_iterator;
};

#endif //CONCATENATEDCONTAINERVIEW_HPP
