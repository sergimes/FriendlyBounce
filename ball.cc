#include "ball.hh"

Ball::Ball() : Object() {

}

Ball::~Ball() {

}

float get_radi() {
    return radi;
}

void modify_radi(float radi) {
    this->radi = radi;
}
