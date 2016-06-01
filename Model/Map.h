//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_MAP_H
#define SFMLTEST_MAP_H

#include <c++/list>
#include "Hitbox.h"

class Map
{
public:
    Map(bool hostile);
    ~Map();
    Map(const Map& other);

    ///Getters and Setters
    int* getLevel();
    std::list<Hitbox*> getHitbox();
    bool getHostile();

private:
    int height;
    int width;
    int* level;
    std::list<Hitbox*> hitbox;
    bool isHostile;
};


#endif //SFMLTEST_MAP_H
