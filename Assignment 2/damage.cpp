
/* Name: Andres Candido
Date: 9/23/2020
Section: 6
Assignment: Homework 2
Due Date: 9/24/2020
About this project: In this program I will estimate the damage caused by a sharknado.
Assumptions: Correct user input.

All work below was performed by Andres Candido */

#include <iostream>
#include <iomanip>    //include this library just to show 2 decimal points on damage.
using namespace std;

int main() {
    cout <<"Basking Shark - B"<< endl;     //First I made the user menu with all the available shark types.
    cout <<"Great White Shark - G"<<endl;
    cout <<"Hammerhead Shark - H"<<endl;
    cout <<"Whale Shark - W"<<endl;
    cout <<"Bull Shark - U"<<endl;
    cout <<"Lemon Shark - L"<<endl;
    char shark;                          //Introduce all the variables I will be using in this program.
    double windspeed, duration, weight;

    cout<<"Enter the shark: ";            //Allow the user to input the required data.
    cin >> shark;
    cout<<"Enter windspeed (in miles per hour): ";
    cin >> windspeed;
    cout<<"Enter the duration (in seconds): ";
    cin >> duration;
    cout<<endl;


    switch (shark)       //Use switch to list the different possible inputs (cases) and their corresponding outputs.
    {
        case 'B': {weight=14500;
            cout<<fixed<<showpoint<<setprecision(2)<<"Estimate sharknado damage: $"<<((windspeed*0.447)*weight*duration)<<endl;}
        break;  //Use break after each case to avoid fallthrough (switch will run ALL the other cases after the selected case unless I use break).
        case 'G': {weight=2270;
            cout<<fixed<<showpoint<<setprecision(2)<<"Estimate sharknado damage: $"<<((windspeed*0.447)*weight*duration)<<endl;}
        break;
        case 'H': {weight=230;
            cout<<fixed<<showpoint<<setprecision(2)<<"Estimate sharknado damage: $"<<((windspeed*0.447)*weight*duration)<<endl;}
        break;
        case 'W': {weight=21000;
            cout<<fixed<<showpoint<<setprecision(2)<<"Estimate sharknado damage: $"<<((windspeed*0.447)*weight*duration)<<endl;}
        break;
        case 'U': {weight=130;
            cout<<fixed<<showpoint<<setprecision(2)<<"Estimate sharknado damage: $"<<((windspeed*0.447)*weight*duration)<<endl;}
        break;
        case 'L': { weight=183;
            cout<<fixed<<showpoint<<setprecision(2)<<"Estimate sharknado damage: $"<<((windspeed*0.447)*weight*duration)<<endl;}
        break;
        default: cout<<"Error, invalid shark input.";

    }


    return 0;
}
