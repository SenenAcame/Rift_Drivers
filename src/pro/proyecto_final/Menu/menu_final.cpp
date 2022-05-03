#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu_final.h"

menu_final::menu_final(float width, float heigth){
    if(!font.loadFromFile("../resources/Barbarian NS.ttf"))
    {
       std::cout << "No se ha cargado la fuente" << std::endl;
    } else{
      std::cout << "cargado la fuente" << std::endl;
    }
    
    //defino el menu final con las opciones
    final_opciones[0].setFont(font);
    final_opciones[0].setFillColor(sf::Color::Green);
    final_opciones[0].setString("Reintentar");
    final_opciones[0].setPosition(sf::Vector2f(width/2, heigth/(2+1)*1));

    final_opciones[0].setFont(font);
    final_opciones[0].setFillColor(sf::Color::Green);
    final_opciones[0].setString("Volver al inicio");
    final_opciones[0].setPosition(sf::Vector2f(width/2, heigth/(2+1)*2));

}