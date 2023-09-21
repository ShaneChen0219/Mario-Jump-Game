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
{   float marioLeft = mario._marioBound.left;
    float marioRight =(mario._marioBound.left +mario._marioBound.width);
    float marioTop = mario._marioBound.top;
    float marioBottom = (mario._marioBound.top+mario._marioBound.height);
    float goombaLeft = goomba._goombaBound.left;
    float goombaRight = goomba._goombaBound.left+goomba._goombaBound.width;
    float goombaMid = (goomba._goombaBound.left+goomba._goombaBound.width/2);
    float goombaTop = goomba._goombaBound.top;
    float goombaBottom = (goomba._goombaBound.top + goomba._goombaBound.height);
    if(marioLeft>=goombaMid){
        if (marioLeft<goombaRight&& marioRight<(goombaRight+marioRight)){
            if((mario._marioBound.top+mario._marioBound.height)<=goomba._goombaBound.top){
                
                if(goomba._isJumped ==false){
                    scores +=1;
                    scoresText.setString("Score: " + std::to_string(scores) );
                    goomba._isJumped=true;
                }
            }
            
        }
    }else{
        
    };
    //        if (mario._marioBound.intersects(koopa._koopaBound)&&(mario._marioBound.top+mario._marioBound.height)>koopa._koopaBound.top&&koopa._isJumped==false){
    //            scores +=1;
    //            scoresText.setString("Score: " + std::to_string(scores));
    //            koopa._isJumped = true;
    //        };
}
