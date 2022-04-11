#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/tinyxml2.h"
#include "ej_modulos/mimodulo.h"
#include "ai.cpp"

using namespace tinyxml2;

#define kVel 2
#define MARGEN 10

int main() {
  //int margen = 50;
  srand(time(NULL));
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

  ai npc = ai(sprite2,0.03,100,400);
  //ai npc2 = ai(sprite2,0.03,100,400,1);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(540, 360);

  string mapas[3] = {"../resources/curva_derecha.xml","../resources/curva_abajo.xml","../resources/zigzag.xml"};
  int cont=0; 
  
  for(int i=0; i<(int)(sizeof(mapas)/sizeof(*mapas)); i++){
    const char* fichero = mapas[i].c_str();
    XMLDocument doc;
    doc.LoadFile(fichero);
    XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
    for(XMLNode *hijo = grupo->FirstChild(); hijo; hijo = hijo->NextSibling()){
      cont++;
    }
    fichero=NULL;
    grupo=NULL;
  }

  float **list = new float*[cont];
  int global=0;
  int vari = 0;

  sf::Vertex line[cont];
  sf::Vertex line2[cont];
  sf::Vertex line3[cont];

  for(int i=0; i<(int)(sizeof(mapas)/sizeof(*mapas)); i++){
    const char* frag = mapas[i].c_str();
    XMLDocument doc;
    doc.LoadFile(frag);
    XMLElement *group = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
    for(XMLElement *son = group->FirstChildElement("object"); son; son = son->NextSiblingElement("object")){
      
      int v = rand() % 11-5;
      vari += v;
      
      //cout << vari << endl;
      list[global] = new float[2];
      if(i==2){
        list[global][0] = son->FloatAttribute("x")+320+vari;
        list[global][1] = son->FloatAttribute("y")+320+vari;
      }
      else{
        list[global][0] = son->FloatAttribute("x")+320*i+vari;
        list[global][1] = son->FloatAttribute("y")+vari;
      }

      line[global].position = sf::Vector2f(list[global][0],list[global][1]);
      line[global].color = sf::Color::Red;

      line2[global].position = sf::Vector2f(list[global][0]+MARGEN,list[global][1]);
      line2[global].color = sf::Color::Blue;

      line3[global].position = sf::Vector2f(list[global][0]-MARGEN,list[global][1]);
      line3[global].color = sf::Color::Green;

      global++;
    }
    frag=NULL;
    group=NULL;
  }
  /*
  XMLDocument doc;
  doc.LoadFile("../resources/curva_abajo.xml");
  XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
  */
  /*
  int num=0;
  for(XMLNode *child = grupo->FirstChild(); child; child = child->NextSibling()){
    num++;
  }
  */

  //float **list = new float*[num];
  /*
  for(int i=0; i<num;i++){
    list[i] = new float[2];
    XMLNode *nd = grupo->FirstChild();
    list[i][0] = grupo->FirstChildElement("object")->FloatAttribute("x");
    list[i][1] = grupo->FirstChildElement("object")->FloatAttribute("y");
    grupo->DeleteChild(nd);
  }
  */
  int cap = 0;
  //int cap2 = 0;
  //Bucle del juego
  sf::Vertex line4[cont];
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;

    //Movimiento del NPC
    if(cap<cont){
      npc.seguirNodo(list[cap][0], list[cap][1]);
      //npc2.seguirNodo(list[cap2][0], list[cap2][1]);
      if(abs(npc.getX()-list[cap][0])<MARGEN && abs(npc.getY()-list[cap][1])<MARGEN){
        
        line4[cap].position = sf::Vector2f(npc.getX(),npc.getY());
        line4[cap].color = sf::Color::White;
        cap++;
      }
      /*
      if(abs(npc2.getX()-list[cap2][0])<50 && abs(npc2.getY()-list[cap2][1])<50){
        cap2++;
      }
      */
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
    //window.draw(npc2.getSpr());
    window.draw(line,cont,sf::LinesStrip);
    window.draw(line2,cont,sf::LinesStrip);
    window.draw(line3,cont,sf::LinesStrip);
    window.draw(line4,cont,sf::LinesStrip);
    
    window.display();
  }
  
  for(int i=0; i<cont; i++){
    delete [] list[i];
  }
  delete [] list;
  
  return 0;
}