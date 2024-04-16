
/* Name: Andres Candido
Date: 10/9/2020
Section: 6
Assignment: Homework 3
Due Date: 10/9/2020
About this project: I will write a program able to find the coprimes of all numbers bellow the user's input.
Assumptions: correct user input.

All work below was performed by Andres Candido */

#include <iostream>
using namespace std;

int main() {

    int input;

    cout<<"Enter a number: ";
    cin>>input;
    cout<<"The coprime numbers are (No factors equals coprime number): "<<endl;

    if (input >= 2 && input <= 2147483647)    // set parameters for valid user input.
    {

        for (int i = 2; i < input; i++ )    //First loop to set output in columns.
        { cout<<i<<" - ";

                for(int f=2; i <= input && f <= i; ++f) //second loop for the factor rows.
                {
                    if(input%f==0 && i%f==0) //parameter for determining if f is a common factor.
                    {
                        cout<<f<<", ";             //output of common factors.
                    }

                }
                cout<<endl;
        }
    }

    else if (input < 2){ cout<<"Number is too small. Goodbye.";} //cases for wrong user inputs

    else cout<<"Number is too big. Goodbye.";


    return 0;
}
