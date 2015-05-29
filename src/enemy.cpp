#include "enemy.hpp"
const float passiveMoving = 1.0f;
const float rangePassiveMov = 100.0f;


enemy::enemy(const sf::Texture& texture, const sf::Vector2f& pos) :
    sprite(texture) , initPos(pos), dirGoing(dir::Right)
{
    this->sprite.setPosition(pos);

}
void enemy::logic(void)
{
    //MOVEMENT CODE
    {
        if(dir::Right == this->dirGoing)
        {
            this->sprite.move(passiveMoving,0.0f);

        }
        else if(dir::Left == this->dirGoing)
        {
            this->sprite.move(-1.0f*passiveMoving,0.0f);
        }
    }
    //change direction
    {
        if(this->sprite.getPosition().x > (this->initPos.x + rangePassiveMov) )
        {
            this->dirGoing = dir::Left;
        }
        else if(this->sprite.getPosition().x < this->initPos.x)
        {
            this->dirGoing = dir::Right;
        }
    }

}
