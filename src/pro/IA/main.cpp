#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/tinyxml2.h"
#include "ej_modulos/mimodulo.h"
#include "ai.cpp"

using namespace tinyxml2;

#define kVel 10

int main() {

  //MiModulo *mod = new MiModulo();
  
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "Prototipo de IA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("../resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  sf::Sprite sprite2(tex);

  ai npc = ai(sprite2,0.02,125,90);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(540, 360);

  
  XMLDocument doc;
  doc.LoadFile("../resources/mapa_prueba2.xml");
  XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");

  int num=0;
  for(XMLNode *child = grupo->FirstChild(); child; child = child->NextSibling()){
    num++;
  }

  float **list = new float*[num];
  for(int i=0; i<num;i++){
    list[i] = new float[2];
    XMLNode *nd = grupo->FirstChild();
    list[i][0] = grupo->FirstChildElement("object")->FloatAttribute("x");
    list[i][1] = grupo->FirstChildElement("object")->FloatAttribute("y");
    grupo->DeleteChild(nd);
  }

  int cap = 0;
  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;

    //Movimiento del NPC
    if(cap<num){
      npc.seguirNodo(list[cap][0], list[cap][1]);
      if(abs(npc.getX()-list[cap][0])<1 && abs(npc.getY()-list[cap][1])<1){
        cap++;
      }
    }
    
    //npc.perseguir(sprite);

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
    window.draw(npc.getSpr());
    window.display();
  }

  return 0;
}