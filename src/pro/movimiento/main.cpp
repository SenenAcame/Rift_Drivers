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
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Movimiento");

  //Limite de FPS
  window.setFramerateLimit(60);



  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/f1rot.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(13, 8);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  sprite.setScale(+4.0f, +4.0f);
  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(320, 240);

  sf::Vector2f position, previous;

  position.x = 320;
  position.y = 240;

  float prev = 0;
  float rot = sprite.getRotation();

   float speed = 0.0f;

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

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
          sprite.rotate(-15.0f);
          rot = sprite.getRotation();
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
          sprite.rotate(+15.0f);
          rot = sprite.getRotation();
          }
          

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          if(speed<=50.0f){
          speed += 1.0f;
          }
          
          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
          }else{
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)==false){

          
          if(speed>0.0f){
          speed -= 1.0f;
          }
          
          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
          }       
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
          if(speed>0.0f && speed-5.0f>=0){
          speed -= 5.0f;
          }
          if(speed>5.0f){
          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
          }
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
          window.close();
          }


        }

        window.clear();
        sprite.setPosition(previous + ((position - previous) * (accumulator / timestep)));
        if( sprite.getRotation()<345 && sprite.getRotation()>0){
        sprite.setRotation(prev +((rot - prev)* (accumulator / timestep)));
        }
        

        window.draw(sprite);

        window.display();
  }

  return 0;
}

