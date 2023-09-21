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
    float koopaLeft = koopa._koopaBound.left;
    float koopaRight = (koopaLeft+koopa._koopaBound.width);
    float koopaMid =(koopaLeft+koopa._koopaBound.width/2);
    float koopaTop = koopa._koopaBound.top;
    float koopaBottom = (koopaTop+koopa._koopaBound.height);
    
    
    if(marioLeft>=goombaMid){
        if (marioLeft<goombaRight&& marioRight<(goombaRight+marioRight)){
            if(marioBottom<=goombaTop && marioBottom>goombaTop-10){
                
                if(goomba._isJumped ==false){
                    scores +=1;
                    scoresText.setString("Score: " + std::to_string(scores) );
                    goomba._isJumped=true;
                }
            }
            
        }
    }else if(marioRight>goombaLeft){
        if(marioBottom<=goombaTop && marioBottom>goombaTop-10){
            
            if(goomba._isJumped ==false){
                scores +=1;
                scoresText.setString("Score: " + std::to_string(scores) );
                goomba._isJumped=true;
            }
        }
    };
    
    
    if(marioLeft>=koopaMid){
        if (marioLeft<koopaRight&& marioRight<(koopaRight+marioRight)){
            if(marioBottom<=koopaTop && marioBottom>koopaTop-10){
                
                if(koopa._isJumped ==false){
                    scores +=1;
                    scoresText.setString("Score: " + std::to_string(scores) );
                    koopa._isJumped=true;
                }
            }
            
        }
    }else if(marioRight>koopaLeft){
        if(marioBottom<=koopaTop && marioBottom>koopaTop-10){
            
            if(koopa._isJumped ==false){
                scores +=1;
                scoresText.setString("Score: " + std::to_string(scores) );
                koopa._isJumped=true;
            }
        }
    };
}
