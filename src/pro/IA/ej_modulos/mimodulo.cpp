#include "mimodulo.h"

#include <iostream>

MiModulo::MiModulo() {
    std::cout << "Creando mi modulo..."; 
}

NPC::NPC(float v, float exi, float eyi, float ang){
    setVel(v);
    setX(exi);
    setY(eyi);
    setAngle(ang);
}

void NPC::setVel(float v){
    vel=v;
}

float NPC::getVel(){
    return vel;
}

void NPC::setX(float coorx){
    x=coorx;
}

float NPC::getX(){
    return x;
}

void NPC::setY(float coory){
    x=coory;
}

float NPC::getY(){
    return y;
}

void NPC::setAngle(float angu){
    angle=angu;
}

float NPC::getAngle(){
    return angle;
}