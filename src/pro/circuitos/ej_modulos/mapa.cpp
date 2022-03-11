#include "mapa.h"

Mapa::Mapa(){
    sf::Vector2i mapa[10][10];
}

void Mapa::CargarMapa(){
    sf::Texture textura;
    sf::Sprite tile;

    textura.loadFromFile("../resources/curva_derecha.png");
    tile.setTexture(textura);
}