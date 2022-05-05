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
    Circuito *circuito = new Circuito();
    circuito->CrearMapa();
    circuito->montaMapa();
    //circuito->dibujaMapa();
    
    
}