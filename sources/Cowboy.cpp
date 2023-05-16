
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
        if(isAlive() && NumOfBullets >= 0)
        {
            int temp = enemy->getPoints();
            temp -=10;
            this->NumOfBullets -=1;
        }
        return;
    }
    bool Cowboy::hasboolets()
    {   
        if (this->NumOfBullets > 0 )
            return true;
        return false;
    }
    void Cowboy::reload()
    {
        this->NumOfBullets += 6;
    }
    string Cowboy::print()
    {
        if (isAlive()) 
        return "--C--name: " + this->name+ "\npoints: " + to_string(this->points) + "\nlocation: " + this->location.print() + "\nNumOfBullets" + to_string(this->NumOfBullets) + "\n";
    return '(' + this->name + ')';  
    }   
        
 
}