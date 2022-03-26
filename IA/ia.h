#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class ia
{
    private:
        float **list;
    /*
        sf::Sprite spr;
        float vel, x, y, rad;
        float angle;
    */

    public: 
        ia(string mapas[]);
        float **getList();
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