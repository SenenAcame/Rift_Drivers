#include <iostream>
#include <math.h>

#include "vehiculo.h"

#define Pi 3.14159265

//Constructor modificado
//Senen
vehiculo::vehiculo(float vel, float acc, float gir, string spr, sf::Sprite &sf){
    setVelocidad(vel);
    setAceleracion(acc);
    setGiro(gir);
    setSprite(spr);
    setImagen(sf);
    setReloj();
}
//Fin

void vehiculo::setVelocidad(float vel){
    velocidad = vel;
}

float vehiculo::getVelocidad(){
    return velocidad;
}

void vehiculo::setAceleracion(float acc){
    aceleracion = acc;
}

float vehiculo::getAceleracion(){
    return aceleracion;
}

void vehiculo::setGiro(float gir){
    giro = gir;
}

float vehiculo::getGiro(){
    return giro;
}

void vehiculo::setSprite(string spr){
    //Comprobar que la textura existe
    //Senen
    sf::Texture tex;
    if (!tex.loadFromFile(spr)) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    //Fin
    spritename = spr;
}

string vehiculo::getSprite(){
    return spritename;
}

//Que el vehiculo tenga un sprite
//Senen
void vehiculo::setImagen(sf::Sprite &sf){
    imagen = sf;
    imagen.setOrigin(11.5f, 8);
    float rot = -90.00f;
    imagen.setRotation(rot);
    imagen.setScale(2.5f, 2.5f);
    imagen.setTextureRect(sf::IntRect(0 , 0, 23, 16));
    imagen.setPosition(25*320+320/2, 25*320+320/2+320);

    //cout << "Enlazado" << endl;
}

sf::Sprite vehiculo::getImagen(){
    return imagen;
}

void vehiculo::moverIA(float vx, float vy){
    imagen.move(vx,vy);
}

void vehiculo::rotarIA(float ang){
    //float angulo = ang*180/Pi+90;
    imagen.rotate(ang);
}
//Fin

void vehiculo::setReloj(){
    reloj.restart();
}

float vehiculo::getReloj(){
    return reloj.getElapsedTime().asSeconds();
}

