#include "juego.h"
#include "Manejador.h"
#include "../Menu/menu.h"

juego * juego::pinstance = 0;
juego::juego()
{
    Circuito *circuito = new Circuito();
    circuito->CrearMapa();
    circuito->montaMapa();
    //circuito->dibujaMapa();
    
    
}