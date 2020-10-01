/* 
 * File:       Calculator.cpp
 * Author:     Jonah Mamakeesic
 * Date:       January 5, 2019
 * Course:     Comp-3141
 * Assignment: Final Project
 */

#include <cmath>
#include <iostream>
#include <iomanip>
#include "Calculator.h"
using namespace std;

Calculator::Calculator(){}
Calculator::~Calculator(){}

double Calculator::add(double x, double y) //For adding
    {return (x+y);}
double Calculator::subtract(double x, double y)//For subtracting
    {return (x-y);}
double Calculator::multiply(double x, double y)//For multiplying
    {return (x*y);}
double Calculator::divide(double x, double y)//For dividing
    {return (x/y);}
double Calculator::square(double x)//For square
    {return (x*x);}
double Calculator::squareRoot(double x)//For squareroot
    {return (sqrt(x));}
double Calculator::modulus(double x, double y)//For remainder
    {return (x%y);}

//print basic math calculation menu
void Calculator::printMenu(){
    std::cout<< "----------------------\n"<<
                " 1) Addition\n" <<
                " 2) Subtraction\n" <<
                " 3) Multiplication\n" <<
                " 4) Division\n" <<
                " 5) Square\n" <<
                " 6) Square Root\n" <<
                " 7) Scientific Mode...\n" <<
                " 8) Exit\n" <<
                "----------------------\n";
}

// perform selection of basic math calculations
void Calculator::calculate(int selection){
    double x, y;
    Calculator calc;
    cout<<fixed<<setprecision(2);
    
    // get appropriate number of input values
    if (selection<5){
        cout << "Enter two numbers: ";
        cin >> x >> y;
    }else{
        cout << "Enter a number: ";
        cin >> x;
    }
    
    // print calculation result
    switch(selection){ 
        case 1: cout<<x<<" + "<<y<<" = "<<calc.add(x,y)<<"\n\n";
                break;
        case 2: cout<<x<<" - "<<y<<" = "<<calc.subtract(x,y)<<"\n\n";
                break;
        case 3: cout<<x<<" * "<<y<<" = "<<calc.multiply(x,y)<<"\n\n";
                break;
        case 4: cout<<x<<" / "<<y<<" = "<<calc.divide(x,y)<<"\n\n";
                break;
        case 5: cout<<x<<"^2 = "<<calc.square(x)<<"\n\n";
                break;
        case 6: cout<<"sqrt("<<x<<") = "<<calc.squareRoot(x)<<"\n\n";
                break;
    }
}
