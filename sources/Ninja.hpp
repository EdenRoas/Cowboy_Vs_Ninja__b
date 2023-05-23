#include <iostream>
#include <vector>
#include <stdexcept>
#include "Character.hpp"
#pragma once
using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
    private:
       int speed;
       //int flag; // to know which type the ninja
       //string name;
    public:
        
        Ninja(const string &nameN ,const Point &location, int life, int speed);
        void move(Character *enemy);
        void slash(Character *enemy);
        int getspeed();
        string print() override;
    };

    class OldNinja : public Ninja
    {
        private:
        const int speed = 12;
       
        public:
        OldNinja(const string &nameN ,const Point &location);
        
        
    };

    class YoungNinja : public Ninja
        {
        private:
        const int speed = 14;
       
        public:
        YoungNinja(const string &nameN ,const Point &location);
         
        
        
    };
    class TrainedNinja : public Ninja
    {
        private:
        const int speed = 8;
       
        public:
        TrainedNinja(const string &nameN ,const Point &location);
        
    };

}
