#ifndef NIM_PLAYER_H
#define NIM_PLAYER_H

#include <string>

class NimPlayer {
    public:
        virtual ~NimPlayer() {};
        virtual void set_name(string name) = 0;
        virtual const std::string& get_name() const = 0;
}

#endif // NIM_PLAYER_H
