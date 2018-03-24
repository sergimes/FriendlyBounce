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

        Ball(float radi);

        //Destructors
        ~Ball();

        //Consultors
        float get_radi();

        //Modifiers
        void modify_radi(float radi);
};
