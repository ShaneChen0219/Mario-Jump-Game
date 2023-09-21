#include <SFML/Graphics.hpp>
#include "Mario.hpp"
#include "Koopa.hpp"
#include "Globle.hpp"
#include "Map.hpp"
#include "Renderer.hpp"
#include "Goomba.hpp"
#include "JumpStage.hpp"
#include "Gameover.hpp"
#include "Score.hpp"
#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <vector>

int main()
{
    // create the window
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Super Mario");
    sf::Event event;
    sf::Time deltaTime;
    sf::Clock deltaTimeClock;
    
    Renderer renderer(window);
    Map map;
    Mario mario;
    //Generate koopas
//    for(unsigned int i= 0; i< 50;){
//        srand(i);
//    }
    int pos = rand()%800 +40;
    int speed = rand()%5 +1;
    pos = rand()%800 +40;
    speed = rand()%5 +1;
    Koopa koopa(pos,speed);
    pos = rand()%800 +40;
    speed = rand()%5 +1;
    Koopa koopa1(pos,speed);
    pos = rand()%800 +40;
    speed = rand()%5 +1;
    Koopa koopa2(pos,speed);
    std::vector<Koopa> koopas = {koopa,koopa1,koopa2};
    pos = rand()%800 +40;
    Goomba goomba(pos);
    pos = rand()%800 +40;
    Goomba goomba1(pos);
    pos = rand()%800 +40;
    Goomba goomba2(pos);
    std::vector<Goomba> goombas = {goomba,goomba1,goomba2};
    GameOver gameover;
    Score score;
//    JumpStage jumpstage;
//    JumpStage jumpstage1(sf::Vector2f{200,150});
//    JumpStage jumpstage2(sf::Vector2f{250,200});
//    std::vector<JumpStage> allJumpStage={jumpstage,jumpstage1,jumpstage2};
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        deltaTime = deltaTimeClock.restart();
        
        window.clear(sf::Color::White);
        if(mario._isalive ==true){
            mario.UpdateMario(map);
            map.drawMap(renderer);
            mario.drawMario(window);
            
            koopa.drawKoopa(window);
            koopa.UpdateKoopa(map);
            koopa.JumpedOnTop(mario);
            koopa.Move(map);
            
            
            
            goomba.drawGoomba(window);
            goomba.UpdateGoomba(map);
            goomba.JumpedOnTop(mario);
            goomba.Move(map);
            
            
            score.update(koopa,goomba,mario._isalive);
            score.drawScores(window);
            
            koopa.reset();
            goomba.reset();
            
            koopa1.drawKoopa(window);
            koopa1.UpdateKoopa(map);
            koopa1.JumpedOnTop(mario);
            koopa1.Move(map);
            
            goomba1.drawGoomba(window);
            goomba1.UpdateGoomba(map);
            goomba1.JumpedOnTop(mario);
            goomba1.Move(map);
            
            
            score.update(koopa1,goomba1,mario._isalive);
            score.drawScores(window);
            goomba1.reset();
            koopa1.reset();
            
            
            
            koopa2.drawKoopa(window);
            koopa2.UpdateKoopa(map);
            koopa2.JumpedOnTop(mario);
            koopa2.Move(map);
            
            goomba2.drawGoomba(window);
            goomba2.UpdateGoomba(map);
            goomba2.JumpedOnTop(mario);
            goomba2.Move(map);
            score.drawScores(window);

            score.update(koopa2,goomba2,mario._isalive);
            score.drawScores(window);
            koopa2.reset();
            goomba2.reset();
            
            mario.GameOver(goomba, koopa);
            mario.GameOver(goomba1, koopa1);
            mario.GameOver(goomba2, koopa2);
            score.drawScores(window);
            
            
        }else{
            gameover.drawGameOver(window);
            score.drawScores(window);
        }
        // end the current frame
        window.display();
    }
    
    return 0;
}
