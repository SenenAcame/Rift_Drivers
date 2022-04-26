/*
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "include/config.h"
#include "ej_modulos/mimodulo.h"
//incluir nuestras carpetas
#include "IA/ia.h"
#include "Mejoras/mejora.h"
#include "Juego/juego.h"
#include "Menu/menu.h"
#include "Poderes/poderes.h"
#include "Juego/Manejador.h"
#include "Motor/Motor.h"

//#define kVel 5

int main() 
{
  //creo la ventana
  //sf::RenderWindow window(sf::VideoMode(640, 680), "VENTANA MENU");
  Motor * motor = Motor::instance();
  Menu * Menu = Menu::Instance();
  Manejador * instancia = Manejador::instancia();
  instancia->cambiarEstado(Menu);
  juego* juego = juego::instance();

  while(motor->getOpen())
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){

}
*/
  //Menu menu(window.getSize().x, window.getSize().y);
  //creo singletons
  /*
  Menu *menu1 = Menu::Instance();
  Menu *menu2 = menu1->Instance();
  Menu &ref = * Menu::Instance();
  */
/*
  while(window.isOpen())
  {
    sf::RenderWindow* window = motor->getVentana();
    sf::Event event;

    while(window->pollEvent(event))
    {
*/
      /*
      switch (event.type)
      {
          case sf::Event::EventType::Closed :
            window->close();
          break;

        case sf::Keyboard::Key::Enter:
          switch (menu.GetPressedItem()){
            case 0:
              std::cout <<"Has seleccionado emmpezar" << std::endl;
              //Menu_empezar.draw(window);
              //dibujo el otro Menu
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
        */
      
/*
      }
    }
    window->display();
  }
  
  
    //window.clear();
   // menu.draw(window);
    //window.display();
  }
  //return 0;
*/


#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
//incluir nuestras carpetas
//#include "Mejoras/mejora.h"
//#include "IA/ia.h"
#include "Juego/juego.h"
#include "Menu/menu.h"
#include "Poderes/poderes.h"
//#include "Vehiculo/vehiculo.h"
#include "Circuito/circuito.h"


//#define kVel 5
bool colisionCoche(sf::Sprite &image1, sf::Sprite &image2){
  bool colision=image1.getGlobalBounds().intersects(image2.getGlobalBounds());
  return colision;
}

