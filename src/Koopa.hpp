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
    
    bool _return = 0;
    float _koopaSpeed =0.1f;
public:
    Koopa();
    Koopa(int pos);
    Koopa(int pos, int speedTime);
    void drawKoopa(sf::RenderWindow& window);
    void UpdateKoopa(Map& map);
    sf::Vector2f _koopaPos{0.f, 0.f};
    sf::FloatRect _koopaBound;
    void JumpedOnTop(Mario& mario);
    void Move(Map& map);
    bool _isJumped=0;
    void reset();
};
    
    
    
    

#endif /* Koopa_hpp */
