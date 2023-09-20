//
//  Map.hpp
//  SuperMario
//
//  Created by Shane Chen on 9/19/23.
//

#ifndef Map_hpp
#define Map_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Globle.hpp"
#include "Renderer.hpp"
class Map{
public:
    sf::Sprite mapSprite;
    sf::Texture mapTexture;
    int offset=0;
    Map();
    void updateMap();
    void resetMap();
    void drawMap(Renderer& renderer);
};
#endif /* Map_hpp */
