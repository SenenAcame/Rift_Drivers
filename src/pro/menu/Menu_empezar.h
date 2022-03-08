#pragma once
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_CIRCUITS 3
class Menu_empezar
{
    public:
        Menu_empezar(float width, float height);
        ~Menu_empezar();

        void draw(sf::RenderWindow &window);
        
    private:
        int selectedItem = 0;
        sf::Font font;
        sf::Text circuitos[MAX_NUMBER_CIRCUITS];
    
};
