#include <SFML/Graphics.hpp>
#include <iostream>
//incluyo mi menu
#include "Menu.h"

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

//#define kVel 5

int main() 
{
  //creo la ventana
  sf::RenderWindow window(sf::VideoMode(640, 680), "VENTANA MENU");

  Menu menu(window.getSize().x, window.getSize().y);
  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::KeyReleased:
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
          menu.MoveUp();
          break;
        
        case sf::Keyboard::Down:
          menu.MoveDown();
          break;
        
        case sf::Keyboard::Return:
          switch (menu.GetPressedItem())
          {
          case 0:
            std::cout <<"Has seleccionado emmpezar" << std::endl;
            break;
          case 1:
            std::cout <<"Has seleccionado las opciones" << std::endl;
            break;
          case 2:
            window.close();
            break;
          }
        break;
        }
        break;

      case sf::Event::Closed:
        window.close();
        break;
      }
    }
    window.clear();
    menu.draw(window);
    window.display();
  }
  //return 0;
}