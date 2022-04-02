#include <SFML/Graphics.hpp>
#include <vector>

#ifndef CIRCUITO_H
#define CIRCUITO_H
class Circuito{
    
    public:
        std::vector<std::vector<std::string> > circuito;
        int fila;
        int col;
        bool final=false;
        Circuito();
        void CrearMapa();
        std::string BuscaCacho(int);
        bool CompruebaCacho(std::string);
        void CompruebaFinal();
        std::vector<std::vector<std::string> > getCircuito();
        void vaciaMapa();

};
#endif