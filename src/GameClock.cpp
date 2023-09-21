//
//  GameClock.cpp
//  SuperMario
//
//  Created by Jakob West on 9/21/23.
//

#include "GameClock.hpp"
#include "Mario.hpp"
#include "Score.hpp"

GameClock::GameClock()
    :clockFont(), clockText()
    {
      if(clockFont.loadFromFile("../src/image/OpenSans-Bold.ttf"))
      {
        clockText.setFont(clockFont);
        clockText.setCharacterSize(15);
        clockText.setPosition(850,50);
        clockText.setFillColor(sf::Color::Black);
        clockText.setString("Time Left: " + std::to_string(timeLeft));
      }
    }

void GameClock::drawClock(sf::RenderWindow& window){
  window.draw(clockText);
};

void GameClock::update(){
    // Get the time elapsed since the last clock update
        sf::Time elapsedTime = clock.getElapsedTime();

        // Check if one second has passed (1000 milliseconds)
    if (elapsedTime.asMilliseconds() >= 1000) {
        clock.restart(); // Restart the clock
        
        // Decrease the clock by one second
        if (timeLeft > 0) {
            timeLeft--; // Assuming clock is of integer type
        }
        
        // Update the clock text
        clockText.setString("Time Left: " + std::to_string(timeLeft));
    }
};
