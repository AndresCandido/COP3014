/* Name: Andres Candido
Date: 10/20/2020
Section: 6
Assignment: Homework 4
Due Date: 10/23/2020
About this project: I (being Patrick Star) will write three programs that will help me solve problems form my math class.
Assumptions: correct user input

All work below was performed by Andres Candido */

#include <iostream>
#include <cstdlib>       //need this for the rng --> srand and rand//
using namespace std;

int reverse(int a);              //introduce the two other functions before main//
int value(int b, int c, int d);

int main()
{
    int seed, num1, num2, reve, special, sum = 0;  //introduce all variables//
    cout<<"Enter the seed for the random number generator: ";
    cin>>seed;

    srand(seed);               //srand allows for selecting a seed for the rand//
    num1 = rand() % 10 + 15;   // "% 10 + 15" tells that the range of numbers is between 15 and 25//

    cout<<"Enter the numbers (0 to stop): ";

    while(num2 != 0)    //simple while loop for more inputs//
    {
        cin>>num2;
        reve = reverse(num2);              //here we use the reverse function//
        special = value(num1, num2, reve); //here we use the value function//
        sum=sum+special;                   //here is the sum of "special values"//
    }

    cout<<"The sum of the special values is: "<<sum<<endl;
    return 0;
}


int value(int b, int c, int d)
{
    int spvalue, absolute;
    absolute = abs(c-d);     //use abs to get the absolute value of c-d//
    spvalue = ( b * absolute); //gets special value//

    return spvalue;   // returns the special value to main, special value is then assigned to "special" variable//
}


int reverse(int a)
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