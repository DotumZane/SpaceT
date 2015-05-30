#include "playerManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "main.h"
#include <textureManager.h>


playerManager::playerManager(const textureManager& images) : thePlayer(3,images.getTexture("player.png"),
            sf::Vector2f(0.0f,static_cast<float>(screenHeight) - 50.0f)) , images(images)
{
    //ctor
}
void playerManager::drawItems(sf::RenderWindow& app)
{

    app.draw(thePlayer.getSprite());
    auto it = playerBullets.begin();
    while( it != playerBullets.end() )
    {
        app.draw(it->getSprite());
        ++it;
    }

}
void playerManager::checkSides(const sf::FloatRect& screenRect)
{
    /*
        it is an iterator that points
        the current instance of the
        playerBullets.
    */
    auto it = playerBullets.begin();
    while( it != playerBullets.end() )
    {
        if(it->calcSide(screenRect))
        {
            //get rid of bullets on the outside of the screen
            playerBullets.erase(it++);
        }
        else
        {
            it->logic();
            ++it;
        }
    }
}
void playerManager::KeyEvents(void)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        pBullet Nbullet(images.getTexture("bullet.png"),
                        thePlayer.getSprite().getPosition());
        playerBullets.push_back(Nbullet);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        thePlayer.move(4.0f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        thePlayer.move(-4.0f);
    }
}

