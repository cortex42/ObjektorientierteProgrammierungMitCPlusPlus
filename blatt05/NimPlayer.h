#ifndef NIM_PLAYER_H
#define NIM_PLAYER_H

#include <string>
#include "NimMove.h"

class NimPlayer
{
public:
    virtual ~NimPlayer() {};
    virtual const std::string get_name() const = 0;
    virtual const NimMove get_move() const = 0;
};

#endif // NIM_PLAYER_H
