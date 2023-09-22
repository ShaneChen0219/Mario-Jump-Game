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
    
    bool _return = 0;
public:
    Goomba();
    Goomba(int pos);
    Goomba(int pos,int speedTime);
    void drawGoomba(sf::RenderWindow& window);
    sf::Vector2f _goombaPos;
    sf::FloatRect _goombaBound;
    void Move(Map& map);
    bool _isJumped=0;
    void reset();
};
#endif /* Goomba_hpp */
