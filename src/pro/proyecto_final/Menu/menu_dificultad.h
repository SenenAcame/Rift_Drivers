#pragma once
#include "SFML/Graphics.hpp"
#define MAX_DIFICULTAD 3

class menu_dificultad
{
private:
    int selectedItem = 0;
    sf::Font font;
    sf::Text dificultad_opciones[MAX_DIFICULTAD];
    sf::Texture textura;
public:
    menu_dificultad(float width, float height);
    ~menu_dificultad();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItem;}
};
