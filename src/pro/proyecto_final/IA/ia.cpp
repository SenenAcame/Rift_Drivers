#include <iostream>
#include <math.h>

#include "ia.h"
#include "../tinyxml/tinyxml2.h"

#define TamTile 320
#define kVel 5
#define Pi 3.14159265
#define MARGEN 10

using namespace tinyxml2;

ia::ia(Circuito *world, vehiculo *car){
    setList(world);
    setVehi(car);
    setCont(0);
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

    for(int i=0; i<(int)world->getMapas().size(); i++){
        if(world->getMapas().at(i).size()>0){
            string nom = "../resources/"+world->getMapas().at(i)+".xml";
            const char* fichero = nom.c_str();
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
            fichero=NULL;
            grupo=NULL;
        }
    }
    setSize(cont);
}

float ** ia::getList(){
    return list;
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

void ia::setVehi(vehiculo *car){
    vehi = car;
}

vehiculo * ia::getVehi(){
    return vehi;
}

int ia::contarPuntos(Circuito *world){
    int cont=0; 
    for(int i=0; i<(int)world->getMapas().size(); i++){
        if(world->getMapas().at(i).size()>0){
            string nom = "../resources/"+world->getMapas().at(i)+".xml";
            const char* fichero = nom.c_str();
            XMLDocument doc;
            doc.LoadFile(fichero);
            XMLElement *grupo = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
            for(XMLNode *hijo = grupo->FirstChild(); hijo; hijo = hijo->NextSibling()){
                cont++;
            }
            fichero=NULL;
            grupo=NULL;
        }
    }
    return cont;
}

int *ia::posicionesMapa(Circuito *world){
    int *posis = new int[world->getMapas().size()];
    for(int i=0; i<(int)world->getMapas().size();i++){
        if(world->getMapas().at(i).size()>0){
            char y = world->getMapas().at(i).at(2);
            posis[i] = y-48;
        }
    }

    return posis;
}

void ia::dibujaRecorrido(sf::RenderWindow *vent){
    sf::Vertex lineas[size];
    for(int i=0; i<size; i++){
        lineas[i].position = sf::Vector2f(list[i][0],list[i][1]);
        lineas[i].color = sf::Color::Red;
    }
    vent->draw(lineas,size,sf::LinesStrip);
}

void ia::seguirRuta(){
    if(cont<size){
        siguienteNodo();
        if(abs(vehi->getImagen().getPosition().x-list[cont][0])<MARGEN && abs(vehi->getImagen().getPosition().y-list[cont][1])<MARGEN){
            cont++;
        }
    }
}

void ia::siguienteNodo(){
    float angu = calcularDirc();
    float vx = cos(angu)*kVel;
    float vy = sin(angu)*kVel;
    vehi->moverIA(vx,vy);
}

float ia::calcularDirc(){
    float dx = list[cont][0] - vehi->getImagen().getPosition().x;
    float dy = list[cont][1] - vehi->getImagen().getPosition().y;
    float angle = atan2(dy,dx);
    return angle;
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
}