#include "gameTile.h"


GameTile::GameTile(std::string nomtextura,float x,float y,bool pasa,bool sale){
    if(!setUpSprite(nomtextura)){
        return;
    }
    pos=sf::Vector2f(x,y);
    sprite.setPosition(pos);
    pasable=pasa;
    salida=sale;
}

bool GameTile::setUpSprite(std::string nombre){
    sf::Texture textura;
    if(!textura.loadFromFile(nombre)){
        return false;
    }
    textura.setSmooth(true);
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0,0,50,50));
    return true;
}