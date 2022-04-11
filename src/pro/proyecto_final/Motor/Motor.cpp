#include "Motor.h"

Motor* Motor::pinstance=NULL;

Motor::Motor()
{
    ventana = new sf::RenderWindow(sf::VideoMode(640, 680),"Drift Drivers");
}

Motor::~Motor()
{
    delete ventana;
}

Motor* Motor::instance()
{
    if(pinstance == 0)
    {
        pinstance = new Motor();
    }
    return(pinstance);
}

void Motor::limpieza()
{
    ventana->clear();
}

void Motor::mostrar()
{
    ventana->display();
}

bool Motor::getOpen()
{
    return(ventana->isOpen());
}