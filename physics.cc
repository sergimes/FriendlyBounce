#include "physics.hh"



void Physics::update(std::vector<Player> &players,
                     int &n_players,
                     std::vector<Ball> &balls,
                     int &n_balls,
                     sf::Time &elapsed,
                     int windowWidth,
                     int windowHeight){

    update_positions(players, n_players, balls, n_balls, elapsed);

    update_velocities(players, n_players, /*balls, n_balls,*/ elapsed);


    collision(players, n_players, balls, n_balls, windowWidth, windowHeight);
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

    sf::Keyboard::Key keys_left[4] = {sf::Keyboard::A,sf::Keyboard::Left,sf::Keyboard::H, sf::Keyboard::Numpad4};

    sf::Keyboard::Key keys_right[4] = {sf::Keyboard::D,sf::Keyboard::Right,sf::Keyboard::K, sf::Keyboard::Numpad6};

    //keys_left = {sf::Keyboard::A,sf::Keyboard::Left,sf::Keyboard::H, sf::Keyboard::Numpad4};

    //keys_right = {sf::Keyboard::D,sf::Keyboard::Right,sf::Keyboard::K, sf::Keyboard::Numpad6};

    for(int i = 0; i < n_players; ++i){

        if(sf::Keyboard::isKeyPressed(keys_left[i])){
            if(i == 0 or i == 1){
                float actual_vy = players[i].get_vy();
                float new_vy = actual_vy - players[i].get_ay() * elapsed.asSeconds();
                players[i].modify_vy(new_vy);
            }
            else{
                float actual_vx = players[i].get_vx();
                float new_vx = actual_vx - players[i].get_ax() * elapsed.asSeconds();
                players[i].modify_vx(new_vx);
            }

        }

        if(sf::Keyboard::isKeyPressed(keys_right[i])){
            if(i == 0 or i == 1){
                float actual_vy = players[i].get_vy();
                float new_vy = actual_vy + players[i].get_ay() * elapsed.asSeconds();
                players[i].modify_vy(new_vy);
            }
            else{
                float actual_vx = players[i].get_vx();
                float new_vx = actual_vx + players[i].get_ax() * elapsed.asSeconds();
                players[i].modify_vx(new_vx);
            }
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

void Physics::player_limits(Player &player, int windowWidth, int windowHeight) {
    point position = player.get_position();
    if (position.first < 0) player.modify_x(0);
    if (position.first + player.get_w() > windowWidth) player.modify_x(windowWidth - player.get_w());
    if (position.second < 0) player.modify_y(0);
    if (position.second + player.get_h() > windowHeight) player.modify_y(windowHeight - player.get_h());
}

void Physics::ricochet(Ball &ball, std::pair<point,point> &arista) {
    point center = ball.get_center();
    if (center.first < arista.first.first) {
          if (center.first < arista.second.first) ball.modify_vx(-abs(ball.get_vx()));
          else if (center.second < arista.second.second) ball.modify_vy(-abs(ball.get_vy()));
          else ball.modify_vy(abs(ball.get_vy()));
    }
    else {
        if (center.first > arista.second.first) ball.modify_vx(abs(ball.get_vx()));
        else if (center.second < arista.second.second) ball.modify_vy(-abs(ball.get_vy()));
        else ball.modify_vy(abs(ball.get_vy()));
    }
}

float Physics::min_distance(Ball &ball, std::pair<point,point> arista) {
    if (arista.first.first != arista.second.first) {
        return abs(ball.get_center().second - arista.first.second);
    }
    else {
        return abs(ball.get_center().first - arista.first.first);
    }
}

float Physics::distance(point a, point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

std::pair<point,point> Physics::closer_arista(Player &player, Ball &ball) {
    point center = ball.get_center();

    pair<float,point> min1, min2, aux;
    min1.first = distance(center, std::make_pair(player.get_x(), player.get_y()));
    min1.second = std::make_pair(player.get_x(), player.get_y());
    min2.first = distance(center,std::make_pair(player.get_x() + player.get_w(), player.get_y()));
    min2.second = std::make_pair(player.get_x() + player.get_w(), player.get_y());
    if (min1.first > min2.first) swap(min1,min2);
    aux.first = distance(center,std::make_pair(player.get_x(), player.get_y() + player.get_h()));
    aux.second = std::make_pair(player.get_x(), player.get_y() + player.get_h());
    if (min1.first > aux.first) {
        swap(min1,min2);
        min1 = aux;
    }
    else if (min2 > aux) min2 = aux;
    aux.first = distance(center,std::make_pair(player.get_x() + player.get_w(), player.get_y() + player.get_h()));
    aux.second = std::make_pair(player.get_x() + player.get_w(), player.get_y() + player.get_h());
    if (min1 > aux) {
        swap(min1,min2);
        min1 = aux;
    }
    else if (min2 > aux) min2 = aux;

    std::cout << player.getId() << " " << (int) min1.second.first << " " << (int) min1.second.second << " " << (int) min2.second.first << " " << (int) min2.second.second << std::endl;

    return std::make_pair(min1.second, min2.second);
}

void Physics::ball_player_coll(Player &player, Ball &ball) {
    /*
    std::pair<point,point> arista = closer_arista(player, ball);
    float dis = Physics::min_distance(ball, arista);
    if (ball.get_radi() >= dis) Physics::ricochet(ball, arista);
    */
    
    point center = ball.get_center();
    point vertex[2] = {player.get_position(), std::make_pair(player.get_x() + player.get_w(), player.get_y() + player.get_h())};

    srand (time(NULL));
    float rnumb = ((rand() % 60)*0.01)-0.3; //random number between 0.0 and 0.25


    if ((center.first < vertex[1].first) and (center.first > vertex[0].first)) {
        if ((center.second < vertex[0].second) and (center.second < vertex[1].second)) {//Bottom Player Collision
            float minDis = min_distance(ball,std::make_pair(std::make_pair(vertex[1].first, vertex[0].second),vertex[0]));
            if (minDis < ball.get_radi()) {
                float vy = ball.get_vy();
                float vx = ball.get_vx();
                float vm = sqrt(pow(vx,2) + pow(vy,2));
                float alfa = atan(vx/vy);
                vy = vm * cos(alfa + rnumb);
                vx = vm * sin(alfa + rnumb);
                std::cout << vx << " " << vy << std::endl;
                ball.modify_velocity(vx, -abs(vy));
            }
        }
        else if ((center.second > vertex[0].second) and (center.second > vertex[1].second)) {//Top Player Collision
            float minDis = min_distance(ball,std::make_pair(std::make_pair(vertex[0].first, vertex[1].second),vertex[1]));
            if (minDis < ball.get_radi()) {
                float vy = ball.get_vy();
                float vx = ball.get_vx();
                float vm = sqrt(pow(vx,2) + pow(vy,2));
                float alfa = atan(vx/vy);
                vy = vm * cos(alfa + rnumb);
                vx = vm * sin(alfa + rnumb);
                ball.modify_velocity(vx, abs(vy));
            }
        }
    }
    else if ((center.second < vertex[1].second) and (center.second > vertex[0].second)) {
        if ((center.first < vertex[0].first) and (center.first < vertex[1].first)) {//Right Player Collision
            float minDis = min_distance(ball,std::make_pair(std::make_pair(vertex[1].first, vertex[0].second),vertex[1]));
            if (minDis < ball.get_radi()) {
                float vy = ball.get_vy();
                float vx = ball.get_vx();
                float vm = sqrt(pow(vx,2) + pow(vy,2));
                float alfa = atan(vy/vx);
                vy = vm * sin(alfa + rnumb);
                vx = vm * cos(alfa + rnumb);
                ball.modify_velocity(-abs(vx), vy);
            }

        }
        else if ((center.first > vertex[0].first) and (center.first > vertex[1].first)) {//Left Player Collision
            float minDis = min_distance(ball,std::make_pair(std::make_pair(vertex[0].first, vertex[1].second),vertex[0]));
            if (minDis < ball.get_radi()) {
                float vy = ball.get_vy();
                float vx = ball.get_vx();
                float vm = sqrt(pow(vx,2) + pow(vy,2));
                float alfa = atan(vy/vx);
                vy = vm * sin(alfa + rnumb);
                vx = vm * cos(alfa + rnumb);
                ball.modify_velocity(abs(vx), vy);
            }
        }
    }
}

void Physics::collision(std::vector<Player> &players,
                        int &n_players,
                        std::vector<Ball> &balls,
                        int &n_balls,
                        int windowWidth,
                        int windowHeight) {
    for (int i = 0; i < n_balls; ++i) {
        for (int j = 0; j < n_players; ++j) {
            ball_player_coll(players[j], balls[i]);
        }
    }

    for (int i = 0; i < n_players; ++i) {
        player_limits(players[i], windowWidth, windowHeight);
    }

}
