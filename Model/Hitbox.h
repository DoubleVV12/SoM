//
// Created by DoubleVV on 01/05/2016.
//

#ifndef SFMLTEST_HITBOX_H
#define SFMLTEST_HITBOX_H

#include <SFML/Graphics.hpp>

class Hitbox {
private:
    sf::Vector2f position;
    sf::Vector2i size;
public:
    enum direction{LEFT,UP,RIGHT,DOWN};

    Hitbox();
    Hitbox(sf::Vector2f pos, sf::Vector2i size);
    Hitbox(float xpos, float ypos, sf::Vector2i size);
    Hitbox(sf::Vector2f pos, int xsize, int ysize);
    Hitbox(float xpos, float ypos, int xsize, int ysize);
    sf::Vector2f getPosition();
    sf::Vector2i get_size();
    void setPosition(float,float);
    void set_size(sf::Vector2i s);
    bool collision(Hitbox h);
    void scale(float);
    void move(unsigned short int, float speed);
};


#endif //SFMLTEST_HITBOX_H
