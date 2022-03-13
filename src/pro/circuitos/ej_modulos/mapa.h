#include <SFML/Graphics.hpp>
#include <vector>

#ifndef MAPA_H
#define MAPA_H
class Mapa{
    
    public:
        std::vector<std::vector<std::string> > circuito;
        int fila;
        int col;
        bool final=false;
        Mapa();
        void CrearMapa();
        std::string BuscaCacho(int);
        bool CompruebaCacho(std::string);
        void CompruebaFinal();
        std::vector<std::vector<std::string> > getCircuito();
        

};

#endif