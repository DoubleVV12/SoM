//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_CHARACTER_H
#define SFMLTEST_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Hitbox.h"

#define WALKING_SPEED 100

class Character
{
private:
    sf::Vector2f position;
    float speed;
    Hitbox hitbox;

public:
    Character();
    Character(int xpos, int ypos);
    Character(sf::Vector2f pos);
    ~Character();
    Character(const Character& other);
    sf::Vector2f getPosition();
    Hitbox* get_hitbox();
    void setPosition(sf::Vector2f);
    void setPosition(int,int);
    void move(unsigned short int, float factor = 1);
    void stop();
    void calcul_hitbox();
    bool verify_move(unsigned short int,Hitbox*);
};


#endif //SFMLTEST_CHARACTER_H
