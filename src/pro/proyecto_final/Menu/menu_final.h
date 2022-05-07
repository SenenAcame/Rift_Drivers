#pragma once
#include "SFML/Graphics.hpp"
#define NUM_OPCIONES 2

class menu_final
{
private:
    sf::Font font;
    sf::Text final_opciones[NUM_OPCIONES];
    int selected = 0;
    static menu_final* p_instance;
public:
    menu_final(float width, float heigth);
    void draw(sf::RenderWindow &window);
    void Mover_arriba();
    void Mover_abajo();
    int GetPressed() {return selected;}
};