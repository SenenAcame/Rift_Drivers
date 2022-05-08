/*
#pragma once
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 3

#include "../Juego/Manejador.h"
#include "../Motor/Motor.h"

#ifndef MENU_H
#define MENU_H

class Menu : public Estado
{
    public:
        //para cambiar de estado
        static Menu* Instance();
        void update(float deltaTime); //para el cambio de estado

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() {return selectedItemIdex; }
        ~Menu();
    protected:
        Menu(float width, float height);
        Menu &operator= (const Menu & );
    private:
        static Menu* pinstance;

        int selectedItemIdex = 0;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Texture textura;
};

#endif
*/
#pragma once
#include "SFML/Graphics.hpp"
//#include "menu_empezar.h"
#define MAX_NUMBER_OF_ITEMS 2

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
        //menu_empezar();a
        ~Menu();

    private:
        int selectedItemIdex = 0;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Texture textura;
};