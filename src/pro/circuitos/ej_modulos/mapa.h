#include <SFML/Graphics.hpp>
#include <vector>

#ifndef MAPA_H
#define MAPA_H
class Mapa{
    public:
        Mapa();
        std::vector<sf::Sprite> Mapa::CrearMapa();
        std::string BuscaCacho(int);
        std::vector<std::vector<std::string> > circuito;
        bool final=false;
        bool Mapa::CompruebaCacho(std::string);
        void Mapa::CompruebaFinal(std::vector<int>);
        int fila=5;
        int col=5;

};

#endif