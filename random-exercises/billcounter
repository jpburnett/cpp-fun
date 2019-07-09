#include <iostream>
#include <iomanip>
using namespace std;

void numtender (int);

int main()
{
    int amount;

    cout << "Enter the amount to be tendered: " << endl;
    cin >> amount;
    numtender (amount);

    return 0;
}

void numtender (int amount)
{
    //Array of different denominations
    int den[] = {1, 5, 10, 20, 50, 100};
    int numOfBills;

    if (amount <= 0)

       return;
    cout << "Denomination details:" << endl;
    //Cycles though all the denominations
    for (int i = 5; i >= 0; i--)
    {
        // check if the ammount is greater than the denomination number
        if (amount >= den[i])
        {
            //numofbills will divide the amount by the denomination number in order to get the number of notes it will use
            numOfBills = amount / den[i];
            cout << setw (4) << den[i] << " x "
                 << setw (3) << numOfBills << " = "
                 << setw (8) << den[i] * numOfBills << endl;
            //Change the amount number to get the remainder through mod operator
            amount = amount % den[i];
            //Once there is no remaineder, break
            if (amount == 0)
                 break;
        }
    }
}
