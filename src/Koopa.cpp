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
    _koopaTexture.loadFromFile("../src/image/Koopa.png");
    _koopaSprite.setTexture(_koopaTexture);
    _koopaSprite.setPosition(30, 700);
    _koopaSprite.setScale(sf::Vector2f(5,5));
    _koopaPos = _koopaSprite.getPosition();
};

void Koopa::drawKoopa(sf::RenderWindow& window){
    window.draw(_koopaSprite);
};
