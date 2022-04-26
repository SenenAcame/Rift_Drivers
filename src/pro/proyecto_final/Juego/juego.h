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
<<<<<<< HEAD
    ia * ia;
    mejora * mejora;
    Circuito* circuito;
    vehiculo * vehiculo;
=======
    //ia * ia;
    //mejora * mejora;

>>>>>>> 477511f8364bf31951018d444e6c10aa032004cc
protected:
    juego();
    ~juego();
public:
    static juego * instance();
    void update(float deltaTime);
    void render(float porcentaje);

    //ia * ia;
    //poderes * poderes; ----falta definirlo---
<<<<<<< HEAD
=======
    //vehiculo * vehiculo;
>>>>>>> 477511f8364bf31951018d444e6c10aa032004cc
    //llamadas a las coliciones(?)
    
};

#endif