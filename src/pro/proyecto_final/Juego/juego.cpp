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
<<<<<<< HEAD
    //vehiculo = new vehiculo(15.0, 2.0, 15.0, );

=======
    Circuito *circuito = new Circuito();
    circuito->CrearMapa();
    circuito->montaMapa();
    //circuito->dibujaMapa();
    
>>>>>>> 477511f8364bf31951018d444e6c10aa032004cc
    
}