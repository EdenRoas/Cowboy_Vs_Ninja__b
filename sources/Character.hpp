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
        Point location;
        string name;
        unsigned int points; 
       
    public:
        //vector<string> ListOfPlayers;
       Character();
       Character(const string &name, const Point &place, int points);
       virtual ~Character();
       bool isAlive();
       int getPoints();
       double distance(Character &other);
       void hit(int number);
       string getName();
       Point getLocation();
       string virtual print();


       
        
    };

}