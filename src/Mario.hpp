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

class Mario{
private:
    sf::Sprite marioSprite;
    sf::Texture marioTexture;
    float _marioSpeed =5.0f;
    float _marioJumpHeight = 5.0f;

public:
    Mario();
    void drawMario(sf::RenderWindow& window);
    void UpdateMario();
    
    sf::Vector2f marioPos{0.f, 0.f};
    sf::Vector2f marioMotion{0.f, 0.f};
    sf::FloatRect marioBounds;
    std::array<sf::IntRect, 6> frames;
    sf::Time timeTracker;
    int animationCounter = 0;
};
#endif /* Mario_hpp */
