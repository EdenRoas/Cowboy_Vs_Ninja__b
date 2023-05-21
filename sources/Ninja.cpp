#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    
    
    
    Ninja::Ninja(const string &nameN ,const Point &location, int life, int speed)  :  Character(nameN,location,life), speed(speed)
    {

        
    }
    
    void Ninja::move(Character *enemy)
    {
        this->location=this->location.moveTowards(this->location,enemy->getLocation(),this->speed);
    }
    void Ninja::slash(Character *enemy)
    {
        if(this==enemy){__throw_runtime_error("Self Damage");}   
        if (!enemy->isAlive()){__throw_runtime_error("The enemy is dead2");}
        
        if(isAlive())
        {
            if(this->distance(enemy) <= 1){enemy->hit(40);}            
        }
        
        else
            __throw_runtime_error("The ninja is dead");
    }
    string Ninja::print()
    {
        if (!isAlive()) 
        {
        return "--N--\nname: (" + name + ")\npos: " + location.print() + "\nSpeed: " +
               to_string(speed) + "\n";
        }   
        else {
        return "--N--\nname: " + name + "\nhitPoint: " + to_string(points) + "\npos: " + location.print() + "\nSpeed: " +
               to_string(speed) + "\n";
            }
    }
    OldNinja::OldNinja(const string &nameN ,const Point &location) : Ninja(nameN,location,150,8)
    {
           
    }
    

    YoungNinja::YoungNinja(const string &nameN ,const Point &location) :  Ninja(nameN,location,100,14)
    {
    }
   
    TrainedNinja::TrainedNinja(const string &nameN ,const Point &location) :  Ninja(nameN,location,120,12)
    {
    }
    

}