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
#include "Mario.hpp"
#include "Map.hpp"
class Map;
class Mario;

class Goomba{
private:
    //standard sfml library
    sf :: Sprite _goombaSprite;
    sf :: Texture _goombaTexture;
    float _goombaSpeed =2.0f;
    bool _isJumped=0;
public:
    Goomba();
    void drawGoomba(sf::RenderWindow& window);
    void UpdateGoomba(Map& map);
    sf::Vector2f _goombaPos{0.f, 0.f};
    sf::FloatRect _goombaBound;
    void JumpedOnTop(Mario& mario);
    
};
#endif /* Goomba_hpp */
