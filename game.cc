#include "game.hh"

void Game::game(){
    game_window.create(sf::VideoMode(600, 700), "Ant Simulator");
    game_window.setPosition(sf::Vector2i(0,0));

    player player1(1);
    players[0] = player1;
}

void Game::gameLoop(){
    while(gameWindow.isOpen()){

        window_events();

        game_window.clear();

        game_physics.update();

        draw_game();

        display_game();

        std::cout << ++frameCounter << std::endl;


    }
}

void Game::window_events(){
    sf::Event event;
    while (simulationWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed){
            simulationWindow.close();
        }
    }
}

void Game::draw_game(){

    for(int i = 0; i <= n_players ; ++i){//Draw players
        sf::RectangleShape player(sf::Vector2f(players[i].get_w, players[i].get_w));
        player.setFillColor(players[i].get_color);
        player.setPosition(players[i].get_x, players[i].get_y);
        game_window->draw(player);
    }

    for(int i = 0; i <= balls ; ++i){//Draw balls
        sf::CircleShape ball(sf::Vector2f(balls[i].get_w, balls[i].get_w));
        ball.setFillColor(balls[i].get_color);
        ball.setPosition(balls[i].get_x, balls[i].get_y);
        game_window->draw(ball);
    }
}

void Game::display_game(){
    game_window.display();
}
