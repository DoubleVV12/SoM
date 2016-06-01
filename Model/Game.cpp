//
// Created by DoubleVV on 26/04/2016.
//

#include "Game.h"


Game::Game()
{
    std::cout << "Game." << std::endl;
    npc.push_back(new Npc(150, 50, NULL));
    list_player[0] = new Player(new PlayableChar(50, 50, NULL), 0, Player::GAME);
    player.push_back(list_player[0]->getCharacter());
    current_map = new Map(false);

//TODO Ancienne version. A effacer.

//    cTest = new Character_view(test);
//    cView = new Character_view(player);
//    mapView = new Map_view(current_map);
//    camera = sf::View(player->getPosition(), sf::Vector2f(352, 240));
//    start_clock();
}

//TODO Ancienne version. A effacer.
//void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    target.draw(*mapView);
//    target.draw(*cView);
//    target.draw(*cTest);
//    if(debug_show_camera_hitbox)
//        target.draw(line, 5, sf::LinesStrip);
//    if(debug_show_sprite_hitbox){
//        target.draw(*cView->get_debug_hitbox());
//        target.draw(*cTest->get_debug_hitbox());
//    }
//    std::list<Hitbox_view>::iterator i;
//    i = mapView->get_hitbox_view().begin();
//
//    while( i != mapView->get_hitbox_view().end())
//    {
//        target.draw(*i);
//        i++;
//    }
//}

//TODO Ancienne version. A effacer.
//void Game::handle_event(sf::Event* e) {
//    static bool pressed;
//    if(e->type == sf::Event::KeyReleased)
//    {
//        if(!(e->key.code == sf::Keyboard::Right or
//             e->key.code == sf::Keyboard::Down or
//             e->key.code == sf::Keyboard::Left or
//             e->key.code == sf::Keyboard::Up))
//            pressed = false;
//        else{
////            player->stop(); //TODO chercher a quoi ça sert
////            cView->stop();
//        }
//    }
//    if(e->type == sf::Event::KeyPressed) {
//        if (e->key.code == sf::Keyboard::R and !(pressed)) {
//            (bullettime) ? (bullettime = false) : (bullettime = true);
//            std::cout << "Bullet time : " << ((bullettime) ? "On" : "Off");
//            std::cout << std::endl;
//        }
//        if (e->key.code == sf::Keyboard::F1 and !(pressed)) {
//            (debug_show_camera_hitbox) ? (debug_show_camera_hitbox = false) : (debug_show_camera_hitbox = true);
//            std::cout << "Debug(show camera boundaries) : " << ((debug_show_camera_hitbox) ? "On"  : "Off");
//            std::cout << std::endl;
//        }
//        if (e->key.code == sf::Keyboard::F2 and !(pressed)) {
//            (debug_show_sprite_hitbox) ? (debug_show_sprite_hitbox = false) : (debug_show_sprite_hitbox = true);
//            std::cout << "Debug(show sprites hitboxes) : " << ((debug_show_sprite_hitbox) ? "On"  : "Off");
//            std::cout << std::endl;
//        }
//        if(!(e->key.code == sf::Keyboard::Right or
//                e->key.code == sf::Keyboard::Down or
//                e->key.code == sf::Keyboard::Left or
//                e->key.code == sf::Keyboard::Up))
//            pressed = true;
//
//    }
////    if (e->key.code == sf::Keyboard::Left)
//}

