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
#include "Renderer.hpp"

class Koopa{
private:
    //standard sfml library
    sf :: Sprite _koopaSprite;
    sf :: Texture _koopaTexture;
    float _koopaSpeed;
    
public:
    Koopa();
    void drawKoopa(sf::RenderWindow& window);
    //void UpdateKoopa(Map& map);
    sf::Vector2f _koopaPos{0.f, 0.f};
    
};
    
    
    
    

#endif /* Koopa_hpp */
