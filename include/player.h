#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
// TODO (jadon#1#): moves only long the x axis ...
//create function to do that
/*
    Class: player
        the player class for space invaders

    See Also:
        <playerManager> - manage players
*/
class player
{
public:
    /*
        Constructor: player(int,const sf::Texture&,const sf::Vector2f&)
            construct a player at the specifed spot and lives

        Parameters:
            lives(1) - the number of lives to initilize with
            images(2) - texture manager
            pos(3) - position to place player
    */
    player(int lives,const sf::Texture&,const sf::Vector2f& pos);
    /** Default destructor */
    virtual ~player();
    // Function: getLives()
    // get the lives of player
    inline unsigned int Getlives()
    {
        return lives;
    }
    // Function: hit()
    // destroy one life
   inline void hit()
    {
        lives -= 1;
    }
    // Function: move(float)
    // move the player across along the x axis
    inline void move(float x)
    {
        this->sprite.move(sf::Vector2f(x,0));
    }
    // Function: getSprite()
    // get the sprite
    inline const sf::Sprite& getSprite()
    {
        return this->sprite;
    }
protected:
private:
     sf::Sprite sprite; //!< Member variable "boundingRect"
    unsigned int lives; //!< Member variable "lives"
};

#endif // PLAYER_H
