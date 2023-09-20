//
//  Goomba.cpp
//  SuperMario
//
//  Created by Jakob West on 9/20/23.
//

#include "Goomba.hpp"
#include "Globle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
Goomba::goomba()

{
    _goombaTexture.loadFromFile("../src/image/Goomba.png");
    _goombaSprite.setTexture(_goombaTexture);
    _goombaSprite.setPosition(600, 340);
    _goombaSprite.setScale(sf::Vector2f(5,5));
    _goombaPos = _goombaSprite.getPosition();
};

void Koopa::drawGoomba(sf::RenderWindow& window){
    window.draw(_goombaSprite);
};
