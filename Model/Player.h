//
// Created by Walid on 27/05/2016.
//

#ifndef SOM_PLAYER_H
#define SOM_PLAYER_H


#include <SFML/Window/Keyboard.hpp>
#include "Character.h"
#include "PlayableChar.h"

class Player {
public:
    enum listState{MENU,GAME,DIALOGUE,CUTSCENE};
    enum control{DOWN,LEFT,UP,RIGHT,ACTION,SECOND_ACTION,INVENTORY,SECOND_INVENTORY,START,SELECT,LEFT_MATE,RIGHT_MATE};

    Player(PlayableChar *chararcter, uint_fast8_t ind, int s = GAME, sf::Keyboard::Key* mapping = NULL);

    sf::Keyboard::Key *getMapping();
    PlayableChar* getCharacter();
    int getState();

    void setState(listState l);

private:
    const sf::Keyboard::Key defaultMapping[12] = {
            sf::Keyboard::Down,
            sf::Keyboard::Left,
            sf::Keyboard::Up,
            sf::Keyboard::Right,
            sf::Keyboard::E,
            sf::Keyboard::R,
            sf::Keyboard::D,
            sf::Keyboard::F,
            sf::Keyboard::Escape,
            sf::Keyboard::Space,
            sf::Keyboard::Q,
            sf::Keyboard::S,
    };

    sf::Keyboard::Key* mapping;
    PlayableChar *character;
    uint_fast8_t indice;
    uint_fast8_t indiceControl;
    listState state;

};


#endif //SOM_PLAYER_H
