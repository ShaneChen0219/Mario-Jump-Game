//
//  Goomba.hpp
//  SuperMario
//
//  Created by Jakob West on 9/20/23.
//

#ifndef Goomba_hpp
#define Goomba_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Globle.hpp"


class Goomba{
private:
    //standard sfml library
    sf :: Sprite _goombaSprite;
    sf :: Texture _goombaTexture;
    float _goombaSpeed;
    
public:
    Goomba();
    void drawGoomba(sf::RenderWindow& window);
    //void UpdateGoomba(Map& map);
    sf::Vector2f _goombaPos{0.f, 0.f};
    
};
#endif /* Goomba_hpp */
