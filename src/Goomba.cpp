
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

void Goomba::drawGoomba(sf::RenderWindow& window){
    // if isjumped  which = false:0 is not true then we draw the goombaSprite which will create its position, bound, etc
    if(_isJumped != true){
        window.draw(_goombaSprite);
    }
};
    

void Goomba::JumpedOnTop(Mario& mario){
//        if(_goombaBound.intersects(mario._marioBound)&&((mario._marioBound.top+mario._marioBound.height)>=_goombaBound.top)&& (mario._marioBound.left<=(_goombaBound.left+_goombaBound.width))&&(mario._marioBound.left+mario._marioBound.width)>=_goombaBound.left) {
//            _isJumped = true;
//        }
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
        _goombaPos.y += 5.0f;
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
