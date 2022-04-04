#include <iostream>
#include <math.h>

#include "ia.h"
#include "../tinyxml/tinyxml2.h"

using namespace tinyxml2;

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

void ia::setVehi(vehiculo *car){
    vehi = car;
}

vehiculo * ia::getVehi(){
    return vehi;
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
}