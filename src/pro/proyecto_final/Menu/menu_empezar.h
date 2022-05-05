#pragma once
#include "SFML/Graphics.hpp"
#define MAX_EMPEZAR 2
class menu_empezar
{
    public:
        static menu_empezar* instance();
        //menu_empezar(float width, float heigth);
        void update(float deltaTime);
    protected:
        menu_empezar(float width, float heigth);
    private:
        sf::Font font;
        sf::Text empezar_opciones[MAX_EMPEZAR];
        
};