#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 5

int main() {

  MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  sf::View camara;
  camara=sf::View(sf::FloatRect(0,0,640,480));
  window.setView(camara);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  sf::Texture texm;
  if (!tex.loadFromFile("../resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texm.loadFromFile("../resources/1,2.png")) {
    std::cerr << "Error cargando la imagen curva_derecha.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  sf::Sprite spritem(texm);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(320, 240);
  camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);

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
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        spritem.setPosition(i*64,j*64);
        spritem.setTextureRect(sf::IntRect(i*64,j*64,64,64));
        window.draw(spritem);
      }
    }
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        spritem.setPosition(i*64,j*64+640);
        spritem.setTextureRect(sf::IntRect(i*64,j*64,64,64));
        window.draw(spritem);
      }
    }
    

    window.draw(sprite);
    camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
    window.setView(camara);
    window.display();
  }

  return 0;
}