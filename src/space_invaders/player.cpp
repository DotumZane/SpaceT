#include "space_invaders/player.h"

player::player(int lives,const sf::Texture& texture,const sf::Vector2f& pos) : sprite(texture),
    lives(lives)
{
    this->sprite.setPosition(pos);
}

player::~player()
{
    //dtor
}
