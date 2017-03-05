#include <cassert>
#include <vector>
#include "NimGame.h"

NimGame::NimGame(unsigned int number_of_heaps_, unsigned int maxtake_) :
    number_of_heaps(number_of_heaps_), maxtake(maxtake_),
/* make heap_size a vector of number_of_heaps elements */
    heap_size(number_of_heaps_),
    next_player(PLAYER1)
{
}

unsigned int NimGame::get_number_of_heaps() const
{
    return number_of_heaps;
}

void NimGame::set_heap_size(unsigned int index, unsigned int size)
{
    assert(index < number_of_heaps);
    heap_size[index] = size;
}

unsigned int NimGame::get_heap_size(unsigned int index) const
{
    assert(index<get_number_of_heaps());

    return heap_size[index];
}

bool NimGame::finished() const
{
    for (unsigned int i=0; i<get_number_of_heaps(); ++i)
    {
        if (get_heap_size(i)!=0)
        {
            return false;
        }
    }
    return true;
}

NimGame::Player NimGame::winner() const
{
    assert(finished());

    return (next_player==PLAYER1) ? PLAYER2
           : PLAYER1;
}

NimGame::Player NimGame::get_next_player() const
{
    return next_player;
}

bool NimGame::valid_move(NimMove move) const
{
    if (move.get_heap()>=get_number_of_heaps())
    {
        return false;
    }
    if (move.get_count()>maxtake && maxtake!=0)
    {
        return false;
    }
    if (move.get_count()>get_heap_size(move.get_heap()))
    {
        return false;
    }
    if (move.get_count()==0)
    {
        return false;
    }
    return true;
}

void NimGame::execute_move(NimMove move)
{
    assert(!finished());
    assert(valid_move(move));


    set_heap_size(move.get_heap(), get_heap_size(move.get_heap())-move.get_count());
    next_player = (next_player==PLAYER1) ? PLAYER2
                  : PLAYER1;
}

unsigned int NimGame::nim_value() const
{
    unsigned int res = 0;

    for (unsigned int index=0; index<get_number_of_heaps(); ++index)
    {
        res ^= (maxtake!=0) ? get_heap_size(index) % (maxtake+1)
               : get_heap_size(index);
    }
    return res;
}
