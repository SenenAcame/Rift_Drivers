#include <iostream>
#include <math.h>

#include "ai.h"

#define kVel2 0.01
#define Pi 3.14159265

ai::ai(sf::Sprite &spri, float v, float exi, float eyi /*float ang*/){
    setVel(v);
    setX(exi);
    setY(eyi);
    angle=0;
    //setAngle(ang);
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
    calcuAngle(jug);
    spr.move(vel*cos(angle),vel*sin(angle));
    /*
    if(spr.getPosition().x<jug.getPosition().x){
        if(spr.getPosition().y<jug.getPosition().y){
            spr.move(vel*cos(angle),vel*sin(angle));
        }
        else{
            spr.move(vel*cos(angle),vel*sin(angle));
        }
    }
    else{
        if(spr.getPosition().y<jug.getPosition().y){
            spr.move(vel*cos(angle),vel*sin(angle));
        }
        else{
            spr.move(vel*cos(angle),vel*sin(angle));
        }
    }
    */
    setX(spr.getPosition().x);
    setY(spr.getPosition().y);
}

void ai::calcuAngle(sf::Sprite &jug){
    float xj = jug.getPosition().x-x;
    float yj = jug.getPosition().y-y;
    /*
    float num = xj;
    float div = sqrt(pow(xj,2)+(pow(yj,2)))*
                sqrt(pow(x,2)+(pow(y,2)));
    */
    float resu = xj/sqrt(pow(xj,2)+(pow(yj,2)));
    float angu = acos(resu)*180/Pi;
    if(yj<1){
        angu=angu*(-1);
    }
    setAngle(angu);
    //std::cout << angu << std::endl;
}