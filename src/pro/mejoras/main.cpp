#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
#include "vehiculo.cpp"

#define kVel 5

int main() {

  //MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "Prototipo de Mejoras");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("../resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  vehiculo jug = vehiculo(sprite,5,10,0);
  sf::Clock clock;
  sf::Clock clock2;
  bool check = false;
  bool check2 = false;

  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    
    if(check & clock.getElapsedTime().asSeconds()>10){
      jug.setVel(5);
      std::cout << "Velocidad restaurada" << endl;
      check = false;
    }
    if(check2 & clock2.getElapsedTime().asSeconds()>10){
      jug.setGiro(10);
      std::cout << "Giro restaurado" << endl;
      check2 = false;
    }
    
    while (window.pollEvent(event)) {

      switch (event.type) {

        //Si se recibe el evento de cerrar la ventana la cierro
        case sf::Event::Closed:
          window.close();
          break;

        //Se pulsó una tecla, imprimo su codigo
        case sf::Event::KeyPressed:

          //Verifico si se pulsa alguna tecla de movimiento
          switch (event.key.code) {
            
            case sf::Keyboard::Num1:
              check = true;
              clock.restart();
              jug.setVel(10);
              std::cout << "Velocidad aumentada" << endl;
              break;
              
            case sf::Keyboard::Num2:
              check2 = true;
              clock2.restart();
              jug.setGiro(20);
              std::cout << "Giro aumentado" << endl;
              break;

            //Mapeo del cursor
            case sf::Keyboard::Right:
              jug.rotar(1);
              break;

            case sf::Keyboard::Left:
              jug.rotar(-1);
              break;

            case sf::Keyboard::Up:
              jug.mover(-1);
              break;

            case sf::Keyboard::Down:
              jug.mover(1);
              break;

            //Tecla ESC para salir
            case sf::Keyboard::Escape:
              window.close();
              break;

            //Cualquier tecla desconocida se imprime por pantalla su código
            default:
              std::cout << event.key.code << std::endl;
              break;
          }
      }
    }

    window.clear();
    window.draw(jug.getSpr());
    window.display();
  }

  return 0;
}