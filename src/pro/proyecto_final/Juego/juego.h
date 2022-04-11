#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Manejador.h"
#include "../Mejoras/mejora.h"
#include "../IA/ia.h"
#include "../Poderes/poderes.h"


#ifndef JUEGO_H
#define JUEGO_H

class juego : public Estado
{
private:
    static juego* pinstance;
    ia * ia;
    mejora * mejora;

protected:
    juego();
    ~juego();
public:
    static juego *instance();
    void update(float deltaTime);
    void render(float porcentaje);

    //ia * ia;
    //poderes * poderes; ----falta definirlo---
    vehiculo * vehiculo;
    //llamadas a las coliciones(?)
    
};

#endif