#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class vehiculo{
    private:
        float velocidad;
        float aceleracion;
        float giro;
        string spritename;
        sf::Clock reloj;
        
    public:
        vehiculo(float vel, float acc, float gir, string spr);

        void setVelocidad(float vel);
        float getVelocidad();

        void setAceleracion(float acc);
        float getAceleracion();

        void setGiro(float gir);
        float getGiro();

        void setSprite(string sprname);
        string getSprite();

        void setReloj();
        float getReloj();

};