//
//  Score.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/21/23.
//

#include "Score.hpp"
#include "Mario.hpp"
#include "Score.hpp"
Score::Score()
    :scoresFont(), scoresText()
    {
      if(scoresFont.loadFromFile("../src/image/OpenSans-Bold.ttf"))
      {
        scoresText.setFont(scoresFont);
        scoresText.setCharacterSize(15);
        scoresText.setPosition(50,50);
        scoresText.setFillColor(sf::Color::Black);
        scoresText.setString("Score: " + std::to_string(scores) );

      }
    }
void Score::drawScores(sf::RenderWindow& window){
  window.draw(scoresText);
};
void Score::update(Koopa koopa, Goomba goomba, bool _isalive)
    {

        if (koopa._isJumped ==1){
            scores +=1;
            std::cout<<scores;
            scoresText.setString("Score: " + std::to_string(scores) );
        };
        if (goomba._isJumped ==1){
            scores +=1;
            scoresText.setString("Score: " + std::to_string(scores));
        };
    }
