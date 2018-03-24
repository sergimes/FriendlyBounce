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
        players[i].modify_vx(players[i].get_vx()*0.999);
        players[i].modify_vy(players[i].get_vy()*0.999);
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

    sf::Keyboard keys_left[4] = {sf::Keyboard::A,sf::Keyboard::Left,sf::Keyboard::H, sf::Keyboard::Numpad4};

    sf::Keyboard keys_right[4] = {sf::Keyboard::D,sf::Keyboard::Right,sf::Keyboard::K, sf::Keyboard::Numpad6};

    //keys_left = {sf::Keyboard::A,sf::Keyboard::Left,sf::Keyboard::H, sf::Keyboard::Numpad4};

    //keys_right = {sf::Keyboard::D,sf::Keyboard::Right,sf::Keyboard::K, sf::Keyboard::Numpad6};

    for(int i = 0; i < n_players; ++i){

        if(sf::Keyboard::isKeyPressed(keys_left[i])){
            float actual_vy = players[i].get_vy();
            float new_vy = actual_vy - players[i].get_ax() * elapsed.asSeconds();
            players[i].modify_vy(new_vy);
        }

        if(sf::Keyboard::isKeyPressed(keys_right[i])){
            float actual_vy = players[i].get_vy();
            float new_vy = actual_vy + players[i].get_ax() * elapsed.asSeconds();
            players[i].modify_vy(new_vy);
        }

        /*
        switch (i) {
        case 0:
            if(sf::Keyboard::isKeyPressed(keys_left[i])){
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
        case 1:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                float actual_vy = players[i].get_vy();
                float new_vy = actual_vy - players[i].get_ax() * elapsed.asSeconds();
                players[i].modify_vy(new_vy);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                float actual_vy = players[i].get_vy();
                float new_vy = actual_vy + players[i].get_ax() * elapsed.asSeconds();
                players[i].modify_vy(new_vy);
            }
            break;

        case 2:
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
        case 3:
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
        }*/
    }

    /*for(int i = 0; i < n_balls; ++i){
        float actual_vy = players[i].get_vy();
        float new_vy = actual_vy - players[i].get_ax() * elapsed.asSeconds();
    }*/
}
