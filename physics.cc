#include "physics.hh"

void Physics::update(std::vector<Player> &players,
                     int &n_players,
                     std::vector<Ball> &balls,
                     int &n_balls,
                     sf::Time &elapsed){

    update_positions(players, n_players, balls, n_balls, elapsed);

    update_velocities(players, n_players, /*balls, n_balls,*/ elapsed);
}


void Physics::update_positions(std::vector<Player> &players,
                               int &n_players,
                               std::vector<Ball> &balls,
                               int &n_balls,
                               sf::Time &elapsed){

    for(int i = 0; i < n_players; ++i){
        players[i].move_with_velocity(elapsed);
    }

    for(int i = 0; i < n_balls; ++i){
        balls[i].move_with_velocity(elapsed);
    }
}

void Physics::update_velocities(std::vector<Player> &players,
                                int &n_players,
                                /*std::vector<Ball> &balls,
                                int &n_balls,*/
                                sf::Time &elapsed){

    for(int i = 0; i < n_players; ++i){
        switch (i) {
        case 0:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                float actual_vy = players[i].get_vy();
                float new_vy = actual_vy - players[i].get_ax() * elapsed.asSeconds();
                players[i].modify_vy(new_vy);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                float actual_vy = players[i].get_vy();
                float new_vy = actual_vy + players[i].get_ax() * elapsed.asSeconds();
                players[i].modify_vy(new_vy);
            }
            break;
        default:
            break;
        }
    }

    /*for(int i = 0; i < n_balls; ++i){
        float actual_vy = players[i].get_vy();
        float new_vy = actual_vy - players[i].get_ax() * elapsed.asSeconds();
    }*/
}
