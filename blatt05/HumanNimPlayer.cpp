#include "HumanNimPlayer.h"

#include <iostream>

const std::string HumanNimPlayer::get_name() const
{
    return "HumanNimPlayer";
}

const NimMove HumanNimPlayer::get_move() const
{
    size_t heap_index, count;

    std::cout << "Your move: ";
    std::cin >> heap_index >> count;

    return NimMove(heap_index, count);
}

extern "C" NimPlayer* construct() {
    return new HumanNimPlayer();
}
