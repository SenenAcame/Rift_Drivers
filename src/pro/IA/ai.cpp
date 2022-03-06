#include <iostream>

#include "ai.h"

#define kVel2 0.01

ai::ai(sf::Sprite &spri, float v, float exi, float eyi, float ang){
    setVel(v);
    setX(exi);
    setY(eyi);
    setAngle(ang);
    setSpr(spri);
}

void ai::setSpr(sf::Sprite &s){
    spr=s;
    spr.setOrigin(75 / 2, 75 / 2);
    spr.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    spr.setPosition(x, y);
}

sf::Sprite ai::getSpr(){
    return spr;
}

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

void ai::perseguir(sf::Sprite &jug){
    if(spr.getPosition().x<jug.getPosition().x){
        if(spr.getPosition().y<jug.getPosition().y){
            spr.move(vel,vel);
        }
        else{
            spr.move(vel,-vel);
        }
    }
    else{
        if(spr.getPosition().y<jug.getPosition().y){
            spr.move(-vel,vel);
        }
        else{
            spr.move(-vel,-vel);
        }
    }
}
