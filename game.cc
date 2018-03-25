#include "game.hh"

Game::Game(int n_players, int n_balls, int window_width, int window_height){
    game_window.create(sf::VideoMode(window_width, window_height), "Funny Bouncer");
    game_window.setPosition(sf::Vector2i(0,0));

    players = std::vector<Player> (4);

    players[0] = Player(1,window_width, window_height);


    players[1] = Player(2,window_width, window_height);


    players[2] = Player(3,window_width, window_height);


    players[3] = Player(4,window_width, window_height);

    balls = std::vector<Ball> (1);

    balls[0] = Ball(10, window_width, window_height);

    srand (time(NULL));
    float rnumb = ((rand() % ((int)((2*M_PI)*100)))*0.01) - M_PI;
    float vm = 300;

    balls[0].modify_velocity(vm * cos(rnumb) , vm * sin(rnumb));

    this->n_players = n_players;
    this->n_balls = n_balls;
}

void Game::game_loop(){
    while(game_window.isOpen()){



        window_events();

        game_window.clear();

        elapsed = clock.restart();
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        srand((time_t)ts.tv_nsec);

        if(not (rand()%10)) {
            balls.push_back(Ball(10, (int)game_window.getSize().x, (int)game_window.getSize().y));
            float rnumb = ((rand() % ((int)((2*M_PI)*100)))*0.01) - M_PI;
            float vm = 300;
            balls[n_balls].modify_velocity(vm * cos(rnumb) , vm * sin(rnumb));
            n_balls++;
        }

        Physics::update(players, n_players, balls, n_balls, elapsed, game_window.getSize().x, game_window.getSize().y);


        draw_game();

        display_game();
    }
}

void Game::window_events(){
    sf::Event event;
    while (game_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed){
            game_window.close();
        }
    }
}

void Game::draw_game(){

    for(int i = 0; i < n_players ; ++i){//Draw players
        sf::RectangleShape player(sf::Vector2f(players[i].get_w(), players[i].get_h()));
        player.setFillColor(players[i].get_color());
        player.setPosition(players[i].get_x(), players[i].get_y());


        //sf::RectangleShape player(sf::Vector2f(50, 50));
        //player.setFillColor(sf::Color::Green);
        //player.setPosition(250, 250);

        game_window.draw(player);
    }

    for(int i = 0; i < n_balls ; ++i){//Draw balls
        sf::CircleShape ball(balls[i].get_radi());
        ball.setFillColor(balls[i].get_color());
        ball.setPosition(balls[i].get_x(), balls[i].get_y());
        game_window.draw(ball);
    }
}

void Game::display_game(){
    game_window.display();
}
