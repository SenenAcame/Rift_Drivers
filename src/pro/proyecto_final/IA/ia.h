#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Vehiculo/vehiculo.h"

using namespace std;

class ia{
    private:
        int size;
        float **list;
        vehiculo *vehi;

    public: 
        ia(string mapas[], int longi, vehiculo *car);

        void setList(string mapas[], int num);
        float **getList();

        void setSize(int tam);
        int getSize();

        void setVehi(vehiculo *car);
        vehiculo *getVehi();

        int contarPuntos(string mapas[], int num);
        void deleteList();

        ~ia();
};