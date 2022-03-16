#include <iostream>
#include <math.h>

#include "mejora.h"

mejora::mejora(int t, float b, int d){
    setTipo(t);
    setBonus(b);
    setDuracion(d);
    setReloj();
    check=false;
}

void mejora::setTipo(int t){
    tipo = t;
}

int mejora::getTipo(){
    return tipo;
}

void mejora::setDuracion(int d){
    duracion = d;
}

int mejora::getDuracion(){
    return duracion;
}

void mejora::setBonus(float b){
    bonus = b;
}

float mejora::getBonus(){
    return bonus;
}

void mejora::setReloj(){
    reloj.restart();
}

float mejora::getReloj(){
    return reloj.getElapsedTime().asSeconds();
}

void mejora::setCheck(bool v){
    check=v;
}

bool mejora::getCheck(){
    return check;
}