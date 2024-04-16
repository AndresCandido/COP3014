
/* Name: Andres Candido
Date: 9/23/2020
Section: 6
Assignment: Homework 2
Due Date: 9/24/2020
About this project: For this program, I will write 3 numbers and order them in ascending order.
Assumptions: Correct user input.

All work below was performed by Andres Candido */

#include <iostream>

using namespace std;

int main() {
    cout << "Enter 3 numbers:" << endl;
    double x,y,z;                        //First we establish the 3 number the user will input.
    cin >> x >> y >> z;

    if (x>=y && y>z)       //Here we start listing the possible scenarios that could occur depending on user input.
    {                      // Note: Use "if" only for the first scenario.
        cout <<"The ascending order is: "<< z <<" < "<< y <<" < "<< x << endl;
        cout <<"The range is "<< x-z <<endl;
    }

    else if (y>=x && x>z)    //Note: Use "else if" for all other scenarios except for the last one.
    {                        // >= means greater or equal to, && means and.
        cout <<"The ascending order is: "<< z <<" < "<< x <<" < "<< y << endl;
        cout <<"The range is "<< y-z <<endl;
    }

    else if (y>=z && z>x)
    {
        cout <<"The ascending order is: "<< x <<" < "<< z <<" < "<< y <<endl;
        cout <<"The range is "<< y-x <<endl;
    }

    else if (z>=y && y>x)
    {
        cout <<"The ascending order is: "<< x <<" < "<< y <<" < "<< z <<endl;
        cout <<"The range is "<< z-x <<endl;
    }

    else if (z>=x && x>y)
    {
        cout <<"The ascending order is: "<< y <<" < "<< x <<" < "<< z <<endl;
        cout <<"The range is "<< z-y <<endl;
    }

    else if (x>=z && z>y)
    {
        cout <<"The ascending order is: "<< y <<" < "<< z <<" < "<< x <<endl;
        cout <<"The range is "<< x-y <<endl;
    }

    else if (x>z && z==y)       // == means equal to.
    {
        cout <<"The ascending order is: "<< y <<" = "<< z <<" < "<< x <<endl;
        cout <<"The range is "<< x-y <<endl;
    }

    else if (y>z && z==x)
    {
        cout <<"The ascending order is: "<< x <<" = "<< z <<" < "<< y <<endl;
        cout <<"The range is "<< y-x <<endl;
    }

    else if (z>x && x==y)
    {
        cout <<"The ascending order is: "<< y <<" < "<< x <<" < "<< z <<endl;
        cout <<"The range is "<< z-y <<endl;
    }

    else                             //Use "else" of the last scenario.
        cout << "Doesn't apply, you entered the same three numbers" << endl;

    return 0;
}
