#ifndef STATE_H
#define STATE_H

#include "player.hh"
#include "ball.hh"
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
                       sf::Time &elapsed,
                       int windowWidth,
                       int windowHeight);

    static void update_positions(std::vector<Player> &players,
                          int &n_players,
                          std::vector<Ball> &balls,
                          int &n_balls,
                          sf::Time &elapsed);

    static void update_velocities(std::vector<Player> &players,
                          int &n_players,
                          sf::Time &elapsed);

    static void player_limits(Player &player, int windowWidth, int windowHeight);

    static void ricochet(Ball &ball, std::pair<point,point> &arista);

    static float min_distance(Ball &ball, std::pair<point,point> arista);

    static float distance(point a, point b);

    static std::pair<point,point> closer_arista(Player &player, Ball &ball);

    static void ball_player_coll(Player &player, Ball &ball);

    static void collision(std::vector<Player> &players,
                          int &n_players,
                          std::vector<Ball> &balls,
                          int &n_balls,
                          int windowWidth,
                          int windowHeight);
};
