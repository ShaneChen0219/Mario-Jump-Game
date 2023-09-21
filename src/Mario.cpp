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
    _marioSprite.setPosition(10, 200);
    _marioSprite.setScale(sf::Vector2f(3,3));
    _marioPos = _marioSprite.getPosition();
    _marioBound =_marioSprite.getGlobalBounds();
};

void Mario::drawMario(sf::RenderWindow& window){
//    if (_isalive) {
        window.draw(_marioSprite);
//    }
    
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
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&_marioBound.intersects(map.mapBound)){
        _marioPos.y -= _marioJumpHeight;
        //Jump from Ground
        if (_marioBound.intersects(map.mapBound)) {
            _marioPos.y -= _marioJumpHeight;
        }
    }
    
    if(!_marioBound.intersects(map.mapBound)) {
        _marioPos.y += _marioFallSpeed;
    }
       
    _marioSprite.setPosition(_marioPos);
};

void Mario::GameOver(Goomba goombas,Koopa koopas){
    if(_marioBound.intersects(goombas._goombaBound)&&goombas._isJumped==0){
        _isalive =false;
    }
    if(_marioBound.intersects(koopas._koopaBound)&&koopas._isJumped==0){
        _isalive =false;
    }
};
