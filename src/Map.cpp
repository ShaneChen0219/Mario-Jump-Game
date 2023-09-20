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

Map::Map():
mapSprite(),mapTexture()
{
    if (mapTexture.loadFromFile("../src/image/Block.png")) {
        mapSprite.setTexture(mapTexture);
        mapSprite.setScale(5, 10);
        mapSprite.setPosition(sf::Vector2f(0,350));
    }
};
void Map::updateMap(){
    if(offset > mapTexture.getSize().x - screenWidth){
        offset = 0;
    }
    offset += gameSpeed;
    mapSprite.setTextureRect(sf::IntRect(offset,0,screenWidth,screenHeight));
};
void Map::resetMap(){
    offset = 0;
    mapSprite.setTextureRect(sf::IntRect(0,0,screenWidth,screenHeight));
};
void Map::drawMap(Renderer& renderer){
    sf::Texture mapTexture1;
    sf::Texture mapTexture2;
    mapTexture1.loadFromFile("../src/image/Block.png");
    mapTexture2.loadFromFile("../src/image/brokenblock.png");
    for(unsigned int i = 0; i<50 ;i++){
        if (i%2==0) {
            renderer.Draw(mapTexture1, sf::Vector2f(55*i,475), sf::Vector2f(60,60));
        }else{
            renderer.Draw(mapTexture2, sf::Vector2f(55*i,475), sf::Vector2f(60,60));
        }
        
    }
}
