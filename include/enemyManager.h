#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <list>
#include <enemy.hpp>
class textureManager;
namespace sf
{
class RenderWindow;
}


class enemyManager
{
public:
    enemyManager(const textureManager& images);
    void draw(sf::RenderWindow& app);
    void addEnemy(const textureManager& images);
protected:
private:
    //enemy NeewEnemy;
   const textureManager& imageManager;
    std::list<enemy> enemiesList;
    //const textureManager& images;
};

#endif // ENEMYMANAGER_H
