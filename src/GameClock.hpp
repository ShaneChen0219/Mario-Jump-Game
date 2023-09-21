//
//  GameClock.hpp
//  SuperMario
//
//  Created by Jakob West on 9/21/23.
//

#ifndef GameClock_hpp
#define GameClock_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Globle.hpp"
#include <iostream>
#include <string>
class Mario;
class Koopa;
class Goomba;
class Score;

class GameClock{
public:
    sf::Text clockText;
    sf::Font clockFont;

    GameClock();
    void reset();
    void drawClock(sf::RenderWindow& window);
    void update();
    
private:
    sf::Clock clock;
    short timeLeft = 60;
};
    
#endif /* GameClock_hpp */
