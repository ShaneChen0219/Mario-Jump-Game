//
//  Renderer.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#include "Renderer.hpp"
#include <vector>
// creating a constructor for our class renderer
//Our Renderer constructor takes a reference to the RenderTarget as an argument to create a render object
Renderer::Renderer(sf::RenderTarget& target)
:target(target) //this constructor is used to create a Renderer object, and it sets the 'target' member variable to the provided sf::RenderTarget reference - this line assigns the target argument to the target member variable.
{
    
};


void Renderer::Draw(const sf::Texture& texture, const sf::Vector2f& position,const sf::Vector2f& size)
{
    // Set the texture for the sprite
    sprite.setTexture(texture);
    //Setting the origin for the sprite in the center of it by dividing the size of the texture by 2
    sprite.setOrigin((sf::Vector2f)texture.getSize()/2.0f);
    sprite.setPosition(position);
    /*
     size is not Scale
     the setScale is setting by the ratio of the sprite
     the default is texture is larger than the size -> for getting more clear on the window(detail)
     That's why we need to decrease the size of texture to fit the sprite
     */
    //size.x / texture.getSize().x: This calculates the horizontal scale factor by dividing the desired width (size.x) by the width of the texture (texture.getSize().x).
    sprite.setScale(sf::Vector2f(size.x/texture.getSize().x,size.y/texture.getSize().y));
    // This basically adjusts the sprites size to fit the texture size within the desired size
    
    target.draw(sprite);

}
