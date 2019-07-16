#include <iostream>
#include <stack>

using namespace std;

int binaryToDecimal(int binaryNum){
  int decimalVal = 0; // decimal value initialized, this will be returned at the end
  
  int n = 1;  // helps determine the power of 2. (2^n)
  
  int temp = binaryNum;
  
  while(temp){
    int lastBit = temp % 10;
    temp = temp / 10;
    
    decimalVal += lastBit * n;
    n = n * 2;
  }
  
  return decimal Val;
}

void printStack(stack <int> s){
  while (!s.empty()){
    cout << s.top();
     s.pop();
    }
}

void decimalToBinary(int decimalNum){
  int binaryNum = 0;
  stack <int> s;  //stack to store the binary bits
  int temp = decimalNum
  
  while (temp){
    int bit = temp % 2;
    temp = temp / 2;
    
    s.push(bit);
  }
  
  printStack(s);
}

int main(){
  cout << "Binary to Decimal Converter \n";
  cout << "Enter binary number to convert (16 bits max): ";
  int userNum;
  cin >> userNum;
  
  int result = binaryToDecimal(userNum);
  
  cout << "Your number is: " << result << endl;
  
  cout << "Decimal to Binary Converter \n";
  cout << "Enter decimal number: ";
  int userdecimalnum;
  cin >> userdecimalnum;
  decimalToBinary(userdecimalnum);
  
  return 0;
}
