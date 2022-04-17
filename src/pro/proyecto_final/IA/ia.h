#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Vehiculo/vehiculo.h"
#include "../Circuito/circuito.h"

using namespace std;

class ia{
    private:
        int cont;
        int size;
        float **list;
        vehiculo *vehi;
        bool dibCheck, segCheck;

    public: 
        ia(Circuito *mundo, vehiculo *car);

        void setList(Circuito *mundo);
        float **getList();

        void setSize(int tam);
        int getSize();

        void setCont(int con);
        int getCont();

        void setVehi(vehiculo *car);
        vehiculo *getVehi();

        void setDibCheck(bool dib);
        bool getDibCheck();

        void setSegCheck(bool seg);
        bool getSegCheck();
        
        int contarPuntos(Circuito *mundo);
        int *posicionesMapa(Circuito *mundo);
        void dibujaRecorrido(sf::RenderWindow *wind);

        void seguirRuta();
        void siguienteNodo();
        float calcularDirc();

        void deleteList();
        ~ia();
};