#include <SFML/Graphics.hpp>

#ifndef CIRCUITO_H
#define CIRCUITO_H
class Circuito{
    
    private:
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

        std::vector<std::string> mapas;

        
        std::string BuscaCacho(int);
        bool CompruebaCacho(std::string);
        void CompruebaFinal();

    public:
        Circuito();
        void CrearMapa();
        std::vector<std::vector<std::string> > getCircuito();
        void vaciaMapa();
        void dibujaMapa(sf::RenderWindow *);
        void montaMapa();
        std::vector<std::string> getMapas();
};

#endif