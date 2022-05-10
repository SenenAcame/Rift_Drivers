#include <iostream>
#include "circuito.h"

Circuito::Circuito(){
    
    for(int i=0;i<50;i++){
        std::vector<std::string> linea;
        for(int j=0;j<50;j++){
            linea.push_back("0");
        }
        circuito.push_back(linea);
    }
    for(int i=0;i<50;i++){
        std::vector<std::string> linea;
        for(int j=0;j<50;j++){
            linea.push_back("0");
        }
        circuitobw.push_back(linea);
    }
    fila=25;
    col=25;
    final=false;
    nieve=false;
    //cachos=new std::vector<sf::Sprite>;
    srand(time(0));
    if (!tex12.loadFromFile("../resources/1,2.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex13.loadFromFile("../resources/1,3.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex14.loadFromFile("../resources/1,4.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex23.loadFromFile("../resources/2,3.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex24.loadFromFile("../resources/2,4.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex34.loadFromFile("../resources/3,4.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex12nieve.loadFromFile("../resources/1,2nieve.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex13nieve.loadFromFile("../resources/1,3nieve.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex14nieve.loadFromFile("../resources/1,4nieve.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex23nieve.loadFromFile("../resources/2,3nieve.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex24nieve.loadFromFile("../resources/2,4nieve.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex34nieve.loadFromFile("../resources/3,4nieve.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex12bw.loadFromFile("../resources/1,2bw.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex13bw.loadFromFile("../resources/1,3bw.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex14bw.loadFromFile("../resources/1,4bw.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex23bw.loadFromFile("../resources/2,3bw.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex24bw.loadFromFile("../resources/2,4bw.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex34bw.loadFromFile("../resources/3,4bw.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    if (!tex12nievebw.loadFromFile("../resources/1,2nievebw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex13nievebw.loadFromFile("../resources/1,3nievebw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex14nievebw.loadFromFile("../resources/1,4nievebw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex23nievebw.loadFromFile("../resources/2,3nievebw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex24nievebw.loadFromFile("../resources/2,4nievebw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex34nievebw.loadFromFile("../resources/3,4nievebw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  if (!texsalida.loadFromFile("../resources/salida.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texsalidabw.loadFromFile("../resources/salidabw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta1.loadFromFile("../resources/meta1.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta1bw.loadFromFile("../resources/meta1bw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta2.loadFromFile("../resources/meta2.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta2bw.loadFromFile("../resources/meta2bw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta3.loadFromFile("../resources/meta3.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta3bw.loadFromFile("../resources/meta3bw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta4.loadFromFile("../resources/meta4.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texmeta4bw.loadFromFile("../resources/meta4bw.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!texvortice.loadFromFile("../resources/vortice.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  imvortice.setTexture(texvortice);
    /*
  if (!texfuera.loadFromFile("../resources/fuera.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
*/
}

void Circuito::CrearMapa(){

    
    int contador=0;
    int cachos=0;
    nieve=false;
    std::string cacho="salida";
    std::string cacho1;
    std::string cacho2;
    mapas.push_back(cacho);
    int buscar=1;
    cacho1="../resources/"+cacho+".png";
    cacho2="../resources/"+cacho+"bw.png";
    circuito.at(fila).at(col)=cacho1;
    circuitobw.at(fila).at(col)=cacho2;
    fila=fila-1;
    while(!final){
        if(contador>6){
            int random=rand()%3;
            if(random==0 && !nieve){
                nieve=true;
                contador=0;
            }
            else if(random==0 && nieve){
                nieve=false;
                contador=0;
            }
        }
        contador++;
        cachos++;
        cacho=BuscaCacho(buscar);
        if(nieve){
            mapas.push_back(cacho+"nieve");
        }
        else{
            mapas.push_back(cacho);
        }
        if(nieve){
            cacho1="../resources/"+cacho+"nieve.png";
            cacho2="../resources/"+cacho+"nievebw.png";
        }
        else{
            cacho1="../resources/"+cacho+".png";
            cacho2="../resources/"+cacho+"bw.png";
        }
        if(!final){
            circuito.at(fila).at(col)=cacho1;
            circuitobw.at(fila).at(col)=cacho2;
            if(circuito.at(fila).at(col)=="../resources/salida.png"){
                circuitobw.at(fila).at(col)="../resources/salidabw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/2,1.png"){
                circuitobw.at(fila).at(col)="../resources/1,2bw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/2,1nieve.png"){
                circuitobw.at(fila).at(col)="../resources/1,2nievebw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/3,1.png"){
                circuitobw.at(fila).at(col)="../resources/1,3bw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/3,1nieve.png"){
                circuitobw.at(fila).at(col)="../resources/1,3nievebw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/3,2.png"){
                circuitobw.at(fila).at(col)="../resources/2,3bw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/3,2nieve.png"){
                circuitobw.at(fila).at(col)="../resources/2,3nievebw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/4,1.png"){
                circuitobw.at(fila).at(col)="../resources/1,4bw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/4,1nieve.png"){
                circuitobw.at(fila).at(col)="../resources/1,4nievebw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/4,2.png"){
                circuitobw.at(fila).at(col)="../resources/2,4bw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/4,2nieve.png"){
                circuitobw.at(fila).at(col)="../resources/2,4nievebw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/4,3.png"){
                circuitobw.at(fila).at(col)="../resources/3,4bw.png";
            }
            if(circuito.at(fila).at(col)=="../resources/4,3nieve.png"){
                circuitobw.at(fila).at(col)="../resources/3,4nievebw.png";
            }
            
            
            buscar=stoi(cacho.substr(2,1));

            switch (buscar)
            {
            case 1:
                buscar=4;
                fila++;
                break;
            
            case 2:
                buscar=3;
                col++;
                break;
            case 3:
                buscar=2;
                col--;
                break;
            case 4:
                buscar=1;
                fila--;
                break;
            }
        }
    }
    mapas.push_back("meta"+std::to_string(buscar));
    std::cerr << "fila :"+std::to_string(fila)<<"\n";
    std::cerr << "col :"+std::to_string(col)<<"\n";
    circuito.at(fila).at(col)="../resources/meta"+std::to_string(buscar)+".png";
    if(circuito.at(fila).at(col)=="../resources/meta1.png"){
        circuitobw.at(fila).at(col)="../resources/meta1bw.png";
    }
    if(circuito.at(fila).at(col)=="../resources/meta2.png"){
        circuitobw.at(fila).at(col)="../resources/meta2bw.png";
    }
    if(circuito.at(fila).at(col)=="../resources/meta3.png"){
        circuitobw.at(fila).at(col)="../resources/meta3bw.png";
    }
    if(circuito.at(fila).at(col)=="../resources/meta4.png"){
        circuitobw.at(fila).at(col)="../resources/meta4bw.png";
    }
    if(cachos<50){
        vaciaMapa();
        for(int i=0;i<50;i++){
            std::vector<std::string> linea;
            for(int j=0;j<50;j++){
                linea.push_back("0");
            }
            circuito.push_back(linea);
        }
        for(int i=0;i<50;i++){
            std::vector<std::string> linea;
            for(int j=0;j<50;j++){
                linea.push_back("0");
            }
            circuitobw.push_back(linea);
        }
        fila=25;
        col=25;
        final=false;
        contador=0;
        std::cerr<<std::to_string(cachos)<<" Repite\n";
        CrearMapa();
    }
    
    imvortice.setOrigin(160,160);
    imvortice.setPosition(160+32*10*col,160+32*10*fila);
    
}

std::string Circuito::BuscaCacho(int entrada){
    std::string cacho="";
    int num2;
    bool pasa=false;
        num2=entrada;
        
        while(num2==entrada||!pasa){
            
            cacho="";
            if(final)
                break;
            CompruebaFinal();
            num2=1+rand()%4;

            cacho=std::to_string(entrada)+","+std::to_string(num2);
            //std::cerr << cacho<<"\n";
            pasa=CompruebaCacho(cacho);
        }
        //std::cerr << cacho<<"\n";
    return cacho;
}

bool Circuito::CompruebaCacho(std::string cacho){
    bool pasa=false;
    std::string split1=cacho.substr(0,1);
    std::string split2=cacho.substr(2,1);
    int fila2=stoi(split1);
    int col2=stoi(split2);
    switch (col2)
    {
    case 1:
        if(fila+1<circuito.size()&&circuito.at(fila+1).at(col)=="0"){
            pasa=true;
        }
        break;
    case 2:
        if(col+1<circuito.at(0).size()&&circuito.at(fila).at(col+1)=="0"){
            pasa=true;
        }
        break;
    case 4:
        if(fila-1>=0&&circuito.at(fila-1).at(col)=="0"){
            pasa=true;
        }
        break;
    case 3:
        if(col-1>=0&&circuito.at(fila).at(col-1)=="0"){
            pasa=true;
        }
        break;
    
    }
    return pasa;
}

void Circuito::CompruebaFinal(){
    bool uno=false,dos=false,tres=false,cuatro=false;
    if(fila+1<circuito.size()&&circuito.at(fila+1).at(col)!="0"||!(fila+1<circuito.size())){
        uno=true;
    }
    if(col+1<circuito.at(0).size()&&circuito.at(fila).at(col+1)!="0"||!(col+1<circuito.at(0).size())){
        dos=true;
    }
    if(fila-1>=0&&circuito.at(fila-1).at(col)!="0"||fila-1<0){
        tres=true;
    }
    if(col-1>=0&&circuito.at(fila).at(col-1)!="0"||col-1<0){
        cuatro=true;
    }
    if(uno&&dos&&tres&&cuatro){
        final=true;
        std::cerr << "final\n";
    }

}

std::vector<std::vector<std::string> > Circuito::getCircuito(){
    return circuito;
}

std::vector<std::vector<std::string> > Circuito::getCircuitobw(){
    return circuitobw;
}

void Circuito::vaciaMapa(){
    for(int i=49;i>=0;i--){
        circuito.at(i).clear();
    }
    circuito.clear();
    for(int i=49;i>=0;i--){
        circuitobw.at(i).clear();
    }
    circuitobw.clear();
    cachos.clear();
    mapas.clear();
}

void Circuito::dibujaMapa(sf::RenderWindow *window){
    for(int i=0;i<cachos.size();i++){
        window->draw(cachos.at(i));
      }
    imvortice.setRotation(imvortice.getRotation()-2);
    window->draw(imvortice);
}
/*
void Circuito::dibujaMapabw(sf::RenderWindow *window){
    for(int i=0;i<cachosbw.size();i++){
        window->draw(cachosbw.at(i));
      }
}
*/
void Circuito::montaMapa(){
    sf::Sprite spritefuera(texfuera);
    spritefuera.setTextureRect(sf::IntRect(-640,-640,320*54,320*54));
    cachos.push_back(spritefuera);
    for(int k=0;k<circuito.size();k++){
        for (int l = 0; l < circuito.at(k).size(); l++){
            if(circuito.at(k).at(l)!="0"){
                if(circuito.at(k).at(l)=="../resources/1,2.png"||circuito.at(k).at(l)=="../resources/2,1.png"){
                    sf::Sprite sprite12(tex12);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite12.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite12);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,3.png"||circuito.at(k).at(l)=="../resources/3,1.png"){
                    sf::Sprite sprite13(tex13);
                    //sf::Sprite sprite13bw(tex13bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite13.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite13.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite13);
                            /*
                            sprite13bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite13bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite13bw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,4.png"||circuito.at(k).at(l)=="../resources/4,1.png"){
                    sf::Sprite sprite14(tex14);
                    //sf::Sprite sprite14bw(tex14bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite14.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite14.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite14);
                            /*
                            sprite14bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite14bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite14bw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,3.png"||circuito.at(k).at(l)=="../resources/3,2.png"){
                    sf::Sprite sprite23(tex23);
                    //sf::Sprite sprite23bw(tex23bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite23.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite23.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite23);
                            /*
                            sprite23bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite23bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite23bw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,4.png"||circuito.at(k).at(l)=="../resources/4,2.png"){
                    sf::Sprite sprite24(tex24);
                    //sf::Sprite sprite24bw(tex24bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite24.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite24.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite24);
                            /*
                            sprite24bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite24bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite24bw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/3,4.png"||circuito.at(k).at(l)=="../resources/4,3.png"){
                    sf::Sprite sprite34(tex34);
                    //sf::Sprite sprite34bw(tex34bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite34.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite34);
                            /*
                            sprite34bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34bw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,2nieve.png"||circuito.at(k).at(l)=="../resources/2,1nieve.png"){
                    sf::Sprite sprite12nieve(tex12nieve);
                    //sf::Sprite sprite12nievebw(tex12nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite12nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite12nieve);
                            /*
                            sprite12nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,3nieve.png"||circuito.at(k).at(l)=="../resources/3,1nieve.png"){
                    sf::Sprite sprite13nieve(tex13nieve);
                    //sf::Sprite sprite13nievebw(tex13nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite13nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite13nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite13nieve);
                            /*
                            sprite13nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite13nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite13nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,4nieve.png"||circuito.at(k).at(l)=="../resources/4,1nieve.png"){
                    sf::Sprite sprite14nieve(tex14nieve);
                    //sf::Sprite sprite14nievebw(tex14nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite14nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite14nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite14nieve);
                            /*
                            sprite14nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite14nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite14nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,3nieve.png"||circuito.at(k).at(l)=="../resources/3,2nieve.png"){
                    sf::Sprite sprite23nieve(tex23nieve);
                    //sf::Sprite sprite23nievebw(tex23nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite23nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite23nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite23nieve);
                            /*
                            sprite23nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite23nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite23nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,4nieve.png"||circuito.at(k).at(l)=="../resources/4,2nieve.png"){
                    sf::Sprite sprite24nieve(tex24nieve);
                    //sf::Sprite sprite24nievebw(tex24nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite24nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite24nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite24nieve);
                            /*
                            sprite24nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite24nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite24nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/3,4nieve.png"||circuito.at(k).at(l)=="../resources/4,3nieve.png"){
                    sf::Sprite sprite34nieve(tex34nieve);
                    //sf::Sprite sprite34nievebw(tex34nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite34nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite34nieve);
                            /*
                            sprite34nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/salida.png"){
                    sf::Sprite spritesalida(texsalida);
                    //sf::Sprite sprite34nievebw(tex34nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritesalida.setPosition(i*32+32*10*l,j*32+32*10*k);
                            spritesalida.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritesalida);
                            /*
                            sprite34nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/meta1.png"){
                    sf::Sprite spritemeta1(texmeta1);
                    //sf::Sprite sprite34nievebw(tex34nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritemeta1.setPosition(i*32+32*10*l,j*32+32*10*k);
                            spritemeta1.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritemeta1);
                            /*
                            sprite34nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34nievebw);
                            */
                        }
                    }

                }
                else if(circuito.at(k).at(l)=="../resources/meta2.png"){
                    sf::Sprite spritemeta2(texmeta2);
                    //sf::Sprite sprite34nievebw(tex34nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritemeta2.setPosition(i*32+32*10*l,j*32+32*10*k);
                            spritemeta2.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritemeta2);
                            /*
                            sprite34nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/meta3.png"){
                    sf::Sprite spritemeta3(texmeta3);
                    //sf::Sprite sprite34nievebw(tex34nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritemeta3.setPosition(i*32+32*10*l,j*32+32*10*k);
                            spritemeta3.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritemeta3);
                            /*
                            sprite34nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34nievebw);
                            */
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/meta4.png"){
                    sf::Sprite spritemeta4(texmeta4);
                    //sf::Sprite sprite34nievebw(tex34nievebw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritemeta4.setPosition(i*32+32*10*l,j*32+32*10*k);
                            spritemeta4.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritemeta4);
                            /*
                            sprite34nievebw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nievebw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite34nievebw);
                            */
                        }
                    }
                }/*
                if(k-1>=0&&l-1>=0&&circuito.at(k-1).at(l-1)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l-1),j*32+32*10*(k-1));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(l-1>=0&&circuito.at(k).at(l-1)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l-1),j*32+32*10*(k));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(k+1<circuito.size()&&l+1<circuito.at(k+1).size()&&circuito.at(k+1).at(l+1)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l+1),j*32+32*10*(k+1));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(l+1<circuito.at(k).size()&&circuito.at(k).at(l+1)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l+1),j*32+32*10*(k));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(k+1<circuito.size()&&l-1>=0&&circuito.at(k+1).at(l-1)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l-1),j*32+32*10*(k+1));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(k+1<circuito.size()&&circuito.at(k+1).at(l)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l),j*32+32*10*(k+1));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(k-1>=0&&l+1<circuito.at(k-1).size()&&circuito.at(k-1).at(l+1)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l+1),j*32+32*10*(k-1));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }
                if(k-1>=0&&circuito.at(k-1).at(l)=="0"){
                    sf::Sprite spritefuera(texfuera);
                    //sf::Sprite sprite12bw(tex12bw);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            spritefuera.setPosition(i*32+32*10*(l),j*32+32*10*(k-1));
                            spritefuera.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(spritefuera);
                            /*
                            sprite12bw.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12bw.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachosbw.push_back(sprite12bw);
                            *//*
                        }
                    }
                }*/
            }
        }
    }
}

std::vector<std::string> Circuito::getMapas(){
    return mapas;
}

int Circuito::getFinalx(){
    return fila;
}

int Circuito::getFinaly(){
    return col;
}