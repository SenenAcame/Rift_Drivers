/*
#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"
#include "../Juego/juego.h"

Menu* Menu::pinstance = 0;

Menu* Menu::Instance ()
{
    if(pinstance == 0)
    {
        pinstance = new Menu(640, 680);
    }
    return pinstance;
}

Menu::Menu(float width, float heigth)
{   
    
    //cargo la textura para el fondo, con la imagen
    //if(!textura.loadFromFile("../resources/carrera2.jpeg"))
    //{
        //std::cout << "No se ha cargado la textura del fondo" << std::endl;
    //} else{
        //std::cout << "cargado el fondo" << std::endl;
    //}
    
     //cargo la fuente para el texto de las opciones
    if(!font.loadFromFile("../resources/Barbarian NS.ttf"))
    {
       std::cout << "No se ha cargado la fuente" << std::endl;
    } else{
      std::cout << "cargado la fuente" << std::endl;
    }
    //defino texto de las 3 opciones
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("Empezar");
    menu[0].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Opciones");
    menu[1].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*3));

}

void Menu::update(float deltaTime)
{
    if(selectedItemIdex == 0){
        //para empezar a jugar
    }
}

Menu::~Menu()
{
    
}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if(selectedItemIdex - 1 >= 0)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        selectedItemIdex--;
        menu[selectedItemIdex].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if(selectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        selectedItemIdex++;
        menu[selectedItemIdex].setFillColor(sf::Color::Green);
    }
}
*/
#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"
#include "menu_empezar.h"

Menu::Menu(float width, float heigth)
{   
    /*
    //cargo la textura para el fondo, con la imagen
    if(!textura.loadFromFile("../resources/carrera2.jpeg"))
    {
        std::cout << "No se ha cargado la textura del fondo" << std::endl;
    } else{
        std::cout << "cargado el fondo" << std::endl;
    }
    */
     //cargo la fuente para el texto de las opciones
    if(!font.loadFromFile("../resources/Barbarian NS.ttf"))
    {
       std::cout << "No se ha cargado la fuente" << std::endl;
    } else{
      std::cout << "cargado la fuente" << std::endl;
    }
    //defino texto de las 3 opciones
    /*
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    //menu[0].setColor(sf::Color::Red);
    menu[0].setString("Empezar");
    //menu[0].setCharacterSize(100);
    menu[0].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*1));
    //menu[0].setOrigin(sf::Vector2f(width/2, heigth/((MAX_NUMBER_OF_ITEMS+1)*1)));
    */
    menu[0].setFont(font);
    //menu[0].setFillColor(sf::Color::Green);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Empezar");
    menu[0].setScale(5, 4);
    menu[0].setOutlineColor(sf::Color::Black);
    menu[0].setOutlineThickness(2);
    //menu[0].setCharacterSize(100);
    menu[0].setPosition(sf::Vector2f(width/2-285, heigth/(MAX_NUMBER_OF_ITEMS+1)*1-20));
    /*
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    //menu[1].setColor(sf::Color::White);
    menu[1].setString("Opciones");
    menu[1].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*2));
    */
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[1].setString("Salir");
    menu[1].setScale(4, 3);
    menu[1].setOutlineColor(sf::Color::Black);
    menu[1].setOutlineThickness(2);
    menu[1].setPosition(sf::Vector2f(width/2-165, heigth/(MAX_NUMBER_OF_ITEMS+1)*2-20));
    /*
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*3));
    */
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if(selectedItemIdex - 1 >= 0)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);

        menu[selectedItemIdex].setScale(4, 3);
        menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-165, 720/(MAX_NUMBER_OF_ITEMS+1)*2));
        selectedItemIdex--;
        menu[selectedItemIdex].setFillColor(sf::Color::Red);

        menu[selectedItemIdex].setScale(5, 4);
        menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-285, 720/(MAX_NUMBER_OF_ITEMS+1)*1-20));
    }
}

void Menu::MoveDown()
{
    if(selectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        menu[selectedItemIdex].setScale(4, 3);
        menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-225, 720/(MAX_NUMBER_OF_ITEMS+1)*1));
        selectedItemIdex++;
        menu[selectedItemIdex].setFillColor(sf::Color::Red);
        menu[selectedItemIdex].setScale(5, 4);
        menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-185, 720/(MAX_NUMBER_OF_ITEMS+1)*2-20));
    }
}