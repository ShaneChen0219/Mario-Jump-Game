//
//  Mario.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/19/23.
//

#include "Mario.hpp"
#include "Globle.hpp"
#include <SFML/Graphics.hpp>
Mario::Mario()
{
    _marioTexture.loadFromFile("../src/image/Mario.png");
    _marioSprite.setTexture(_marioTexture);
    _marioSprite.setPosition(10, 390);
    _marioSprite.setScale(sf::Vector2f(3,3));
    _marioPos = _marioSprite.getPosition();
};

void Mario::drawMario(sf::RenderWindow& window){
    window.draw(_marioSprite);
};

void Mario::UpdateMario(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _marioPos.x -= _marioSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _marioPos.x += _marioSpeed;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
//        marioPos.y +=
    }
};
