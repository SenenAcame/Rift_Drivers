#include <SFML/Graphics.hpp>

#ifndef MAPA_H
#define MAPA_H
class Mapa{
    
    public:
        std::vector<std::vector<std::string> > circuito;
        int fila;
        int col;
        bool final=false;
        std::vector<sf::Sprite> cachos;
        sf::Texture tex12;
        sf::Texture tex13;
        sf::Texture tex14;
        sf::Texture tex23;
        sf::Texture tex24;
        sf::Texture tex34;
        Mapa();
        void CrearMapa();
        std::string BuscaCacho(int);
        bool CompruebaCacho(std::string);
        void CompruebaFinal();
        std::vector<std::vector<std::string> > getCircuito();
        void vaciaMapa();
        void dibujaMapa(sf::RenderWindow *);
        void montaMapa();


};

#endif