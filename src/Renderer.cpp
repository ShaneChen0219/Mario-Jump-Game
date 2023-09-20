//
//  Renderer.cpp
//  SuperMario
//
//  Created by Shane Chen on 9/20/23.
//

#include "Renderer.hpp"
#include <vector>

Renderer::Renderer(sf::RenderTarget& target)
:target(target)
{
    
};


void Renderer::Draw(const sf::Texture& texture, const sf::Vector2f& position,const sf::Vector2f& size)
{
    sprite.setTexture(texture);
    sprite.setOrigin((sf::Vector2f)texture.getSize()/2.0f);
    sprite.setPosition(position);
    /*
     size is not Scale
     the setScale is setting by the ratio of the sprite
     the default is texture is larger than the size -> for getting more clear on the window(detail)
     That's why we need to decrease the size of texture to fit the sprite
     */
    // size.x = to 60, 60 * pixel of size of imae (16x16) converts the texture
    sprite.setScale(sf::Vector2f(size.x/texture.getSize().x,size.y/texture.getSize().y));
    
    
    target.draw(sprite);

}
