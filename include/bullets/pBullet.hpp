#ifndef PBULLET_H
#define PBULLET_H

#include <bullet.h>


class pBullet : public bullet
{
    public:
        pBullet(const sf::Texture& texture, const sf::Vector2f& pos);
        virtual ~pBullet();
        void logic()
        {
            this->move(-3.0f);
        }
        bool calcSide(sf::FloatRect& rect)
        {
            //if not inside global screen
            return !(this->getSprite().getGlobalBounds().intersects(rect));
        }
    protected:
    private:
};

#endif // PBULLET_H
