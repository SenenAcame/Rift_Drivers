#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 5
/*
bool collision(sf::Image &image1, sf::Image &image2, int x1, int x2, int y1, int y2){
  sf::Color color[2];
  bool collision=false;
  int i, j;
  for(i=0; (i<40)&& (!collision); i++){
    for(j=0; (j<40)&& (!collision); j++){
      color[0]=image1.getPixel(x1+j, y1+i);
      color[1]=image2.getPixel(x2+j, y2+i);
      if((color[0].r==0) && (color[0].g==0) && (color[0].b==0))
      if((color[1].r!=0) || (color[1].g!=255) || (color[1].b!=0))
        collision=true;
    }
  }
  return collision;
}
*/

int main() {

  //MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("/home/alu/node/proyectoabp-grupo-c04/src/pro/fisicas_colisiones/resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  sf::Sprite sprite2(tex);
  float width=75, heigth=75;
  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  sprite2.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  sprite2.setTextureRect(sf::IntRect(4.5 * 75, 0 * 75, 75, 75));

  //prueba de poner hitbox
  //sf::Rect pos1=sprite.getGlobalBounds();
  //sf::Rect pos2=sprite2.getGlobalBounds();

  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(320, 240);
  sprite2.setPosition(100, 200);

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
            sprite2.setTextureRect(sf::IntRect(1 * 75, 2 * 75, 75, 75));
            //Escala por defecto
            sprite.setScale(1, 1);
            sprite2.setScale(1, 1);
            sprite.move(kVel, 0);
            if(sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
              sprite.move(-kVel, 0);
            }
          break;

        case sf::Keyboard::Left:
            sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(1 * 75, 2 * 75, 75, 75));
            //Reflejo vertical
            sprite.setScale(-1, 1);
            sprite2.setScale(-1, 1);
            sprite.move(-kVel, 0);
            if(sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
              sprite.move(kVel, 0);
            }
          break;

        case sf::Keyboard::Up:
            sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(1 * 75, 3 * 75, 75, 75));
            sprite.move(0, -kVel);
            if(sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
                sprite.move(0, kVel);
            }
          break;

        case sf::Keyboard::Down:
            sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(4.5 * 75, 0 * 75, 75, 75));
            sprite.move(0, kVel);
            if(sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
                sprite.move(0, -kVel);
            }
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
    window.draw(sprite2);
    window.display();
  }

  return 0;
}