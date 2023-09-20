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

//defining a class to implement our map texture: block.png for our mario to have a ground
class Map{
public:
    //initializing our Sprite field called mapSprite, this will be the size for our texture to fill
    sf::Sprite mapSprite;
    // initializing our texture that we will take a image file and fill our sprite
    sf::Texture mapTexture;
    //
    int offset=0;
    sf::FloatRect mapBound;
    //Creating our Map constructor for our class
    Map();
    
    void updateMap();
    void resetMap();
    // Creating a function that will take in our class Renderers constructor constructor, drawmap will take in the values directly for manipulation
    void drawMap(Renderer& renderer);
};
#endif /* Map_hpp */
