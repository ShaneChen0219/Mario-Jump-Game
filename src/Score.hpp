//
//  Score.hpp
//  SuperMario
//
//  Created by Shane Chen on 9/21/23.
//

#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Globle.hpp"
#include <iostream>
#include <string>
class Mario;
class Koopa;
class Goomba;
class Score{
public:
  sf::Text scoresText;
  sf::Font scoresFont;
  short scores = 0;
  Score();
  void reset();
  void update(Koopa& koopa, Goomba& goomba, Mario mario);
  void drawScores(sf::RenderWindow& window);
};
#endif /* Score_hpp */
