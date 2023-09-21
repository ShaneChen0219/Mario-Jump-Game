#include <SFML/Graphics.hpp>
#include "Mario.hpp"
#include "Koopa.hpp"
#include "Globle.hpp"
#include "Map.hpp"
#include "Renderer.hpp"
#include "Goomba.hpp"
#include "JumpStage.hpp"
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
    int pos = rand()%800 +30;
    Koopa koopa;
    Koopa koopa1(pos);
    pos = rand()%800 +30;
    Koopa koopa2(pos);
    std::vector<Koopa> koopas = {koopa,koopa1,koopa2};
    
    Goomba goomba;
    
    JumpStage jumpstage;
    JumpStage jumpstage1(sf::Vector2f{200,150});
    JumpStage jumpstage2(sf::Vector2f{250,200});
    std::vector<JumpStage> allJumpStage={jumpstage,jumpstage1,jumpstage2};
    
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
        
        mario.UpdateMario(map);
        map.drawMap(renderer);
        mario.drawMario(window);
        
        koopa.drawKoopa(window);
        koopa.UpdateKoopa(map);
        koopa.JumpedOnTop(mario);
        koopa.Move(map);
        
        koopa1.drawKoopa(window);
        koopa1.UpdateKoopa(map);
        koopa1.JumpedOnTop(mario);
        koopa1.Move(map);
        
        koopa2.drawKoopa(window);
        koopa2.UpdateKoopa(map);
        koopa2.JumpedOnTop(mario);
        koopa2.Move(map);
        
        goomba.drawGoomba(window);
        goomba.UpdateGoomba(map);
        goomba.JumpedOnTop(mario);
        goomba.Move(map);
        
        jumpstage.drawJumpStage(window);
        jumpstage1.drawJumpStage(window);
        jumpstage2.drawJumpStage(window);
        // end the current frame
        window.display();
    }
    
    return 0;
}
