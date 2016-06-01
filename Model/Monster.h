//
// Created by Walid on 29/05/2016.
//

#ifndef SOM_MONSTER_H
#define SOM_MONSTER_H


#include "Character.h"

class Monster : public Character {
public:
    Monster(int posx, int posy, std::string name = "Monster");
    bool move(direction d, Map* m, std::list<Character*>* npc, std::list<Character*>* playableChar, float factor = 1);
};


#endif //SOM_MONSTER_H
