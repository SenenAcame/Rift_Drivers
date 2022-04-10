#include <SFML/Graphics.hpp>

#ifndef MAPA_H
#define MAPA_H
class Mapa{
    
    private:
        std::vector<std::vector<std::string> > circuito;
        int fila;
        int col;
        bool final=false;
        bool nieve=false;
        std::vector<sf::Sprite> cachos;
        sf::Texture tex12;
        sf::Texture tex13;
        sf::Texture tex14;
        sf::Texture tex23;
        sf::Texture tex24;
        sf::Texture tex34;
        sf::Texture tex12nieve;
        sf::Texture tex13nieve;
        sf::Texture tex14nieve;
        sf::Texture tex23nieve;
        sf::Texture tex24nieve;
        sf::Texture tex34nieve;
        std::string BuscaCacho(int);
        bool CompruebaCacho(std::string);
        void CompruebaFinal();

    public:
        Mapa();
        void CrearMapa();
        std::vector<std::vector<std::string> > getCircuito();
        void vaciaMapa();
        void dibujaMapa(sf::RenderWindow *);
        void montaMapa();


};

#endif