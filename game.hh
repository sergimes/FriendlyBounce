#include "player.hh"
#include "ball.hh"
#include "physics.hh"

class Game{

private:
    int n_players;
    int n_balls;
    std::vector<player> players;
    std::vector<ball> balls;

    sf::RenderWindow game_window;

    Physics game_physics;
public:
    void game();

    void game_loop();

    void window_events();

    void draw_game();

    void display_game();
}
