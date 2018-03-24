#include "ball.hh"

Ball::Ball() : Object() {

}

Ball::Ball(float radi) : Object() {
    this->radi = radi;
}

Ball::~Ball() {

}

float Ball::get_radi() {
    return radi;
}

void Ball::modify_radi(float radi) {
    this->radi = radi;
}