void Game::handle_event(){
    //TODO animation de poussé pour les collisions entre personnages.
//    if (sf::Keyboard::isKeyPressed(list_player[0]->getMapping()[Player::control::LEFT]))
//    {
////        if (!(current_map->verifyMove(1,player.front())))
////        {
////            if (!(player.front()->verifyMove(1,npc.front()->getHitbox())))
////            {
////                player.front()->move(1);
////            }
////        }
////        cView->animate(WALK_LEFT);
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//    {
//        if (!(current_map->verifyMove(2,player.front())))
//        {
//            if (!(player.front()->verifyMove(2,npc.front()->getHitbox())))
//            {
//                player.front()->move(2);
//            }
//        }
////        cView->animate(WALK_UP);
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//    {
//        if (!(current_map->verifyMove(3,player.front())))
//        {
//            if (!(player.front()->verifyMove(3,npc.front()->getHitbox())))
//            {
//                player.front()->move(3);
//            }
//        }
////        cView->animate(WALK_RIGHT);
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//    {
//        if (!(current_map->verifyMove(0,player.front())))
//        {
//            if (!(player.front()->verifyMove(0,npc.front()->getHitbox())))
//            {
//                player.front()->move(0);
//            }
//        }
////        cView->animate(WALK_DOWN);
//    }

    for(Player *p : list_player){
        if(p != NULL){
            switch (p->getState())
            {
                case Player::GAME:
                    /*if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::LEFT])){
                        if (!(current_map->verify_move(p->getCharacter()->get_hitbox())))
                        {
                            Character *isPushed = NULL;
                            for(Character* chara : npc){
                                if (p->getCharacter()->verify_move(Character::LEFT,chara->get_hitbox())){                                {
                                    isFree = false;
                                    isPushed = chara;
                                }
                            }
                            if(isFree)
                                p->getCharacter()->move(Character::LEFT, current_map);
                            else{
                                p->getCharacter()->move(Character::LEFT, current_map,0.4);
                                isPushed->move(Character::LEFT, current_map,0.4);
                                isFree = true;
                            }}
                        }
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::UP])){
                        if (!(current_map->verify_move(p->getCharacter()->get_hitbox())))
                        {
                            Character *isPushed = NULL;
                            for(Character* chara : npc){
                                if (p->getCharacter()->verify_move(Character::UP,chara->get_hitbox())){                                {
                                        isFree = false;
                                        isPushed = chara;
                                    }
                                }
                                if(isFree)
                                    p->getCharacter()->move(Character::UP,current_map);
                                else{
                                    p->getCharacter()->move(Character::UP,current_map,0.4);
                                    isPushed->move(Character::UP,current_map,0.4);
                                    isFree = true;
                                }}
                        }
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::RIGHT])){
                        if (!(current_map->verify_move(p->getCharacter()->get_hitbox())))
                        {
                            Character *isPushed = NULL;
                            for(Character* chara : npc){
                                if (p->getCharacter()->verify_move(Character::RIGHT,chara->get_hitbox())){                                {
                                        isFree = false;
                                        isPushed = chara;
                                    }
                                }
                                if(isFree)
                                    p->getCharacter()->move(Character::RIGHT,current_map);
                                else{
                                    p->getCharacter()->move(Character::RIGHT,current_map,0.4);
                                    isPushed->move(Character::RIGHT,current_map,0.4);
                                    isFree = true;
                                }}
                        }
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::DOWN])){
                        if (!(current_map->verifyMove(p->getCharacter()->getHitbox())))
                        {
                            Character *isPushed = NULL;
                            for(Character* chara : npc){
                                if (p->getCharacter()->verify_move(Character::DOWN,chara->getHitbox())){                                {
                                        isFree = false;
                                        isPushed = chara;
                                    }
                                }
                                if(isFree)
                                    p->getCharacter()->move(Character::DOWN,current_map);
                                else{
                                    p->getCharacter()->move(Character::DOWN,current_map,0.4);
                                    isPushed->move(Character::DOWN,current_map,0.4);
                                    isFree = true;
                                }}
                        }
                    }*/
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::LEFT])){
                        p->getCharacter()->move(Character::LEFT, current_map, (std::list<Character *> *) &npc,
                                                (std::list<Character *> *) &player);
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::UP])){
                        p->getCharacter()->move(Character::UP, current_map,(std::list<Character *> *) &npc,
                                                (std::list<Character *> *) &player);
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::RIGHT])){
                        p->getCharacter()->move(Character::RIGHT, current_map,(std::list<Character *> *) &npc,
                                                (std::list<Character *> *) &player);
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::DOWN])){
                        p->getCharacter()->move(Character::DOWN, current_map,(std::list<Character *> *) &npc,
                                                (std::list<Character *> *) &player);
                    }
                    if (sf::Keyboard::isKeyPressed(p->getMapping()[Player::control::ACTION])){
                        switch(current_map->getHostile()){
                            case false:
                                if(p->getCharacter()->dialog(&npc))
                                    p->setState(Player::DIALOGUE);
                                break;
                            case true:
                                break;
                        }
                    }

                case Player::MENU:
                    break;
                case Player::DIALOGUE:
                    break;
                case Player::CUTSCENE:
                    break;
            }
        }
    }
}

void Game::handle_hitboxes() {
}

std::list<PlayableChar*> Game::get_player() {
    return player;
}

std::list<Npc*> Game::get_npc() {
    return npc;
}

Map *Game::get_map() {
    return current_map;
}

Player **Game::getPlayer() {
    return list_player;
}








