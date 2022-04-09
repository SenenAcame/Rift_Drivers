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
protected:
    Motor();
public:
    ~Motor();
    static Motor * instance();
};

#endif