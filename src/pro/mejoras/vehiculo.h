#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class vehiculo
{
    private:
        sf::Sprite spr;
        float vel, giro, acel, posi;

    public: 
        vehiculo(sf::Sprite &spr, float vel, float giro, float acel);

        void setSpr(sf::Sprite &s);
        sf::Sprite getSpr();

        void setVel(float vel);
        float getVel();

        void setGiro(float gir);
        float getGiro();

        void setAcel(float ace);
        float getAcel();

        void mover(float vel);
        void rotar(int sent);
        /*
        void perseguir(sf::Sprite &jugador);
        void calcuAngle(sf::Sprite &s);
        void calcuAngle(float x, float y);
        void seguirNodo(float x, float y);
        */
};