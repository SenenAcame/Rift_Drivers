/*
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "include/config.h"
#include "ej_modulos/mimodulo.h"
#include <math.h>
//incluir nuestras carpetas
#include "IA/ia.h"
#include "Mejoras/mejora.h"
#include "Juego/juego.h"
#include "Menu/menu.h"
#include "Poderes/poderes.h"
#include "Juego/Manejador.h"
#include "Motor/Motor.h"

//#define kVel 5
/*
int main() 
{
  //creo la ventana
  //sf::RenderWindow window(sf::VideoMode(640, 680), "VENTANA MENU");
  Motor * motor = Motor::instance();
  Menu * Menu = Menu::Instance();
  Manejador * instancia = Manejador::instancia();
  instancia->cambiarEstado(Menu);
  juego * juego = juego::instance();

  while(motor->getOpen())

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
#include "Juego/juego.h"
#include "Menu/menu.h"
#include "Menu/menu_final.h"
#include "Poderes/poderes.h"
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
   sf::Color color[4];
   int colision=0;
  bool negro=false;
  bool col=false;
  */
  int otroCont=0;
  if((color[0].r==0) && (color[0].g==0) && (color[0].b==0)){
      negro=true;
      col=true;
    }else if((color[0].r==204) && (color[0].g==204) && (color[0].b==204)){
      col=true;
    }else if((color[0].r==170) && (color[0].g==170) && (color[0].b==170)){
      otroCont=1;
    }else if((color[0].r==119) && (color[0].g==119) && (color[0].b==119)){
      otroCont=2;
    }
  if(col==true){
    if(negro==true){
      colision=2;
    }else{
      colision=1;
    }
  } else if(otroCont!=0){
    if(otroCont==1){
      //META
      colision=3;
      //META
    }else if(otroCont==2){
      colision=4;
    }
  }
  return colision;
} 

