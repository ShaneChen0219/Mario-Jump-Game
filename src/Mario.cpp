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
:timeTracker()
{
    marioTexture.loadFromFile("../src/image/Mario.png");
    marioSprite.setTexture(marioTexture);
    //???
    for(int i = 0; i < frames.size(); i++){
        frames[i] = sf::IntRect(i * 90, 0, 90, 95);
    }
    marioSprite.setTextureRect(frames[0]);
    marioPos = marioSprite.getPosition();
};

void Mario::drawMario(sf::RenderWindow& window){
};

void Mario::UpdateMario(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        marioPos.x -= _marioSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        marioPos.x += _marioSpeed;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
//        marioPos.y +=
    }
};
