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
    if(_isJumped != true){
        window.draw(_koopaSprite);
        
        
    }
    else{
        if(_koopaTexture.loadFromFile("../src/image/DeadKoopa.png")){
            _koopaSprite.setTexture(_koopaTexture);
            window.draw(_koopaSprite);
            for(int i =0; i<1000; i++){
                if(i==999){
                    reset();
                }
            }
        }
        
    }
};


void Koopa::Move(Map& map){
    _koopaBound = _koopaSprite.getGlobalBounds();
    if (_koopaBound.intersects(map.mapBound)) {
        if(_koopaTexture.loadFromFile("../src/image/Koopa.png")){
            _koopaSprite.setTexture(_koopaTexture);}
        if (_koopaPos.x<screenWidth-100 and _return == false) {
            _return = false;
            _koopaPos.x+= _koopaSpeed;
        }else{
            _return =true;
            _koopaPos.x-= _koopaSpeed;
            if (_koopaPos.x<=30 and _return == true) {
                _return = false;
                _koopaPos.x+= _koopaSpeed;
            }
        }
    }else{
        _koopaPos.y += 1.0f;
    }
    _koopaSprite.setPosition(_koopaPos);
};


void Koopa::reset(){
    if(_isJumped==1){
        int pos;
        if (_koopaPos.x+70>700) {
            pos = 400;
        }else{
            pos =_koopaPos.x;
        }

        _koopaSprite.setPosition(sf::Vector2f(pos, 0));
        _koopaPos = _koopaSprite.getPosition();
        _isJumped = 0;
    }
};
