/* Name: Andres Candido
Date: 12/04/2020
Section: 6
Assignment: Homework 7
Due Date: 12/04/2020
About this project: i will be making a program that allows my little cousin to play a rigged version of snake.
 Assuming correct user input.

All work below was performed by Andres Candido */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std; //include all libraries


char** createField (int lenght, int width);
void playGame ( char** arr, int lenght, int width);

int main() {

    int rows, columns;
    cout<<"Enter the number of rows: ";
    cin>>rows;

    cout<<"Enter the number of columns: ";
    cin>>columns;
    cout<<endl;

    char** array;
    array = createField(rows,columns); //calls field function
    playGame (array, rows, columns);  //calls play function

    return 0;
}


// functions:

char** createField (int lenght, int width)
{
    char** arr = new char*[lenght];
    for(int i=0; i<lenght; ++i){
        arr[i]= new char[width];
        for(int j=0; j<width; ++j){

            if ( i==0 || j==0 )
            {arr[i][j]='W';}

            else if ( i == lenght-1 )
            {arr[i][j]='W';}

            else if ( j == width-1 )
            {arr[i][j]='W';}

            else arr[i][j]='.';
        }
    }

    int N, X, Y;

    cout<<"Enter the number of obstacles: ";
    cin>>N;

    for(int a=0; a<N; ++a){
        cout<<"Enter the location of an obstacle: (ex: 5,5)"<<endl;
        cin>>X>>Y;

        arr[X][Y]='O';
    }

    return arr;
}


void playGame ( char** arr, int lenght, int width)
{
    int gate, turns, spaces, row=0, column;
    char direction;
    cout<<"Enter the location of the gate: (ex: 0,2)";
    cin>>gate;
    column=gate;
    arr[row][gate]='G';


    cout<<"Enter the number of turns: ";
    cin>>turns;

    for(int a=0; a<turns; ++a) // loop for making all the turns
    {
        cout<<"Enter the turn: -Direction(U,D,R,L), then spaces-"<<endl;
        cin>>direction>>spaces;

        if (direction == 'U')
        {
            for(int i=0; i<spaces; ++i) //loop for a single turn
            {
                row = row-1;
                if (arr[row][column] == 'S')
                {
                    a=turns; //this will stop the loop that allows players to make more turns, ending the game
                    i=spaces; //this will stop the current turn
                }
                else if (arr[row][column] == 'O'){i=spaces;}  //stops current turns
                else arr[row][column] = 'S'; //makes space into a "S" and continues the turn
            }
        }

        else if (direction == 'D')
        {
            for(int i=0; i<spaces; ++i)
            {
                row = row+1;
                if (arr[row][column] == 'S')
                {
                    a=turns;
                    i=spaces;
                }
                else if (arr[row][column] == 'O'){i=spaces;}
                else arr[row][column] = 'S';
            }
        }

        else if (direction == 'R')
        {
            for(int i=0; i<spaces; ++i)
            {
                column = column+1;
                if (arr[row][column] == 'S')
                {
                    a=turns;
                    i=spaces;
                }
                else if (arr[row][column] == 'O'){i=spaces;}
                else arr[row][column] = 'S';
            }
        }

        else if (direction == 'L')
        {
            for(int i=0; i<spaces; ++i)
            {
                column = column-1;
                if (arr[row][column] == 'S')
                {
                    a=turns;
                    i=spaces;
                }
                else if (arr[row][column] == 'O'){i=spaces;}
                else arr[row][column] = 'S';
            }
        }
    }


    for(int i=0; i<lenght; ++i){  //loops for printing the array
        for(int j=0; j<width; ++j){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    delete [] arr;

}