#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
// TODO (jadon#1#): moves only long the x axis ...
//create function to do that
/**
 custom player class
*/
class player
{
public:
    /** Default constructor */
    player(int lives,const sf::Texture&,const sf::Vector2f& pos);
    /** Default destructor */
    virtual ~player();
    /** Access lives
     * \return The current value of lives
     */
    inline unsigned int Getlives()
    {
        return lives;
    }
   inline void hit()
    {
        lives -= 1;
    }
    inline void move(float x)
    {
        this->sprite.move(sf::Vector2f(x,0));
    }
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
