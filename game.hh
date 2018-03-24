#include <SFML/Graphics.hpp>

#ifndef STATE_H
#define STATE_H

#include "Player.hh"
#include "Ball.hh"
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

#endif

#include "physics.hh"

class Game{

private:
    int n_players;
    int n_balls;
    std::vector<player> players;
    std::vector<ball> balls;

    sf::RenderWindow game_window;

    Physics game_physics;

    sf::Time elapsed;
    sf::Clock clock;
public:
    Game();

    void game_loop();

    void window_events();

    void draw_game();

    void display_game();
}
