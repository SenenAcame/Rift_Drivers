#include <iostream>

#include "ai.h"

ai::ai(/*sf::Sprite sprite, */float v, float exi, float eyi, float ang){
    setVel(v);
    setX(exi);
    setY(eyi);
    setAngle(ang);
}
/*
void ai::setSpr(sf::Sprite s){
    spr=s;
}

sf::Sprite ai::getSpr(){
    return spr;
}
*/
void ai::setVel(float v){
    vel=v;
}

float ai::getVel(){
    return vel;
}

void ai::setX(float coorx){
    x=coorx;
}

float ai::getX(){
    return x;
}

void ai::setY(float coory){
    y=coory;
}

float ai::getY(){
    return y;
}

void ai::setAngle(float angu){
    angle=angu;
}

float ai::getAngle(){
    return angle;
}
/*
void movement(float x, float y){

}
*/