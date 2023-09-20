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
        _koopaSprite.setPosition(500, 0);
        _koopaSprite.setScale(sf::Vector2f(3,3));
        _koopaPos = _koopaSprite.getPosition();
        _koopaBound = _koopaSprite.getGlobalBounds();
        
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
    if ((mario._marioBound.top +mario._marioBound.height)<=_koopaBound.top &&  (mario._marioBound.left<=(_koopaBound.left+_koopaBound.width))&&(mario._marioBound.left+mario._marioBound.width)>=_koopaBound.left) {
        _isJumped = true;
    }
};
void Move(){
    
};
