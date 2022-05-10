#include <iostream>
#include <math.h>

#include "ia.h"
#include "../tinyxml/tinyxml2.h"

#define TamTile 320
//#define kVel 7
#define Pi 3.14159265
#define MARGEN 10
#define NoContains string::npos

using namespace tinyxml2;

ia::ia(Circuito *world, vehiculo *car){
    setList(world);
    setVehi(car);
    setCont(0);
    setAngulo(0);
    setSpeed(7);
    setDibCheck(false);
    setSegCheck(true);
}

void ia::setList(Circuito *world){
    
    if(list!=0){
        deleteList();
    }
    
    int cont=contarPuntos(world); 
    list = new float*[cont];
    int global=0;
    int *posiciones = posicionesMapa(world);
    int x=25,y=25;
    srand(time(NULL));
    for(int i=0; i<(int)world->getMapas().size(); i++){
        if(world->getMapas().at(i).size()>0 && i!=(int)world->getMapas().size()-2){
            string trozo = tipoTerreno(world, i);
            const char* fichero = trozo.c_str();
            XMLDocument doc;
            doc.LoadFile(fichero);
            XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
            for(XMLElement *son = grupo->FirstChildElement("object"); son; son = son->NextSiblingElement("object")){
                list[global] = new float[2];
                list[global][0] = son->FloatAttribute("x")+TamTile*x;
                list[global][1] = son->FloatAttribute("y")+TamTile*y;
                global++;
            }
            int value = posiciones[i];
            switch(value){
                case 1:
                    y++;
                break;

                case 2:
                    x++;
                break;

                case 3:
                    x--;
                break;
                    
                case 4:
                    y--;
                break;
            }
        }
    }
    setSize(cont);
}

float ** ia::getList(){
    return list;
}

void ia::setSpeed(int spe){
    speed = spe;
}

int ia::getSpeed(){
    return speed;
}

void ia::setSize(int num){
    size = num;
}

int ia::getSize(){
    return size;
}

void ia::setCont(int c){
    cont = c;
}

int ia::getCont(){
    return cont;
}

void ia::setAngulo(float a){
    angulo = a;
}

int ia::getAngulo(){
    return angulo;
}

void ia::setVehi(vehiculo *car){
    vehi = car;
}

vehiculo * ia::getVehi(){
    return vehi;
}

void ia::setDibCheck(bool check){
    dibCheck = check;
}

bool ia::getDibCheck(){
    return dibCheck;
}

void ia::setSegCheck(bool check){
    segCheck = check;
}

bool ia::getSegCheck(){
    return segCheck;
}

int ia::contarPuntos(Circuito *world){
    int cont=0; 
    srand(time(NULL));
    for(int i=0; i<(int)world->getMapas().size(); i++){
        if(world->getMapas().at(i).size()>0 && i!=(int)world->getMapas().size()-2){
            string trozo = tipoTerreno(world, i);
            const char* fichero = trozo.c_str();
            XMLDocument doc;
            doc.LoadFile(fichero);
            XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
            for(XMLNode *hijo = grupo->FirstChild(); hijo; hijo = hijo->NextSibling()){
                cont++;
            }
        }
    }
    return cont;
}

int *ia::posicionesMapa(Circuito *world){
    int *posis = new int[world->getMapas().size()];
    for(int i=0; i<(int)world->getMapas().size();i++){
        if(world->getMapas().at(i).size()>0){
            char y = world->getMapas().at(i).at(2);
            if(y=='l'){
                y='4';
            }
            posis[i] = y-48;
        }
    }
    return posis;
}

void ia::dibujaRecorrido(sf::RenderWindow *vent){
    if(dibCheck){
        sf::Vertex lineas[size];
        for(int i=0; i<size; i++){
            lineas[i].position = sf::Vector2f(list[i][0],list[i][1]);
            lineas[i].color = sf::Color::Red;
        }
        vent->draw(lineas,size,sf::LinesStrip);
    }
}

string ia::tipoTerreno(Circuito *world, int posi){
    string part = "";
    if(world->getMapas().at(posi).find("salida")==NoContains && world->getMapas().at(posi).find("meta")==NoContains){
        char ent = world->getMapas().at(posi).at(0);
        char sal = world->getMapas().at(posi).at(2);
        part.push_back(ent);
        part += ",";
        part.push_back(sal);
        if(!((ent=='1' && sal=='4') || (ent=='4' && sal=='1') || (ent=='2' && sal=='3') || (ent=='3' && sal=='2'))){
            int v = rand() % 2;
            if(world->getMapas().at(posi).find("nieve")==NoContains){
                v++;
            }
            part += ","+to_string(v);
        } 
    }
    else{
        part = world->getMapas().at(posi);
    }
    string fichero = "../resources/"+part+".xml";
    return fichero;
}

void ia::seguirRuta(){
    if(cont<size && segCheck){
        siguienteNodo();
        if(abs(vehi->getImagen().getPosition().x-list[cont][0])<MARGEN && abs(vehi->getImagen().getPosition().y-list[cont][1])<MARGEN){
            girarVehiculo();
            cont++;
        }
    }
}

void ia::siguienteNodo(){
    float angu = calcularDirc();
    float vx = cos(angu)*speed;
    float vy = sin(angu)*speed;
    vehi->moverIA(vx,vy);
}

float ia::calcularDirc(){
    float dx = list[cont][0] - vehi->getImagen().getPosition().x;
    float dy = list[cont][1] - vehi->getImagen().getPosition().y;
    float angle = atan2(dy,dx);
    return angle;
}

void ia::girarVehiculo(){
    float rot = calcularDirc();
    rot = rot*180/Pi+90;
    if(rot>180){
        rot-=360;
    }
    vehi->rotarIA(rot-angulo);
    setAngulo(rot);
}

void ia::deleteList(){
    for(int i=0; i<size; i++){
        delete[] list[i];
    }
    delete[] list;
}

ia::~ia(){
    deleteList();
    setSize(0);
    setVehi(NULL);
    setCont(0);
    setAngulo(0);
    setSpeed(0);
    setDibCheck(false);
    setSegCheck(false);
}