//
//  Koopa.hpp
//  SuperMario
//
//  Created by Jakob West on 9/20/23.
//

#ifndef Koopa_hpp
#define Koopa_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Globle.hpp"
#include "Mario.hpp"
#include "Map.hpp"
class Map;
class Mario;
class Koopa{
private:
    //standard sfml library
    sf::Sprite _koopaSprite;
    sf::Texture _koopaTexture;
    bool _isJumped=0;
    float _koopaSpeed =2.0f;
public:
    Koopa();
    void drawKoopa(sf::RenderWindow& window);
    void UpdateKoopa(Map& map);
    sf::Vector2f _koopaPos{0.f, 0.f};
    sf::FloatRect _koopaBound;
    void JumpedOnTop(Mario& mario);
    void Move();
};
    
    
    
    

#endif /* Koopa_hpp */
