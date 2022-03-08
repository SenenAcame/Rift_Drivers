#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 20.0f
#define UPDATE_TICK_TIME 1


int main() {

  MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "Movimiento");

  //Limite de FPS
  window.setFramerateLimit(60);



  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(320, 240);

  sf::Vector2f position, previous;

  position.x = 320;
  position.y = 240;

  float prev = 0;
  float rot = sprite.getRotation();

  const float speed = kVel;

  sf::Clock clock;
  sf::Clock updateClock;



  

  float accumulator = 0;
  const float timestep = 1.0f / 15.0f; 
  while (window.isOpen())
  {

          sf::Event e;
          while (window.pollEvent(e))
                  if (e.type == sf::Event::Closed)
                          window.close();

          accumulator += clock.restart().asSeconds();
          while (accumulator >= timestep)
          {
                  accumulator -= timestep;

                  previous = position;
                sprite.setRotation(rot);
                  prev = rot;

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                          rot = sprite.getRotation()-15.0f;

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                          rot = sprite.getRotation()+15.0f;

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
                          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
                  }

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                      
                  }

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                      window.close();
                  }


          }

          window.clear();
          sprite.setPosition(previous + ((position - previous) * (accumulator / timestep)));
          sprite.setRotation(prev +((rot - prev)* (accumulator / timestep)));
          

          window.draw(sprite);

          window.display();
  }

  return 0;
}

