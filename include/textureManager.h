#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>
/**
    this class wraps up the map container.
    it designed to reduce the complexity of
    the map api and simplify the purpose of the map.

*/
class textureManager
{
public:
    /**
        get texture by id.
        the id is usally the name of the file.
    */
    inline const sf::Texture& getTexture(std::string key) const
    {
        return gameTextures.find(key)->second;
    }
    /**
        the overloaded version of the
        getTexture. allows programmer to not have to write extra
        characters later.
    */
   inline const sf::Texture& getTexture(const char * key) const
    {
        /// note when dont try to reuse above function.
        /// cause recurstivity
        std::string strKey(key);
        return  gameTextures.find(key)->second;
    }
    /**
        Function:addTexture(std::string,sf::Texture)
            adds textures using an id to refer later.

    */
    inline void addTexture(std::string& key,sf::Texture& texture)
    {
        gameTextures.insert(std::pair<std::string,sf::Texture>(key,texture));
    }

    inline void addTexture(const char* key,sf::Texture& texture)
    {
        std::string strKey(key);
        this->addTexture(strKey,texture);
    }
   inline bool addAllCommonTextures(void)
    {
        sf::Texture playerTexture;
        if (!playerTexture.loadFromFile("player.png"))
            return false;
        this->addTexture("player.png",playerTexture);
        //player bullets
        sf::Texture pBulletTexture;
        if(!pBulletTexture.loadFromFile("bullet.png"))
            return false;
        this->addTexture("bullet.png",pBulletTexture);

         sf::Texture enemiesTexture;
        if(!enemiesTexture.loadFromFile("enemy.png"))
            return false;
        this->addTexture("enemy.png",enemiesTexture);
        return true;

    }
protected:
private:
    std::map<std::string,sf::Texture> gameTextures;
};

#endif // TEXTUREMANAGER_H
