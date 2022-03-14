#include <iostream>
#include <math.h>

#include "vehiculo.h"

#define kVel2 0.01
#define Pi 3.14159265

vehiculo::vehiculo(sf::Sprite &spri, float v, float g, float a){
    setVel(v);
    setGiro(g);
    setAcel(a);
    setSpr(spri);
    posi=90;
}

void vehiculo::setSpr(sf::Sprite &s){
    spr=s;
    spr.setOrigin(75 / 2, 75 / 2);
    spr.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    spr.setPosition(320, 240);
}

sf::Sprite vehiculo::getSpr(){
    return spr;
}

void vehiculo::setVel(float v){
    vel=v;
}

float vehiculo::getVel(){
    return vel;
}

void vehiculo::setGiro(float g){
    giro=g;
}

float vehiculo::getGiro(){
    return giro;
}

void vehiculo::setAcel(float a){
    acel=a;
}

float vehiculo::getAcel(){
    return acel;
}

void vehiculo::mover(float s){
    spr.move(0, vel*s);
}

void vehiculo::rotar(int s){
    spr.rotate(s*giro);
}