#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class ai
{
    private:
        sf::Sprite spr;
        float vel, x, y, angle;

    public: 
        ai(string load, float vel, float x, float y, float angle);
        void setSpr(string path);
        sf::Sprite getSpr();
        void setVel(float vel);
        float getVel();
        void setX(float x);
        float getX();
        void setY(float y);
        float getY();
        void setAngle(float angle);
        float getAngle();
};