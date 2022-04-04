#include <iostream>
#include <math.h>

#include "vehiculo.h"

vehiculo::vehiculo(float vel, float acc, float gir, string spr){
    setVelocidad(vel);
    setAceleracion(acc);
    setGiro(gir);
    setSprite(spr);
    setReloj();
}

void vehiculo::setVelocidad(float vel){
    velocidad = vel;
}

float vehiculo::getVelocidad(){
    return velocidad;
}

void vehiculo::setAceleracion(float acc){
    aceleracion = acc;
}

float vehiculo::getAceleracion(){
    return aceleracion;
}

void vehiculo::setGiro(float gir){
    giro = gir;
}

float vehiculo::getGiro(){
    return giro;
}

void vehiculo::setSprite(string spr){
    spritename = spr;
}

string vehiculo::getSprite(){
    return spritename;
}


void vehiculo::setReloj(){
    reloj.restart();
}

float vehiculo::getReloj(){
    return reloj.getElapsedTime().asSeconds();
}

