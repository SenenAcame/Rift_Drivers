#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 10
bool colision(sf::Sprite &image1, sf::Sprite &image2){
  bool colision=image1.getGlobalBounds().intersects(image2.getGlobalBounds());
  return colision;
}
/*
int colisionMapa(sf::Image &image1, sf::Image &image2, int x1, int x2, int y1, int y2){
  sf::Color color[2];
  int colision=0;
  int i, j;
  bool negro=false;
  bool col=false;
  //for(i=0; i<40; i++){
    //for(j=0; j<40; j++){
      //color[0]=image1.getPixel(x1+i, y1+j);
      //color[1]=image2.getPixel(x2+i, y2+j);
      color[0]=image1.getPixel(x1, y1);
      //color[1]=image2.getPixel(x2, y2);
      printf("color1: [ %d, %d, %d ]",color[0].r, color[0].g, color[0].b);
      //printf("color2: [ %d, %d, %d ]\n",color[1].r, color[1].g, color[1].b);
      if((color[0].r==0) && (color[0].g==0) && (color[0].b==0)){
        //if((color[1].r!=0) && (color[1].g!=255) && (color[1].b!=0))
        col=true;
        negro=true;
      }  
      else if((color[0].r==204) && (color[0].g==204) && (color[0].b==204)){
        //if((color[1].r!=0) && (color[1].g!=255) && (color[1].b!=0))
        col=true;
      }  
    //}
  //}
  if(col){
    if(negro){
      colision=2;
    }else{
      colision=1;
    }
  }
  */
  int colisionMapa(sf::Image &image1, int x1, int y1, int tx, int ty){
  sf::Color color[4];
  int colision=0;
  bool negro=false;
  bool col=false;
  int x=(int)tx/2;
  int y=(int)ty/2;
  color[0]=image1.getPixel(x1-x, y1);
  color[1]=image1.getPixel(x1+x, y1);
  color[3]=image1.getPixel(x1, y1+y);
  color[2]=image1.getPixel(x1, y1);
  printf("color2: [ %d, %d, %d ]\n",color[2].r, color[2].g, color[2].b);
  for(int i=0; i<4 && col==false;i++){
    if((color[i].r==0) && (color[i].g==0) && (color[i].b==0)){
      negro=true;
      col=true;
    }else if((color[i].r==204) && (color[i].g==204) && (color[i].b==204)){
      col=true;
    } 
  } 
  if(col==true){
    if(negro==true){
      colision=2;
    }else{
      colision=1;
    }
  }
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
  sf::Texture verde;
  if (!verde.loadFromFile("../resources/sprites-dureza-verde.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  sf::Image dbw=durmp.copyToImage();
  sf::Image sp=tex.copyToImage();
  sf::Image dr=verde.copyToImage();
  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  sf::Sprite sprite2(tex);
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
  int tam[2];
  tam[0]=75;
  tam[1]=75;
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
            if(colision(sprite, sprite2)){
              sprite.move(-kVel, 0);
            }
            //if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==2){
            if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==2){
              sprite.move(-kVel, 0);
            }
            //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
              else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==1){
              sprite.move(-kVel/1.3, 0);
            }
          break;

        case sf::Keyboard::Left:
            sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(1 * 75, 2 * 75, 75, 75));
            //Reflejo vertical
            sprite.setScale(-1, 1);
            sprite2.setScale(-1, 1);
            sprite.move(-kVel, 0);
            if(colision(sprite, sprite2)){
              sprite.move(kVel, 0);
            }
             //if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==2){
            if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==2){
              sprite.move(kVel, 0);
            }
            //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
              else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==1){
              sprite.move(kVel/1.3, 0);
            }
          break;

        case sf::Keyboard::Up:
            sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(1 * 75, 3 * 75, 75, 75));
            sprite.move(0, -kVel);
            if(colision(sprite, sprite2)){
                sprite.move(0, kVel);
            }
              //if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==2){
            if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==2){
              sprite.move(0, kVel);
             }
              //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
              else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==1){ 
              sprite.move(0, kVel/1.3);
             }
          break;

        case sf::Keyboard::Down:
            sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            sprite2.setTextureRect(sf::IntRect(4.5 * 75, 0 * 75, 75, 75));
            sprite.move(0, kVel);
            if(colision(sprite, sprite2)){
                sprite.move(0, -kVel);
            }
              //if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==2){
            if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==2){
              sprite.move(0, -kVel);
             }
              //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
              else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1])==1){ 
              sprite.move(0, -kVel/1.3);
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
        roadbw.setPosition(i*32+ 20,j*32+20);
        roadbw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
        window.draw(roadbw);
      }
    }
    for(int i=0; i<10; i++){
      for(int j=0;j<10; j++){
        sf::Sprite road (mp);
        road.setPosition(i*32+20,j*32+20);
        road.setTextureRect(sf::IntRect(i*32,j*32,32,32));
        window.draw(road);
      }
    }
    window.draw(sprite);
    /*window.draw(sprite2);*/
    window.display();
  }

  return 0;
}