int colisionMapa(sf::Image &image1, int x1, int y1, int tx, int ty, float rot){
  sf::Color color[4];
  int colision=0;
  bool negro=false;
  bool col=false;
  int x=(int)tx/2;
  int y=(int)ty/2;
  color[0]=image1.getPixel(x1, y1);
  /*
  sf::Transform matr1(cos(rot), -sin(rot), 0, sin(rot), cos(rot), 0, 0, 0, 1);
  
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
  */
  if((color[0].r==0) && (color[0].g==0) && (color[0].b==0)){
      negro=true;
      col=true;
    }else if((color[0].r==204) && (color[0].g==204) && (color[0].b==204)){
      col=true;
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
  if (!tex.loadFromFile("../resources/cocherot.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  sf::Texture tex2;
  if (!tex2.loadFromFile("../resources/f1rot.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  sf::Sprite spr2(tex);
  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex2);
  //Le pongo el centroide donde corresponde
  sprite.setOrigin(11, 8);
  spr2.setOrigin(11.5f, 8);
  sprite.setScale(3.5f, 3.5f);
  spr2.setScale(3.5f, 3.5f);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 , 0, 22, 16));
  spr2.setTextureRect(sf::IntRect(0 , 0, 23, 16));
  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(25*320+320/2, 25*320+320/2);
  sprite.scale(0.75,0.75);
  camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);

  //inicio un menu
  //Menu menu(window.getSize().x, window.getSize().y);

  vehiculo *coche = new vehiculo(1,2,3,"../resources/cocherot.png",spr2);
  Circuito *cir = new Circuito();
  cir->CrearMapa();
  cir->montaMapa();
  bool pista=true;
  
  ia *ene = new ia(cir,coche);
  
 //Creamos clase circuito
    //Circuito circuito=Circuito();
    //bool pista=false;

  //inicio un menu
  //menu menu(window.getSize().x, window.getSize().y);
  sf::Vector2f position, previous;

  position.x = 25*320+320/2;
  position.y = 25*320+320/2;

  float prev = 0;
  //float rot = sprite.getRotation();
  float rot = -90.00f;
  sprite.setRotation(rot);
  float speed = 0.0f;

  int tam[2];
  tam[0]=22*3.5f;
  tam[1]=16*3.5f;

  float gir = 10.0f;

  sf::Clock clock;
  sf::Clock updateClock;

  float accumulator = 0;
  const float timestep = 1.0f / 15.0f; 
  //Bucle del juego
  while (window.isOpen()){
    sf::Event e;

    ene->seguirRuta();

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
        sprite.rotate(-gir);
        rot = sprite.getRotation();

        int col=(int)sprite.getPosition().x/320;
        int row=(int)sprite.getPosition().y/320;
        //printf("(%d, %d)", row, col);
        //1,2.png -> 1,2bw.png
        /*
        std::string trozo_bw =cir->getCircuito().at(row).at(col);
        if(trozo_bw!="0"){
        if(cir->getNieve()){
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5.7)+ "nievebw.png";
          }
          else{
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
          }
        sf::Texture durmp;
        if (!durmp.loadFromFile(trozo_bw)) {
          std::cerr << "Error cargando la imagen sprites.png";
          exit(0);
        }
        sf::Image dbw=durmp.copyToImage();
        if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
          speed=speed/10;
        }
          //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
        if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
            speed=speed/2;
        }
        }
        */
        //Giro de la camara y minimapa
        /*
        camara.rotate(-gir);
        minimapa.rotate(-gir);
        */
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        sprite.rotate(+gir);
        rot = sprite.getRotation();
        
        int col=(int)sprite.getPosition().x/320;
        int row=(int)sprite.getPosition().y/320;
        //printf("(%d, %d)", row, col);
        //1,2.png -> 1,2bw.png
        /*
        std::string trozo_bw =cir->getCircuito().at(row).at(col);
        if(trozo_bw!="0"){
        if(cir->getNieve()){
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5)+ "nievebw.png";
          }
          else{
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
          }
        sf::Texture durmp;
        if (!durmp.loadFromFile(trozo_bw)) {
          std::cerr << "Error cargando la imagen sprites.png";
          exit(0);
        }
        sf::Image dbw=durmp.copyToImage();
        if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
          speed=speed/10;
        }
          //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
        if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
            speed=speed/2;
        }
        }
        */
        
        //Giro de la camara y minimapa
        /*
        camara.rotate(+gir);
        minimapa.rotate(+gir);
        */
      }
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        int col=(int)sprite.getPosition().x/320;
        int row=(int)sprite.getPosition().y/320;
        //printf("(%d, %d)", row, col);
        //1,2.png -> 1,2bw.png
        /*
        std::string trozo_bw =cir->getCircuito().at(row).at(col);
        if(trozo_bw!="0"){
        if(cir->getNieve()){
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5)+ "nievebw.png";
          }
          else{
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
          }
        sf::Texture durmp;
        if (!durmp.loadFromFile(trozo_bw)) {
          std::cerr << "Error cargando la imagen sprites.png";
          exit(0);
        }
        sf::Image dbw=durmp.copyToImage();
        if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
          speed=speed/10;
        }
          //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
        else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
            speed=speed/2;
        } else{
          if(speed<=50.0f){
            speed += 1.0f;
          }
        }
        }
        */
        if(speed<=50.0f){
          speed += 1.0f;
        }
        position.x += cos(sprite.getRotation()*M_PI/180)*speed;
        position.y += sin(sprite.getRotation()*M_PI/180)*speed;
      }
      else{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)==false){
          int col=(int)sprite.getPosition().x/320;
          int row=(int)sprite.getPosition().y/320;
          //printf("(%d, %d)", row, col);
          //1,2.png -> 1,2bw.png
          /*
          std::string trozo_bw =cir->getCircuito().at(row).at(col);
          if(trozo_bw!="0"){
          if(cir->getNieve()){
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5)+ "nievebw.png";
          }
          else{
            trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
          }
          sf::Texture durmp;
          if (!durmp.loadFromFile(trozo_bw)) {
            std::cerr << "Error cargando la imagen sprites.png";
            exit(0);
          }
          sf::Image dbw=durmp.copyToImage();
          if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
            speed=speed/10;
          }
            //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
          else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
              speed=speed/2;
          } else{
            if(speed>0.0f){
              speed -= 1.0f;
            }
          }
          }
          */
         if(speed>0.0f){
              speed -= 1.0f;
            }
          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
        }       
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
        int col=(int)sprite.getPosition().x/320;
        int row=(int)sprite.getPosition().y/320;
        printf("(%d, %d)", row, col);
        if(speed>0.0f){
          speed -= 5.0f;
        }
        if(speed<1.0f){
          speed = 0.0f;
        }
        if(speed>5.0f){
          position.x += cos(sprite.getRotation()*M_PI/180)*speed;
          position.y += sin(sprite.getRotation()*M_PI/180)*speed;
        }
        if(speed==0.0f){
          position.x -= cos(sprite.getRotation()*M_PI/180)*5.0f;
          position.y -= sin(sprite.getRotation()*M_PI/180)*5.0f;
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
        ene->~ia();
        ene = new ia(cir,coche);
        speed=0;
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
        ene->setDibCheck(!ene->getDibCheck());
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        ene->setSegCheck(!ene->getSegCheck());
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
    window.draw(ene->getVehi()->getImagen());

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
    window.draw(ene->getVehi()->getImagen());

    window.display();
  }

  return 0;
}
