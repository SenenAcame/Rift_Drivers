#pragma once
#include "SFML/Graphics.hpp"
#include "menu_final.h"
#include "menu.h"

class menu_final : public Menu
{
private:
    sf::Font font;
    sf::Text final_opciones[2];
public:
    static menu_final* instance();
    void update(float deltaTime);
    menu_final(float width, float heigth);
    ~menu_final();
protected:
    //menu_final(float width, float heigth);
};