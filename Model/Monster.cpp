//
// Created by Walid on 29/05/2016.
//

#include <c++/iostream>
#include "Monster.h"

Monster::Monster(int posx, int posy, std::string name) : Character(posx,posy,name) {
    std::cout << "Monster." << std::endl;
}

bool Monster::move(direction d, Map* m, std::list<Character*>* npc, std::list<Character*>* playableChar, float factor) {
    setSpeed((float)(WALKING_SPEED*dt.asSeconds())*factor);
    if (!(verifyMoveMap(d, m->getHitbox()))){
        for(Character* chara : *npc){
            if (verifyMove(d, chara->getHitbox()) and chara != this){
                setSpeed(0);
                return false;
            }
        }
        for(Character* chara : *playableChar){
            if (verifyMove(d, chara->getHitbox())){
                setSpeed(0);
                return false;
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

