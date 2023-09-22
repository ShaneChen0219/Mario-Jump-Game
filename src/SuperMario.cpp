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
#include "GameClock.hpp"

int main()
{
    // create the window
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Super Mario");
    sf::Event event;
    sf::Time deltaTime;
    sf::Clock deltaTimeClock;
    //For random number
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distributionForPos(100, 800);
    std::uniform_int_distribution<int> distributionForSpeed(1, 5);
    
    
    Renderer renderer(window);
    Map map;
    Mario mario;
    GameClock gameclock;
    
    //    Generate koopas
    int pos = distributionForPos(generator);
    float speed = distributionForSpeed(generator);
    int numOfKoopaAndGoomba =2;
    std::vector<Koopa> koopas;
    for(int i= 0; i<numOfKoopaAndGoomba;i++){
        pos = distributionForPos(generator);
        speed = distributionForSpeed(generator);
        Koopa koopa_obj(pos,speed);
        koopas.push_back(koopa_obj);
    }
    //only for making the image right
    Koopa any;
    std::vector<Goomba> goombas;
    for(int i= 0; i<numOfKoopaAndGoomba;i++){
        pos = distributionForPos(generator);
        speed = distributionForSpeed(generator);
        Goomba goombas_obj(pos,speed);
        goombas.push_back(goombas_obj);
        
    }
    //only for making the image right
    Goomba any2;
    GameOver gameover;
    Score score;
    bool startGame = true;
    int timesRumming =0;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        deltaTime = deltaTimeClock.restart();
        
        window.clear(sf::Color::White);
        
            if(mario._isalive ==true){
                map.drawMap(renderer);
                mario.UpdateMario(map);
                mario.drawMario(window);
                gameclock.drawClock(window);
                gameclock.update();
                
                for (int i = 0; i<numOfKoopaAndGoomba ;i++) {
                    koopas[i].drawKoopa(window);
                    koopas[i].Move(map);
                    goombas[i].drawGoomba(window);
                    goombas[i].Move(map);
                }
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
                startGame = false;
            }
        
        // end the current frame
        window.display();
    }
    
    return 0;
}
