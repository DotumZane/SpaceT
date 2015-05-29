#include "playerManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../appProccess.hpp"
#include <textureManager.h>

//                       args for player are: lives,texture,
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
void playerManager::checkSides(sf::FloatRect& screenRect)
{
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
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void playerManager::eventLogic(void)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        thePlayer.move(4.0f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        thePlayer.move(-4.0f);
    }
}
