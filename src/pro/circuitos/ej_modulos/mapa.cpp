#include "mapa.h"

Mapa::Mapa(){
    
    for(int i=0;i<10;i++){
        std::vector<std::string> linea;
        for(int j=0;j<10;j++){
            linea.push_back("0");
        }
        circuito.push_back(linea);
    }
    fila=5;
    col=5;
    final=false;
}

std::vector<sf::Sprite> Mapa::CrearMapa(){
    sf::Texture texm;
    std::vector<sf::Sprite> sprites;
    //std::vector<std::vector<sf::Sprite> > spritesmapa;
    std::string cacho=BuscaCacho(0);
    int buscar=1;
    cacho="../resources/"+cacho+".png";
    texm.loadFromFile(cacho);
    circuito.at(fila).at(col)=cacho;
    fila=fila-1;
    while(!final){
        sf::Sprite spritem(texm);
        std::cerr << "fila:"<<fila<<"\n";
        std::cerr << "columna:"<<col<<"\n";
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                spritem.setPosition(i*64+640*fila,j*64+640*col);
                spritem.setTextureRect(sf::IntRect(i*64,j*64,64,64));
                sprites.push_back(spritem);
            }
        }
        //spritesmapa.push_back(sprites);
        cacho="../resources/"+BuscaCacho(buscar)+".png";
        if(!final){
            texm.loadFromFile(cacho);
            circuito.at(fila).at(col)=cacho;
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
            std::cerr << "esto es cacho"<<cacho<<"\n";
            std::cerr << "esto es buscar"<<buscar<<"\n";
        }
    }
    return sprites;
}

std::string Mapa::BuscaCacho(int entrada){
    std::string cacho;
    int num2,num;
    bool pasa=false;
    if(entrada==0){
        /*srand(time(NULL));
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
        cacho=num+","+num2;*/
        cacho="1,4";
    }
    else{
        num2=entrada;
        srand(time(NULL));
        while(num2==entrada||!pasa){
            cacho="";
            if(final)
                break;
            CompruebaFinal();
            num2=1+rand()%4;
            std::cerr << "esto es num2"<<num2<<"\n";
            cacho=std::to_string(entrada)+","+std::to_string(num2);
            std::cerr << "esto es cacho"<<cacho<<"\n";
            pasa=CompruebaCacho(cacho);
        }
    }
    return cacho;
}

bool Mapa::CompruebaCacho(std::string cacho){
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