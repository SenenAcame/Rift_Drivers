#include <SFML/Graphics.hpp>

#ifndef ESTADO_H
#define ESTADO_H

//Patron State para los estados
class Estado{
    protected:
    
    public:
        Estado();
        ~Estado();

        //update para cada estado
        virtual void update(float deltaTime);
        //render para cada estado
        virtual void render(float num);
};
#endif