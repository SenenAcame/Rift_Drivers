/*
#include <SFML/Graphics.hpp>
#include <iostream>
//incluyo mi menu
#include "Menu.h"

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
  //creo singletons
  //Transicion* trans = Transicion::instancia();

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
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
//incluir nuestras carpetas
#include "Mejoras/mejora.h"
#include "IA/ia.h"
#include "Juego/juego.h"
#include "Menu/menu.h"
#include "Poderes/poderes.h"
//#include "Vehiculo/vehiculo.h"
#include "Circuito/circuito.h"

#define kVel 5

int main() {

  //MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "P0. Fundamentos de los Videojuegos. DCCIA");

  //camara y minimapa
  sf::View camara;
  sf::View minimapa;
  camara=sf::View(sf::FloatRect(0,0,1080,720));
  minimapa.setViewport(sf::FloatRect(0.85f,0,0.15f,0.25f));
  window.setView(camara);

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
  sprite.setPosition(25*320+320/2, 25*320+320/2);
  camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);

  string mapas[3] = {"../resources/curva_derecha.xml","../resources/curva_abajo.xml","../resources/zigzag.xml"};
  string mapa[1] = {"../resources/curva_abajo.xml"};

  //inicio un menu
  //Menu menu(window.getSize().x, window.getSize().y);

  vehiculo *coche = new vehiculo(1,2,3,"sprite");
  //ia *ene = new ia(mapas,sizeof(mapas)/sizeof(*mapas),coche);
  Circuito *cir = new Circuito();
  cir->CrearMapa();
  cir->montaMapa();
  bool pista=true;
  ia *ene = new ia(cir,coche);
  
  
  /*
  cout << ene->getSize() << endl;
  cout << ene->getList()[0][0] << " , " << ene->getList()[0][1] << endl;

  ene->setList(mapa,sizeof(mapa)/sizeof(*mapa));

  cout << ene->getSize() << endl;
  cout << ene->getList()[0][0] << " , " << ene->getList()[0][1] << endl;
  */

  //ene->~ia();

  //cout << "Enemigo eliminado" << endl;
  /*
  string letra = "3,2";
  char let = letra.at(0);
  int num = let-48;
  cout << num << endl;


  char let2 = letra.at(2);
  int num2 = let2-48;
  cout << num2 << endl;
  */
  
 //Creamos clase circuito
    //Circuito circuito=Circuito();
    //bool pista=false;

  sf::Vector2f position, previous;

  position.x = 25*320+320/2;
  position.y = 25*320+320/2;

  float prev = 0;
  //float rot = sprite.getRotation();
  float rot = -90.00f;
  sprite.setRotation(rot);

   float speed = 0.0f;

  sf::Clock clock;
  sf::Clock updateClock;

  float accumulator = 0;
  const float timestep = 1.0f / 15.0f; 
  //Bucle del juego
  while (window.isOpen()){

    sf::Event e;

    while (window.pollEvent(e))
      if (e.type == sf::Event::Closed)
        window.close();

    accumulator += clock.restart().asSeconds();

    while (accumulator >= timestep){
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
      }
      else{
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

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
        if(pista){
          sprite.setPosition((position.x = 25*320+320/2),(position.y = 25*320+320/2));
          cir->vaciaMapa();
          cir=new Circuito();
          rot=-90.00f;
          sprite.setRotation(rot);
        }
        cir->CrearMapa();
        cir->montaMapa();
        pista=true;
        ene = new ia(cir,coche);
        speed=0;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
      }
    }

    window.clear();
    
    camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
    minimapa.setCenter(sprite.getPosition().x,sprite.getPosition().y);

    window.setView(camara);
    if(pista){
      cir->dibujaMapa(&window);
      ene->dibujaRecorrido(&window);
    }
    window.draw(sprite);

    window.setView(minimapa);
    if(pista){
      cir->dibujaMapa(&window);
      ene->dibujaRecorrido(&window);
    }
    sprite.setPosition(previous + ((position - previous) * (accumulator / timestep)));
    if(sprite.getRotation()<345 && sprite.getRotation()>0){
      sprite.setRotation(prev +((rot - prev)* (accumulator / timestep)));
    }
    window.draw(sprite);

    window.display();
  }

  return 0;
}