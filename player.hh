#include"object.hh"
#include<Color.hpp>
#include<string>

using namespace std;

class Player : public Object {
    private:
        int id; //The player's id
        string name; //The player's name
        unsigned int points; //The player's points
        sf::Color color;

    public:
        //Constructors
        Player(int playerId);

        Player(int playerId, string playerName);

        Player(int playerId, string playerName, sf::Color color);

        //Destructor
        ~Player();

        //Consultors
        int getId();

        string getName();

        int getPoints();

        //Modifiers
        void setId(int newId);

        void setName(string newName);

        void setPoints(int newPoints);

        void setColor(sf::Color newColor);

        void incPoints(int increase);
};
