#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Character.hpp"
#pragma once
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
    int NumOfBullets;
       
    public:
    
    
    Cowboy(const string &nameC ,Point location);
    void shoot(Character *enemy);
    bool hasboolets();
    void reload();
    string print()override;
       
        
    };

}