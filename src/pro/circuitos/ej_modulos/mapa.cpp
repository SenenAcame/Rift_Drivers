#include "mapa.h"

Mapa::Mapa(){
    std::vector<std::string> linea;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            linea.push_back("0");
        }
        circuito.push_back(linea);
    }
}

std::vector<sf::Sprite> Mapa::CrearMapa(){
    sf::Texture texm;
    sf::Sprite spritem;
    std::vector<sf::Sprite> sprites;
    //std::vector<std::vector<sf::Sprite> > spritesmapa;
    std::string cacho=BuscaCacho(0);
    int buscar=stoi(cacho.substr(2));
    cacho="../resources/1"+BuscaCacho(0)+".png";
    texm.loadFromFile(cacho);
    circuito.at(fila).at(col)=cacho;
    while(!final){
        sf::Sprite spritem(texm);
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                spritem.setPosition(i*32+320*fila,j*32+320*col);
                spritem.setTextureRect(sf::IntRect(i*32,j*32,128,128));
                sprites.push_back(spritem);
            }
        }
        //spritesmapa.push_back(sprites);
        cacho="../resources/1"+BuscaCacho(buscar)+".png";
        texm.loadFromFile(cacho);
        circuito.at(fila).at(col)=cacho;
        buscar=stoi(cacho.substr(2));
    }
}

std::string Mapa::BuscaCacho(int entrada){
    std::string cacho;
    std::vector<int> carriles;
    int num2,num;
    bool pasa=false;
    if(entrada==0){
        srand(time(NULL));
        num=1+rand()%4;
        num2=num;
        switch (num)
        {
        case 1:
            num2=4;
            break;
        case 2:
            num2=3;
            break;
        case 3:
            num2=2;
            break;
        case 4:
            num2=1;
            break;
        }
        cacho=num+","+num2;
    }
    else{
        num2=entrada;
        srand(time(NULL));
        while(num2!=entrada&&pasa||!final){
            CompruebaFinal(carriles);
            num2=1+rand()%4;
            cacho=entrada+","+num2;
            pasa=CompruebaCacho(cacho);
            carriles.push_back(num2);
        }
    }
}

bool Mapa::CompruebaCacho(std::string cacho){
    bool pasa=false;
    std::string split1=cacho.substr(0,1);
    std::string split2=cacho.substr(2);
    int fila2=stoi(split1);
    int col2=stoi(split2);
    switch (col2)
    {
    case 1:
        if(fila+1<circuito.size()&&circuito.at(fila+1).at(col)=="0"){
            fila=fila+1;
            pasa=true;
        }
        break;
    case 2:
        if(col+1<circuito.at(0).size()&&circuito.at(fila).at(col+1)=="0"){
            col=col+1;
            pasa=true;
        }
        break;
    case 4:
        if(fila-1>=0&&circuito.at(fila+1).at(col)=="0"){
            fila=fila-1;
            pasa=true;
        }
        break;
    case 3:
        if(col-1>=0&&circuito.at(fila).at(col-1)=="0"){
            col=col-1;
            pasa=true;
        }
        break;
    
    }
}

void Mapa::CompruebaFinal(std::vector<int> carriles){
    bool uno=false,dos=false,tres=false,cuatro=false;
    for(int i=0;i<carriles.size();i++){
        switch (carriles.at(i))
        {
        case 1:
            uno=true;
            break;
        case 2:
            dos=true;
            break;
        case 3:
            tres=true;
            break;
        case 4:
            cuatro=true;
            break;
        }
    }
    if(uno&&dos&&tres&&cuatro)
        final=true;
}