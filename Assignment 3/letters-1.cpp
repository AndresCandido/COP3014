
/* Name: Andres Candido
Date: 10/9/2020
Section: 6
Assignment: Homework 3
Due Date: 10/9/2020
About this project: I will be creating a program that can print P, O, AND J in ASCH art and loops if desired.
Assumptions: correct user input.

All work below was performed by Andres Candido */

#include <iostream>
using namespace std;
int main() {

    char again = 'Y';    //Since the entire program is a big loop I had to make the default condition true to make it run for the first time.

    do{
        int size;
        cout<<"Enter the size: ";
        cin>>size;


        if (size <= 6 || size%2 ==0 || size%10 ==0)         //This if statement and loop are for checking valid inputs of size.
        {
            do{cout<<"Invalid input. Enter size: ";
                cin>>size;}while(size <= 6 || size/2 ==0 || size%10 ==0);
        }

        int half = (size-1) / 2;  //it was easier to use some of the if statements with this variable rather than using equations with the "size" variable.

        char letter;
        cout<<"Enter the letter: ";
        cin>>letter;

        if (letter != 'P' && letter != 'O' && letter != 'J')   //This if statement and loop are for checking valid inputs of letters.
        {
            do{cout<<"Invalid input. Enter letter: ";
                cin>>letter;}while(letter != 'P' && letter != 'O' && letter != 'J');
        }


        if (letter == 'P')         // one of the possible letter input cases. the for loops are the same in all of them to create the grid.
        {                                   // But the if statements are different in each in order to write the symbols in a specific arrangement.
            for(int i = 0; i < size; ++i)
            {
                for(int j = 0; j < size; ++j)
                {
                    if (i==0 || j==0)                      // These are the lines and columns that will become "*"
                    {cout<<"*"<<" ";}

                    else if ( i == half)
                    {cout<<"*"<<" ";}

                    else if ( i <= half && j == size-1)
                    {cout<<"*"<<" ";}

                    else cout<<"  ";
                }
                cout<<endl;
            }
        }

        else if (letter == 'O')
        {
            for(int i = 0; i < size; ++i)
            {
                for(int j = 0; j < size; ++j)
                {
                    if (i==0 || j==0)
                    {cout<<"*"<<" ";}

                    else if (i == size-1)
                    {cout<<"*"<<" ";}

                    else if (j == size-1)
                    {cout<<"*"<<" ";}

                    else cout<<"  ";
                }
                cout<<endl;
            }
        }

        else if (letter == 'J')
        {
            for(int i = 0; i < size; ++i)
            {
                for(int j = 0; j < size; ++j)
                {
                    if (i==0)
                    {cout<<"*"<<" ";}

                    else if ( j == half)
                    {cout<<"*"<<" ";}

                    else if ( j <= half && i == size-1)
                    {cout<<"*"<<" ";}

                    else cout<<"  ";
                }
                cout<<endl;
            }
        }


        cout<<"Do you want to continue? (Y / N): ";
        cin>>again;

        if (again != 'Y' && again != 'N')
        {
            do{cout<<"Invalid input. Do you want to continue? (Y / N): ";
                cin>>again;}while(again != 'Y' && again != 'N');
        }

    }while(again == 'Y');   // condition for the big loop to repeat, if "Y" start again, if "N" print exit message.


    cout<<endl;
    cout<<"Goodbye."<<endl;


    return 0;
}
