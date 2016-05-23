// Created by DoubleVV on 26/04/2016.
//

#define GLOBAL
#include <c++/iostream>
#include "Character.h"
#include "../Util/util.h"

Character::Character()
{
    std::cout << "Character." << std::endl;
    setPosition(50,50);
    speed = 0;
    hitbox = Hitbox(position.x+3,position.y+(CHARA_SPRITE_H/2), CHARA_SPRITE_W-9,CHARA_SPRITE_H/2-4);
}

Character::Character(const Character &other)
{
    position = other.position;
    speed=other.speed;
    hitbox = other.hitbox;
}

sf::Vector2f Character::getPosition()
{
    return position;
}

void Character::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
}

void Character::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

Character::~Character() {

}

//Down = 0, Left = 1, Up = 2, Right = 3
void Character::move(unsigned short int direction,float factor) {
    speed = (float)(WALKING_SPEED*dt.asSeconds())*factor;
//            std::cout<< (float)dt.asSeconds() << std::endl;
    switch (direction){
        case 0 :
            position.y += speed;
            break;
        case 1 :
            position.x -= speed;
            break;
        case 2 :
            position.y -= speed;
//        std::cout<< position.x << " " << position.y << std::endl;
            break;
        case 3 :
            position.x += speed;
            break;
    }
    calcul_hitbox();
}

void Character::stop() {
    speed = 0;
}

Character::Character(int xpos, int ypos) {
    position = sf::Vector2f(xpos,ypos);
    hitbox = Hitbox(position.x+4,position.y+(CHARA_SPRITE_H/2), CHARA_SPRITE_W-9,CHARA_SPRITE_H/2-4);
}

Character::Character(sf::Vector2f pos) {
    position = pos;
    hitbox = Hitbox(position.x+4,position.y+(CHARA_SPRITE_H/2), CHARA_SPRITE_W-9,CHARA_SPRITE_H/2-4);
}

Hitbox* Character::get_hitbox() {
    return &hitbox;
}

void Character::calcul_hitbox() {
    hitbox.set_position(sf::Vector2f(position.x+4,position.y+(CHARA_SPRITE_H/2)));
}

bool Character::verify_move(unsigned short int direction, Hitbox* h) {
    Hitbox next_move;
    float next_speed = (WALKING_SPEED*dt.asSeconds());
    switch (direction){
        case 0 :
            next_move = Hitbox(hitbox.get_position().x,hitbox.get_position().y+next_speed,hitbox.get_size());
            return h->collision(next_move);
        case 1 :
            next_move = Hitbox(hitbox.get_position().x-next_speed,hitbox.get_position().y,hitbox.get_size());
            return h->collision(next_move);
        case 2 :
            next_move = Hitbox(hitbox.get_position().x,hitbox.get_position().y-next_speed,hitbox.get_size());
            return h->collision(next_move);
        case 3 :
            next_move = Hitbox(hitbox.get_position().x+next_speed,hitbox.get_position().y,hitbox.get_size());
            return h->collision(next_move);
    }
    return false;
}



















