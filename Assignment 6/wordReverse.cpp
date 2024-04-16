/* Name: Andres Candido
Date: 11/24/2020
Section: 6
Assignment: Homework 6
Due Date: 11/24/2020
About this project: i will be making a program that reverts words in a string.
 assuming correct grammatical input from user.

All work below was performed by Andres Candido */

#include <iostream>
#include <cstring>
using namespace std;     //include all libraries

void printText (char arr[25][200]); //declare function


int main() {

    char array[25][200]; //declare array

    cout<<"Enter the text: "<<endl;

    for (int i=0; i<25; ++i) //loop for getting all the rows
    {
        cin.getline(array[i],200);

        if (array[i][0] == '\0')
        {
            i=26;
        }
    }

    cout<<endl;

    printText(array); //call function

    return 0;
}

void printText (char arr[25][200]) { //reverse function
    int start, end, j=0;
    char temp;


    for (int i = 0; i < 25; i++)   //loop for rows
    {
        for (int a = 0; a < strlen(arr[i])+1; a++) //loop for characters in a row
        {
            if (arr[i][a] == ' ' || arr[i][a] == '\0' || arr[i][a] == '\n')
            {
                for (start = j, end = a-1; start < (a + j)/2; start++, end--)   // loop for switching/reversing letters
                {
                    temp = arr[i][start];
                    arr[i][start] = arr[i][end];
                    arr[i][end] = temp;
                }
                j = a + 1;
            }
        }
        cout << arr[i] << endl;  //print string

        if (arr[i][0] == '\0')  //stop loop when there aren't more rows
        {
            i=26;
        }
    }
}