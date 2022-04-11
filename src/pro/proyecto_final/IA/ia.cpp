#include <iostream>
#include <math.h>

#include "ia.h"
#include "../tinyxml/tinyxml2.h"

#define TamTile 320
#define kVel 5
#define Pi 3.14159265
#define MARGEN 50

using namespace tinyxml2;
/*
ia::ia(string maps[],int leng, vehiculo *car){
    setList(maps,leng);
    setVehi(car);
}

void ia::setList(string maps[], int leng){
    if(list!=0){
        deleteList();
    }
    int cont=contarPuntos(maps, leng); 
    list = new float*[cont];
    int global=0;
    int vari = 0;

    for(int i=0; i<leng; i++){
        const char* frag = maps[i].c_str();
        XMLDocument doc;
        doc.LoadFile(frag);
        XMLElement *group = doc.FirstChildElement("map")->FirstChildElement("objectgroup");
        for(XMLElement *son = group->FirstChildElement("object"); son; son = son->NextSiblingElement("object")){  
            //int v = rand() % 11-5;
            //vari += v;
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

    setSize(cont);
}

int ia::contarPuntos(string maps[], int leng){
    int cont=0; 
    for(int i=0; i<leng; i++){
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

    return cont;
}
*/

ia::ia(Circuito *world, vehiculo *car){
    setList(world);
    setVehi(car);
    setCont(0);
    setX(vehi->getImagen().getPosition().x);
    setY(vehi->getImagen().getPosition().y);
    setAngle(0);
    /*
    float aux1 = list[cont][0];
    float aux2 = list[cont][1];

    calcularDirc(aux1,aux2);
    */
}

void ia::setList(Circuito *world){
    
    if(list!=0){
        deleteList();
    }
    
    int cont=contarPuntos(world); 
    list = new float*[cont];
    int global=0;
    //int vari = 0;
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

void ia::setAngle(float a){
    angle = a;
}

float ia::getAngle(){
    return angle;
}

void ia::setX(int ex){
    x = ex;
}

int ia::getX(){
    return x;
}

void ia::setY(int ey){
    y = ey;
}

int ia::getY(){
    return y;
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
        siguienteNodo(list[cont][0],list[cont][1]);
        if(abs(vehi->getImagen().getPosition().x-list[cont][0])<MARGEN && 
           abs(vehi->getImagen().getPosition().y-list[cont][1])<MARGEN){
               cont++;
               //calcularDirc(list[cont][0],list[cont][1]);
        }
    }
}

void ia::siguienteNodo(float ex, float hy){
    calcularDirc(ex,hy);
    //int angulo = cambiarDirecc();
    //if(abs(angulo-angle)>1){
        //angle=angulo-90;
    //}
    /*
    float nx = ex-x;
    float ny = hy-y;
    angle = atan(ny/nx)*180/Pi;
*/
    float vx = kVel*cos(angle);
    float vy = kVel*sin(angle);
    //cout << "Posicion actual: " << x << " , " << y << endl;
    //cout << "Velocidad : " << vx << " , " << vy << endl;
    //cout << "Posicion objetivo: " << list[cont][0] << " , " << list[cont][1] << endl;
    getVehi()->moverIA(vx,vy);
    setX(vehi->getImagen().getPosition().x);
    setY(vehi->getImagen().getPosition().y);
    //cout << "Posicion siguiente: " << x << " , " << y << endl;
}

void ia::calcularDirc(float ex, float hy){
    //cout << "Posicion: " << vehi->getImagen().getPosition().x << " , " << vehi->getImagen().getPosition().y << endl;
    //cout << "Siguiente punto: " << list[cont][0] << " , " << list[cont][1] << endl;
    float nx = ex-x;
    float ny = hy-y;
    //cout << "Distancia: " << x << " , " << y << endl;
    angle = atan(ny/nx)*180/Pi;
    //cout << angle << endl;
    //cout << "Angulo: " << angle << endl;
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