//
// Created by ivo on 10.03.17.
//

#ifndef CONCATENATEDCONTAINERVIEW_HPP
#define CONCATENATEDCONTAINERVIEW_HPP

#include <iterator>

template<typename T, typename U>
class ConcatenatedContainerView {
public:
    ConcatenatedContainerView() {};

    ConcatenatedContainerView(const T &container1, const U &container2)
            : begin_iterator{container1.begin(), container1.end(), container1.begin(), container2.begin(),
                             container2.end(), container2.begin()},
              end_iterator{container1.begin(), container1.end(), container1.end(), container2.begin(), container2.end(),
                           container2.end()} {}

    ConcatenatedContainerView(const ConcatenatedContainerView &other) : begin_iterator{other.begin_iterator},
                                                                        end_iterator{other.end_iterator} {};

    ConcatenatedContainerView(ConcatenatedContainerView &&rhs) : ConcatenatedContainerView() {
        swap(*this, rhs);
    }

    ConcatenatedContainerView &operator=(ConcatenatedContainerView rhs) {
        swap(*this, rhs);
        return *this;
    }

    friend void swap(ConcatenatedContainerView &view1, ConcatenatedContainerView &view2) {
        std::swap(view1.begin_iterator, view2.begin_iterator);
        std::swap(view1.end_iterator, view2.end_iterator);
    }

    template<typename V, typename W>
    class ConcatenatedIterator {
    public:

        ConcatenatedIterator() {};

        ConcatenatedIterator(V begin_container1, V end_container1, V position_container1, W begin_container2,
                             W end_container2, W position_container2) :
                begin_container1{begin_container1}, end_container1{end_container1},
                position_container1{position_container1},
                begin_container2{begin_container2}, end_container2{end_container2},
                position_container2{position_container2} {}

        ConcatenatedIterator(const ConcatenatedIterator &other) : begin_container1{other.begin_container1},
                                                                  begin_container2{other.begin_container2},
                                                                  end_container1{other.end_container1},
                                                                  end_container2{other.end_container2},
                                                                  position_container1{other.position_container1},
                                                                  position_container2{other.position_container2} {}

        ConcatenatedIterator(ConcatenatedIterator &&rhs) : ConcatenatedIterator() {
            swap(*this, rhs);
        }

        friend void swap(ConcatenatedIterator &iterator1, ConcatenatedIterator &iterator2) {
            std::swap(iterator1.begin_container1, iterator2.begin_container1);
            std::swap(iterator1.end_container1, iterator2.end_container1);
            std::swap(iterator1.position_container1, iterator2.position_container1);
            std::swap(iterator1.begin_container2, iterator2.begin_container2);
            std::swap(iterator1.end_container2, iterator2.end_container2);
            std::swap(iterator1.position_container2, iterator2.position_container2);
        }

        ConcatenatedIterator &operator=(ConcatenatedIterator &&rhs) {
            swap(*this, rhs);
            return *this;
        }

        bool operator==(const ConcatenatedIterator &other) const {
            if (position_container1 == end_container1 && position_container2 == end_container2
                && other.position_container1 == other.end_container1 &&
                other.position_container2 == other.end_container2) {
                return true;
            }

            if (position_container1 != end_container1 && other.position_container1 != other.end_container1) {
                return position_container1 == other.position_container1;
            }

            if (position_container1 == end_container1 && position_container2 != end_container2
                && other.position_container1 == other.end_container1 &&
                other.position_container2 != other.end_container2) {
                return position_container2 == other.position_container2;
            }

            return false;
        }

        bool operator!=(const ConcatenatedIterator &other) const {
            return !(*this == other);
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

    ConcatenatedIterator<typename T::const_iterator, typename U::const_iterator> begin() const {
        return begin_iterator;
    }

    ConcatenatedIterator<typename T::const_iterator, typename U::const_iterator> end() const {
        return end_iterator;
    }

private:
    ConcatenatedIterator<typename T::const_iterator, typename U::const_iterator> begin_iterator, end_iterator;
};

#endif //CONCATENATEDCONTAINERVIEW_HPP
