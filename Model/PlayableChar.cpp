//
// Created by Walid on 29/05/2016.
//

#include <c++/iostream>
#include "PlayableChar.h"
#include "../Util/Global.h"

PlayableChar::PlayableChar(int posx, int posy, std::string *message, std::string name) : Character(posx, posy) {
    std::cout << "PlayableChar." << std::endl;

}

bool PlayableChar::move(direction d, Map *m, std::list<Character *> *npc,std::list<Character *> * playableChar,float factor) {
    setSpeed((float)(WALKING_SPEED*dt.asSeconds())*factor);
    if (!(verifyMoveMap(d, m->getHitbox()))){
        for(Character* chara : *npc){
            if (verifyMove(d, chara->getHitbox())){
                if(chara->move(d,m,npc,playableChar,PUSH_FACTOR))
                    setSpeed(getSpeed()*PUSH_FACTOR);
                else
                    setSpeed(0);
            }
        }
        switch (d){
            case DOWN :
                setPosition(getPosition().x,getPosition().y+getSpeed());
                break;
            case LEFT :
                setPosition(getPosition().x-getSpeed(),getPosition().y);
                break;
            case UP :
                setPosition(getPosition().x,getPosition().y-getSpeed());
                break;
            case RIGHT :
                setPosition(getPosition().x+getSpeed(),getPosition().y);
                break;
        }
        calculHitbox(d);
    }
    else
        return false;
    return true;
}

bool PlayableChar::dialog(std::list<Npc *> *p) {
    for(Npc* pc : *p){
        if((pc->getDialogHitbox()->collision(*getHitbox()))) {
            printf("a");
            return true;
        }
    }
    return false;
}





