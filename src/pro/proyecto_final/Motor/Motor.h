#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
private:
    sf::RenderWindow * ventana;
    bool instanced; //si esta instanciada
    static Motor* pinstance;
public:
    Motor();
    ~Motor();
    static Motor * instance();

    void close();
    void limpieza();
    void mostrar();
    bool getOpen();
    sf::RenderWindow* getVentana(){return ventana;}
};

#endif