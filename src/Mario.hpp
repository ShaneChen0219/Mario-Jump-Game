//
//  Mario.hpp
//  SuperMario
//
//  Created by Shane Chen on 9/19/23.
//

#ifndef Mario_hpp
#define Mario_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Map.hpp"
class Map;
class Mario{
private:
    sf::Sprite _marioSprite;
    sf::Texture _marioTexture;
    float _marioSpeed =1.0f;
    float _marioJumpHeight = 100.0f;
    float _marioFallSpeed = 5.0f;


public:
    Mario();
    void drawMario(sf::RenderWindow& window);
    void UpdateMario(Map& map);
    sf::Vector2f _marioPos{0.f, 0.f};
    sf::FloatRect _marioBound;
    
    void StartJump();
};
#endif /* Mario_hpp */
