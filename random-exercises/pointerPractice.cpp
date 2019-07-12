#include <iostream>

int main(){
  std::cout << "Hello There! \n";
  
  int number = 420; // Just a normal ol' number
  std::cout << "number's address: " << &number << std::endl; // Print the address of number
  int *numPtr;  // defines an int pointer called numPtr, meaning it is capable of holding an address
  numPtr = &number; // numPtr gets the address of a number
  
  std::cout << "The address of number is: " << numPtr << std::endl; // Prints the address (This will change each time it is compiled)
  
  // Making sense of all this madness...
  
  int num1, num2; // Declare 2 ints
  int* somepointer; // Declare an int pointer, somepointer
  
  // Before changing things
  std::cout << "num1 is: " << num1 << std::endl;
  std::cout << "num2 is: " << num2 << std::endl;
  
  // Do some pointing
  somepointer = &num1;  // somepointer gets the address of num1
  *somepointer = 10;  // somepointer is dereferenced, and the value somepointer is pointing to is asigned to 10
  somepointer = &num2;  // somepointer gets the address of num2 (points to num2)
  *somepointer = 20;  // somepointer is dereferenced again, and the value it is pointing to (num2) is assigned 20
  
  // after changing things, see what you did
  std::cout << "num1 is: " << num1 << std::endl;
  std::cout << "num2 is: " << num2 << std::endl;
  
  // Working with arrays
  double values[10];  // Array values, with 10 elements
  double* pValues = values; // a pointer to the array, values
  std::cout << "Address of values array: " << values << std::endl;
  std::cout << "pValues: " << pValue << std::endl;
  
  return 0;
}
