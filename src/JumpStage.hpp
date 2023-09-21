//
//  JumpStage.hpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#ifndef JumpStage_hpp
#define JumpStage_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Globle.hpp"
#include "Mario.hpp"
#include "Map.hpp"

class Map;
class Mario;
class JumpStage{
private:
    sf::Sprite _jumpStageSprite;
    sf::Texture _jumpStageTexture;
public:
    JumpStage();
    JumpStage(sf::Vector2f pos);
    sf::Vector2f _jumpStagePos{0.f, 0.f};
    sf::FloatRect _jumpStageBound;
    void drawJumpStage(sf::RenderWindow& window);
};
#endif /* JumpStage_hpp */
