#include "RandomNimPlayer.h"

#include <iostream>

RandomNimPlayer::RandomNimPlayer(const NimGame& game) : game {game} {}

const std::string RandomNimPlayer::get_name() const
{
    return "RandomNimPlayer";
}

const NimMove RandomNimPlayer::get_move() const
{

    // computer
    if (game.nim_value() == 0)
    {
        // bad luck
        for (unsigned int i = 0; i < game.get_number_of_heaps(); ++i)
        {
            if (game.get_heap_size(i) > 0)
            {
                return NimMove(i, 1);
            }
        }
    }
    else
    {
        // find a winning move
        bool not_done = true;
        for (unsigned int heap_index=0; not_done && heap_index<game.get_number_of_heaps(); ++heap_index)
        {
            for (unsigned int count=1;
                    not_done
                    && count <= game.get_heap_size(heap_index)
                    && (maxtake==0 || count<=maxtake);
                    ++count)
            {
                NimGame test = game; // make a copy of the current game
                NimMove testmove(heap_index, count); // create a move
                test.execute_move(testmove); // execute it
                if (test.nim_value() == 0)
                {
                    return testmove;
                }
            }
        }
    }
}

extern "C" NimPlayer* construct() {
    return new RandomNimPlayer //todo
}
