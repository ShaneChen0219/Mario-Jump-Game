//
//  JumpStage.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#include "JumpStage.hpp"
#include "Globle.hpp"
#include <SFML/Graphics.hpp>
JumpStage::JumpStage(){
    if (_jumpStageTexture.loadFromFile("../src/image/QuestionBlock.png")) {
        _jumpStageSprite.setTexture(_jumpStageTexture);
        _jumpStageSprite.setPosition(500, 400);
        _jumpStageSprite.setScale(2, 2);
        _jumpStagePos =_jumpStageSprite.getPosition();
        _jumpStageBound = _jumpStageSprite.getGlobalBounds();
    }
}
JumpStage::JumpStage(sf::Vector2f pos){
    if (_jumpStageTexture.loadFromFile("../src/image/QuestionBlock.png")) {
        _jumpStageSprite.setTexture(_jumpStageTexture);
        _jumpStageSprite.setPosition(pos);
        _jumpStageSprite.setScale(2, 2);
        _jumpStagePos =_jumpStageSprite.getPosition();
        _jumpStageBound = _jumpStageSprite.getGlobalBounds();
    }
};

void JumpStage::drawJumpStage(sf::RenderWindow& window){
    window.draw(_jumpStageSprite);
};
