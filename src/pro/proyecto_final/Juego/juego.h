#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Manejador.h"
#include "../Circuito/circuito.h"
//#include "../IA/ia.h"
//#include "../Mejoras/mejora.h"
#include "../Poderes/poderes.h"
//#include "../Vehiculo/vehiculo.h"

#ifndef JUEGO_H
#define JUEGO_H

class juego : public Estado
{
private:
    static juego* pinstance;
protected:
    juego();
    ~juego();
public:
    static juego *instance();
    void update(float deltaTime);
    void render(float porcentaje);

    Circuito * circuito;
    ia * ia;
    mejora * mejora;
    //poderes * poderes; ----falta definirlo---
    //vehiculo * vehiculo; ---falta definirlo---
    //llamadas a las coliciones(?)
    
};

#endif