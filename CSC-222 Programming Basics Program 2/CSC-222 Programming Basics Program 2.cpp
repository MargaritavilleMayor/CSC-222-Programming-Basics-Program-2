// CSC-222 Programming Basics Pt. 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <iomanip>

using namespace std;


int main()
{
    //initializing variables
    ifstream input_file{ "SalaryData.txt" };
    ofstream output_file;
    double raise_per{ 0 };
    string last_name{ "" };
    string first_name{ "" };
    double og_salary{ 0 };
    output_file.open("SalaryOut.txt");
    output_file << fixed << setprecision(2);

    while (!input_file.eof())
    {
        //reads a line from the input file into their respective variables
        input_file >> last_name >> first_name >> og_salary >> raise_per;
        raise_per = raise_per / 100;
        //reads the information into a new file in a different order
        output_file << first_name << " " << last_name << " ";
        output_file << "$" << og_salary + (og_salary * raise_per) << endl;
    }
}