#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <list>
#include <space_invaders/enemy.hpp>
class textureManager;
namespace sf
{
class RenderWindow;
}

/*
    Class: enemyManager
        manages instances of the enemy class

        relives the main file from dealing with
        the containers of enemies.

    See Also:
        <enemy>
*/
class enemyManager
{
public:
    /*
        Constructor: enemyManager(const textureManager&,const sf::FloatRect&)
            initilize manager with texture system.

        Parameters:
            images(1) - the textureManager
    */
    enemyManager(const textureManager& images,const sf::FloatRect&);
    /*
        Function: update(sf::RenderWindow&)
            draw and update all instances of enemies

        Parameters:
            app(1) - rendering window
    */
    void update(sf::RenderWindow& app);
    /*
        Function: addEnemy(const textureManager&)
            adds enemies

            currently adds enemies as needed.
    */
    void addEnemy(const textureManager& images);
protected:
private:
    //enemy NeewEnemy;
   const textureManager& imageManager;
    std::list<enemy> enemiesList;
   const sf::FloatRect screenComp;
};

#endif // ENEMYMANAGER_H
