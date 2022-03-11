#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu_empezar.h"

Menu_empezar::Menu_empezar(float width, float heigth)
{
    if(!font.loadFromFile("../resources/Barbarian NS.ttf"))
    {
       std::cout << "No se ha cargado la fuente" << std::endl;
    } else{
      std::cout << "cargado" << std::endl;
    }
    circuitos[0].setFont(font);
    circuitos[0].setFillColor(sf::Color::Green);
    circuitos[0].setString("Práctica");
    circuitos[0].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_CIRCUITS+1)*1));

    circuitos[1].setFont(font);
    circuitos[1].setFillColor(sf::Color::White);
    circuitos[1].setString("Desafío");
    circuitos[1].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_CIRCUITS+1)*2));

    circuitos[2].setFont(font);
    circuitos[2].setFillColor(sf::Color::White);
    circuitos[2].setString("Procedural");
    circuitos[2].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_CIRCUITS+1)*3));
}

Menu_empezar::~Menu_empezar()
{

}

void Menu_empezar::draw(sf::RenderWindow &window)
{
        for(int i = 0; i < MAX_NUMBER_CIRCUITS; i++)
    {
        window.draw(circuitos[i]);
    }

}
