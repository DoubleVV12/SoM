// Created by DoubleVV on 26/04/2016.
//


#include "Character.h"

Character::Character(int xpos, int ypos, std::string name) {
    std::cout << "Character." << std::endl;
    this->name = name;
    position = sf::Vector2f(xpos,ypos);
    speed = 0;
    hitbox = Hitbox(position.x+6,position.y+(CHARA_SPRITE_H/2), CHARA_SPRITE_W-14,CHARA_SPRITE_H/2-6);
}

Character::Character(const Character &other){
    std::cout << "Character." << std::endl;
    position = other.position;
    speed=other.speed;
    hitbox = other.hitbox;
}

Character::~Character() {
    std::cout << "~Character." << std::endl;
}

sf::Vector2f Character::getPosition() {
    return position;
}

void Character::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Character::stop() {
    speed = 0;
}

Hitbox* Character::getHitbox() {
    return &hitbox;
}

void Character::calculHitbox(direction d) {
    hitbox.move(d,speed);
}

bool Character::verifyMove(direction d, Hitbox *h) {
    Hitbox next_move;
    float next_speed = (WALKING_SPEED*dt.asSeconds());
    switch (d){
        case DOWN :
            next_move = Hitbox(hitbox.getPosition().x, hitbox.getPosition().y+next_speed,hitbox.get_size());
            return h->collision(next_move);
        case LEFT :
            next_move = Hitbox(hitbox.getPosition().x-next_speed, hitbox.getPosition().y,hitbox.get_size());
            return h->collision(next_move);
        case UP :
            next_move = Hitbox(hitbox.getPosition().x, hitbox.getPosition().y-next_speed,hitbox.get_size());
            return h->collision(next_move);
        case RIGHT :
            next_move = Hitbox(hitbox.getPosition().x+next_speed, hitbox.getPosition().y,hitbox.get_size());
            return h->collision(next_move);
    }
    return false;
}

float Character::getSpeed() {
    return speed;
}

bool Character::verifyMoveMap(direction d, std::list<Hitbox *> hb) {
    for(Hitbox* h : hb){
        if (verifyMove(d, h))
            return true;
    }
    return false;
}

void Character::setSpeed(float s) {
    speed = s;
}

std::string Character::getName() {
    return name;
}

void Character::setName(std::string s) {
    name = s;
}





























