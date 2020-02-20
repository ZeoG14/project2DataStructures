//
//  main.cpp
//  project2
//
//  Created by Eliseo Garcia on 2/19/20.
//  Copyright © 2020 Eliseo Garcia. All rights reserved.
//

#include <iostream>
using namespace std;

template <class DataType>
class Point //main point class that will be used to create and display points
{
protected:
    DataType x; // x point
    DataType y; // y point
public:
    Point();    //default contructor
    Point(DataType xval, DataType yval); //contructor to take in a double value to set for x and a double value to take for y.
    void setLocation(DataType xval, DataType yval); //redefine the points
    DataType& getXvalue(); //getter for the x value since it is protected
    DataType&  getYvalue(); //getter for the y value sine it is protected
    DataType& data();
    void display(); //method to display the current point
};


template <class DataType>
Point<DataType>::Point()//default constructor
{
    x = NULL; //defualt empty x-value
    y = NULL; //default empty y-value
}


template <class DataType>
Point<DataType>::Point(DataType xval, DataType yval)//contructor to set the x and y values
{
    x = xval; //setting x to xval which is set from main
    y = yval; //setting y to yval whihc is set from main
}


template <class DataType>
void Point<DataType>::setLocation(DataType xval, DataType yval) //method to redefine the point
{
    x = xval; //setting x to xval whichd is set from main
    y = yval; //setting y to yval whihc is set from main
}


template <class DataType>
DataType& Point<DataType>::getXvalue() //getter that will send back the x-value of the point
{
    return x; //returing x of the current point
}


template <class DataType>
DataType& Point<DataType>::getYvalue() //getter that will send back the y-value of the point
{
    return y; // returning y of the current point
}


template <class DataType>
void Point<DataType>::display() //method to display the x and y values properly formatted
{
    cout << "(" << getXvalue() << ", " << getYvalue() << ")"; //printing out format
}







int main() {

    
}
