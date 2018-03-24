#ifndef STATE_H
#define STATE_H

#include "player.hh"
#include "ball.hh"
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

#endif

#include "Player.hh"

class Physics{
private:


public:

    void update(std::vector<Player> &players,
                std::vector<Ball> &balls,
                sf::time &elapsed);
};
