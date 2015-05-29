#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics/Sprite.hpp>


class enemy
{
public:
    enemy(const sf::Texture& texture, const sf::Vector2f& pos);
    void logic(void);
    inline const sf::Sprite& getSprite()
    {
        return this->sprite;
    }
protected:
private:
    enum class dir
    {
        Left = 0,
        Right = 1
    };
    sf::Sprite sprite;
    const sf::Vector2f initPos;
    dir dirGoing;

};

#endif // ENEMIES_H
