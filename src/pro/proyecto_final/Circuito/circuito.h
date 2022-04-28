#include <SFML/Graphics.hpp>

#ifndef CIRCUITO_H
#define CIRCUITO_H
class Circuito{
    
    private:
        std::vector<std::vector<std::string> > circuito;
        std::vector<std::vector<std::string> > circuitobw;
        int fila;
        int col;
        bool final=false;
        bool nieve=false;
        std::vector<sf::Sprite> cachos;
        std::vector<sf::Sprite> cachosbw;
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
        sf::Texture tex12bw;
        sf::Texture tex13bw;
        sf::Texture tex14bw;
        sf::Texture tex23bw;
        sf::Texture tex24bw;
        sf::Texture tex34bw;
        sf::Texture tex12nievebw;
        sf::Texture tex13nievebw;
        sf::Texture tex14nievebw;
        sf::Texture tex23nievebw;
        sf::Texture tex24nievebw;
        sf::Texture tex34nievebw;

        std::vector<std::string> mapas;

        
        std::string BuscaCacho(int);
        bool CompruebaCacho(std::string);
        void CompruebaFinal();

    public:
        Circuito();
        void CrearMapa();
        std::vector<std::vector<std::string> > getCircuito();
        std::vector<std::vector<std::string> > getCircuitobw();
        void vaciaMapa();
        void dibujaMapa(sf::RenderWindow *);
        //void dibujaMapabw(sf::RenderWindow *);
        void montaMapa();
        std::vector<std::string> getMapas();
        //std::vector<std::string> getMapasbw();
};

#endif