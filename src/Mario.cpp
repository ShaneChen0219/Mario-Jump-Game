//
//  Mario.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/19/23.
//

#include "Mario.hpp"
#include "Globle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
Mario::Mario()
{
    _marioTexture.loadFromFile("../src/image/Mario.png");
    _marioSprite.setTexture(_marioTexture);
    _marioSprite.setPosition(30, 200);
    _marioSprite.setScale(sf::Vector2f(3,3));
    _marioPos = _marioSprite.getPosition();
    _marioBound =_marioSprite.getGlobalBounds();
};

void Mario::drawMario(sf::RenderWindow& window){
    window.draw(_marioSprite);
};

void Mario::UpdateMario(Map& map){
    _marioBound =_marioSprite.getGlobalBounds();
    if(_marioPos.x>20){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _marioPos.x -= _marioSpeed;
        }
    }
    if(_marioPos.x<850){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _marioPos.x += _marioSpeed;
        }
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if (_marioBound.intersects(map.mapBound)) {
                _marioPos.y -= _marioJumpHeight;
            }
        }
        else{
            if(!_marioBound.intersects(map.mapBound)) {
                _marioPos.y += _marioJumpHeight;
            }
        }
        _marioSprite.setPosition(_marioPos);
};
