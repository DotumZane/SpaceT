#ifndef PLAYERMANGER_H
#define PLAYERMANGER_H
#include <player.h>
#include <bullets/pBullet.hpp>
#include <list>
#include <chrono>
class textureManager;
namespace sf
{
class RenderWindow;
}
/*
    Class: playerManager
        manages the player and player bullets

    note:
        player ship is placed at the bottom of the screen.

    See Also:
        <player> - instance this class manages
        <pbullet> - player bullet
*/
class playerManager
{
public:
    //group: public constructors
    /*
        Constructor: playerManager(const textureManage& images)
            construct playerManager using image DataBase.

        Parameters:
            images(1) -- the image manager to be used
                by the playerManager.

        Warning:
            images must live as long as their is
                playerManager is referring to it.

        See Also:
            <textureManager>
    */
    playerManager(const textureManager& images,sf::FloatRect);
    //group: public methods
    /*
        Function: drawItems(sf::RenderWindow&)
            draw the player and player bullets on window

        Parameters:
            app(1) -- the window to draw the player
                and the playerBullets on.
    */
    void drawItems(sf::RenderWindow& app);
    /*
        Function: checkSides(sf::FloatRect&)
            check if any of the player bullets
            have reached the end of the screen.
    */
    void checkSides();
    /*
        Function: keyEvents
            checks events and the key board.

            this function checks the keyboard to
            see if the keys have been pressed.
    */
    void KeyEvents(void);
protected:
private:
    player thePlayer;
    const textureManager& images;
    std::list<pBullet> playerBullets;
    const sf::FloatRect screenComp;
    std::chrono::time_point<std::chrono::system_clock> lastShotTime;
};

#endif // PLAYERMANGER_H
