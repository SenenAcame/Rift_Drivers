/*
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
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
#include "mejora.cpp"

#define kVel 20.0f
#define UPDATE_TICK_TIME 1


int main() {

  //MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Movimiento");

  //Limite de FPS
  window.setFramerateLimit(60);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("../resources/sprites.png")) {
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
  float speed = 0.0f;

  sf::Clock clock;
  
  float vel=50.0f;
  float ace=1.0f;
  float gir=15.0f;

  mejora veloc = mejora(1,50,5);
  mejora acele = mejora(2,1,5);
  mejora girar = mejora(3,15,5);

  float accumulator = 0;
  const float timestep = 1.0f / 15.0f;

  while (window.isOpen()){
    sf::Event e;

    if(veloc.getCheck() && veloc.getReloj()>veloc.getDuracion()){
      vel-=veloc.getBonus();
      std::cout << "Velocidad restaurada" << std::endl;
      veloc.setCheck(false);
    }
    
    if(acele.getCheck() && acele.getReloj()>acele.getDuracion()){
      ace-=acele.getBonus();
      std::cout << "Aceleracion restaurada" << std::endl;
      acele.setCheck(false);
    }

    if(girar.getCheck() && girar.getReloj()>girar.getDuracion()){
      gir-=girar.getBonus();
      std::cout << "Giro restaurado" << std::endl;
      girar.setCheck(false);
    }

    while (window.pollEvent(e)){
      if (e.type == sf::Event::Closed){
        window.close();
      }
    }

    accumulator += clock.restart().asSeconds();

    while (accumulator >= timestep){
      accumulator -= timestep;
      previous = position;
      sprite.setRotation(rot);
      prev = rot;

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !veloc.getCheck()){
        veloc.setCheck(true);
        veloc.setReloj();
        vel+=veloc.getBonus();
        std::cout << "Velocidad aumentada" << std::endl;
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !acele.getCheck()){
        acele.setCheck(true);
        acele.setReloj();
        ace+=acele.getBonus();
        std::cout << "Aceleracion aumentada" << std::endl;
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !girar.getCheck()){
        girar.setCheck(true);
        girar.setReloj();
        gir+=girar.getBonus();
        std::cout << "Giro aumentado" << std::endl;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        rot = sprite.getRotation()-gir;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        rot = sprite.getRotation()+gir;
      }
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(speed<=vel){
          speed += ace;
        }
        if(speed>vel){
          speed-=ace;
        }
        position.x += cos(sprite.getRotation()*M_PI/180)*speed;
        position.y += sin(sprite.getRotation()*M_PI/180)*speed;
      }
      else{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)==false){
          if(speed>0.0f){
            speed -= ace;
          }
          
          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
        }       
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(speed>0.0f && speed-5.0f>=0){
          speed -= 5.0f;
        }
        
        position.x += cos(sprite.getRotation()*M_PI/180)*speed;
        position.y += sin(sprite.getRotation()*M_PI/180)*speed;
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

