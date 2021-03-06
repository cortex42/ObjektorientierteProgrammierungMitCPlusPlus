#ifndef RANDOM_NIM_PLAYER_H
#define RANDOM_NIM_PLAYER_H

#include "NimPlayer.h"

class RandomNimPlayer : public NimPlayer
{
public:
    RandomNimPlayer(const NimGame& game);

    virtual const std::string get_name() const override;
    virtual const NimMove get_move() const override;

private:
    NimGame& game;
    NimGame& game;
}
