#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    
    
    
    Ninja::Ninja(const string &nameN ,const Point &location)  :  Character(nameN,location,10)
    {

        
    }
    
    void Ninja::move(Character *enemy)
    {
        this->location.moveTowards(this->location,enemy->getLocation(),this->speed);
    }
    void Ninja::slash(Character *enemy)
    {   
        
        if(isAlive() && this->distance(enemy) < 1)
        {
            enemy->hit(40);
        }
        return;
    }
    string Ninja::print()
    {
        if (isAlive()) 
        return "--N--name: " + this->name+ "\npoints: " + to_string(this->points) + "\nlocation: " + this->location.print() + "\n" + "\nspeed:" + to_string(this->speed);
    return '(' + this->name + ')';  
    }
    OldNinja::OldNinja(const string &nameN ,const Point &location): Ninja(nameN,location)
    {
           
    }
    

    YoungNinja::YoungNinja(const string &nameN, const Point &location) : Ninja(nameN,location)
    {
    }
   
    TrainedNinja::TrainedNinja(const string &nameN, const Point &location) :Ninja(nameN,location)
    {
    }
    

}