/* 
 * File:       Calculator.h
 * Author:     Jonah Mamakeesic
 * Date:       January 5, 2019
 * Course:     Comp-3141
 * Assignment: Final Project
 */


#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator 
{
public:
    Calculator();
    ~Calculator();
    double add(double, double);
    double subtract(double, double);
    double multiply(double, double);
    double divide(double, double);
    double square(double);
    double squareRoot(double);
    virtual void printMenu();
    virtual void calculate(int);
};

#endif /* CALCULATOR_H */

