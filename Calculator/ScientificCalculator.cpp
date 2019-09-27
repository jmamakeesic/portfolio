/* 
 * File:       ScientificCalculator.cpp
 * Author:     Jonah Mamakeesic
 * Date:       January 5, 2019
 * Course:     Comp-3141
 * Assignment: Final Project
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Calculator.h"
#include "ScientificCalculator.h"
using namespace std;

ScientificCalculator::ScientificCalculator(){}
ScientificCalculator::~ScientificCalculator(){}

double ScientificCalculator::sine(double x)
    {return sin(x*M_PI/180);}
double ScientificCalculator::cosine(double x)
    {return cos(x*M_PI/180);}
double ScientificCalculator::tangent(double x)
    {return tan(x*M_PI/180);}

// print scientific math calculation menu
void ScientificCalculator::printMenu(){
    cout << "----------------------\n"<<
            " 1) Sine\n" <<
            " 2) Cosine\n" <<
            " 3) Tangent\n" <<
            " 4) Basic Mode...\n" <<
            " 5) Exit\n" <<
            "----------------------\n";
}

// perform selection of scientific math calculations
void ScientificCalculator::calculate(int selection){
    long double x, y;
    ScientificCalculator calc;
    
    // get input value
    cout << "Enter a number: ";
    cin >> x;
    
    // print calculation result
    cout<<fixed<<setprecision(2);
    switch(selection){ 
        case 1: cout<<"sin("<<x<<") = "<<calc.sine(x)<<"\n\n";
                break;
        case 2: cout<<"cos("<<x<<") = "<<calc.cosine(x)<<"\n\n";
                break;
        case 3: cout<<"tan("<<x<<") = "<<calc.tangent(x)<<"\n\n";
                break;
    }
}


