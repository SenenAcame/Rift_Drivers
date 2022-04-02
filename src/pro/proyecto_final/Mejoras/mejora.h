#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class mejora{
    private:
        bool check;
        int tipo, duracion;
        float bonus;
        sf::Clock reloj;
        
    public:
        mejora(int type, float bon, int dur);

        void setTipo(int tipo);
        int getTipo();

        void setDuracion(int dura);
        int getDuracion();

        void setBonus(float bon);
        float getBonus();

        void setReloj();
        float getReloj();

        void setCheck(bool val);
        bool getCheck();

        float aplicarMejora(float stat);
        float restaurarMejora(float stat);
};