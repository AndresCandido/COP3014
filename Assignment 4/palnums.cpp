/* Name: Andres Candido
Date: 10/20/2020
Section: 6
Assignment: Homework 4
Due Date: 10/23/2020
About this project: I (being Patrick Star) will write three programs that will help me solve problems form my math class.
Assumptions: correct user input, assume range of x is correct (-3.14 to 3.14), n is always positive.

All work below was performed by Andres Candido */

#include <iostream>
using namespace std;

int reverse(int a);   //reused function from previous program//
void printPalin(int a, int b); //new void function for getting palindromes//

int main()
{
    int x, y;
    cout<<"Enter the number of digits: ";
    cin>>x;

    while(x<1 || x>9)    //loop to check for correct digit input//
    {
        cout<<"Invalid number of digits (must be from 1 to 9)"<<endl;  // required error message //
        cout<<"Enter the number of digits: ";
        cin>>x;
    }

    cout<<"Enter the factor: ";
    cin>>y;

    while(y<1)   //loop to check for correct factor input//
    {
        cout<<"Invalid factor (must be greater than 1)"<<endl;   // required error message //
        cout<<"Enter the factor: ";
        cin>>y;
    }

    cout<<"The even "<<x<<"digit palindrome numbers that are multiples of "<<y<<" are:"<<endl;
    printPalin(x, y);  //Call void function to output palindromes//


    return 0;
}

void printPalin(int a, int b) //palindrome function//
{
    int i, o;
                          //Since I assured correct user input, I determined the required parameters for each possible -->//
    if (a==1) i=1, o=9;    //--> case for x (which becomes a in this function) to avoid wasting cpu power//
    else if (a==2) i=10, o=99;
    else if (a==3) i=100, o=999;
    else if (a==4) i=1000, o=9999;
    else if (a==5) i=10000, o=99999;
    else if (a==6) i=100000, o=999999;
    else if (a==7) i=1000000, o=9999999;
    else if (a==8) i=10000000, o=99999999;
    else if (a==9) i=100000000, o=999999999;

    for(i=i; i<=o; ++i)
    {
        int reve;
        reve = reverse(i); //Call the reverse function to get the reverse of i//

        if(i==reve && i%b==0) //if i is even and equal to its reverse it gets printed out//
        {
            cout<<i<<endl;
        }
    }

}


int reverse(int a)   //function from previous program//
{
    int rem, rev = 0;
    while(a!=0)           //loop used to to get the reverse of a number//
    {
        rem = a%10;            //gets remainder of a//
        rev = rev*10 + rem;    //gets the reverse of a number//
        a /= 10;
    }

    return rev;  //returns reverse to main, reverse is then assigned to "reve" variable//
}