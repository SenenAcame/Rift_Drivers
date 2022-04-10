#include "mapa.h"

Mapa::Mapa(){
    
    for(int i=0;i<50;i++){
        std::vector<std::string> linea;
        for(int j=0;j<50;j++){
            linea.push_back("0");
        }
        circuito.push_back(linea);
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
}

void Mapa::CrearMapa(){
    int contador=0;
    int cachos=0;
    std::string cacho=BuscaCacho(0);
    int buscar=1;
    cacho="../resources/"+cacho+".png";
    circuito.at(fila).at(col)=cacho;
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
        if(nieve){
            cacho="../resources/"+BuscaCacho(buscar)+"nieve.png";
        }
        else{
            cacho="../resources/"+BuscaCacho(buscar)+".png";
        }
        if(!final){
            circuito.at(fila).at(col)=cacho;
            if(nieve){
                buscar=stoi(cacho.substr(cacho.length()-10,cacho.length()-4));
            }
            else
                buscar=stoi(cacho.substr(cacho.length()-5,cacho.length()-4));

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
    if(cachos<30){
        vaciaMapa();
        for(int i=0;i<50;i++){
            std::vector<std::string> linea;
            for(int j=0;j<50;j++){
                linea.push_back("0");
            }
            circuito.push_back(linea);
        }
        fila=25;
        col=25;
        final=false;
        contador=0;
        std::cerr<<std::to_string(cachos)<<"Repite\n";
        CrearMapa();
    }
}

std::string Mapa::BuscaCacho(int entrada){
    std::string cacho;
    int num2;
    bool pasa=false;
    if(entrada==0){
        cacho="1,4";
    }
    else{
        num2=entrada;
        
        while(num2==entrada||!pasa){
            
            cacho="";
            if(final)
                break;
            CompruebaFinal();
            num2=1+rand()%4;

            cacho=std::to_string(entrada)+","+std::to_string(num2);
            std::cerr << cacho<<"\n";
            pasa=CompruebaCacho(cacho);
        }

    }
    return cacho;
}

bool Mapa::CompruebaCacho(std::string cacho){
    bool pasa=false;
    std::string split2=cacho.substr(2,1);
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

void Mapa::CompruebaFinal(){
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

std::vector<std::vector<std::string> > Mapa::getCircuito(){
    return circuito;
}

void Mapa::vaciaMapa(){
    for(int i=49;i>=0;i--){
        circuito.at(i).clear();
    }
    circuito.clear();
    //delete cachos;
}

void Mapa::dibujaMapa(sf::RenderWindow *window){
    for(int i=0;i<cachos.size();i++){
        window->draw(cachos.at(i));
      }
}

void Mapa::montaMapa(){
    for(int k=0;k<circuito.size();k++){
        for (int l = 0; l < circuito.at(k).size(); l++){
            if(circuito.at(k).at(l)!="0"){
                if(circuito.at(k).at(l)=="../resources/1,2.png"||circuito.at(k).at(l)=="../resources/2,1.png"){
                    sf::Sprite sprite12(tex12);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite12.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite12);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,3.png"||circuito.at(k).at(l)=="../resources/3,1.png"){
                    sf::Sprite sprite13(tex13);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite13.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite13.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite13);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,4.png"||circuito.at(k).at(l)=="../resources/4,1.png"){
                    sf::Sprite sprite14(tex14);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite14.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite14.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite14);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,3.png"||circuito.at(k).at(l)=="../resources/3,2.png"){
                    sf::Sprite sprite23(tex23);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite23.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite23.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite23);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,4.png"||circuito.at(k).at(l)=="../resources/4,2.png"){
                    sf::Sprite sprite24(tex24);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite24.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite24.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite24);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/3,4.png"||circuito.at(k).at(l)=="../resources/4,3.png"){
                    sf::Sprite sprite34(tex34);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite34.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite34);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,2nieve.png"||circuito.at(k).at(l)=="../resources/2,1nieve.png"){
                    sf::Sprite sprite12nieve(tex12nieve);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite12nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite12nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite12nieve);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,3nieve.png"||circuito.at(k).at(l)=="../resources/3,1nieve.png"){
                    sf::Sprite sprite13nieve(tex13nieve);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite13nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite13nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite13nieve);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/1,4nieve.png"||circuito.at(k).at(l)=="../resources/4,1nieve.png"){
                    sf::Sprite sprite14nieve(tex14nieve);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite14nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite14nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite14nieve);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,3nieve.png"||circuito.at(k).at(l)=="../resources/3,2nieve.png"){
                    sf::Sprite sprite23nieve(tex23nieve);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite23nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite23nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite23nieve);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/2,4nieve.png"||circuito.at(k).at(l)=="../resources/4,2nieve.png"){
                    sf::Sprite sprite24nieve(tex24nieve);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite24nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite24nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite24nieve);
                        }
                    }
                }
                else if(circuito.at(k).at(l)=="../resources/3,4nieve.png"||circuito.at(k).at(l)=="../resources/4,3nieve.png"){
                    sf::Sprite sprite34nieve(tex34nieve);
                    for (int i = 0; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            sprite34nieve.setPosition(i*32+32*10*l,j*32+32*10*k);
                            sprite34nieve.setTextureRect(sf::IntRect(i*32,j*32,32,32));
                            cachos.push_back(sprite34nieve);
                        }
                    }
                }
            }
        }
    }
}