#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "menu_dificultad.h"

menu_dificultad::menu_dificultad(float width, float height)
{
  //cargo la fuente para el texto
  if(!font.loadFromFile("../resources/Barbarian NS.ttf"))
  {
      std::cout << "No se ha cargado la fuente para la dificultad" << std::endl;
  } 
  else
  {
      std::cout << "Cargada la fuente para la dificultad" << std::endl;
  }

  //defino las 3 opciones de la dificultad
  dificultad_opciones[0].setFont(font);
  dificultad_opciones[0].setFillColor(sf::Color::Red);
  dificultad_opciones[0].setString("Facil");
  dificultad_opciones[0].setScale(3, 2);
  dificultad_opciones[0].setOutlineColor(sf::Color::Black);
  dificultad_opciones[0].setOutlineThickness(2);
  dificultad_opciones[0].setPosition(sf::Vector2f(width/2-295, height/(MAX_DIFICULTAD+1)*1-20));
  //
  dificultad_opciones[1].setFont(font);
  dificultad_opciones[1].setFillColor(sf::Color::White);
  dificultad_opciones[1].setString("Medio");
  dificultad_opciones[1].setScale(3, 2);
  dificultad_opciones[1].setOutlineColor(sf::Color::Black);
  dificultad_opciones[1].setOutlineThickness(2);
  dificultad_opciones[1].setPosition(sf::Vector2f(width/2-295, height/(MAX_DIFICULTAD+1)*2-20));
  //
  dificultad_opciones[2].setFont(font);
  dificultad_opciones[2].setFillColor(sf::Color::White);
  dificultad_opciones[2].setString("Dificil");
  dificultad_opciones[2].setScale(3, 2);
  dificultad_opciones[2].setOutlineColor(sf::Color::Black);
  dificultad_opciones[2].setOutlineThickness(2);
  dificultad_opciones[2].setPosition(sf::Vector2f(width/2-295, height/(MAX_DIFICULTAD+1)*3-20));
}

menu_dificultad::~menu_dificultad()
{

}

void menu_dificultad::draw(sf::RenderWindow &window)
{
  for(int i = 0; i < MAX_DIFICULTAD; i++)
  {
    window.draw(dificultad_opciones[i]);
  }
}

void menu_dificultad::MoveUp()
{
  if(selectedItem - 1 >= 0)
  {
    dificultad_opciones[selectedItem].setFillColor(sf::Color::White);
    dificultad_opciones[selectedItem].setScale(3, 2);

    selectedItem--;

    dificultad_opciones[selectedItem].setFillColor(sf::Color::Red);
    dificultad_opciones[selectedItem].setScale(4, 3);
  }
}

void menu_dificultad::MoveDown()
{
  if(selectedItem + 1 < MAX_DIFICULTAD)
  {
    dificultad_opciones[selectedItem].setFillColor(sf::Color::White);
    dificultad_opciones[selectedItem].setScale(3, 2);

    selectedItem++;

    dificultad_opciones[selectedItem].setFillColor(sf::Color::Red);
    dificultad_opciones[selectedItem].setScale(4, 3);

  }
}