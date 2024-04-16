/* Name: Andres Candido
Date: 11/6/2020
Section: 6
Assignment: Homework 5
Due Date: 11/6/2020
About this project: I will be making an array that allows the user to add, remove, and shift its elements.
Assumptions: correct user input

All work below was performed by Andres Candido */

#include <iostream>
using namespace std;

#define CAPACITY 100  //global variable for max size of the array.

void insertBefore(double a, double b, double array[], int size);  //All functions used
int removeAll(double a, double array[], int size);
void cyclicRightShift(int a, double array[], int size);

int main()
{
    int elements;
    double array[CAPACITY]; //introduce array

    cout<<"Enter the number of elements you want to enter (Max 100): ";   //initial menu
    cin>>elements;
    cout<<endl;

    cout<<"Enter "<<elements<<" numbers:"<<endl;

    for (int i = 0; i < elements; ++i)
    {
        cin>>array[i];
    }

    int option=1;
    while (option != 5)    // menu that loops for multiple user inputs
    {
        cout<<"1. Insert an element"<<endl;
        cout<<"2. Remove an element"<<endl;
        cout<<"3. Print the array"<<endl;
        cout<<"4. Cyclic right shift"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<endl;
        cout<<"Enter your option: ";
        cin>>option;
        if (option==1)      //this option calls the "insertBefore" function to add an element to the array
        {
            double a,b;
            cout<<"Enter the number: ";
            cin>> a;

            cout<<"Enter the number to be inserted before: ";
            cin>> b;
            cout<<endl;

            insertBefore(a,b,array,elements);

            elements = elements+1; //adjust array size after adding one element

        }
        else if (option==2)  //this option calls the "removeAll" function to remove all instances of a number from array
        {
            double c;
            int occurances;
            cout<<"Enter the element: ";
            cin>>c;

            occurances = removeAll(c, array, elements);

            elements=elements-occurances; //adjust array size depending on number of elements deleted

        }

        else if (option==3) //this option prints the current arrau
        {
            for (int i = 0; i < elements; ++i)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }

        else if (option==4) //this option calls the "cyclicRightShift" function to shift elements to the right
        {
            int quantity;
            cout<<"Enter shift quantity: ";
            cin>>quantity;

            cyclicRightShift(quantity, array, elements);
        }

        else if (option!= 1 && option!= 2 && option!=3 && option!=4 && option!=5) //error message for invalid option number
        {
            cout<<"Invalid option,try again: "<<endl;
        }
    }

    cout<<endl;
    cout<<"Goodbye";

    return 0;
}

void insertBefore(double a, double b,double array[],int size)
{
    int pos;
    for (int i = 0; i >= size; ++i) //determines position where element is to be inserted
    {
        if (array[i]==b)
        {
            pos = i;
        }

    }

    size = size+1;
    for (int i = size; i >= pos; i--) //moves all elements after insertion position
    {
        array[i] = array[i - 1];
    }

    array[pos] = a; //inserts element at desired position

}

int removeAll(double a, double array[], int size)
{
    int pos, occurs = 0;
    for (int i = 0; i < size; ++i) //determines number of elements to be deleted and deletes them
    {
        if (array[i]==a)
        {
            pos = i;
            occurs = occurs+1;

            size = size-1;
            for (int e = pos; e < size; ++e)
            {
                array[e] = array[e + 1];
            }
        }
    }

    return occurs;
}

void cyclicRightShift(int a, double array[], int size)
{
    double tempArray[CAPACITY];    //used temporary array to shift elements
    for (int i = 0; i < size; ++i)  //shift elements to the right depending on user input
    {
        tempArray[(i+a)%size] = array[i];
    }

    for (int i = 0; i < size; ++i)
    {
        array[i] = tempArray[i];
    }
}