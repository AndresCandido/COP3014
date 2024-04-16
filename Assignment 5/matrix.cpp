/* Name: Andres Candido
Date: 11/6/2020
Section: 6
Assignment: Homework 5
Due Date: 11/6/2020
About this project: I will be making a matrix that allows the user to add elements and prints the L21 norm.
Assumptions: correct user input

All work below was performed by Andres Candido */

#include <iostream>
#include <cmath>        //all libraries used
using namespace std;

#define ROWCAP 100   //introduce all global variables
#define COLCAP 100

void initialize(double arr[ROWCAP][COLCAP], int a, int b);     //introduce all functions
void print(double arr[ROWCAP][COLCAP], int a, int b);
double findNorm(double arr[ROWCAP][COLCAP], int a, int b);

int main() {

    double array[ROWCAP][COLCAP]; //introduce array that serves as matrix
    int rows, cols;

    cout<<"Enter the number of rows: ";   //menu for user input
    cin>>rows;
    cout<<endl;

    cout<<"Enter the number of columns: ";
    cin>>cols;
    cout<<endl;

    cout<<"Enter the matrix: (Row by row)"<<endl;
    initialize(array,rows,cols);                   //calls "initialize" function to get element input


    cout<<"The entered matrix was: "<<endl;
    print(array,rows,cols);                        //calls "print" function to print the matrix
    cout<<endl;

    cout<<"The L21 norm is ";
    double Norm;
    Norm = findNorm(array,rows,cols);             //calls "findNorm" function to get the L21 norm of the matrix
    cout<<Norm<<endl;

    return 0;
}

       //Functions:

void initialize(double arr[ROWCAP][COLCAP], int a, int b) //function that allows user to input the elements of the matrix
{
    for(int i=0; i < a; i++)
    {
        for(int e=0; e < b; e++)
        {
            cin>> arr[i][e];
        }
    }
}

void print(double arr[ROWCAP][COLCAP], int a, int b) //function that prints the matrix
{
    for(int i=0; i < a; i++)
    {
        for(int e=0; e < b; e++)
        {
            cout<< arr[i][e]<<" ";
        }
        cout<<endl;
    }
}

double findNorm(double arr[ROWCAP][COLCAP], int a, int b) // function to find the L21 Norm of the matrix
{
    double norm , x, square, squareroot, sum1=0, sum2=0;

    for(int i=0; i < a; i++)
    {
        for(int e=0; e < b; e++)
        {
            x = abs(arr[i][e]);  //get absolute value of element (sqrt doesn't work with negative numbers)
            square = pow(x,2);    //square of the element in column
            sum1 = sum1 + square; //sum of the square of the elements in column
        }
        squareroot = sqrt(sum1);  // square root of the sum of square of the elements in column
        sum2 = sum2 + squareroot; // sum of the square root of sums of the square of the elements in column
    }

    norm = sum2;

    return norm;
}
