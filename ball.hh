#ifndef OBJECT_H
#define OBJECT_H

#include "object.hh"

#endif

class Ball : public Object {
    private:
        float radi;

    public:
        //Constructors
        Ball();

        Ball(float radi, int windowWidth, int windowHeight);

        Ball(float radi, float x, float y);

        //Destructors
        ~Ball();

        //Consultors
        float get_radi();

        std::pair<float,float> get_center();

        //Modifiers
        void modify_radi(float radi);
};
