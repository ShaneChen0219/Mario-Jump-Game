#include <SFML/Graphics.hpp>
#include "Mario.hpp"
#include "Koopa.hpp"
#include "Globle.hpp"
#include "Map.hpp"
#include "Renderer.hpp"
#include "Goomba.hpp"
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
    Koopa koopa;
    Goomba goomba;
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
        goomba.drawGoomba(window);
        goomba.UpdateGoomba(map);
        goomba.JumpedOnTop(mario);
        
	// end the current frame
        window.display();
    }

    return 0;
}
