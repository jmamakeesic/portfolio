/* 
 * File:       main.cpp
 * Author:     Jonah Mamakeesic
 * Date:       January 5, 2019
 * Course:     Comp-3141
 * Assignment: Final Project
 */

#include "Calculator.h"                               
#include "ScientificCalculator.h"
#include <iostream>                                    //including header files

using namespace std;

int main() {                                           //driver function
    Calculator basicCalc;
    ScientificCalculator sciCalc;
    Calculator* calc = &sciCalc;
    int selection, calcType, switchType, exit;
    const int BASIC=1, SCI=2;
    
    cout << "\nWelcome to Calculator!\n";               //calculator menu
    cout << "----------------------\n" <<
            " 1) Basic\n" <<
            " 2) Scientific\n" <<
            "----------------------\n" <<
            "Choose a Calculator: ";
    
    // choose initial calc type, validate choice
    while (true){
        cin >> calcType;
        cin.clear();
        cin.ignore();
        if ((calcType!=BASIC && calcType!=SCI) || cin.fail()){
            cout << "Invalid entry. Try again: ";
        }else break;
    }
    
    // repeat until exit
    while(true){
        // setup calc type
        if (calcType==BASIC){
            calc = &basicCalc;
            switchType = 7;
            exit = 8;
        }else if (calcType==SCI){
            calc = &sciCalc;
            switchType = 4;
            exit = 5;
        }
        
        calc->printMenu();
        cout << "Enter a selection: ";
        
        // repeat selection input until valid
        while(true){
            cin >> selection;
            cin.clear();
            cin.ignore();
            cout << endl;
            
            // validate selection
            if (selection<1 || selection>exit || cin.fail()){
                cout << "Invalid entry. Try again: ";
            // switch calculator mode
            }else if (selection==switchType){
                calcType = ((calcType==BASIC)? SCI:BASIC);
                break;
            // quit program
            }else if (selection==exit){
                return 0;
            // perform calculation
            }else{
                calc->calculate(selection);
                break;
            }
        }
    }
}
