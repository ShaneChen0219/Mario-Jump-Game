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
#include "JumpStage.hpp"
#include "Koopa.hpp"
#include "Goomba.hpp"
#include <vector>
class Map;
class Koopa;
class JumpStage;
class Goomba;
class Mario{
private:
    sf::Sprite _marioSprite;
    sf::Texture _marioTexture;
    const float _marioSpeed =1.5f;
    const float _marioJumpHeight = 70.0f;
    const float _marioFallSpeed = 1.8f;
    
public:
    Mario();
    void drawMario(sf::RenderWindow& window);
    void UpdateMario(Map& map);
    void GameOver(Goomba goombas,Koopa koopas);
    sf::Vector2f _marioPos{0.f, 0.f};
    sf::FloatRect _marioBound;
    bool _isalive= true;
};
#endif /* Mario_hpp */
