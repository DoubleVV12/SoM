//
// Created by Walid on 29/05/2016.
//

#ifndef SOM_NPC_H
#define SOM_NPC_H


#include "Character.h"

class Npc : public Character{
private:
    Hitbox dialogHitbox;
    std::string *message;
public:

    //Constructors and destructors
    Npc(int posx, int posy, std::string *message, std::string name = "NPC");

    //Getters and Setters
    Hitbox *getDialogHitbox();

    void calculHitbox(direction d);
    bool move(direction d, Map* m, std::list<Character*>* npc, std::list<Character*>* playableChar, float factor = 1);
};


#endif //SOM_NPC_H
