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
#include <vector>
class Map;
class JumpStage;
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
    void UpdateMario(Map& map,std::vector<JumpStage> jumpstages);
    sf::Vector2f _marioPos{0.f, 0.f};
    sf::FloatRect _marioBound;
    void StartJump();
    bool _isalive= true;
};
#endif /* Mario_hpp */
