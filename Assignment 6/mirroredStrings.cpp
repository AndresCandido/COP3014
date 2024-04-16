/* Name: Andres Candido
Date: 11/24/2020
Section: 6
Assignment: Homework 6
Due Date: 11/24/2020
About this project: i will be making a program that switches letters in a string.
 assuming correct grammatical input from user.

All work below was performed by Andres Candido */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;     //include all libraries


string readAndMirror (); //declare function


int main() {


    readAndMirror(); //call function

    return 0;
}



string readAndMirror (){

    int num;
    cout<<"Enter the number of strings: ";
    cin>>num;
    num=num+1;
    cout<<endl;

    char array[num][150];

    cout<<"Enter the strings: "<<endl;
    for (int i=0; i<num; ++i) //loop for getting all the rows
    {
        cin.getline(array[i],200);

    }

    cout<<endl;
    cout<<"The mirrored array is: ";

    for (int i = 0; i < num; i++)   //loop for inverting all sentences
    {
        for (int a = 0; a < (strlen(array[i])/2); a++) //loop that invert sentences
        {
           char temp;
           temp=array[i][a];
           array[i][a]=array[i][strlen(array[i])-1-a];
            array[i][strlen(array[i])-1-a]=temp;
        }
    }


    for (int i = 0; i < num; i++)   //loop for rows
    {
        for (int a = 0; a < strlen(array[i]); a++) //loop for switching characters in a row
        {
            if (array[i][a] == 'M' ){ array[i][a] = 'W'; }
            else if (array[i][a] == 'W' ){ array[i][a] = 'M'; }
            else if (array[i][a] == 'b' ){ array[i][a] = 'q'; }
            else if (array[i][a] == 'd' ){ array[i][a] = 'p'; }
            else if (array[i][a] == 'h' ){ array[i][a] = 'y'; }
            else if (array[i][a] == 'm' ){ array[i][a] = 'w'; }
            else if (array[i][a] == 'n' ){ array[i][a] = 'u'; }
            else if (array[i][a] == 'p' ){ array[i][a] = 'd'; }
            else if (array[i][a] == 'q' ){ array[i][a] = 'b'; }
            else if (array[i][a] == 'u' ){ array[i][a] = 'n'; }
            else if (array[i][a] == 'w' ){ array[i][a] = 'm'; }
            else if (array[i][a] == 'y' ){ array[i][a] = 'h'; }
        }
        cout << array[i] << endl;  //print string
    }

}