int main() {

  //MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1080, 720), "Rift Drivers");

  //camara y minimapa
  sf::View camara;
  sf::View minimapa;
  camara=sf::View(sf::FloatRect(0,0,1080,720));
  minimapa.setViewport(sf::FloatRect(0.85f,0,0.15f,0.25f));
  window.setView(camara);
  window.setFramerateLimit(60);

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

   sf::Texture iniF;
  if (!iniF.loadFromFile("../resources/inicio.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  sf::Sprite imgIni(iniF);
  //imgIni.setTexture(iniF, true);
  /*
  std::vector <sf::Sprite> vektor;
  for (int i = 0; i < (int)(1080/32)+1; i++){
        for (int j = 0; j < (int)(720/32)+1; j++){
            imgIni.setPosition(i*32,j*32);
            imgIni.setTextureRect(sf::IntRect(i*32,j*32,32,32));
            vektor.push_back(imgIni);
        }
    }
    */
  imgIni.setTextureRect(sf::IntRect(0,0,1080,720));

  imgIni.setTextureRect(sf::IntRect(0,0,1080,720));

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
  sf::Vector2f position, previous, previous2;

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

 
  menu_final menuFinal(window.getSize().x, window.getSize().y);
  Menu menu(window.getSize().x, window.getSize().y);


  int estado = 0;
  //Bucle del juego
  while (window.isOpen()){
 
    sf::Event e;
   
    switch(estado){
      case 0:
       
        while (window.pollEvent(e)){
          switch(e.type){
            case sf::Event::Closed:
              window.close();
            break;

            case sf::Event::KeyReleased:
              switch (e.key.code){
                /*
                case sf::Keyboard::Z:
                  estado=0;
                break;
                case sf::Keyboard::X:
                  estado=1;
                break;
                case sf::Keyboard::C:
                  estado=2;
                break;
                */
                case sf::Keyboard::Up:
                  menu.MoveUp();
                break;
              
                case sf::Keyboard::Down:
                  menu.MoveDown();
                break;

                case sf::Keyboard::Key::Enter:
                  switch (menu.GetPressedItem()){
                    case 0:
                      std::cout <<"Has seleccionado empezar" << std::endl;
                      estado=1;
                    break;

                    case 1:
                      std::cout <<"Salir" << std::endl;
                      window.close();
                    break;
                  }
                break;

                case sf::Keyboard::Escape:
                  window.close();
                break;
                /*
                default:
                  std::cout << e.key.code << std::endl;
                break;
                */
              }
            break;
          }   
        }

        camara=sf::View(sf::FloatRect(0,0,1080,720));
        window.setView(camara);
        window.clear();
        /*
        for(int i=0; i<vektor.size();i++){
          window.draw(vektor.at(i));
        }
        */
        window.draw(imgIni);
        menu.draw(window);
        
        window.display();

      break;

      case 1:
        while (window.pollEvent(e)){
          switch(e.type){
            case sf::Event::Closed:
              window.close();
            break;

            case sf::Event::KeyReleased:
              switch (e.key.code){
                /*
                case sf::Keyboard::Z:
                  estado=0;
                break;
                case sf::Keyboard::X:
                  estado=1;
                break;
                case sf::Keyboard::C:
                  estado=2;
                break;
                */
                case sf::Keyboard::O:
                   ene->setDibCheck(!ene->getDibCheck());
                break;

                case sf::Keyboard::P:
                   ene->setSegCheck(!ene->getSegCheck());
                   estado=2;
                break;
                
                case sf::Keyboard::L:
                  if(pista){
                    position.x = 25*320+320/2;
                    position.y = 25*320+320/2;
                    sprite.setPosition(position.x,position.y);
                    cir->vaciaMapa();
                    cir=new Circuito();
                    rot=-90.00f;
                    sprite.setRotation(rot);
                  }
                  coche->~vehiculo();
                  coche = new vehiculo(1,2,3,"../resources/cocherot.png",spr2);
                  cir->CrearMapa();
                  cir->montaMapa();
                  pista=true;
                  ene->~ia();
                  ene = new ia(cir,coche);
                  speed=0;
                break;

                case sf::Keyboard::Escape:
                  window.close();
                break;
                /*
                default:
                  std::cout << e.key.code << std::endl;
                break;
                */
              }
            break;
          }   
        }

        accumulator += clock.restart().asSeconds();
        ene->seguirRuta();
        while (accumulator >= timestep){
          accumulator -= timestep;
          previous2 = ene->getVehi()->getImagen().getPosition();
          
          previous = position;
          sprite.setRotation(rot);
          prev = rot;

          int col=(int)ene->getVehi()->getImagen().getPosition().x/320;
          int row=(int)ene->getVehi()->getImagen().getPosition().y/320;

          if(col==cir->getFinaly()&&row==cir->getFinalx()){
            estado=2;
          }
          col=(int)sprite.getPosition().x/320;
          row=(int)sprite.getPosition().y/320;
            //hola
            std::vector<std::vector<std::string>> mapbw = cir->getCircuitobw();
            sf::Texture durmp;
            string trbw=mapbw.at(row).at(col);
            if(trbw=="0"){
              if(speed>40.0f){
                  speed-=65.0f;
                }else if(speed>30.0f){
                  speed-=50.0f;
                }else if(speed>20.0f){
                  speed-=40.0f;
                }else if(speed>15.0f){
                  speed-=29.0f;
                }else if(speed>12.0f){
                  speed-=23.0f;
                }else if(speed>10.0f){
                  speed-=17.0f;
                }else if(speed>8.0f){
                  speed-=14.0f;
                }else if(speed>6.0f){
                  speed-=12.0f;
                }else if(speed>4.0f){
                  speed-=10.5f;
                }else if(speed>2.0f){
                  speed-=6.5f;
                }else if(speed>1){
                  speed-=3.7f;
                }else if(speed>0){
                  speed-=2.0f;
                }
            }
            if(trbw!="0"){
              if (!durmp.loadFromFile(trbw)) {
                std::cerr << "Error cargando la imagen sprites.png";
                exit(0);
              }
              sf::Image dbw=durmp.copyToImage();
              int spx= sprite.getPosition().x;
              int spy= sprite.getPosition().y;

              //esto es para la meta

                if(colisionMapa(dbw, spx%320+1, spy%320+1, tam[0], tam[1], rot)==3){
                  //Esto es cuando pisa EL PORTAL DEL AVERNO 

                  estado=2;
                  break;
                  //NO SE QUE ESTOY HACIENDO MAL, AIUDA
                  /*
                  window.clear();
                  menu.draw(window);
                  break;
                  */
                }

              if(colisionMapa(dbw, spx%320+1, spy%320+1, tam[0], tam[1], rot)==2){
                
                if(speed>40.0f){
                  speed-=65.0f;
                }else if(speed>30.0f){
                  speed-=50.0f;
                }else if(speed>20.0f){
                  speed-=40.0f;
                }else if(speed>15.0f){
                  speed-=29.0f;
                }else if(speed>12.0f){
                  speed-=23.0f;
                }else if(speed>10.0f){
                  speed-=17.0f;
                }else if(speed>8.0f){
                  speed-=14.0f;
                }else if(speed>6.0f){
                  speed-=12.0f;
                }else if(speed>4.0f){
                  speed-=10.5f;
                }else if(speed>2.0f){
                  speed-=6.5f;
                }else if(speed>1){
                  speed-=3.7f;
                }else if(speed>0){
                  speed-=2.0f;
                }
              }
                /*
                speed=0.0f;
                if(speed==0){
                  speed=-3.5f;
                }
                */
              
                else if(colisionMapa(dbw, spx%320+1, spy%320+1, tam[0], tam[1], rot)==1){
                  if(speed>20.0f){
                    speed-=12.0f;
                  }else if(speed>15.0f){
                    speed -= 6.0f;
                  }else if(speed>10.0f){
                    speed -= 4.0f;
                  }
                  
                  if(speed<10.0f){
                    if(speed<9.2f){
                      if(speed>0.0f){
                        speed-= 0.5f;
                      }
                    }else{
                      speed-=1.5f;
                    }
                  }
                  if(speed<0.0f){
                    speed += 0.5f;
                  }
              } 
            }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            int col=(int)sprite.getPosition().x/320;
            int row=(int)sprite.getPosition().y/320;
            //hola
            std::vector<std::vector<std::string>> mapbw = cir->getCircuitobw();
            sf::Texture durmp;
            string trbw=mapbw.at(row).at(col);
            if(trbw!="0"){
              if (!durmp.loadFromFile(trbw)) {
                std::cerr << "Error cargando la imagen sprites.png";
                exit(0);
              }
              sf::Image dbw=durmp.copyToImage();
              int spx= sprite.getPosition().x;
              int spy= sprite.getPosition().y;

                if(colisionMapa(dbw, spx%320+1, spy%320+1, tam[0], tam[1], rot)==4){
                  sprite.rotate(-gir+5.0f);
                  rot = sprite.getRotation();
                }
                else{
                  sprite.rotate(-gir);
                  rot = sprite.getRotation();
                }
            }
            else{
              sprite.rotate(-gir);
              rot = sprite.getRotation();
            }

            

            //Giro de la camara y minimapa
            /*
            camara.rotate(-gir);
            minimapa.rotate(-gir);
            */
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            int col=(int)sprite.getPosition().x/320;
            int row=(int)sprite.getPosition().y/320;
            //hola
            std::vector<std::vector<std::string>> mapbw = cir->getCircuitobw();
            sf::Texture durmp;
            string trbw=mapbw.at(row).at(col);
            if(trbw!="0"){
              if (!durmp.loadFromFile(trbw)) {
                std::cerr << "Error cargando la imagen sprites.png";
                exit(0);
              }
              sf::Image dbw=durmp.copyToImage();
              int spx= sprite.getPosition().x;
              int spy= sprite.getPosition().y;

                if(colisionMapa(dbw, spx%320+1, spy%320+1, tam[0], tam[1], rot)==4){
                  sprite.rotate(+gir-5.0f);
                  rot = sprite.getRotation();
                }
                else{
                  sprite.rotate(+gir);
                  rot = sprite.getRotation();
                }
            }
            else{
              sprite.rotate(+gir);
              rot = sprite.getRotation();
            }
            
            //Giro de la camara y minimapa
            /*
            camara.rotate(+gir);
            minimapa.rotate(+gir);
            */
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
            int col=(int)sprite.getPosition().x/320;
            int row=(int)sprite.getPosition().y/320;
            printf("(%d, %d)", (int)ene->getVehi()->getImagen().getPosition().y/320, (int)ene->getVehi()->getImagen().getPosition().x/320);
            printf("(%d, %d)", cir->getFinalx(), cir->getFinaly());
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
          
        }
        
        window.clear();
        camara=sf::View(sf::FloatRect(0,0,1080+speed*7,720+speed*7));
        camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
        minimapa.setCenter(sprite.getPosition().x,sprite.getPosition().y);

        
        window.setView(camara);
        if(pista){
          //cir->dibujaMapabw(&window);
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

        ene->getVehi()->getImagen().setPosition(previous2 + ((ene->getVehi()->getImagen().getPosition() - previous2) * (accumulator / timestep)));

        sprite.setPosition(previous + ((position - previous) * (accumulator / timestep)));
        
        
        window.draw(sprite);
        window.draw(ene->getVehi()->getImagen());
        window.display();

      break;
      //MENÚ FINALIIIIIIIIIIIIIIIIIIISIMO

      case 2:
        sf::Event e;
        //std::cout <<"HE ENTRADO WEEEEEEEEE ,SOY PROASO" << std::endl;
        //camara.setCenter(25*320+320/2, 25*320+320/2);
        //window.setView(camara);
        while (window.pollEvent(e)){
          switch(e.type){
            case sf::Event::Closed:
              window.close();
            break;
            case sf::Event::KeyReleased:
              switch (e.key.code){
                /*
                case sf::Keyboard::Z:
                  estado=0;
                break;
                case sf::Keyboard::X:
                  estado=1;
                break;
                case sf::Keyboard::C:
                  estado=2;
                break;
                */
                case sf::Keyboard::Up:
                  menuFinal.Mover_arriba();
                break;
              
                case sf::Keyboard::Down:
                  menuFinal.Mover_abajo();
                break;

                case sf::Keyboard::Key::Enter:
                  switch (menuFinal.GetPressed()){
                    case 0:
                      std::cout <<"Has seleccionado: Volver a jugar" << std::endl;
                      if(pista){
                        position.x = 25*320+320/2;
                        position.y = 25*320+320/2;
                        sprite.setPosition(position.x,position.y);
                        cir->vaciaMapa();
                        cir=new Circuito();
                        rot=-90.00f;
                        sprite.setRotation(rot);
                      }
                      coche->~vehiculo();
                      coche = new vehiculo(1,2,3,"../resources/cocherot.png",spr2);
                      cir->CrearMapa();
                      cir->montaMapa();
                      pista=true;
                      ene->~ia();
                      ene = new ia(cir,coche);
                      speed=0;
                      estado=1;
                    break;

                    case 1:
                      std::cout <<"Has seleccionado: Inici" << std::endl;
                      std::cout <<"Has seleccionado: Volver a jugar" << std::endl;
                      if(pista){
                        position.x = 25*320+320/2;
                        position.y = 25*320+320/2;
                        sprite.setPosition(position.x,position.y);
                        cir->vaciaMapa();
                        cir=new Circuito();
                        rot=-90.00f;
                        sprite.setRotation(rot);
                      }
                      coche->~vehiculo();
                      coche = new vehiculo(1,2,3,"../resources/cocherot.png",spr2);
                      cir->CrearMapa();
                      cir->montaMapa();
                      pista=true;
                      ene->~ia();
                      ene = new ia(cir,coche);
                      speed=0;
                      estado=0;
                    break;
                  }
                break;

                case sf::Keyboard::Escape:
                  window.close();
                break;
                /*
                default:
                  std::cout << e.key.code << std::endl;
                break;
                */
              }
            break;
          } 
        }
        
        

        window.clear();
        /*
        window.setView(camara);
        if(pista){
          //cir->dibujaMapabw(&window);
          cir->dibujaMapa(&window);
        }
        window.draw(sprite);
        window.draw(ene->getVehi()->getImagen());
        window.setView(minimapa);
        if(pista){
            cir->dibujaMapa(&window);
        }
        window.draw(sprite);
        window.draw(ene->getVehi()->getImagen());
        */
        camara=sf::View(sf::FloatRect(0,0,1080,720));
        window.setView(camara);
        window.draw(imgIni);
        menuFinal.draw(window);
        window.display();
      break;
    }


/*
    if(estado==0){
      while (window.pollEvent(e)){
        switch(e.type){
          case sf::Event::Closed:
            window.close();
          break;

          case sf::Event::KeyReleased:
            switch (e.key.code){
              case sf::Keyboard::Up:
                menu.MoveUp();
              break;
            
              case sf::Keyboard::Down:
                menu.MoveDown();
              break;

              case sf::Keyboard::Key::Enter:
                switch (menu.GetPressedItem()){
                  case 0:
                    std::cout <<"Has seleccionado empezar" << std::endl;
                    estado=1;
                    //Menu_empezar.draw(window);
                    //dibujo el otro menu
                        //window.clear();
                  break;

                  case 1:
                    std::cout <<"Has seleccionado las opciones" << std::endl;
                  break;

                  case 2:
                    std::cout <<"Salir" << std::endl;
                    window.close();
                  break;
                }
              break;

              case sf::Keyboard::Escape:
                window.close();
              break;

              default:
                std::cout << e.key.code << std::endl;
              break;
            }
          break;
        }   
      }
    }

    if(estado==1){
      while (window.pollEvent(e)){
        switch(e.type){
          case sf::Event::Closed:
            window.close();
          break;

          case sf::Event::KeyReleased:
            switch (e.key.code){
              case sf::Keyboard::O:
                ene->setDibCheck(!ene->getDibCheck());
              break;

              case sf::Keyboard::P:
                ene->setSegCheck(!ene->getSegCheck());
              break;
              
              case sf::Keyboard::L:
                if(pista){
                  position.x = 25*320+320/2;
                  position.y = 25*320+320/2;
                  sprite.setPosition(position.x,position.y);
                  cir->vaciaMapa();
                  cir=new Circuito();
                  rot=-90.00f;
                  sprite.setRotation(rot);
                }
                coche->~vehiculo();
                coche = new vehiculo(1,2,3,"../resources/cocherot.png",spr2);
                cir->CrearMapa();
                cir->montaMapa();
                pista=true;
                ene->~ia();
                ene = new ia(cir,coche);
                speed=0;
              break;

              case sf::Keyboard::Escape:
                window.close();
              break;

              default:
                std::cout << e.key.code << std::endl;
              break;
            }
          break;
        }   
      }
    }
*/
/*
    if(estado==1){
      accumulator += clock.restart().asSeconds();
      ene->seguirRuta();
      while (accumulator >= timestep){
        accumulator -= timestep;
        previous2 = ene->getVehi()->getImagen().getPosition();
        
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
          
          //std::string trozo_bw =cir->getCircuito().at(row).at(col);
          //if(trozo_bw!="0"){
          //if(cir->getNieve()){
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5.7)+ "nievebw.png";
            //}
            //else{
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
            //}
          //sf::Texture durmp;
          //if (!durmp.loadFromFile(trozo_bw)) {
            //std::cerr << "Error cargando la imagen sprites.png";
            //exit(0);
          //}
          //sf::Image dbw=durmp.copyToImage();
          //if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
            //speed=speed/10;
          //}
            //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
          //if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
              //speed=speed/2;
          //}
          //}
          
          //Giro de la camara y minimapa
          
          //camara.rotate(-gir);
          //minimapa.rotate(-gir);
          
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
          sprite.rotate(+gir);
          rot = sprite.getRotation();
          
          int col=(int)sprite.getPosition().x/320;
          int row=(int)sprite.getPosition().y/320;
          //printf("(%d, %d)", row, col);
          //1,2.png -> 1,2bw.png
          
          //std::string trozo_bw =cir->getCircuito().at(row).at(col);
          //if(trozo_bw!="0"){
          //if(cir->getNieve()){
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5)+ "nievebw.png";
            //}
            //else{
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
            //}
          //sf::Texture durmp;
          //if (!durmp.loadFromFile(trozo_bw)) {
            //std::cerr << "Error cargando la imagen sprites.png";
            //exit(0);
          //}
          //sf::Image dbw=durmp.copyToImage();
          //if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
            //speed=speed/10;
          //}
            //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
          //if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
              //speed=speed/2;
          //}
          //}
          
          
          //Giro de la camara y minimapa
          
          //camara.rotate(+gir);
          //minimapa.rotate(+gir);
          
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          int col=(int)sprite.getPosition().x/320;
          int row=(int)sprite.getPosition().y/320;
          //printf("(%d, %d)", row, col);
          //1,2.png -> 1,2bw.png
          
          //std::string trozo_bw =cir->getCircuito().at(row).at(col);
          //if(trozo_bw!="0"){
          //if(cir->getNieve()){
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5)+ "nievebw.png";
            //}
            //else{
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
            //}
          //sf::Texture durmp;
          //if (!durmp.loadFromFile(trozo_bw)) {
            //std::cerr << "Error cargando la imagen sprites.png";
            //exit(0);
          //}
          //sf::Image dbw=durmp.copyToImage();
          //if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
            //speed=speed/10;
          //}
            //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
          //else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
              //speed=speed/2;
          //} else{
            //if(speed<=50.0f){
              //speed += 1.0f;
            //}
          //}
          //}
          
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
            
            //std::string trozo_bw =cir->getCircuito().at(row).at(col);
            //if(trozo_bw!="0"){
            //if(cir->getNieve()){
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-5)+ "nievebw.png";
            //}
            //else{
              //trozo_bw=trozo_bw.substr(0, trozo_bw.length()-6)+ "bw.png";
            //}
            //sf::Texture durmp;
            //if (!durmp.loadFromFile(trozo_bw)) {
              //std::cerr << "Error cargando la imagen sprites.png";
              //exit(0);
            //}
            //sf::Image dbw=durmp.copyToImage();
            //if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==2){
              //speed=speed/10;
            //}
              //else if(colisionMapa(dbw, dr, sprite.getPosition().x, sprite.getPosition().x, sprite.getPosition().y, sprite.getPosition().y)==1){
            //else if(colisionMapa(dbw, sprite.getPosition().x, sprite.getPosition().y, tam[0], tam[1], rot)==1){
                //speed=speed/2;
            //} else{
              //if(speed>0.0f){
                //speed -= 1.0f;
              //}
            //}
            //}
            
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
        ene->getVehi()->getImagen().setPosition((position.x = 25*320+320/2),(position.y = 25*320+320/2));
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
*/
/*
    if(estado==0){
      window.clear();
      menu.draw(window);
      window.display();
    }

    if(estado==1){
      window.clear();
      camara.setCenter(sprite.getPosition().x,sprite.getPosition().y);
      minimapa.setCenter(sprite.getPosition().x,sprite.getPosition().y);

      window.setView(camara);
      if(pista){
        cir->dibujaMapabw(&window);
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

      ene->getVehi()->getImagen().setPosition(previous2 + ((ene->getVehi()->getImagen().getPosition() - previous2) * (accumulator / timestep)));

      sprite.setPosition(previous + ((position - previous) * (accumulator / timestep)));
      if(sprite.getRotation()<345 && sprite.getRotation()>0){
        sprite.setRotation(prev +((rot - prev)* (accumulator / timestep)));
      }
      
      window.draw(sprite);
      window.draw(ene->getVehi()->getImagen());
      window.display();
    }
*/
  }

  return 0;
}
