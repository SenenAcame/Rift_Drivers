#pragma once
#include "SFML/Graphics.hpp"
#include "menu_empezar.h"
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
    public:
        //para cambiar de estado
        static Menu* instance();
        void update(float deltaTime);

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() {return selectedItemIdex; }
        Menu(float width, float height);
        //menu_empezar();
        ~Menu();

    private:
        int selectedItemIdex = 0;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Texture textura;
};