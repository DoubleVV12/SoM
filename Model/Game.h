//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H


#include <SFML/Graphics/Drawable.hpp>
//#include "Model/Map.h"
//#include "Model/Character.h"
#include "../View/Character_view.h"
#include "../View/Map_view.h"
#include "Player.h"
#include "Npc.h"
#include "PlayableChar.h"
#include "Monster.h"

class Game {
public:
    Game();
//    void handle_event(sf::Event*);
    virtual void handle_event();
//    void handle_camera();
    void handle_hitboxes();
//    sf::View get_camera();
    std::list<PlayableChar*> get_player();
    std::list<Npc*> get_npc();
    Map* get_map();
    Player** getPlayer();

private:
//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::list<Npc*> npc;
    std::list<Monster*> monster;
    std::list<PlayableChar*> player;
    Map* current_map;

    Player* list_player[3] {NULL,NULL,NULL};

//    Character_view *cView;
//    Character_view *cTest;
//    Map_view *mapView;

//    sf::Vertex line[5];

};


#endif //SFMLTEST_GAME_H

