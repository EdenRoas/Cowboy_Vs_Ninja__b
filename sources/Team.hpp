#include <iostream>
#include <vector>
#include <stdexcept>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "typeinfo"

#pragma once
using namespace std;

namespace ariel
{
    class Team 
    {
    protected:
        Character *leader;
        //Character team[10];
        vector<Character*> team;
        vector<Cowboy*> Cowboy_team;
        vector<Ninja*> Ninja_team;
        int team_counter;

       
    public:
        Team(Character *leader);
        //~Team();
        //void creat_team();
        void add (Character *player);
        void attack(Team *enemy);
        int stillAlive();
        virtual void print() ;
        //void virtual trans(Team *team);
        


       
        
    };

    class Team2 : public Team
    {
    private:
      
       
    public:
        Team2(Character *leader);
        //~Team2();
        void print() override;
        

    };


    class SmartTeam : public Team
    {
    private:
      
       
    public:
        SmartTeam(Character *leader);
        //~SmartTeam();
        void print() override;
        


       
        
    };

}