#ifndef STATE_H
#define STATE_H

#include "player.hh"
#include "ball.hh"
#include <vector>
#include <iostream>

#endif

#include <SFML/Window.hpp>

class Physics{
private:


public:

    static void update(std::vector<Player> &players,
                       int &n_players,
                       std::vector<Ball> &balls,
                       int &n_balls,
                       sf::Time &elapsed);

    static void update_positions(std::vector<Player> &players,
                          int &n_players,
                          std::vector<Ball> &balls,
                          int &n_balls,
                          sf::Time &elapsed);

    static void update_velocities(std::vector<Player> &players,
                          int &n_players,
                          sf::Time &elapsed);

    void collision(std::vector<Player> &players, int &n_players,

                          std::vector<Ball> &balls,
                          int &n_balls);
};
