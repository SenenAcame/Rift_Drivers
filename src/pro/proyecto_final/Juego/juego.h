#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Manejador.h"
#include "../Mejoras/mejora.h"
#include "../IA/ia.h"
#include "../Poderes/poderes.h"
#include "../Circuito/circuito.h"
#include "../Vehiculo/vehiculo.h"


#ifndef JUEGO_H
#define JUEGO_H

class juego : public Estado
{
private:
    static juego* pinstance;
    ia * ia;
    mejora * mejora;
    Circuito* circuito;
    vehiculo * vehiculo;
protected:
    juego();
    ~juego();
public:
    static juego * instance();
    void update(float deltaTime);
    void render(float porcentaje);

    //ia * ia;
    //poderes * poderes; ----falta definirlo---
    //llamadas a las coliciones(?)
    
};

#endif