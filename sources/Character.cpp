
#include "Character.hpp"
using namespace std;

namespace ariel
{
    //default constractor
    Character::Character() : location(0,0), points(0)
    {

    }
    //another constractor
    Character::Character(const string &name, const Point &location,  unsigned int points) : name(name), location(location),points(points) 
    {
        
    }
    //distructor
    Character::~Character()
    {

    }
    //check if the player still alive
    bool Character::isAlive()
    {
        if (this->points == 0)
            return false;
        return true;
    }
    //return the num of points
    int Character::getPoints()
    {
        return (int)(this->points);
    }
    //return the distance from another player
    double Character::distance(Character *other)
    {   
        return this->location.distance(other->location);
    }
    void Character::hit(unsigned int number)
    {   

        this->points -= number;
    }
    string Character::getName()
    {
        return this->name;
    }
    
    Point Character::getLocation()
    {   
        
        return this->location;
    }
    string Character::print()
    {
        if (isAlive()) 
        return "name: " + this->name + "\npoints: " + to_string(this->points) + "\nlocation: " + this->location.print() + "\n";
    return '(' + name + ')';    
    
    }


       
        
 

}