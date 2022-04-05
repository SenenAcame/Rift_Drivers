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
bool colisionMapa(sf::Image &image1, sf::Image &image2, int x1, int x2, int y1, int y2){
  sf::Color color[2];
  bool colision;
  int i, j;
  colision=false;
  color[0]=image1.getPixel(x1, y1);
  color[1]=image2.getPixel(x2, y2);
  if((color[0].r==0) && (color[0].g==0) && (color[0].b==0))
    colision=true;
  return colision;
}
int main() {

  MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "P0. Fundamentos de los Videojuegos. DCCIA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("../resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  sf::Texture mp;
  sf::Texture durmp;
  if (!mp.loadFromFile("../resources/1,2.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!durmp.loadFromFile("../resources/1,2bw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  sf::Image dbw=durmp.copyToImage();
  sf::Image sp=tex.copyToImage();
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
  sprite.setPosition(240, 240);

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
            if(sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds())){
              sprite.move(-kVel, 0);
            }
            if(colisionMapa(dbw, sp, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)){
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
            if(sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds())){
              sprite.move(kVel, 0);
            }
             if(colisionMapa(dbw, sp, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)){
              sprite.move(kVel, 0);
            }
          break;

        case sf::Keyboard::Up:
            sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(1 * 75, 3 * 75, 75, 75));
            sprite.move(0, -kVel);
            if(sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds())){
                sprite.move(0, kVel);
            }
            if(colisionMapa(dbw, sp, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)){
              sprite.move(0, kVel);
            }
          break;

        case sf::Keyboard::Down:
            sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(4.5 * 75, 0 * 75, 75, 75));
            sprite.move(0, kVel);
            if(sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds())){
                sprite.move(0, -kVel);
            }
              if(colisionMapa(dbw, sp, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)){
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

    for(int i=0; i<10; i++){
      for(int j=0;j<10; j++){
        sf::Sprite roadbw (durmp);
        roadbw.setPosition(i*32,j*32);
        roadbw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
        window.draw(roadbw);
      }
    }

    for(int i=0; i<10; i++){
      for(int j=0;j<10; j++){
        sf::Sprite road (mp);
        road.setPosition(i*32,j*32);
        road.setTextureRect(sf::IntRect(i*32,j*32,32,32));
        window.draw(road);
      }
    }
    window.draw(sprite);
    window.draw(sprite2);
    window.display();
  }

  return 0;
}