//
// Created by DoubleVV on 26/04/2016.
//

#include "Game.h"

Game::Game()
{
    std::cout << "Game." << std::endl;
    test = new Character(150,50);
    player = new Character();
    current_map = new Map();

    cTest = new Character_view(test);
    cView = new Character_view(player);
    mapView = new Map_view(current_map);
    camera = sf::View(player->getPosition(), sf::Vector2f(352, 240));
//    start_clock();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*mapView);
    target.draw(*cView);
    target.draw(*cTest);
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

void Game::handle_event(sf::Event* e) {
    static bool pressed;
    if(e->type == sf::Event::KeyReleased)
    {
        if(!(e->key.code == sf::Keyboard::Right or
             e->key.code == sf::Keyboard::Down or
             e->key.code == sf::Keyboard::Left or
             e->key.code == sf::Keyboard::Up))
            pressed = false;
        else{
            player->stop(); //TODO chercher a quoi ça sert
            cView->stop();
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
            std::cout << "Debug(show camera boundaries) : " << ((debug_show_camera_hitbox) ? "On"  : "Off");
            std::cout << std::endl;
        }
        if (e->key.code == sf::Keyboard::F2 and !(pressed)) {
            (debug_show_sprite_hitbox) ? (debug_show_sprite_hitbox = false) : (debug_show_sprite_hitbox = true);
            std::cout << "Debug(show sprites hitboxes) : " << ((debug_show_sprite_hitbox) ? "On"  : "Off");
            std::cout << std::endl;
        }
        if(!(e->key.code == sf::Keyboard::Right or
                e->key.code == sf::Keyboard::Down or
                e->key.code == sf::Keyboard::Left or
                e->key.code == sf::Keyboard::Up))
            pressed = true;

    }
//    if (e->key.code == sf::Keyboard::Left)
}

void Game::handle_event() {
    //TODO animation de poussé pour les collisions entre personnages.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (!(current_map->verify_move(1,player)))
        {
            if (!(player->verify_move(1,test->get_hitbox())))
            {
                player->move(1);
            }
        }
        cView->animate(WALK_LEFT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (!(current_map->verify_move(2,player)))
        {
            if (!(player->verify_move(2,test->get_hitbox())))
            {
                player->move(2);
            }
        }
        cView->animate(WALK_UP);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (!(current_map->verify_move(3,player)))
        {
            if (!(player->verify_move(3,test->get_hitbox())))
            {
                player->move(3);
            }
        }
        cView->animate(WALK_RIGHT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (!(current_map->verify_move(0,player)))
        {
            if (!(player->verify_move(0,test->get_hitbox())))
            {
                player->move(0);
            }
        }
        cView->animate(WALK_DOWN);
    }
}

sf::View Game::get_camera() {
    return camera;
}

void Game::handle_camera() {
//        std::cout << player->getPosition().y << " < ";
//    std::cout << camera.getCenter().y + (int)(camera.getSize().y * CAMERA_SENSITIVITY) << std::endl;

    if(player->getPosition().x < camera.getCenter().x - (int)(camera.getSize().x * CAMERA_SENSITIVITY)){
        camera.setCenter(camera.getCenter().x - ((camera.getCenter().x ) - (int)(camera.getSize().x * CAMERA_SENSITIVITY) - player->getPosition().x ), camera.getCenter().y);
    }
    if(player->getPosition().y < camera.getCenter().y - (int)(camera.getSize().y * CAMERA_SENSITIVITY)){
        camera.setCenter(camera.getCenter().x, camera.getCenter().y - ((camera.getCenter().y ) - (int)(camera.getSize().y * CAMERA_SENSITIVITY) - player->getPosition().y ));
    }
    if(player->getPosition().x > camera.getCenter().x + (int)(camera.getSize().x * CAMERA_SENSITIVITY) - CHARA_SPRITE_W){
        camera.setCenter(camera.getCenter().x - ((camera.getCenter().x ) + (int)(camera.getSize().x * CAMERA_SENSITIVITY) - CHARA_SPRITE_W - player->getPosition().x) , camera.getCenter().y);
    }
    if(player->getPosition().y > camera.getCenter().y + (int)(camera.getSize().y * CAMERA_SENSITIVITY) - CHARA_SPRITE_H){
        camera.setCenter(camera.getCenter().x, camera.getCenter().y - ((camera.getCenter().y ) + (int)(camera.getSize().y * CAMERA_SENSITIVITY) - CHARA_SPRITE_H - player->getPosition().y ));
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

void Game::handle_hitboxes() {
}
