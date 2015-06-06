#include "space_invaders/player.h"
const static float moveSpeed = 4.0f;
player::player(int lives,const sf::Texture& texture,const sf::Vector2f& pos) : sprite(texture),
    lives(lives)
{
    this->sprite.setPosition(pos);
}

void player::keyMovement(const sf::FloatRect& screenRect)
{

}

