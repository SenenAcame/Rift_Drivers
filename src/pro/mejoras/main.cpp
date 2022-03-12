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

  /*
  sprite.setOrigin(75 / 2, 75 / 2);
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  sprite.setPosition(320, 240);
  */

  /*
  sf::Clock clock;
  sf::Time time = clock.getElapsedTime();
  clock.getElapsedTime().asSeconds();
  clock.restart();
  */

  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
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

        //Mapeo del cursor
        case sf::Keyboard::Right:
          jug.rotar(1);
          /*
          jug.getSpr().setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          jug.getSpr().setScale(1, 1);
          jug.getSpr().move(kVel, 0);
          */
          break;

        case sf::Keyboard::Left:
          jug.rotar(-1);
          /*
          jug.getSpr().setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Reflejo vertical
          jug.getSpr().setScale(-1, 1);
          jug.getSpr().move(-kVel, 0);
          */
          break;

        case sf::Keyboard::Up:
          jug.mover(-1);
          /*
          jug.getSpr().setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
          jug.getSpr().move(0, -kVel);
          */
          break;

        case sf::Keyboard::Down:
          jug.mover(1);
          /*
          jug.getSpr().setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
          jug.getSpr().move(0, kVel);
          */
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