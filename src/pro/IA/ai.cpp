#include <iostream>

#include "ai.h"

ai::ai(float v, float exi, float eyi, float ang){
    setVel(v);
    setX(exi);
    setY(eyi);
    setAngle(ang);
    //setSpr(tex);
}
/*
void ai::setSpr(string load){
    sf::Texture tx;
    if (!tx.loadFromFile(load)) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    spr = sf::Sprite(tx);
    spr.setOrigin(75 / 2, 75 / 2);
    spr.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    spr.setPosition(160, 120);
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