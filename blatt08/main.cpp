#include <iostream>
#include <vector>
#include <list>
#include "ConcatenatedContainerView.hpp"

template<typename T, typename U>
ConcatenatedContainerView<T, U> concatenate(const T &container1, const U &container2) {
    return ConcatenatedContainerView<T, U>(container1, container2);
};

template<typename T, typename U>
typename std::enable_if<
        std::is_same<
                decltype(*std::declval<const T &>().begin()),
                decltype(*std::declval<const U &>().begin())
        >::value,
        typename std::remove_reference<
                decltype(concatenate(std::declval<T &>(), std::declval<U &>()))
        >::type
>::type
operator&(const T &container1, const U &container2) {
    return concatenate(container1, container2);
};

int main() {
    std::vector<int> a = {1, 2, 3};
    std::list<int> b = {4, 5, 6};

    for (int i : concatenate(a, b)) {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;

    for (int i : a & b) {
        std::cout << i << std::endl;
    }

    return 0;
}