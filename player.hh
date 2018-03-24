#ifndef OBJECT_H
#define OBJECT_H

#include"object.hh"

#endif

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
        Player(int playerId, int windowWidth, int windowHeight);

        Player(int playerId, string playerName, int windowWidth, int windowHeight);

        Player(int playerId, string playerName, sf::Color color,  int windowWidth, int windowHeight);

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
