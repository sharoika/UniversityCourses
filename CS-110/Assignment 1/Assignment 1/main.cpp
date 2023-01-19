/**
 Student Name: MAKSIM SHAROIKA
 Student Number: 200446763
 Assignment: Assignment 1
 Program Name: Unit Converter V1
 Date Written: February 7th 2021
 Problem Statement: Write a C++ program to input the number of tons from an input file, called tons.txt, and print out the equivalent in pounds, ounces, kilograms, and grams, to an output file, called report.txt. Also, print the conversion factors to the output file.
 Input: Number of tons
 Ourput: Pounds, Ounces, Kilograms, Grams
*/
/**
 Main Algorithm:
 Input tonnage from file to variable
 Perform calculations and output to specified file
 Close both files
 */
/**
 Varaibles:
 tonsTOpounds : Universal Conversion
 tonsTOounces : Universal Conversion
 tonsTOkilgrams : Universal Conversion
 tonsTOgrams : Universal Conversion
 tons : Working input variable for rest of program and calculations
 */

#include <fstream> // include file input and output

using namespace std; // standard

const int tonsTOpounds = 2000; // set universal conversion
const int tonsTOounces = 32000; // set universal conversion
const float tonsTOkilograms = 907.185; // set universal conversion
const int tonsTOgrams = 907185; // set universal conversion


// main function
int main(int argc, const char * argv[]) {
    int tons; // create a tons variable
    ifstream inputfile; // create an input buffer
    ofstream outputfile; // create an output buffer
    inputfile.open("tons.txt"); // connect buffer to file
    outputfile.open("report.txt"); // connect buffer to file
    inputfile >> tons; // input tons from file into variable
    outputfile << fixed; // set fixed style to output file
    outputfile << "Inputed Tons: " << tons << endl << endl; // output inputed tons
    outputfile << "---Conversion Factors---" << endl; // prints conversions heading
    outputfile << "Tons to Pounds: " << tonsTOpounds << endl; // Prints conversion factor to pounds
    outputfile << "Tons to Ounces: " << tonsTOounces << endl; // Prints conversion factor to ounces
    outputfile << "Tons to Kilograms: " << setprecision(3) << tonsTOkilograms << endl; // Prints conversion factor to kilograms
    outputfile << "Tons to Grams: " << tonsTOgrams << endl << endl; // Prints conversion factor to grams
    outputfile << "---The Outputs---" << endl; // prints outputs heading
    outputfile << "Pounds: " << tons * tonsTOpounds << endl; // output converted pounds
    outputfile << "Ounces: " << tons * tonsTOounces << endl; // output converted ounces
    outputfile << "Kilograms: " << setprecision(3) << float(tons) * tonsTOkilograms << endl; // output converted kgs
    outputfile << "Grams: " << tons * tonsTOgrams << endl; // output converted grams
    inputfile.close(); // close the input file
    outputfile.close(); // close the output file
    return 0;
}
