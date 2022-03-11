#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef MUNDO_H
#define MUNDO_H

class Mundo{
    sf::Vector2i salida;
    sf::Vector2i pos;
    void setUpEstadoInicial();
    void setUpTiles();

    public:
        std::vector< std::vector<GameTile *> > tiles;
        int gridLength;
        Mundo();
};
#endif