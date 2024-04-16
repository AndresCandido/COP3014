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

struct Item{          //declare all structures
    string name[50], department[50];
    int quantity;
    double price;};
struct Date{
    int day, month, year;
    double totalAmount;};
struct Sale{
    int saleMonth, saleDay, saleYear, saleQuantity;
    string name[50];
    };

int main() {

    int numitems, numsales;
    char asterisk, slash;

    Item *items;   //array for first structure
    ifstream in;
    in.open("items.txt");

    if(!in){cout<<"Error opening items file";}
    else{
        in >> numitems;
        items = new Item[numitems];
        in.ignore();

        for (int i=0; i<numitems; i++)
        {
            //getline(in, items[i].name, '*');
            //getline(in, items[i].department, '*');
            in>>items[i].quantity>>asterisk>>items[i].price;
        }
        in.close(); //close first file
    }

    Sale *sales;  //create array for structures
    Date *dates;

    in.open("sales.txt"); //open second file

    if(!in){cout<<"Error opening sales file";}
    else{
        in >> numsales;
        sales = new Sale[numsales];
        dates = new Date[30];
        in.ignore();

        for(int i=0; i<numsales; i++)
        {
            in>>sales[i].saleMonth>>slash>>sales[i].saleDay>>slash>>sales[i].saleYear>>asterisk;
            //getline(in, sales[i].name, '*');
            in>>sales[i].saleQuantity;

            dates[i].month = sales[i].saleMonth;   //move dates to the dates array, initialize total amount to 0.
            dates[i].day = sales[i].saleDay;
            dates[i].year = sales[i].saleYear;
            dates[i].totalAmount = 0;

            for(int j=0; j<numitems; j++)
            {
                if ( sales[i].name == items[j].name )   //this are the cases for all the products that could be sold
                {                                 //they update quantity of products and amount money made in each sale
                    items[j].quantity = sales[i].saleQuantity - items[j].quantity;
                    dates[i].totalAmount = dates[i].totalAmount + (items[j].price * sales[i].saleQuantity);
                }
            }

            for(int j=0; j<numsales; j++) //this loop adds the sale amounts of in the same day
            {
                if ( sales[i].saleDay == sales[j].saleDay && i!=j)
                {
                    dates[i].totalAmount = dates[i].totalAmount + dates[j].totalAmount;
                }
            }
        }
        in.close();
    }

    ofstream out;
    out.open("summary.txt");  //opens summary file

    if(!out){cout<<"Error opening output file";}
    else{
        out<<"Departments: "<<endl;

        for (int i=0; i<numitems; i++) //writes departments, products, and quantity of product in stock
        {
            out<<items[i].department<<endl;
            for(int j=0; j<numsales; j++)
            {
                if ( items[i].department == items[j].department && i!=j && items[j].quantity!=0)
                {
                 out<<items[j].name<<" - "<<items[j].quantity<<endl;
                }

                else if ( items[i].department == items[j].department && i!=j && items[j].quantity==0)
                {
                    out<<items[j].name<<" - out of stock";
                }
            }
            out<<endl;
        }
        out<<endl;
        out<<"Sales: "<<endl;

        for (int i=0; i<numsales; i++) //write dates and totals
        {
            out<<dates[i].month<<'/'<<dates[i].day<<'/'<<dates[i].year<<" - "<<dates[i].totalAmount<<endl;
        }
    }

    delete [] sales; //delete all arrays
    delete [] dates;
    delete [] items;

    return 0;
}
