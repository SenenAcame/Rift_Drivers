#include <iostream>>

class menu_empezar : public menu {
    public:
        static menu_empezar* instance();
        void update(float deltaTime);
};