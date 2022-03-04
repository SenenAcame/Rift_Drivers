#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
#include "ai.cpp"

#define kVel 5
#define kVel2 0.01

int main() {

  MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "Prototipo de IA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  //sf::Sprite sprite2(tex);
  ai *npc = new ai("resources/sprites.png",1,0,0,0);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(320, 240);


  //Creo un segundo sprite para probar el movimiento de la IA
  //Le pongo el centroide donde corresponde
  //sprite2.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  //sprite2.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
  // Lo dispongo en la esquina de la pantalla
  //sprite2.setPosition(160, 120);


  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    //Movimiento del NPC
    /*
    sprite2.move(0, kVel2);
    sprite2.move(kVel2, 0);
    */
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
          sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          sprite.setScale(1, 1);
          sprite.move(kVel, 0);
          break;

        case sf::Keyboard::Left:
          sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Reflejo vertical
          sprite.setScale(-1, 1);
          sprite.move(-kVel, 0);
          break;

        case sf::Keyboard::Up:
          sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
          sprite.move(0, -kVel);
          break;

        case sf::Keyboard::Down:
          sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
          sprite.move(0, kVel);
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
    window.draw(sprite);
    //window.draw(sprite2);
    window.draw(npc->getSpr());
    window.display();
  }

  return 0;
}