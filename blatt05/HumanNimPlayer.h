#ifndef HUMAN_NIM_PLAYER_H
#define HUMAN_NIM_PLAYER_H

#include "NimPlayer.h"

class HumanNimPlayer : public NimPlayer
{
public:
    virtual const std::string get_name() const override;
    virtual const NimMove get_move() const override;
};

#endif // HUMAN_NIM_PLAYER_H
