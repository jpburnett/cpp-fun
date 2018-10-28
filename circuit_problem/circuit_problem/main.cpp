//
//  main.cpp
//  circuit_problem
//
//  Created by Parker Burnett on 10/27/18.
//  Copyright © 2018 Parker Burnett. All rights reserved.
//

#include <iostream>


using namespace std;

void printCircuit() {
    cout << "  ______/\\/\\/\\______+" << endl;
    cout << "  |       75Ω       |\n";
    cout << "  |                 Ω\n";
    cout << "(+ -)\n";
    cout << "  |\n";
    cout << "  |\n";
    cout << "  |_______________\n";
}

int main() {
    // insert code here...
    cout << "Printing Circuit:\n";
    printCircuit();
    
    clock_t start;
    int pause = 10000;
    
    for(int i = 0; i < 3; i++)
    {
        cout<< " . " << flush;
        start = clock();
        while( clock() < start + pause );
    }
    
    return 0;
}
