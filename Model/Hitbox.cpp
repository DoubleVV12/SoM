//
// Created by DoubleVV on 01/05/2016.
//

#include <c++/iostream>
#include "Hitbox.h"

Hitbox::Hitbox(sf::Vector2f pos, sf::Vector2i size) {
    position = pos;
    this->size = size;
}

Hitbox::Hitbox(float xpos, float ypos, sf::Vector2i size) {
    position = sf::Vector2f(xpos,ypos);
    this->size = size;
}

Hitbox::Hitbox(sf::Vector2f pos, int xsize, int ysize) {
    position = pos;
    size = sf::Vector2i(xsize,ysize);
}

sf::Vector2f Hitbox::get_position() {
    return position;
}

sf::Vector2i Hitbox::get_size() {
    return size;
}

void Hitbox::set_position(sf::Vector2f p) {
    position = p;
}

void Hitbox::set_size(sf::Vector2i s) {
    size = s;
}

Hitbox::Hitbox(float xpos, float ypos, int xsize, int ysize) {
    position = sf::Vector2f(xpos,ypos);
    size = sf::Vector2i(xsize,ysize);
}

Hitbox::Hitbox() {
    position = sf::Vector2f(0,0);
    size = sf::Vector2i(0,0);
}

bool Hitbox::collision(Hitbox h) {
    return !((h.position.x >= this->position.x + this->size.x)      // trop à droite
        || (h.position.x + h.size.x <= this->position.x) // trop à gauche
        || (h.position.y >= this->position.y + this->size.y) // trop en bas
        || (h.position.y + h.size.y <= this->position.y));
}








