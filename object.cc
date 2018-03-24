#include "object.hh"

Object::Object() {

}

Object::Object(float h, float w, float x, float y, float vx, float vy, float ax, float ay, sf::Color color) {
    this->h = h;
    this->w = w;
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ax = ax;
    this->ay = ay;
    this->color = color;
}

Object::~Object() {

}

std::pair<float,float> Object::get_size() {
    return std::make_pair(h,w);
}

float Object::get_h() {
    return h;
}

float Object::get_w() {
    return w;
}

std::pair<float,float> Object::get_position() {
    return std::make_pair(x,y);
}

float Object::get_x() {
    return x;
}

float Object::get_y() {
    return y;
}

std::pair<float,float> Object::get_velocity() {
    return std::make_pair(vx,vy);
}

float Object::get_vx() {
    return vx;
}

float Object::get_vy() {
    return vy;
}

std::pair<float,float> Object::get_acceleration() {
    return std::make_pair(ax,ay);
}

float Object::get_ax() {
    return ax;
}

float Object::get_ay() {
    return ay;
}

sf::Color Object::get_color() {
    return color;
}

void Object::modify_position(float x, float y) {
    this->x = x;
    this->y = y;
}

void Object::modify_x(float x) {
    this->x = x;
}

void Object::modify_y(float y) {
    this->y = y;
}

void Object::modify_velocity(float vx, float vy) {
    this->vx = vx;
    this->vy = vy;
}

void Object::modify_vx(float vx) {
    this->vx = vx;
}

void Object::modify_vy(float vy) {
    this->vy = vy;
}

void Object::modify_acceleration(float ax, float ay) {
    this->ax = ax;
    this->ay = ay;
}

void Object::modify_ax(float ax) {
    this->ax = ax;
}

void Object::modify_ay(float ay) {
    this->ay = ay;
}

void Object::modify_color(sf::Color color) {
    this->color = color;
}
