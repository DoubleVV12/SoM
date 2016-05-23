//
// Created by DoubleVV on 26/04/2016.
//

#include <c++/clocale>
#include <c++/iostream>
#include "Map.h"
#include "../Util/util.h"

Map::Map() {
    std::cout << "Map." << std::endl;
    width = 16;
    height = 8;
    level = new int[width*height]
            {
                    0, 24, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 27, 0,
                    1, 18, 6, 7, 3, 9, 11, 17, 3, 4, 3, 3, 4, 3, 3, 27,
                    0, 18, 3, 4, 3, 22, 16, 16, 10, 17, 6, 7, 3, 4, 9, 10,
                    2, 18, 5, 3, 4, 15, 16, 16, 16, 23, 3, 4, 8, 4, 15, 16,
                    1, 19, 4, 6, 7, 9, 16, 29, 15, 29, 3, 3, 6, 7, 4, 15,
                    0, 13, 19, 3, 4, 15, 29, 3, 4, 3, 6, 7, 3, 4, 3, 4,
                    0, 0, 13, 21, 21, 19, 3, 6, 7, 4, 12, 4, 3, 4, 6, 7,
                    1, 1, 1, 0, 1, 13, 21, 21, 21, 19, 3, 6, 7, 3, 3, 4,
            };

    for (int i=0; i < height; i++){
        for(int j=0; j<width; j++){
            if(tile_permeability[level[width*i+j]])
                hitbox.push_back(new Hitbox(j*TILE_SIZE,i*TILE_SIZE,TILE_SIZE,TILE_SIZE));
        }
    }
}

Map::~Map() {
//    delete[] level;
}

int *Map::getLevel() {
    return level;
}

Map::Map(const Map &other) {
    level = other.level;
}

bool Map::verify_move(unsigned short int direction,Character *c) {
    std::list<Hitbox*>::iterator i;
    i = hitbox.begin();

    while( i != hitbox.end())
    {
        if(c->verify_move(direction,*i))
            return true;
//        std::cout << i->get_position().x/TILE_SIZE << "  " << i->get_position().y/TILE_SIZE << std::endl;
        i++;
    }
    return false;
}

std::list<Hitbox *> Map::get_hitbox() {
    return hitbox;
}













