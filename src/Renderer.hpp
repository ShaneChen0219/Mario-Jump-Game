//
//  Renderer.hpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
class Renderer{
public:
    Renderer(sf::RenderTarget& target);
    //Texture is a image store on GPU
    //Member function
    void Draw(const sf::Texture& texture, const sf::Vector2f& position,const sf::Vector2f& size);
private:
    //sprite is declared as an instance of sf::Sprite- it will be used to render textures , because it is intitialized with {} it will use the default constructor  being constructered with no specific parameters and only really being initialized
    sf::Sprite sprite{};
    sf::RenderTarget& target;
};
#endif /* Renderer_hpp */
