#include "Mundo.h"

Mundo::Mundo(){
    gridLength=8;
    setUpEstadoInicial();
}

void Mundo::setUpEstadoInicial(){
    salida=sf::Vector2i(1,0);
    pos=sf::Vector2i(gridLength-1,gridLength-1);
    setUpTiles();
}

void Mundo::setUpTiles(){
    tiles.clear();
    std::vector<GameTile *> linea1;
    linea1.push_back(new GameTile("../resources/curva_derecha.png",0,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",50,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",100,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",150,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",200,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",250,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",300,0,false,false));
    linea1.push_back(new GameTile("../resources/curva_derecha.png",350,0,false,false));
    tiles.push_back(linea1);

    std::vector<GameTile *> linea2;

    linea2.push_back(new GameTile("../resources/curva_derecha.png",0,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",50,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",100,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",150,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",200,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",250,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",300,50,false,false));
    linea2.push_back(new GameTile("../resources/curva_derecha.png",350,50,false,false));
    tiles.push_back(linea2);
}
