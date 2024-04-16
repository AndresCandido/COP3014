/* Name: Andres Candido
Date: 09/08/20
Section: 6
Assignment: Homework 1
Due Date: 09/10/20
About this project: Squidward has hired me to make a calculator for the Krusty Krab.
I will try to learn to write, edit, and debug my first program.
Assumptions: correct user input, prices of the menu items don't change, assume all user is correct,
assume user input for check number isn't 0.

All work below was performed by Andres Candido */

#include <iostream>
#include <iomanip>        // i include iomanip for the decimal point requirement
using namespace std;      // I used this save to time writing std on every line

int main() {
    cout << "Welcome to the Krusty Krab, may I take your order?" << endl;   //this is the introduction message
    cout << endl;

    double dub1 = 3.84, dub2 = 1.89, dub3 = 2.99;       //in this two lines I introduce all the variables that we will be using
    int num1, num2, num3, num4;                         // I used double for the items prices because they have decimals

    cout << "How many menu items would you like to order?" << endl;   //Here we assign a variable to each menu item for client input
    cout << "Number of krabby Patties:";
    cin >> num1;
    cout << "Number of Fries:";
    cin >> num2;
    cout << "Number of Kelp Shakes:";
    cin >> num3;
    cout << endl;    //Lines of separation make the program look better and feels less crowded for the user

    cout << "In how many check(s) would you like to split your order? ";
    cin >> num4;      // If this equals 0 the price clients have to pay becomes infinite, pretty sure mr. krabs wouldn't mind that tho lol.
    cout << endl;

    cout << "Thank you for choosing the Krusty Krab, your total is for each check is: $";  //I added the $ here to save time instead of making it part of the variables
    cout << fixed << showpoint << setprecision (2) << (((num1 * dub1) + (num2 * dub2) + (num3 * dub3)) * 1.75) / num4 << endl;   //formula for final price, doesn't work if checks=0, precision=2 for the two decimals required


    return 0;
}
