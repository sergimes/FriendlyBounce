//#include <SFML/Graphics.hpp>
#include "physics.hh"

#ifndef STATE_H
#define STATE_H

#include "player.hh"
#include "ball.hh"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#endif

class Game{

private:
    int n_players;
    int n_balls;
    std::vector<Player> players;
    std::vector<Ball> balls;

    sf::RenderWindow game_window;

    Physics game_physics;

    sf::Time elapsed;
    sf::Clock clock;
public:
    Game(int n_players, int n_balls, int window_width, int window_height);

    void game_loop();

    void window_events();

    void draw_game();

    void display_game();
};
