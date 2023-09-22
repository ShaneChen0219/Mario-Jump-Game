//
//  Map.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/19/23.
//

#include "Map.hpp"
#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "Globle.hpp"
#include "Renderer.hpp"
#include <iostream>

Map::Map():
mapSprite(),mapTexture()
{
//        mapSprite.setTexture(mapTexture);
        mapSprite.setPosition(sf::Vector2f(0,440));
    
        mapSprite.setTextureRect(sf::IntRect(0,0,screenWidth,100));
        mapBound = mapSprite.getGlobalBounds();
        mapSprite.setScale(5, 10);
        mapSprite.setPosition(sf::Vector2f(0,350));
};
// The drawMap method belongs to the map class: the function will initialize our mapTexture variables  and by using the loadFromFile method we will call image files for those texture variables
void Map::drawMap(Renderer& renderer){
    sf::Texture mapTexture1;
    sf::Texture mapTexture2;
    mapTexture1.loadFromFile("../src/image/Block.png");
    mapTexture2.loadFromFile("../src/image/brokenblock.png");
    //renderer.Draw takes in the texture, position and size for our texture
    // For every element in the rendered space we will assign one texture to draw at every other position i (starting from our first unit of pixels at y:475 and x:55) with the size of the texture being the  size Vector2f(60,60)
    
    for(unsigned int i = 0; i<1000 ;i++){
        if (i%2==0) {
            renderer.Draw(mapTexture1, sf::Vector2f(55*i,475), sf::Vector2f(60,60));
        }else{
            renderer.Draw(mapTexture2, sf::Vector2f(55*i,475), sf::Vector2f(60,60));
        }
        
    }
}
