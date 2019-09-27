/* 
 * File:       ScientificCalculator.h
 * Author:     Jonah Mamakeesic
 * Date:       January 5, 2019
 * Course:     Comp-3141
 * Assignment: Final Project
 */

#ifndef SCIENTIFICCALCULATOR_H
#define SCIENTIFICCALCULATOR_H

class ScientificCalculator : public Calculator 
{
public:
    ScientificCalculator();
    ~ScientificCalculator();
    double sine(double);
    double cosine(double);
    double tangent(double);
    virtual void printMenu();
    virtual void calculate(int);
};

#endif /* SCIENTIFICCALCULATOR_H */

