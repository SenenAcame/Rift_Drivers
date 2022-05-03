#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu_empezar.h"
menu_empezar::menu_empezar(float width, float heigth)
{
    if(!font.loadFromFile("../resources/Barbarian NS.ttf"))
    {
       std::cout << "No se ha cargado la fuente" << std::endl;
    } else{
      std::cout << "cargado la fuente" << std::endl;
    }
    //defino texto de las 2 opciones
    empezar_opciones[0].setFont(font);
    empezar_opciones[0].setFillColor(sf::Color::Green);
    empezar_opciones[0].setString("Circuito");
    empezar_opciones[0].setPosition(sf::Vector2f(width/2, heigth/(MAX_EMPEZAR+1)*1));

    empezar_opciones[1].setFont(font);
    empezar_opciones[1].setFillColor(sf::Color::White);
    empezar_opciones[1].setString("Atrás");
    empezar_opciones[1].setPosition(sf::Vector2f(width/2, heigth/(MAX_EMPEZAR+1)*2));
}