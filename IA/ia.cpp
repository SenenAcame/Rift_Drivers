#include <iostream>
#include <math.h>

#include "ia.h"
#include "../tinyxml/tinyxml2.h"

using namespace tinyxml2;

ia::ia(string maps[]){
    int cont=0; 
  
    for(int i=0; i<(int)(sizeof(maps)/sizeof(*maps)); i++){
        const char* fichero = maps[i].c_str();
        XMLDocument doc;
        doc.LoadFile(fichero);
        XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
        for(XMLNode *hijo = grupo->FirstChild(); hijo; hijo = hijo->NextSibling()){
            cont++;
        }
        fichero=NULL;
        grupo=NULL;
    }

    list = new float*[cont];
    int global=0;
    int vari = 0;

    for(int i=0; i<(int)(sizeof(maps)/sizeof(*maps)); i++){
        const char* frag = maps[i].c_str();
        XMLDocument doc;
        doc.LoadFile(frag);
        XMLElement *group = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
        for(XMLElement *son = group->FirstChildElement("object"); son; son = son->NextSiblingElement("object")){
            /*
            int v = rand() % 11-5;
            vari += v;
            */
            list[global] = new float[2];
            if(i==2){
                list[global][0] = son->FloatAttribute("x")+320+vari;
                list[global][1] = son->FloatAttribute("y")+320+vari;
            }
            else{
                list[global][0] = son->FloatAttribute("x")+320*i+vari;
                list[global][1] = son->FloatAttribute("y")+vari;
            }
            global++;
        }
        frag=NULL;
        group=NULL;
    }
}

float ** ia::getList(){
    return list;
}

/*
ai::ai(sf::Sprite &spri, float v, float exi, float eyi){
    setVel(v);
    setX(exi);
    setY(eyi);
    setAngle(0);
    setRad(0);
    setSpr(spri);
}

ai::ai(sf::Sprite &spri, float v, float exi, float eyi, int i){
    setVel(v);
    setX(exi);
    setY(eyi);
    setAngle(0);
    setRad(0);
    setSpr(spri,i);
}

void ai::setSpr(sf::Sprite &s){
    spr=s;
    spr.setOrigin(3 * 75 / 4, 75 / 2);
    spr.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
    spr.setPosition(x, y);
}

void ai::setSpr(sf::Sprite &s, int pos){
    spr=s;
    spr.setOrigin(3 * 75 / 4, 75 / 2);
    spr.setTextureRect(sf::IntRect(1 * 75, pos * 75, 75, 75));
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

void ai::setRad(float radius){
    rad=radius;
}

float ai::getRad(){
    return rad;
}

void ai::setAngle(float angu){
    angle=angu;
}

float ai::getAngle(){
    return angle;
}

void ai::perseguir(sf::Sprite &jug){
    calcuAngle(jug);

    float vx = vel*rad*cos(angle);
    float vy = vel*rad*sin(angle);

    spr.move(vx,vy);
    
    setX(spr.getPosition().x);
    setY(spr.getPosition().y);
}

void ai::calcuAngle(sf::Sprite &jug){
    float xj = jug.getPosition().x-x;
    float yj = jug.getPosition().y-y;
    float resu = 1;
    float angu = atan(yj/xj)*180/Pi;
    setAngle(angu);
    setRad(resu);
}

void ai::calcuAngle(float ex, float ey){
    float xj = ex-x;
    float yj = ey-y;

    float resu = 1;
    float angu = atan(yj/xj)*180/Pi;
    setAngle(angu);
    setRad(resu);
}

void ai::seguirNodo(float ex, float ey){
    calcuAngle(ex, ey);

    float vx = vel*rad*cos(angle);
    float vy = vel*rad*sin(angle);

    spr.move(vx,vy);
    
    setX(spr.getPosition().x);
    setY(spr.getPosition().y);
}
*/