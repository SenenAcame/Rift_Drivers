#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu_coche.h"


menu_coche::menu_coche(float width, float heigth)
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
    menu[0].setString("Supercoche");
    menu[0].setScale(3.5, 2.75);
    menu[0].setOutlineColor(sf::Color::Black);
    menu[0].setOutlineThickness(2);
    //menu[0].setCharacterSize(100);
    menu[0].setPosition(sf::Vector2f(width/2-255, heigth/(MAX_NUMBER_OF_ITEMS+1)*1+40));
 
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[1].setString("Deportivo");
    menu[1].setScale(3, 2);
    menu[1].setOutlineColor(sf::Color::Black);
    menu[1].setOutlineThickness(2);
    menu[1].setPosition(sf::Vector2f(width/2-165, heigth/(MAX_NUMBER_OF_ITEMS+1)*2+20));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[2].setString("Todoterreno");
    menu[2].setScale(3, 2);
    menu[2].setOutlineColor(sf::Color::Black);
    menu[2].setOutlineThickness(2);
    menu[2].setPosition(sf::Vector2f(1080/2-225, 720/(MAX_NUMBER_OF_ITEMS+1)*3+5));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[3].setString("Kart");
    menu[3].setScale(3, 2);
    menu[3].setOutlineColor(sf::Color::Black);
    menu[3].setOutlineThickness(2);
    menu[3].setPosition(sf::Vector2f(width/2-100, heigth/(MAX_NUMBER_OF_ITEMS+1)*4+10));
    /*
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    //menu[2].setColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setPosition(sf::Vector2f(width/2, heigth/(MAX_NUMBER_OF_ITEMS+1)*3));
    */
}

menu_coche::~menu_coche()
{

}

void menu_coche::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void menu_coche::MoveUp()
{
    if(selectedItemIdex - 1 >= 0)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        if(selectedItemIdex==0){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-175, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+50));
             menu[selectedItemIdex].setScale(2.5, 2);
        }else if(selectedItemIdex==1){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-165, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+10));
             menu[selectedItemIdex].setScale(2.6, 2);
        }else if(selectedItemIdex==2){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-225, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+5));
             menu[selectedItemIdex].setScale(2.5, 2);
        }else if(selectedItemIdex==3){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-100, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(3, 2);
        }

        selectedItemIdex--;

        menu[selectedItemIdex].setFillColor(sf::Color::Red);
        if(selectedItemIdex==0){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-255, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+40));
             menu[selectedItemIdex].setScale(3.5, 2.75);
        }else if(selectedItemIdex==1){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-215, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(3.6, 2.8);
        }else if(selectedItemIdex==2){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-285, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(3.5, 2.75);
        }else if(selectedItemIdex==3){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-120, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(4, 3);
        }
       
    }
}

void menu_coche::MoveDown()
{
    if(selectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIdex].setFillColor(sf::Color::White);
        if(selectedItemIdex==0){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-175, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+50));
             menu[selectedItemIdex].setScale(2.5, 2);
        }else if(selectedItemIdex==1){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-165, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+10));
             menu[selectedItemIdex].setScale(2.6, 2);
        }else if(selectedItemIdex==2){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-225, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+5));
             menu[selectedItemIdex].setScale(2.5, 2);
        }else if(selectedItemIdex==3){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-100, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+10));
             menu[selectedItemIdex].setScale(3, 2);
        }
       
        selectedItemIdex++;

        menu[selectedItemIdex].setFillColor(sf::Color::Red);
        if(selectedItemIdex==0){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-225, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)+40));
             menu[selectedItemIdex].setScale(3.5, 2.75);
        }else if(selectedItemIdex==1){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-215, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(3.6, 2.8);
        }else if(selectedItemIdex==2){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-285, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(3.5, 2.75);
        }else if(selectedItemIdex==3){
            menu[selectedItemIdex].setPosition(sf::Vector2f(1080/2-120, 720/(MAX_NUMBER_OF_ITEMS+1)*(selectedItemIdex+1)));
             menu[selectedItemIdex].setScale(4, 3);
        }
        
    }
}