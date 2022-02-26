#pragma once

class MiModulo{
    
    public:
     MiModulo();

};

class NPC{
    float vel;
    float x, y, angle;

    public: 
        NPC(float vel, float x, float y, float angle);
        void setVel(float vel);
        float getVel();
        void setX(float x);
        float getX();
        void setY(float y);
        float getY();
        void setAngle(float angle);
        float getAngle();
};
