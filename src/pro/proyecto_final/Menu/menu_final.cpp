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
    final_opciones[0].setPosition(sf::Vector2f(width/2, heigth/(NUM_OPCIONES+1)*1));

    final_opciones[1].setFont(font);
    final_opciones[1].setFillColor(sf::Color::Green);
    final_opciones[1].setString("Volver al inicio");
    final_opciones[1].setPosition(sf::Vector2f(width/2, heigth/(NUM_OPCIONES+1)*2));

}

void menu_final::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < NUM_OPCIONES; i++)
    {
        window.draw(final_opciones[i]);
    }
}

void menu_final::Mover_arriba()
{
    if(selected - 1 >= 0)
    {
        final_opciones[selected].setFillColor(sf::Color::White);
        selected--;
        final_opciones[selected].setFillColor(sf::Color::Green);
    }
}

void menu_final::Mover_abajo()
{
    if(selected + 1 < NUM_OPCIONES)
    {
        final_opciones[selected].setFillColor(sf::Color::White);
        selected++;
        final_opciones[selected].setFillColor(sf::Color::Green);
    }
}