#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Vehiculo/vehiculo.h"
#include "../Circuito/circuito.h"

using namespace std;

class ia{
    private:
        int size;
        float **list;
        vehiculo *vehi;

    public: 
        ia(string mapas[], int longi, vehiculo *car);
        ia(Circuito *mundo, vehiculo *car);

        void setList(string mapas[], int num);
        void setList(Circuito *mundo);
        float **getList();

        void setSize(int tam);
        int getSize();

        void setVehi(vehiculo *car);
        vehiculo *getVehi();

        int contarPuntos(string mapas[], int num);
        int contarPuntos(Circuito *mundo);

        int *posicionesMapa(Circuito *mundo);

        void deleteList();

        ~ia();
};