#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"

Menu::Menu(float width, float heigth)
{
     //sf::Font font;
    if(!font.loadFromFile("/home/angie/Escritorio/fv/proyectoabp-grupo-c04/src/pro/menu/resources/MontserratAlternates-Bold.otf"))
    {
       std::cout << "No se ha cargado la fuente" << std::endl;
    } else{
      std::cout << "cargado" << std::endl;
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    //menu[0].setColor(sf::Color::Red);
    menu[0].setString("Empezar");
    menu[0].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    //menu[1].setColor(sf::Color::White);
    menu[1].setString("Opciones");
    menu[1].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*3));

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if(selectedItemIdex - 1 >= 0)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        selectedItemIdex--;
        menu[selectedItemIdex].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if(selectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        selectedItemIdex++;
        menu[selectedItemIdex].setFillColor(sf::Color::Green);
    }
}