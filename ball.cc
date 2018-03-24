#include "ball.hh"

Ball::Ball() : Object() {

}

Ball::Ball(float radi, int windowWidth, int windowHeight) : Object() {
    this->radi = radi;
    x = windowWidth/2 - radi;
    y = windowHeight/2 - radi;
}

Ball::Ball(float radi, float x, float y) {
    this->radi = radi;
    this->x = x - radi;
    this->y = y - radi;
}

Ball::~Ball() {

}

float Ball::get_radi() {
    return radi;
}

void Ball::modify_radi(float radi) {
    this->radi = radi;
}
