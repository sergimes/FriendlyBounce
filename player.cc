#include"player.hh"

//Constructors

Player::Player() {
}

Player::Player(int playerId, int windowWidth, int windowHeight) : Object() {
    id = playerId;
    name = "Player " + id;
    points = 0;
    vx = vy = 0;
    ax = ay = 2000;
    switch(id){
        case 4:
            color = sf::Color(255,255,0);
            w = 200;
            h = 50;
            x = (windowWidth - w)/2;
            y = 0;
            break;
        case 2:
            color = sf::Color(255,0,0);
            w = 50;
            h = 200;
            x = windowWidth - w;
            y = (windowHeight - h)/2;
            break;
        case 3:
            color = sf::Color(0,255,0);
            w = 200;
            h = 50;
            x = (windowWidth - w)/2;
            y = windowHeight - h;
            break;
        case 1:
            color = sf::Color(0,0,255);
            w = 50;
            h = 200;
            x = 0;
            y = (windowHeight - h)/2;
            break;
        default:
            color = sf::Color(0,0,0);
            w = 0;
            h = 0;
            break;
    };
}

Player::Player(int playerId, string playerName, int windowWidth, int windowHeight) : Object(){
    id = playerId;
    name = playerName;
    points = 0;
    vx = vy = 0;
    ax = ay = 2000;
    switch(id){
        case 4:
            color = sf::Color(255,255,0);
            w = 200;
            h = 50;
            x = (windowWidth - w)/2;
            y = 0;
            break;
        case 2:
            color = sf::Color(255,0,0);
            w = 50;
            h = 200;
            x = windowWidth - w;
            y = (windowHeight - h)/2;
            break;
        case 3:
            color = sf::Color(0,255,0);
            w = 200;
            h = 50;
            x = (windowWidth - w)/2;
            y = windowHeight - h;
            break;
        case 1:
            color = sf::Color(0,0,255);
            w = 50;
            h = 200;
            x = 0;
            y = (windowHeight - h)/2;
            break;
        default:
            color = sf::Color(0,0,0);
            w = 0;
            h = 0;
            break;
    };
}

Player::Player(int playerId, string playerName, sf::Color color, int windowWidth, int windowHeight) : Object(){
    id = playerId;
    name = playerName;
    points = 0;
    vx = vy = 0;
    ax = ay = 2000;
    this->color = color;
    switch(id){
        case 4:
            w = 200;
            h = 50;
            x = (windowWidth - w)/2;
            y = 0;
            break;
        case 2:
            w = 50;
            h = 200;
            x = windowWidth - w;
            y = (windowHeight - h)/2;
            break;
        case 3:
            w = 200;
            h = 50;
            x = (windowWidth - w)/2;
            y = windowHeight - h;
            break;
        case 1:
            w = 50;
            h = 200;
            x = 0;
            y = (windowHeight - h)/2;
            break;
        default:
            w = 0;
            h = 0;
            break;
    };
}

//Destructor

Player::~Player(){

}

//Consultors

int Player::getId() {
    return id;
}

string Player::getName() {
    return name;
}

int Player::getPoints() {
    return points;
}

//Modifiers

void Player::setId(int newId) {
    id = newId;
}

void Player::setName(string newName) {
    name = newName;
}

void Player::setPoints(int newPoints) {
    points = newPoints;
}

void Player::incPoints(int increase) {
    points += increase;
}
