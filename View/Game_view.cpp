//
// Created by Walid on 25/05/2016.
//

#include "Game_view.h"

Game_view::Game_view(Game *g) {
    std::cout << "Game_view." << std::endl;
    game = g;
//    for(Character *npc : game->get_npc()){
//        cNpc.push_back(new Character_view(npc));
//    }
//    for(Character *play : game->get_player()){
//        cPlayer.push_back(new Character_view(play));
//    }
//    mapView = new Map_view(game->get_map());

    //Adding map to the map layer
    base.add(new Map_view(game->get_map()));

    //Adding players and NPCs to the sprites layer
    for(Character *npc : game->get_npc()){
        sprites.add(new Character_view(npc));
    }
    for(Character *play : game->get_player()){
        sprites.add(new Character_view(play));
    }

    //Setting the view, with first player as center. Also making the game looking SNES like.
    camera = sf::View(game->get_player().front()->getPosition(), sf::Vector2f(352, 240));
}

void Game_view::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    target.draw(*mapView);
//    for(Character_view *c : cPlayer){
//        target.draw(*c);
//    }
//    for(Character_view *c : cNpc){
//        target.draw(*c);
//    }

    target.draw(background);
    target.draw(base);
    target.draw(decoration);
    target.draw(sprites);
    target.draw(effect);

    if(debug_show_camera_hitbox)
        target.draw(line, 5, sf::LinesStrip);
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
}

void Game_view::handle_camera() {
//        std::cout << player->getPosition().y << " < ";
//    std::cout << camera.getCenter().y + (int)(camera.getSize().y * CAMERA_SENSITIVITY) << std::endl;

    if(game->get_player().front()->getPosition().x < camera.getCenter().x - (int)(camera.getSize().x * CAMERA_SENSITIVITY)){
        camera.setCenter(camera.getCenter().x - ((camera.getCenter().x ) - (int)(camera.getSize().x * CAMERA_SENSITIVITY) - game->get_player().front()->getPosition().x ), camera.getCenter().y);
    }
    if(game->get_player().front()->getPosition().y < camera.getCenter().y - (int)(camera.getSize().y * CAMERA_SENSITIVITY)){
        camera.setCenter(camera.getCenter().x, camera.getCenter().y - ((camera.getCenter().y ) - (int)(camera.getSize().y * CAMERA_SENSITIVITY) - game->get_player().front()->getPosition().y ));
    }
    if(game->get_player().front()->getPosition().x > camera.getCenter().x + (int)(camera.getSize().x * CAMERA_SENSITIVITY) - CHARA_SPRITE_W){
        camera.setCenter(camera.getCenter().x - ((camera.getCenter().x ) + (int)(camera.getSize().x * CAMERA_SENSITIVITY) - CHARA_SPRITE_W - game->get_player().front()->getPosition().x) , camera.getCenter().y);
    }
    if(game->get_player().front()->getPosition().y > camera.getCenter().y + (int)(camera.getSize().y * CAMERA_SENSITIVITY) - CHARA_SPRITE_H){
        camera.setCenter(camera.getCenter().x, camera.getCenter().y - ((camera.getCenter().y ) + (int)(camera.getSize().y * CAMERA_SENSITIVITY) - CHARA_SPRITE_H - game->get_player().front()->getPosition().y ));
    }

    if(debug_show_camera_hitbox)
    {
        line[0] = sf::Vertex(sf::Vector2f(camera.getCenter().x - (int)(camera.getSize().x * CAMERA_SENSITIVITY), camera.getCenter().y - (int)(camera.getSize().y * CAMERA_SENSITIVITY)),sf::Color::Red);
        line[1] = sf::Vertex(sf::Vector2f(camera.getCenter().x - (int)(camera.getSize().x * CAMERA_SENSITIVITY), camera.getCenter().y + (int)(camera.getSize().y * CAMERA_SENSITIVITY)),sf::Color::Red);
        line[2] = sf::Vertex(sf::Vector2f(camera.getCenter().x + (int)(camera.getSize().x * CAMERA_SENSITIVITY), camera.getCenter().y + (int)(camera.getSize().y * CAMERA_SENSITIVITY)),sf::Color::Red);
        line[3] = sf::Vertex(sf::Vector2f(camera.getCenter().x + (int)(camera.getSize().x * CAMERA_SENSITIVITY), camera.getCenter().y - (int)(camera.getSize().y * CAMERA_SENSITIVITY)),sf::Color::Red);
        line[4] = line[0];
    }
//    std::cout << player->getPosition().x << " , " << player->getPosition().y << std::endl;
}

sf::View Game_view::get_camera() {
    return camera;
}

void Game_view::handle_event(sf::Event* e) {
    game->handle_event();

    if(e != NULL)
    {
    static bool pressed;
    if(e->type == sf::Event::KeyReleased)
    {
        if(!(e->key.code == game->getPlayer()[0]->getMapping()[Player::control::LEFT] or    //TODO généraliser ça pour tout les joueurs.
             e->key.code == game->getPlayer()[0]->getMapping()[Player::control::UP] or
             e->key.code == game->getPlayer()[0]->getMapping()[Player::control::RIGHT] or
             e->key.code == game->getPlayer()[0]->getMapping()[Player::control::DOWN]))
            pressed = false;
        else{
            game->getPlayer()[0]->getCharacter()->stop();
//            cPlayer.front()->stop();
        }
    }
    if(e->type == sf::Event::KeyPressed) {
        if (e->key.code == sf::Keyboard::R and !(pressed)) {
            (bullettime) ? (bullettime = false) : (bullettime = true);
            std::cout << "Bullet time : " << ((bullettime) ? "On" : "Off");
            std::cout << std::endl;
        }
        if (e->key.code == sf::Keyboard::F1 and !(pressed)) {
            (debug_show_camera_hitbox) ? (debug_show_camera_hitbox = false) : (debug_show_camera_hitbox = true);
            std::cout << "Debug(show camera boundaries) : " << ((debug_show_camera_hitbox) ? "On" : "Off");
            std::cout << std::endl;
        }
        if (e->key.code == sf::Keyboard::F2 and !(pressed)) {
            (debug_show_sprite_hitbox) ? (debug_show_sprite_hitbox = false) : (debug_show_sprite_hitbox = true);
            std::cout << "Debug(show sprites hitboxes) : " << ((debug_show_sprite_hitbox) ? "On" : "Off");
            std::cout << std::endl;
        }
        if(!(e->key.code == game->getPlayer()[0]->getMapping()[Player::control::LEFT] or    //TODO généraliser ça pour tout les joueurs.
             e->key.code == game->getPlayer()[0]->getMapping()[Player::control::UP] or
             e->key.code == game->getPlayer()[0]->getMapping()[Player::control::RIGHT] or
             e->key.code == game->getPlayer()[0]->getMapping()[Player::control::DOWN]))
            pressed = true;
        }
    }

//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//        cPlayer.front()->animate(WALK_LEFT);
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//        cPlayer.front()->animate(WALK_UP);
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//        cPlayer.front()->animate(WALK_RIGHT);
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//        cPlayer.front()->animate(WALK_DOWN);
}

void Game_view::animate() {
    sprites.sort();

    base.animate();
    decoration.animate();
    sprites.animate();
    effect.animate();
}





