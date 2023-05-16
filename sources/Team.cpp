
#include "Team.hpp"


using namespace std;

namespace ariel
{

      
    Team::Team(Character *leader)
    {
        this->leader = leader;
    }

    //void Team::creat_team(){}
    void Team::add (Character *player){
        if(team.size()< 10)
        {
            if(Ninja *n = dynamic_cast<Ninja*>(player))
            {
                Ninja_team.push_back(n);
            }
            if(Cowboy *c = dynamic_cast<Cowboy*>(player))
            {
                Cowboy_team.push_back(c);
            }
            team.push_back(player);
            team_counter++;
        } 
        runtime_error(" The team is full");
    }
    void Team::attack(Team *enemy){ //not finish
        if(!enemy->leader->isAlive())
        {
            
        }
        if(team_counter != 0){
            --enemy->team_counter;
        }

    }
    int Team::stillAlive()
    {
        return team_counter;
    }
    void Team::print() 
    {   
        for (auto c : Cowboy_team)
            cout <<"--C--name: " << c->getName() << "\npoints: " << to_string(c->getPoints()) << "\nlocation: " << c->getLocation().print() << "\n"<< endl;
        for (auto n : Ninja_team)  
            cout << "--N--name: " << n->getName()+ "\npoints: " << to_string(n->getPoints()) << "\nlocation: " << n->getLocation().print() << "\n" << endl;
 
    }
    
        

    Team2::Team2(Character *leader): Team(leader){
                
        }
        //Team2::~Team2(){}
        void Team2::print(){
            //   for(auto p : team)
            //   {
            //     if(typeid(p) == typeid(Ninja))
            //         return "--N--name: " + this->name+ "\npoints: " + to_string(this->points) + "\nlocation: " + this->location.print() + "\n";
            //     if(typeid(p) == typeid(Cowboy))
            //         return "--C--name: " + this->name+ "\npoints: " + to_string(this->points) + "\nlocation: " + this->location.print() + "\n";
            //   }

        }


       
        
  
    SmartTeam::SmartTeam(Character *leader) : Team(leader)
        {

        }
        //SmartTeam::~SmartTeam(){}
        void SmartTeam::print(){
          
        }
        
};