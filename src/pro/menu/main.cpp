#include <SFML/Graphics.hpp>
#include <iostream>
//incluyo mi menu
#include "Menu.h"
#include "Menu_empezar.h"

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

//#define kVel 5

int main() 
{
  //creo la ventana
  sf::RenderWindow window(sf::VideoMode(640, 680), "VENTANA MENU");
 
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){

}
  Menu menu(window.getSize().x, window.getSize().y);
  //para el menu de la seleccion de tipos de circuito
  //Menu_empezar menu_empezar(window.getSize().x, window.getSize().y);
  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
      window.close();
      break;
      

      case sf::Event::KeyReleased:
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
          menu.MoveUp();
          break;
        
        case sf::Keyboard::Down:
          menu.MoveDown();
          break;

        case sf::Keyboard::Key::Enter:
          switch (menu.GetPressedItem()){
            case 0:
              std::cout <<"Has seleccionado emmpezar" << std::endl;
              //Menu_empezar.draw(window);
              //dibujo el otro menu
                  //window.clear();
              break;
            case 1:
              std::cout <<"Has seleccionado las opciones" << std::endl;
              break;
            case 2:
              std::cout <<"salir" << std::endl;
              window.close();
              break;
          }
        break;
        }
      
      
      
      }
    }
    window.clear();
    menu.draw(window);
    window.display();
  }
  //return 0;
}