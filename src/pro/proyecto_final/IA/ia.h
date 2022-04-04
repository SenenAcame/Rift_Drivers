#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Vehiculo/vehiculo.h"

using namespace std;

class ia{
    private:
        int size;
        float **list;
        vehiculo *vehi;
    /*
        sf::Sprite spr;
        float vel, x, y, rad;
        float angle;
    */

    public: 
        ia(string mapas[], int longi, vehiculo *car);

        void setList(string mapas[], int num);
        float **getList();

        void setSize(int tam);
        int getSize();

        void setVehi(vehiculo *car);
        vehiculo *getVehi();

        ~ia();
    /*
        ai(sf::Sprite &spr, float vel, float x, float y);
        ai(sf::Sprite &spr, float vel, float x, float y, int i);

        void setSpr(sf::Sprite &s);
        void setSpr(sf::Sprite &s, int i);
        sf::Sprite getSpr();

        void setVel(float vel);
        float getVel();

        void setX(float x);
        float getX();

        void setY(float y);
        float getY();

        void setRad(float r);
        float getRad();

        void setAngle(float angle);
        float getAngle();
        
        void perseguir(sf::Sprite &jugador);
        void calcuAngle(sf::Sprite &s);
        void calcuAngle(float x, float y);
        void seguirNodo(float x, float y);
        */
};