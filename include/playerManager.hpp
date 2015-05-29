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
