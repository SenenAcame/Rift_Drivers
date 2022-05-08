#pragma once
#include "SFML/Graphics.hpp"
//#include "menu_empezar.h"
#define MAX_NUMBER_OF_ITEMS 4

class menu_coche
{
    public:
        //para cambiar de estado
        static menu_coche* instance();
        void update(float deltaTime);

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() {return selectedItemIdex; }
        menu_coche(float width, float height);
        //menu_empezar();a
        ~menu_coche();

    private:
        int selectedItemIdex = 0;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Texture textura;
};