#include <iostream>
#include <vector>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include "Point.hpp"

#pragma once
using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        bool is_play;
        Point location;
        string name;
        int points;

    public:
        // vector<string> ListOfPlayers;
        Character();
        Character(const Character &other);
        Character &operator=(const Character &other);     // Copy assignment operator
        Character(Character &&other) noexcept;            // Move constructor
        Character &operator=(Character &&other) noexcept; // Move assignment operator
        Character(const string &name, const Point &place, int points);
        virtual ~Character();
        void change();
        bool isAlive();
        int getPoints();
        bool get_playing();
        double distance(Character *other);
        void hit(int number);
        string getName();
        Point getLocation();
        string virtual print();
    };

}