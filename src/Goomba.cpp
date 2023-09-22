
//  Goomba.cpp
//  SuperMario
//
//  Created by Jakob West on 9/20/23.
//

#include "Goomba.hpp"
#include "Globle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
Goomba::Goomba()

{
    if( _goombaTexture.loadFromFile("../src/image/Goomba.png")){
        _goombaSprite.setTexture(_goombaTexture);
        _goombaSprite.setPosition(600, 0);
        _goombaSprite.setScale(sf::Vector2f(2,2));
        _goombaPos = _goombaSprite.getPosition();
        _goombaBound = _goombaSprite.getGlobalBounds();
    };
};

Goomba::Goomba(int pos)

{
    if( _goombaTexture.loadFromFile("../src/image/Goomba.png")){
        _goombaSprite.setTexture(_goombaTexture);
        _goombaSprite.setPosition(pos, 0);
        _goombaSprite.setScale(sf::Vector2f(2,2));
        _goombaPos = _goombaSprite.getPosition();
        _goombaBound = _goombaSprite.getGlobalBounds();
    };
};

Goomba::Goomba(int pos, int speedTime)

{
    if( _goombaTexture.loadFromFile("../src/image/Goomba.png")){
        _goombaSprite.setTexture(_goombaTexture);
        _goombaSprite.setPosition(pos, 0);
        _goombaSprite.setScale(sf::Vector2f(2,2));
        _goombaPos = _goombaSprite.getPosition();
        _goombaBound = _goombaSprite.getGlobalBounds();
        _goombaSpeed *=speedTime;
    };
};

void Goomba::drawGoomba(sf::RenderWindow& window) {
    if (_isJumped != true) {
        window.draw(_goombaSprite);
    } else {
        if (_goombaTexture.loadFromFile("../src/image/DeadGoomba.png")) {
            _goombaSprite.setTexture(_goombaTexture);
            window.draw(_goombaSprite);

            // Create a timer using sf::Clock
            static sf::Clock timer;
            sf::Time elapsedTime = timer.getElapsedTime();
            
            if (elapsedTime.asSeconds() >= 0.2f) { // 2 seconds in this example
                // Reset the Goomba and load the default texture
                reset();
                if (_goombaTexture.loadFromFile("../src/image/Goomba.png")) {
                    _goombaSprite.setTexture(_goombaTexture);
                }
                timer.restart();
            }
        }
    }
    
    
};
    

void Goomba::Move(Map& map){
    _goombaBound = _goombaSprite.getGlobalBounds();
    if (_goombaBound.intersects(map.mapBound)) {
        if (_goombaPos.x>30 and _return ==false) {
            _return = false;
            _goombaPos.x -=0.5f;
        }else{
            _return = true;
            _goombaPos.x += 0.5f;
            if (_goombaPos.x >=screenWidth-100 and _return == true) {
                _return = false;
                _goombaPos.x -=0.5f;
            }
        }
    }else{
        _goombaPos.y += 0.75f;
    }
    _goombaSprite.setPosition(_goombaPos);
};

void Goomba::reset(){
    if (_isJumped ==1) {
        int pos;
        if (_goombaPos.x+70>700) {
            pos = 400;
        }else{
            pos =_goombaPos.x;
        }
        _goombaSprite.setPosition(sf::Vector2f(pos, 0));
        _goombaPos = _goombaSprite.getPosition();
        _isJumped = 0;
    }

};
