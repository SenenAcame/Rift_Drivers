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
    final_opciones[0].setFillColor(sf::Color::Red);
    final_opciones[0].setString("Reintentar");
    final_opciones[0].setScale(5, 4);
    //final_opciones[0].setScale(4, 3);
    final_opciones[0].setOutlineColor(sf::Color::Black);
    final_opciones[0].setOutlineThickness(2);
    final_opciones[0].setPosition(sf::Vector2f(width/2-340, (heigth/(NUM_OPCIONES+1)*1)+60));

    final_opciones[1].setFont(font);
    final_opciones[1].setFillColor(sf::Color::White);
    final_opciones[1].setString("Volver al inicio");
    final_opciones[1].setScale(3.5, 3);
    final_opciones[1].setOutlineColor(sf::Color::Black);
    final_opciones[1].setOutlineThickness(2);
    final_opciones[1].setPosition(sf::Vector2f(width/2-350, (heigth/(NUM_OPCIONES+1)*2)+20));

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
        final_opciones[selected].setScale(3.5, 3);
        final_opciones[selected].setPosition(sf::Vector2f(1080/2-350, (720/(NUM_OPCIONES+1)*2)+20));
        selected--;
        final_opciones[selected].setFillColor(sf::Color::Red);
        final_opciones[selected].setScale(5, 4);
        final_opciones[selected].setPosition(sf::Vector2f(1080/2-340, (720/(NUM_OPCIONES+1)*1)+60));
    }
}

void menu_final::Mover_abajo()
{
    if(selected + 1 < NUM_OPCIONES)
    {
        final_opciones[selected].setFillColor(sf::Color::White);
        final_opciones[selected].setScale(4, 3);
        final_opciones[selected].setPosition(sf::Vector2f(1080/2-270, (720/(NUM_OPCIONES+1)*1)+80));
        selected++;
        final_opciones[selected].setFillColor(sf::Color::Red);
        final_opciones[selected].setScale(4.5, 4);
        final_opciones[selected].setPosition(sf::Vector2f(1080/2-450, (720/(NUM_OPCIONES+1)*2)+10));
    }
}