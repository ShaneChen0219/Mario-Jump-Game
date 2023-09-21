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
    //    Generate koopas
    int pos = rand()%800 +40;
    float speed = rand()%5 +1;
    int numOfKoopaAndGoomba =10;
    std::vector<Koopa> koopas;
    for(int i= 0; i<numOfKoopaAndGoomba;i++){
        srand(i+speed);
        pos = rand()%800 +40;
        speed = (rand()% 5000 +1000)/1000;
        Koopa koopa_obj(pos,speed);
        koopas.push_back(koopa_obj);
    }
    //only for making the image right
    Koopa any;
    std::vector<Goomba> goombas;
    for(int i= 0; i<numOfKoopaAndGoomba;i++){
        srand(i+speed);
        pos = rand()%800 +40;
        speed = (rand()% 5000 +1000)/1000;
        Goomba goombas_obj(pos,speed);
        goombas.push_back(goombas_obj);
        
    }
    //only for making the image right
    Goomba any2;
    
    //    pos = rand()%800 +40;
    //    speed = rand()%5 +1;
    //    Koopa koopa(pos,speed);
    //    pos = rand()%800 +40;
    //    speed = rand()%5 +1;
    // Koopa koopaiijkjkhkhjh(pos,speed);
    //    pos = rand()%800 +40;
    //    speed = rand()%5 +1;
    //    Koopa koopa2(pos,speed);
    
    //    std::vector<Koopa> koopas = {koopa[0],koopa[1]};
    //    pos = rand()%800 +40;
    //    Goomba goomba(pos);
    //    pos = rand()%800 +40;
    //    Goomba goomba1(pos);
    //    pos = rand()%800 +40;
    //    Goomba goomba2(pos);
    //    std::vector<Goomba> goombas = {goomba,goomba1,goomba2};
    GameOver gameover;
    Score score;
    int timesRumming =0;
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
            
            map.drawMap(renderer);
            mario.UpdateMario(map);
            mario.drawMario(window);
            
            for (int i = 0; i<numOfKoopaAndGoomba ;i++) {
                koopas[i].drawKoopa(window);
                koopas[i].Move(map);
                goombas[i].drawGoomba(window);
                goombas[i].Move(map);
            }
            
            //        koopa.JumpedOnTop(mario);
            //        goomba.JumpedOnTop(mario);
            
            score.drawScores(window);
            
            if (timesRumming>=500) {
                for (int i = 0; i<numOfKoopaAndGoomba ;i++) {
                    koopas[i].reset();
                    goombas[i].reset();
                }
                timesRumming=0;
            }
            for (int i = 0; i<numOfKoopaAndGoomba ;i++) {
                score.update(koopas[i],goombas[i],mario);
                mario.GameOver(goombas[i],koopas[i]);
            }
            score.drawScores(window);
            timesRumming++;
            
        }else{
            gameover.drawGameOver(window);
            score.drawScores(window);
        }
        // end the current frame
        window.display();
    }
    
    return 0;
}
