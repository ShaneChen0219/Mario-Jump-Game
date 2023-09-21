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
void Score::update(Koopa& koopa, Goomba& goomba, Mario mario)
    {

        if (mario._marioBound.intersects(goomba._goombaBound)&&(mario._marioBound.top+mario._marioBound.height)>goomba._goombaBound.top&&goomba._isJumped ==false){
            scores +=1;
            scoresText.setString("Score: " + std::to_string(scores) );
            goomba._isJumped=true;
        };
        if (mario._marioBound.intersects(koopa._koopaBound)&&(mario._marioBound.top+mario._marioBound.height)>koopa._koopaBound.top&&koopa._isJumped==false){
            scores +=1;
            scoresText.setString("Score: " + std::to_string(scores));
            koopa._isJumped = true;
        };
    }
