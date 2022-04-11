#include "juego.h"

juego * juego::pinstance = 0;

juego* juego::instance()
{
    if(pinstance == 0)
    {
        pinstance = new juego();
    }
    return pinstance;
}

juego::juego()
{
    //vehiculo = new vehiculo(15.0, 2.0, 15.0, );

    
}