#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <string>

#pragma once
using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;
    public:
        //vector<string> ListOfPlayers;
        //Point();
       
        Point(double x_l , double y_r);
        //~Point();
        double distance(Point target);
        //string winner();
        string print();
        static Point moveTowards(Point start, Point finish ,double dis);
        
    };

}