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

#include "include/config.h"
#include "ej_modulos/mimodulo.h"
//incluir nuestras carpetas
#include "Mejoras/mejora.h"
#include "IA/ia.h"
#include "Juego/juego.h"
#include "Menu/menu.h"
#include "Poderes/poderes.h"
//#include "Vehiculo/vehiculo.h"
//#include "Circuito/circuito.h"

#define kVel 5

int main() {

  //MiModulo *mod = new MiModulo();

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

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

  string mapas[3] = {"../resources/curva_derecha.xml","../resources/curva_abajo.xml","../resources/zigzag.xml"};
  string mapa[1] = {"../resources/curva_abajo.xml"};

  //inicio un menu
  //Menu menu(window.getSize().x, window.getSize().y);

  vehiculo *coche = new vehiculo(1,2,3,"sprite");
  ia *ene = new ia(mapas,sizeof(mapas)/sizeof(*mapas),coche);

  cout << ene->getSize() << endl;
  cout << ene->getList()[0][0] << " , " << ene->getList()[0][1] << endl;

  ene->setList(mapa,sizeof(mapa)/sizeof(*mapa));

  cout << ene->getSize() << endl;
  cout << ene->getList()[0][0] << " , " << ene->getList()[0][1] << endl;
  
  ene->~ia();
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
    window.display();
  }

  return 0;
}