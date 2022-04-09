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

        //Atributo sprite
        //Senen
        sf::Sprite imagen;
        //Fin
        
    public:
        //Modificado constructor para pasarle un sprite por referencia
        //Senen
        vehiculo(float vel, float acc, float gir, string spr, sf::Sprite &img);
        //Fin

        void setVelocidad(float vel);
        float getVelocidad();

        void setAceleracion(float acc);
        float getAceleracion();

        void setGiro(float gir);
        float getGiro();

        void setSprite(string sprname);
        string getSprite();

        //Metodos para establecer y obtener el sprite
        //Senen
        void setImagen(sf::Sprite &tx);
        sf::Sprite getImagen();
        //Fin

        void setReloj();
        float getReloj();
};