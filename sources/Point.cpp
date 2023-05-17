
#include "Point.hpp"
using namespace std;

namespace ariel
{
        //Point p(1,1);
        
        Point::Point(double x_l , double y_r) :  x(x_l), y(y_r)
        {
          this->x = x_l;
          this->y = y_r;  
        }
        //Point::~Point(){}
        double Point::distance(Point p)
        {   
            return (sqrt(pow(this->x - p.x,2)+(pow(this->y - p.y,2))));
           
        }
        
        // string Point::winner()
        // {
        //     return "";
        // }
        string Point::print()
        {
           return "("+ to_string(this->x) + ","  + to_string(this->y) + ")";
        }
        Point Point::moveTowards(Point src, Point dst, double dist)
        {   
            if(dist<0)
            __throw_invalid_argument("dis cannot be negative");
            double pointsDistance=src.distance(dst);
            if(pointsDistance<=dist){return dst;}
            double ratio = dist / pointsDistance;
            double newX = (src.x*(1 - ratio)) + (ratio * dst.x);
            double newY = (src.y*(1 - ratio)) + (ratio * dst.y);
            return Point(newX,newY);
        }
        

}