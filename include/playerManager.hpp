#ifndef PLAYERMANGER_H
#define PLAYERMANGER_H
#include <player.h>
#include <bullets/pBullet.hpp>
#include <list>
class textureManager;
namespace sf
{
class RenderWindow;
}
/*
    Class: playerManager
        manages the player and player bullets

    See Also:
        <player> - instance this class manages
        <pbullet> -
*/
class playerManager
{
public:
    playerManager(const textureManager& images);
    void drawItems(sf::RenderWindow& app);
    void checkSides(sf::FloatRect&);
    void eventLogic(void);
    void KeyEvents(void);
protected:
private:
    player thePlayer;
    const textureManager& images;
    std::list<pBullet> playerBullets;
};

#endif // PLAYERMANGER_H
