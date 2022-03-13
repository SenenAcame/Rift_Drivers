#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile{
    public:
        GameTile(std::string,float,float,bool,bool);
        bool pasable;
        bool salida;
        sf::Vector2f pos;
        sf::Texture textura;
        sf::Sprite sprite;
        bool setUpSprite(std::string);
};

#endif