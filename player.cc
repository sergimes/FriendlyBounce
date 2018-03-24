#include"player.hh"

//Constructors

Player::Player(int playerId) {
    id = playerId;
    name = "Player " + id;
    points = 0;
    switch(id){
        case 1:
            color = sf::Color(255,255,0,255);
            break;
        case 2:
            color = sf::Color(255,0,0,255);
            break;
        case 3:
            color = sf::Color(0,255,0,255);
            break;
        case 4:
            color = sf::Color(0,0,255,255);
            break;
        default:

            break;
    }
}

Player::Player(int playerId, string playerName){

}

Player::Player(int playerId, string playerName, sf::Color color){

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
