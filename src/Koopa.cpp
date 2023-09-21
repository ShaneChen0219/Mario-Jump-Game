//
//  Koopa.cpp
//  SuperMario
//
//  Created by Jakob West on 9/20/23.
//

#include "Koopa.hpp"
#include "Globle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
Koopa::Koopa()
{
    
    if(_koopaTexture.loadFromFile("../src/image/Koopa.png")){
        _koopaSprite.setTexture(_koopaTexture);
        _koopaSprite.setPosition(800, 0);
        _koopaSprite.setScale(sf::Vector2f(3,3));
        _koopaPos = _koopaSprite.getPosition();
        _koopaBound = _koopaSprite.getGlobalBounds();
        
    };
};

Koopa::Koopa(int pos)
{
    
    if(_koopaTexture.loadFromFile("../src/image/Koopa.png")){
        _koopaSprite.setTexture(_koopaTexture);
        _koopaSprite.setPosition(pos, 0);
        _koopaSprite.setScale(sf::Vector2f(3,3));
        _koopaPos = _koopaSprite.getPosition();
        _koopaBound = _koopaSprite.getGlobalBounds();
        
    };
};

Koopa::Koopa(int pos,int speedTime)
{
    
    if(_koopaTexture.loadFromFile("../src/image/Koopa.png")){
        _koopaSprite.setTexture(_koopaTexture);
        _koopaSprite.setPosition(pos, 0);
        _koopaSprite.setScale(sf::Vector2f(3,3));
        _koopaPos = _koopaSprite.getPosition();
        _koopaBound = _koopaSprite.getGlobalBounds();
        _koopaSpeed *=speedTime;
    };
};


void Koopa::drawKoopa(sf::RenderWindow& window){
//    std::cout<<_koopaSprite.getGlobalBounds().left<<"\n";
    if(!_isJumped){
        window.draw(_koopaSprite);
    }
};

void Koopa::UpdateKoopa(Map& map){
    _koopaBound = _koopaSprite.getGlobalBounds();
    
    if(!_koopaBound.intersects(map.mapBound)){
        _koopaPos.y += 5.0f;
    }
    _koopaSprite.setPosition(_koopaPos);
};

void Koopa::JumpedOnTop(Mario& mario){
    if ((mario._marioBound.top +mario._marioBound.height)>=_koopaBound.top &&  (mario._marioBound.left<=(_koopaBound.left+_koopaBound.width))&&(mario._marioBound.left+mario._marioBound.width)>=_koopaBound.left) {
        _isJumped = true;
    }
};
void Koopa::Move(Map& map){
    if (_koopaBound.intersects(map.mapBound)) {
        if (_koopaPos.x<screenWidth-100 and _return == false) {
            _return = false;
            _koopaPos.x+= _koopaSpeed;
        }else{
            _return =true;
            _koopaPos.x-= _koopaSpeed;
            if (_koopaPos.x==30 and _return == true) {
                _return = false;
                _koopaPos.x+= _koopaSpeed;
            }
        }
        _koopaSprite.setPosition(_koopaPos);
        
    }
    _koopaSprite.setPosition(_koopaPos);
};


void Koopa::reset(){
    if(_isJumped==1){
        _koopaSprite.setPosition(_koopaPos.x+50, 0);
        _isJumped = 0;
    }
};
