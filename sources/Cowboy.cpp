
#include "Cowboy.hpp"
#include "Team.hpp"
using namespace std;

namespace ariel
{
    Cowboy::Cowboy(const string &nameC ,Point location) : Character(nameC,location,110) , NumOfBullets(6)
    {
        
    }
    void Cowboy::shoot(Character *enemy)
    {
        if(this==enemy){__throw_runtime_error("Self Damage");}
        if(!enemy->isAlive()){__throw_runtime_error("Enemy is dead1");}
        if(isAlive())
        {
            if(this->hasboolets())
            {
                enemy->hit(10);
                this->NumOfBullets -=1;
            }
        }
        else
            __throw_runtime_error("The cowboy is dead!");
    }
    bool Cowboy::hasboolets()
    {   
        if (this->NumOfBullets > 0 )
            return true;
        return false;
    }
    void Cowboy::reload()
    {
        if(!this->isAlive()){__throw_runtime_error("Dead cowboy can't reload");}
        this->NumOfBullets = 6;
    }
    string Cowboy::print()
    {
        if (isAlive()) 
        return "--C--name: " + this->name+ "\npoints: " + to_string(this->points) + "\nlocation: " + this->location.print() + "\nNumOfBullets" + to_string(this->NumOfBullets) + "\n";
    return '(' + this->name + ')';  
    }   
        
 
}