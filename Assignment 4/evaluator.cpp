/* Name: Andres Candido
Date: 10/20/2020
Section: 6
Assignment: Homework 4
Due Date: 10/23/2020
About this project: I (being Patrick Star) will write three programs that will help me solve problems form my math class.
Assumptions: correct user input, assume range of x is correct (-3.14 to 3.14), n is always positive.

All work below was performed by Andres Candido */

#include <iostream>
#include <iomanip>           //include iomanip to show the desired decimal pointin output//
#include <cmath>             //include cmath for pow,cos and abs functions//
using namespace std;

double factorial(double a);     //introduce the two functions I made//
double sum(double b, double c);

int main()
{
    double x, n, cosx;       //introduce variables//
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<"Enter the number of terms: ";
    cin>>n;

    cosx = sum(x, n);       //use the "sum" function with te variables//
    cout<<fixed<<showpoint<<setprecision(6)<<"cos("<<x<<") = "<<cosx<<endl; //setprecision for 6th decimal place//

    double pi=3.14159265359, y, cmathcos;   //get margin of error by comparing my cosine with cmath's//
    y = cos (x*pi/180);
    cmathcos = abs(cosx-y);   //use abs just in case of getting a negative difference//
    cout<<fixed<<showpoint<<setprecision(6)<<"Margin of error: "<<cmathcos<<endl;
             //my margin of error might be different to the one in the sample due to the number of decimals in pi//

    return 0;
}


double factorial(double a)
{
    double fac = 1;
    for(int i=1; i<=a; ++i)   //loop to get the factorial by multiplying all numbers until a//
    {
        fac = fac * i;
    }

    return fac; //returns the factorial of number a to main//
}

double sum(double b, double c) //b becomes x and c becomes n when function is called in main//
{
    double cosine=0;
    for(int i=0; i<=c; ++i)    //this loop represents all the values of k in the Mclaurin series expansion equation//
    {
        double num, denom, right;
        num = pow(-1, i);   //numerator (-1)^k //
        denom = factorial(2*i); //denominator (2k)! , which uses the factorial function//
        right = pow(b, 2*i); //Right to the numerator and denominator = X^2k//
        cosine = cosine + ((num/denom)*right);  //adds u all the values depending on the terms//
    }
    return cosine;  //returns my value for cosine to main//
}