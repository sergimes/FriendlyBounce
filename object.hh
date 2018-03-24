#include <SFML/Graphics.hpp>
#include <utility>

class Object {

    protected:
        float h, w; //Size (h,w)
        float x, y; //Positions (x,y)
        float vx, vy; //Velocity
        float ax, ay; //Acceleration
        sf::Color color; //Color


    public:
        //Constructors
        Object();

        Object(float h, float w, float x, float y, float vx, float vy, float ax, float ay, sf::Color color);

        //Destructor
        ~Object();

        //Consultors
        std::pair<float,float> get_size();

        float get_h();

        float get_w();

        std::pair<float,float> get_position();

        float get_x();

        float get_y();

        std::pair<float,float> get_velocity();

        float get_vx();

        float get_vy();

        std::pair<float,float> get_acceleration();

        float get_ax();

        float get_ay();

        sf::Color get_color();

        //Modifiers
        void modify_position(float x, float y);

        void modify_x(float x);

        void modify_y(float y);

        void modify_velocity(float vx, float vy);

        void modify_vx(float vx);

        void modify_vy(float vy);

        void modify_acceleration(float ax, float ay);

        void modify_ax(float ax);

        void modify_ay(float ay);

        void modify_color(sf::Color color);
};
