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
    int speed = rand()%5 +1;
    
    std::vector<Koopa> koopas;
    for(int i= 0; i<2;i++){
            pos = rand()%800 +40;
            speed = rand()%5 +1;
            Koopa koopa_obj(pos,speed);
            koopas.push_back(koopa_obj);
         
        }

    
//    Koopa any;
    std::vector<Goomba> goombas;
    for(int i= 0; i<2;i++){
            pos = rand()%800 +40;
            speed = rand()%5 +1;
            Goomba goombas_obj(pos,speed);
            goombas.push_back(goombas_obj);
         
        }
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
        //        if(mario._isalive ==true){
        
        map.drawMap(renderer);
        mario.UpdateMario(map);
        mario.drawMario(window);
//        koopa1.drawKoopa(window);
//        koopa1.Move(map);

        for (int i = 0; i<2 ;i++) {
            koopas[i].drawKoopa(window);
            koopas[i].Move(map);
            goombas[i].drawGoomba(window);
            goombas[i].Move(map);
//            std::cout<<koopas[i]._koopaPos.x<<"\n";
//            std::cout<<koopas[i]._koopaPos.y<<"\n";
//            std::cout<<koopas[i]._isJumped<<"\n";
            
        }
      

        

        //            koopa.JumpedOnTop(mario);
        
        
//        goomba.drawGoomba(window);
        //            goomba.JumpedOnTop(mario);
//        goomba.Move(map);
        
//        score.update(koopa,goomba,mario);
        score.drawScores(window);
        
        if (timesRumming>=500) {
            
//            koopa.reset();
//            goomba.reset();
            timesRumming=0;
        }
        
//        mario.GameOver(goomba, koopa);
//        mario.GameOver(goomba1, koopa1);
        //            mario.GameOver(goomba2, koopa2);
        score.drawScores(window);
        timesRumming++;
        
        //        }else{
        //            gameover.drawGameOver(window);
        //            score.drawScores(window);
        //        }
        // end the current frame
        window.display();
    }
    
    return 0;
}
