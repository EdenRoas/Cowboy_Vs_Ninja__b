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
    protected:
       int speed;
       int flag; // to know which type the ninja
       //string name;
    public:
        
        Ninja(const string &nameN ,const Point &location);
        void move(Character *enemy);
        void slash(Character *enemy);
        virtual string print();
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