//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_MAP_H
#define SFMLTEST_MAP_H

#include <c++/list>
#include "Hitbox.h"
#include "Character.h"

class Map
{
public:
    Map();
    ~Map();
    Map(const Map& other);
    int* getLevel();
    bool verify_move(unsigned short int,Character *c);
    std::list<Hitbox*> get_hitbox();

private:
    int height;
    int width;
    int* level;
    std::list<Hitbox*> hitbox;
};


#endif //SFMLTEST_MAP_H
