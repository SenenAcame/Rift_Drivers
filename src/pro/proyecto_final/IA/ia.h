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

    public: 
        //Obsoletas
        /*
        ia(string mapas[], int longi, vehiculo *car);
        void setList(string mapas[], int num);
        int contarPuntos(string mapas[], int num);
        */
        ia(Circuito *mundo, vehiculo *car);

        void setList(Circuito *mundo);
        float **getList();

        void setSize(int tam);
        int getSize();

        void setCont(int con);
        int getCont();

        void setVehi(vehiculo *car);
        vehiculo *getVehi();
        
        int contarPuntos(Circuito *mundo);
        int *posicionesMapa(Circuito *mundo);
        void dibujaRecorrido(sf::RenderWindow *wind);

        void deleteList();

        ~ia();
};