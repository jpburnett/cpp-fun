//
//  main.cpp
//  circuit_problem
//
//  Created by Parker Burnett on 10/27/18.
//  Copyright © 2018 Parker Burnett. All rights reserved.
//
#include <time.h>

#include <iostream>


using namespace std;

// Function to sleep and delay the output for a second
void sleep(uint sleeptime){
    clock_t goal = sleeptime + clock();
    while (goal > clock());
}

// Prints the layout of a circuit board
void printCircuit(int r_val1, int r_val2) {
    cout << "  ______/\\/\\/\\_______" << endl;
    cout << "  |     " << r_val1 << " Ω       |\n";
    cout << "  |                 |\n";
    cout << "(+ -)             "<< r_val2 <<" Ω\n";
    cout << " 10V                |\n";
    cout << "  |                 |\n";
    cout << "  |_________________|\n";
}

int main() {
    // Initialize values for the resistors
    int r1 = 0, r2 = 0;
    
    cout << "Please enter value for R1: ";
    cin >> r1;
    cout << "Please enter value for R2: ";
    cin >> r2;
    
    cout << "Printing Circuit";
    sleep(1200000);
    cout << ".";
    sleep(1200000);
    cout << ".";
    sleep(1200000);
    cout << "." << "\n";
    sleep(1200000);
    printCircuit(r1, r2);
    
    return 0;
}
