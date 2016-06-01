//
// Created by Walid on 29/05/2016.
//

#ifndef SOM_PLAYABLECHAR_H
#define SOM_PLAYABLECHAR_H


#include "Character.h"
#include "Npc.h"
#include "Dialog.h"

class PlayableChar : public Character {
public:
    PlayableChar(int, int, std::string *message, std::string name = "PlayableChar");
    ~PlayableChar(){};

    bool move(direction d, Map* m, std::list<Character*>* npc, std::list<Character*>* playableChar, float factor = 1);
    bool dialog(std::list<Npc*>* p);

private:
    Dialog *message;
};


#endif //SOM_PLAYABLECHAR_H
