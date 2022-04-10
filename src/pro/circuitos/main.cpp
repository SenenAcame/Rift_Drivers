#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
#include "ej_modulos/mapa.cpp"

#define kVel 15

int main() {

  MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  sf::View camara;
  camara=sf::View(sf::FloatRect(0,0,640,480));
  window.setView(camara);
  sf::View minimapa;
  minimapa.setViewport(sf::FloatRect(0.85f,0,0.15f,0.25f));

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("../resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  /*sf::Texture tex12;
  sf::Texture tex13;
  sf::Texture tex14;
  sf::Texture tex23;
  sf::Texture tex24;
  sf::Texture tex34;
  
  if (!tex12.loadFromFile("../resources/1,2.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex13.loadFromFile("../resources/1,3.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex14.loadFromFile("../resources/1,4.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex23.loadFromFile("../resources/2,3.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex24.loadFromFile("../resources/2,4.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex34.loadFromFile("../resources/3,4.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }*/

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);


  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(25*320+320/2, 25*320+320/2);
  camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
  minimapa.setCenter(sprite.getPosition().x,sprite.getPosition().y);

    Mapa mapa=Mapa();
    bool pista=false;
    sprite.setScale(0.5, 0.5);
    //std::vector<sf::Sprite> cachos;

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
            sprite.setPosition(25*320+320/2, 25*320+320/2);
            mapa.vaciaMapa();
            mapa=Mapa();
            //cachos.clear();

          }
          mapa.CrearMapa();
          /*for(int k=0;k<mapa.getCircuito().size();k++){
            for (int l = 0; l < mapa.getCircuito().at(k).size(); l++){
              if(mapa.getCircuito().at(k).at(l)!="0"){
                if(mapa.getCircuito().at(k).at(l)=="../resources/1,2.png"||mapa.getCircuito().at(k).at(l)=="../resources/2,1.png"){
                  sf::Sprite sprite12(tex12);
                  for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sprite12.setPosition(i*32+32*10*l,j*32+32*10*k);
                        sprite12.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                        cachos.push_back(sprite12);
                    }
                  }
                }
                else if(mapa.getCircuito().at(k).at(l)=="../resources/1,3.png"||mapa.getCircuito().at(k).at(l)=="../resources/3,1.png"){
                  sf::Sprite sprite13(tex13);
                  for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sprite13.setPosition(i*32+32*10*l,j*32+32*10*k);
                        sprite13.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                        cachos.push_back(sprite13);
                    }
                  }
                }
                else if(mapa.getCircuito().at(k).at(l)=="../resources/1,4.png"||mapa.getCircuito().at(k).at(l)=="../resources/4,1.png"){
                  sf::Sprite sprite14(tex14);
                  for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sprite14.setPosition(i*32+32*10*l,j*32+32*10*k);
                        sprite14.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                        cachos.push_back(sprite14);
                    }
                  }
                }
                else if(mapa.getCircuito().at(k).at(l)=="../resources/2,3.png"||mapa.getCircuito().at(k).at(l)=="../resources/3,2.png"){
                  sf::Sprite sprite23(tex23);
                  for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sprite23.setPosition(i*32+32*10*l,j*32+32*10*k);
                        sprite23.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                        cachos.push_back(sprite23);
                    }
                  }
                }
                else if(mapa.getCircuito().at(k).at(l)=="../resources/2,4.png"||mapa.getCircuito().at(k).at(l)=="../resources/4,2.png"){
                  sf::Sprite sprite24(tex24);
                  for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sprite24.setPosition(i*32+32*10*l,j*32+32*10*k);
                        sprite24.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                        cachos.push_back(sprite24);
                    }
                  }
                }
                else if(mapa.getCircuito().at(k).at(l)=="../resources/3,4.png"||mapa.getCircuito().at(k).at(l)=="../resources/4,3.png"){
                  sf::Sprite sprite34(tex34);
                  for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sprite34.setPosition(i*32+32*10*l,j*32+32*10*k);
                        sprite34.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                        cachos.push_back(sprite34);
                    }
                  }
                }
              }
            }
          }*/
          mapa.montaMapa();
          pista=true;
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
      }
    }
    window.clear();
    camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
    minimapa.setCenter(sprite.getPosition().x,sprite.getPosition().y);
    window.setView(camara);
    if(pista){
      /*for(int i=0;i<cachos.size();i++){
        window.draw(cachos.at(i));
      }*/
      mapa.dibujaMapa(&window);
    }
    

    window.draw(sprite);
    
    window.setView(minimapa);
    if(pista){
      /*for(int i=0;i<cachos.size();i++){
        window.draw(cachos.at(i));
      }*/
      mapa.dibujaMapa(&window);
    }
    window.draw(sprite);
    window.display();
  }

  return 0;
}