//
//  Gameover.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#include "Gameover.hpp"
#include <iostream>
GameOver::GameOver(){
    if(_gameOverTexture.loadFromFile("../src/image/gameover.png")){
        _gameOverSprite.setTexture(_gameOverTexture);
        _gameOverSprite.setPosition(236, 0);
        _gameOverSprite.setScale(1, 1);
        _gameoverPos = _gameOverSprite.getPosition();
    };
    
};
void GameOver::drawGameOver(sf::RenderWindow& window){
    window.draw(_gameOverSprite);
};

