#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
#include "ej_modulos/mapa.cpp"

#define kVel 15

int main() {

  MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(720, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  sf::View camara;
  sf::View minimapa;
  camara=sf::View(sf::FloatRect(0,0,720,480));
  minimapa.setViewport(sf::FloatRect(0.85f,0,0.15f,0.25f));
  minimapa.setSize(2732,1536);
  window.setView(camara);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  sf::Texture texm;
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
  sprite.setPosition(10*320+320/2, 10*320+320/2);
  camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);

    Mapa mapa=Mapa();
    bool pista=false;
    sprite.setScale(0.5, 0.5);

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
          sprite.setScale(0.5, 0.5);
          sprite.move(kVel, 0);
          break;

        case sf::Keyboard::Left:
          sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Reflejo vertical
          sprite.setScale(-0.5, 0.5);
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
        
        case sf::Keyboard::L:
          if(pista){
            sprite.setPosition(10*320+320/2, 10*320+320/2);
            mapa.vaciaMapa();
            mapa=Mapa();
          }
          mapa.CrearMapa();
          pista=true;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
      }
    }
    window.clear();
    camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
    minimapa.setCenter(sprite.getPosition());
    window.setView(camara);
    if(pista){
      for(int k=0;k<mapa.getCircuito().size();k++){
        for (int l = 0; l < mapa.getCircuito().at(k).size(); l++){
          if(mapa.getCircuito().at(k).at(l)!="0"){
            texm.loadFromFile(mapa.getCircuito().at(k).at(l));
            sf::Sprite spritem(texm);
            for (int i = 0; i < 10; i++){
              for (int j = 0; j < 10; j++){
                  spritem.setPosition(i*32+32*10*l,j*32+32*10*k);
                  spritem.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                  window.draw(spritem);
              }
            }
          }
        }
      }
    }
    
    
    window.draw(sprite);
    window.setView(minimapa);
    if(pista){
      for(int k=0;k<mapa.getCircuito().size();k++){
        for (int l = 0; l < mapa.getCircuito().at(k).size(); l++){
          if(mapa.getCircuito().at(k).at(l)!="0"){
            texm.loadFromFile(mapa.getCircuito().at(k).at(l));
            sf::Sprite spritem(texm);
            for (int i = 0; i < 10; i++){
              for (int j = 0; j < 10; j++){
                  spritem.setPosition(i*32+32*10*l,j*32+32*10*k);
                  spritem.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                  window.draw(spritem);
              }
            }
          }
        }
      }
    }
    
    
    window.draw(sprite);
    
    
    
    window.display();
  }

  return 0;
}