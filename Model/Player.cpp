//
// Created by Walid on 27/05/2016.
//

#include "Player.h"

Player::Player(PlayableChar *chararcter, uint_fast8_t ind, int s, sf::Keyboard::Key *mapping) {
    this->character = chararcter;
    this->indice = ind;
    this->mapping = mapping;
    this->state = (listState)s;

    //Setting default mapping controls if instance of the first player
    if(this->mapping == NULL and ind == 0){
        this->mapping = new sf::Keyboard::Key[12];
        for(int i=0; i<12; i++){
            this->mapping[i] = defaultMapping[i];
        }
    }
}

sf::Keyboard::Key *Player::getMapping() {
    return mapping;
}

PlayableChar* Player::getCharacter() {
    return character;
}

int Player::getState() {
    return state;
}

void Player::setState(listState l) {
    state=l;
}









