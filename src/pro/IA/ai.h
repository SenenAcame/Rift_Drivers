#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class ai
{
    private:
        sf::Sprite spr;
        float vel, x, y, rad;
        float angle;

    public: 
        ai(sf::Sprite &spr, float vel, float x, float y);

        void setSpr(sf::Sprite &s);
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
};