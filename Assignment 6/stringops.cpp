/* Name: Andres Candido
Date: 11/24/2020
Section: 6
Assignment: Homework 6
Due Date: 11/24/2020
About this project: i will be making a program that counts words, punctuations, and uppercase letters in a string.
 assuming correct grammatical input from user.

All work below was performed by Andres Candido */

#include <iostream>
#include <cctype>
#include <string>
using namespace std;     //include all libraries

int wordCount (char arr[]);
int puncCount (char arr[]);
int uppercaseCount (char arr[]);
int fingSubString (char arr[]);    // declare all functions

int main() {

    char string[500];
    int stop = 0;

    while (stop==0) {                   //loop until stop = 1
        cout << "Enter the string:  ";
        cin.getline(string, 500);

        int words, puncts, upper;

        words = wordCount(string);
        cout << "Number of words:  " << words << endl;

        puncts = puncCount(string);
        cout << "Number of punctuations:  " << puncts << endl;

        upper = uppercaseCount(string);
        cout << "Number of uppercase characters:  " << upper << endl;  //runs all the functions

        cout<<endl;

        stop =  fingSubString(string); // determines if string= "Done" to stop loop

    }

    return 0;
}

int wordCount (char arr[])
{
    int num=0;

    for( int i=0; i<strlen(arr); ++i)
    {
        if (arr[i] == ' ')
        {
            num = num + 1;    //sum all spaces " " to determine word count
        }
    }
    num=num+1;   //add an extra word for the last word in a sentence (there is no space after it)

    return num;
}

int puncCount (char arr[])
{
    int num=0;

    for( int i=0; i<strlen(arr); ++i)
    {
        if (ispunct(arr[i]))    //function for determining punctuations
        {
            num = num + 1;
        }
    }

    return num;
}

int uppercaseCount (char arr[])
{
    int num=0;

    for( int i=0; i<strlen(arr); ++i)
    {
        if (isupper(arr[i]))  //function for determining uppercase characters
        {
            num = num + 1;
        }
    }

    return num;
}

int fingSubString (char arr[])
{
    char temp[500];
    int stop = 0;

    temp[0] = 'D';  //make temp= "Done"
    temp[1] = 'o';
    temp[2] = 'n';
    temp[3] = 'e';

    for( int i=0; i<strlen(temp); ++i)
    {
        if ( arr[i] == temp[i]){ stop = 1;}  //compares if temp is equal to arr
    }


    return stop;
}
