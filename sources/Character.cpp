
#include "Character.hpp"
using namespace std;

namespace ariel
{
    //default constractor
    Character::Character() : location(0,0), points(0), is_play(false)
    {

    }
    //another constractor
    Character::Character(const string &name, const Point &location, int points) : name(name), location(location),points(points), is_play(false)
    {
        
    }
    //distructor
    Character::~Character()
    {

    }
    void Character::change(){
        this->is_play = true;
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
    bool Character::get_playing()
    {
        return this->is_play;
    }
    //return the distance from another player
    double Character::distance(Character *other)
    {   
        return this->location.distance(other->location);
    }
    void Character::hit(int number)
    {   
        if(number < 0 )
                __throw_invalid_argument("The hit cannot be negative!!");
        this->points -= number;
        if(this->points <= 0)
        {
            this->points = 0;
            this->is_play = false;
        }
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