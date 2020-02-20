//
//  main.cpp
//  project2
//
//  Created by Eliseo Garcia on 2/19/20.
//  Copyright © 2020 Eliseo Garcia. All rights reserved.
//

#include <iostream>
using namespace std;


double squareroot(double k){
    double eps = 1e-6;
    double l = 0.0;
    double r = 0.0;
    double mid = 0.0;
    
    if (k>=1)
    {
        r = k;
    }
    if (k<1)  {
        r = 1;
    }

    while (l-k/l > eps || l-k/l < -eps)
    {
        mid = l + (r - l) /2 ;
        if (mid<k/mid)
        {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return l;
}


double round(double num)
{
    double rndnum;
    double num2 = num * 100;
    int num3 = (int)num2;
    double dec3 = num2 - num3;
    
    if ((dec3*10) >= 5)
    {
        rndnum = ((int)((num)*100))/100.00 + 0.01;
    }
    else
    {
        rndnum= ((int)((num)*100))/100.00;
    }
    return rndnum;
}

template <class DataType> class Point //main point class that will be used to create and display points
{
protected:
    DataType x; // x point
    DataType  y; // y point
public:
    Point();    //default contructor
    Point(DataType xval, DataType yval); //contructor to take in a double value to set for x and a double value to take for y.
    void setLocation(DataType xval, DataType yval); //redefine the points
    DataType getXvalue(); //getter for the x value since it is protected
    DataType  getYvalue(); //getter for the y value sine it is protected
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
DataType Point<DataType>::getXvalue() //getter that will send back the x-value of the point
{
    return x; //returing x of the current point
}


template <class DataType>
DataType Point<DataType>::getYvalue() //getter that will send back the y-value of the point
{
    return y; // returning y of the current point
}


template <class DataType>
void Point<DataType>::display() //method to display the x and y values properly formatted
{
    cout << "(" << round(getXvalue()) << ", " << round(getYvalue()) << ")"; //printing out format
}


template <class DataType> class LineSegment
{
protected:
    Point<DataType>  P1; //Pointer to P1 that will set by user/file
    Point<DataType> P2; //Pointer to P2 that will set by user/file
public:
    LineSegment(); //default constructor for LineSegment
    LineSegment( Point<DataType> one,  Point<DataType> two); // contructor to build a linesegment from the two points
    DataType length(); //method to calculate the length of the linesegment
    Point<DataType> midpoint();//method to calculate the midpoint of the linesegment
    Point<DataType> xIntercept ();//method to calculate the x-intercept returns it as a point
    Point<DataType> yIntercept ();//method to calculate the y-intercept returns it as a point
    DataType slope();//method to calculate the slope and returns it as a double
    bool itIntersects (LineSegment L);//method that will check if the points intersect
    DataType min(DataType num1, DataType num2);//method to calculate the min of two numbers and returns it as a double
    Point<DataType> intersectionPoint (LineSegment L);//method that computes the intersection point and returns it as a point
    bool isParallel (LineSegment L); //method to determine wether two linesegments are parallel returns it as a boolean
    Point<DataType>  getP1(); //getter for P1 returns it as a point
    Point<DataType> getP2();// getter for P2 returns it as a point
    void displayEquation(); //method to correctly display the line segment's equation in slope-intercept form
};


template <class DataType>
LineSegment<DataType>::LineSegment() //default constructor
{
   P1 = NULL; //default null value
   P2 = NULL; //default null value
}

template <class DataType>
LineSegment<DataType>::LineSegment(Point<DataType> one, Point<DataType> two)//non-default constructor
{
    P1 = one; //setting P1 to one which is set from main
    P2 = two; //setting P2 to two which is set from main
}

template <class DataType>
DataType LineSegment<DataType>:: length() // method to calculate length of the linesegment
{
    //using the length formula from refrence
    DataType differenceOfX = P1.getXvalue() - P2.getXvalue(); //calculating x1 - x2
    DataType differenceOfY = P1.getYvalue() - P2.getYvalue(); // calculating y1 - y2
    DataType xSquared = differenceOfX * differenceOfX; // difference of X is squared
    DataType ySquared = differenceOfY * differenceOfY;// difference of Y is squared
    DataType length = squareroot(xSquared + ySquared);// taking the squareroot of X + Y which results in the length of linesegment
    return length; // returning the length of the linesegment
}

template <class DataType>
Point<DataType> LineSegment<DataType>:: midpoint() //method to calculate the midpoint
{
    //formula from refrence
    DataType xValue = ((P1.getXvalue() + P2.getXvalue())/ 2);//adding P1 xvalue and P2 xvalue and dividing by 2
    DataType yValue = ((P1.getYvalue() + P2.getYvalue()) / 2); //adding P1 yvalue and P2 yvalue and dividing by 2
    Point <DataType> midPoint(xValue, yValue); //creating the midpoint from the xValue and yValue
    return midPoint; //returning the midpoint
}

template <class DataType>
Point<DataType>  LineSegment<DataType>::xIntercept()//method to find the xIntercept
{
    //formula from refrence ((x1-y1) * (x2-x1)) / (y2-y1))
    DataType xIntercept = ((P1.getXvalue() - P1.getYvalue()) * ((P2.getXvalue() - P1.getXvalue())))/ (P2.getYvalue() - P1.getYvalue()); //((x1-y1) * (x2-x1)) / (y2-y1))
    Point<DataType> intercept(xIntercept, 0); //creating a new point where y is always equal to zero at the xIntercept
    return (intercept); //returning the point containing the xIntercept
}

template <class DataType>
Point<DataType> LineSegment<DataType>::yIntercept()//method to find to yIntercept
{
    //using formula from refrence to obtain the yIntercept = y1 - slope * x1
    DataType yIntercept = P1.getYvalue() - (slope()) * P1.getXvalue(); // multiplying slope by x1 and then subtracting from y1
    Point<DataType> intercept (0, yIntercept); //creating new point for yIntercept where x is always zero;
    return (intercept); //dereferencing yIntercept and returning it
}

template<class DataType>
DataType LineSegment<DataType>::slope()//method to find the slope
{
    //using formula from refrence to find slope y2 - y1 / x2 - x1
    DataType differenceInY = P2.getYvalue() - P1.getYvalue();// difference in y2 - y1
    DataType differenceInX = P2.getXvalue() - P1.getXvalue();// difference in x2 - x1
    DataType slope = differenceInY / differenceInX; // obtain the slope y2 - y1 / x2 - x1
    return slope; //returns double containing slope
}


template<class DataType>
bool LineSegment<DataType>::itIntersects(LineSegment L)//method to determine wether two LineSegments intersect
{
    //used formula found in reference
    //creating vectors m and n by obtaing the length of the vector from the P1P2  and P1Q1
    DataType d1u1 = P2.getXvalue() - P1.getXvalue();//P2 xvalue - P1 xvalue which will be u1 for vector m
    DataType d1v1 = P2.getYvalue() - P1.getYvalue();//P2 yvalue - P1 yvalue which will be v1 for vector m
    DataType d1u2 = L.P1.getXvalue() - P1.getXvalue();//P3 xvalue - P1 xvalue which will be u2 for vector n
    DataType d1v2 = L.P1.getYvalue() - P1.getYvalue();//P3 yvalue - P1 yvalue which will be u2 for vecotr n
    DataType d1 = ((d1u1) * (d1v2) - ((d1u2 * (d1v1)))); //calculating the determinant and assinging the value to d1
    
    DataType d2u1 = P2.getXvalue() - P1.getXvalue();//P2 xvalue - P1 xvalue which will be u1 for vector m
    DataType d2v1 = P2.getYvalue() - P1.getYvalue();//P2 yvalue - P1 yvalue which will be v1 for vector m
    DataType d2u2 = L.P2.getXvalue() - P1.getXvalue();//P4 xvalue - P1 xvalue which will be u2 for vector n
    DataType d2v2 = L.P2.getYvalue() - P1.getYvalue();//P4 yvalue - P1 xvalue which will be v2 for vector n
    DataType d2 = ((d2u1) * (d2v2) - ((d2u2 * (d2v1)))); //calculating the determinant and assinging the value to d2
  
    DataType d1d2 = d1 * d2; //multiplying d1 and d2 in order to test for d1d2 <= 0;
    
    DataType d3v1 = L.P2.getYvalue() - L.P1.getYvalue();//P4 yvalue - P3 yvalue which will be v1 for vector m
    DataType d3u1 = L.P2.getXvalue() - L.P1.getXvalue();//P4 vvalue - P3 vvalue which will be u1 for vector m
    DataType d3v2 = P1.getYvalue() - L.P1.getYvalue();//P1 yvalue - P3 yvalue which will be v2 for vector n
    DataType d3u2 = P1.getXvalue() - L.P1.getXvalue();//P1 xvalue - P3 xvalue which will be u2 for vector n
    DataType d3 = ((d3u1) * (d3v2) - ((d3u2 * (d3v1)))); //calculating the determinant and assinging the value to d3
    
    DataType d4v1 = L.P2.getYvalue() - L.P1.getYvalue();//P4 yvalue - P1 yvalue which will be v1 for vector m
    DataType d4u1 = L.P2.getXvalue() - L.P1.getXvalue();//P4 xvalue - P1 xvalue which will be u1 for vector m
    DataType d4v2 = P2.getYvalue() - P1.getYvalue();//P2 yvalue - P1 yvalue which will be v2 for vector n
    DataType d4u2 = P2.getXvalue() - P1.getXvalue();//P2 xvalue - P1 xvalue which will be u2 for vector n
    DataType d4 = ((d4u1) * (d4v2) - ((d4u2 * (d4v1)))); //calculating the determinant and assinging the value to d3
    
    DataType d3d4 = d3 * d4;//multiplying d2 and d4 in order to test for d1d2 <= 0;
    
   
    if((d1d2 <= 0) && (d3d4 <= 0 )) // if true than lines intersect (per formula)
    {
           return true; //retruning true
    }
    else if(this->intersectionPoint(L).getXvalue() < min(P1.getXvalue(), L.P1.getXvalue())) //checking if the xValue is on the linesegment, if not than false they don't intercept
    {
           return false; //returning false
    }
    else//all other cases return false
    {
        return false; //returning false
    }
    
    
}

template<class DataType>
DataType LineSegment<DataType>::min(DataType num1, DataType num2)//method to find the largest number between two numbers
{
    if(num1 > num2) //if num1 is greater than num2
    {
        return num2;//return num2 since it is smaller
    }
    else//num1 is smaller
    {
        return num1;//return num1 since it is smaller
    }
}

template <class DataType>
Point<DataType> LineSegment<DataType>::intersectionPoint (LineSegment L)//method to determine and return the intersection point
{
    //formula found in refrence x = (c2 - c1)/ / (m2-m1) and y = (c1m2 - c2m1) / (m2-m1)           where c = yIntercept and m = slope
    DataType xValue = ((L.yIntercept().getYvalue() - this->yIntercept().getYvalue()) / (this->slope() - L.slope()));// obtining x value by computing (c2 - c1)/ / (m2-m1)
    DataType yValue = (((this->yIntercept().getYvalue() * L.slope()) - (L.yIntercept().getYvalue() * this->slope())) / ((L.slope()) - this->slope())); // obtaining y value (c1m2 - c2m1) / (m2-m1)
    Point<DataType> intersection(xValue, yValue); //creating new point from xValue and yValue
    return (intersection);//returning the intersection point
}


template <class DataType>
bool LineSegment<DataType>::isParallel (LineSegment L) //method to determine whether two lineSegments are parallel
{
     if((*this).slope() == L.slope()) //if the two linesegments have the same slope than return true they do intercept
       {
           return true; //returing true they intercept
       }
       else //all other cases
       {
           return false; //returning false they do not intercept
       }
}

template<class DataType>
Point<DataType> LineSegment<DataType>:: getP1() //getter to be able to obtain P1
{
    return (P1); //dereferencing P1 and returning it
}


template<class DataType>
Point<DataType> LineSegment<DataType>:: getP2()//getter to be able to obtain P2
{
    return (P2);//dereferencing P2 and returning it
}


template<class DataType>
void LineSegment<DataType>::displayEquation() //method to display the slope intercept form line
{
    cout << "y=" << round(slope()) << "*x+" << round(yIntercept().getYvalue()) << endl; // proper format to display y=mx+c
}






int main()
{

    Point<double> p(0.0, 0.0);
    Point<double> q(5.23, 5.23);

    Point<double> r(0.0, 5.23);
    Point<double> s(5.23, 0.0);
    
    Point<double> t(0.0, 5.23);
    Point<double> u(5.23, 0.0);
    
    LineSegment<double> l (p, q);
    LineSegment<double> m(r,s);
    LineSegment<double> n(t,u);
    
    l.xIntercept().display();
    l.yIntercept().display();
    cout << endl;
    double length = l.length();
    cout << length << endl;
    l.midpoint().display();
    bool d = l.isParallel(m);
    cout << d << endl;
    
    
    l.intersectionPoint(m).display();
    
   

    
    
    
    
}
