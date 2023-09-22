//
//  Gameover.hpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#ifndef Gameover_hpp
#define Gameover_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
class GameOver{
    
private:
    sf::Sprite _gameOverSprite;
    sf::Texture _gameOverTexture;
public:
    GameOver();
    sf::Vector2f _gameoverPos{0.f,0.f};
    void drawGameOver(sf::RenderWindow& window);

};
#endif /* Gameover_hpp */
