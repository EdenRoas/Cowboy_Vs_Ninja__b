#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
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
    private:
        int team_counter;
    
    protected:
        Character *leader;
        //Character team[10];
        vector<Character*> team_v;
        vector<Cowboy*> Cowboy_team;
        vector<Ninja*> Ninja_team;

       
    public:
        Team();
        Team(Character *leader);
        virtual ~Team();
         Team(const Team &other); //copy
        Team &operator=(const Team &other); //Copy assignment operator
        Team(Team &&other) noexcept; //Move constructor
        Team &operator=(Team &&other) noexcept; //Move assignment operator

        void add (Character *player);
        Character* new_leader(Team *team);
        Character* new_target(Team *enemy);
        void attack(Team *enemy);
        int stillAlive();
        virtual void print() ;
        //void virtual trans(Team *team);
        


       
        
    };

    class Team2 : public Team
    {
    private:
      
       
    public:
        //Team2() : Team(){}
        Team2(Character *leader);
        //~Team2();
        void attack(Team *enemy);
        void print() override;
        

    };


    class SmartTeam : public Team
    {
    private:
      
       
    public:
        SmartTeam(Character *leader);
        //~SmartTeam();      
        
    };

}