/**
 Student Name: MAKSIM SHAROIKA
 
 Student Number: 200446763
 
 Assignment: CS 110-087 Assignment 2
 
 Program Name: main.cpp
 
 Date Written: 03/10/2021
 
 Problem Statement: Approximating the Geometrical Shape of Molecules - Write a C++ program to predict the molecular geometry of molecules based on formulas like AB_b, where the approximate shape is one A atom in the centre surrounded by b B atoms.
 
 Input: Molecules.txt file in the format of center atom, # of binding atoms, type of binding atom
 
 Output: The center atom, the number and type of bind atoms, and the molecular geometry.
 
 Main Algorithm: Input the center atoms, binding number, and binding atom. Determine the number of valence electrons in the center atom, determine the number of electrons left after binding, divide by 2 to account for binding domains then use if statements to find the matching molecular geometry. Then output to an output file.
 
 Varaibles: A is the center atom name, b is number of binding atoms, B is the name of binding atom. e is the electrons leftover non-binding electrons, n is the number of of domains with lone or double electrons, v is the number of valence electrons for the center atom.
 
 Assumptions: All binding will occure with single bonds, and the molecules remain in stable forms. We also assume that electrons will tend to be in groups of 2.
 
 Program Limitations: The program is hardcoded for the input to be very specific and only applying to the atoms that are provided, it also does not account for any extra chemical behavours.
 */

#include <fstream> // include file input and output
#include <iostream> // include terminal input and output
#include <string> // include strings

using namespace std;

int main() {
    
    int valence = 0; // Initializing valence electron variable
    int lone_electrons = 0; // Initializing lone electrons on center atom
    int electron_domains = 0; // Initializing the number of lone electron domains
    int bonding_domains = 0; // Initializing bonding domains
    
    string center_atom; // Initializing string for center atom
    string binding_atom; // Initializing string for binding atoms
    string geometry; // Initializing string geometry
    
    ifstream inputfile; // create an input buffer
    ofstream outputfile; // create an output buffer
    
    inputfile.open("molecules.txt"); // connect input buffer to file
    outputfile.open("geometricalshapes.txt"); // connect output buffer to file
    
    if(!inputfile) // checking if the unput file was opened correctly
    {
        cout << "Error : Input file failed to open." << endl; // if the file failed to notifying user
    }
    
    if(!outputfile) // checking if the output file was opened correctly
    {
        cout << "Error : Outputfile failed to open." << endl; // if the file failed to notifying user
    }
    
    inputfile >> center_atom; // priming read, inserting the string of the center atom (name)
    inputfile >> binding_atom; // priming read, inserting the string of the binding atom (name)
    inputfile >> bonding_domains; // priming read, inserting the number of binding atoms / bonding domains
    
    while(inputfile) // while statement for an end of file loop for molecules.txt (in this case)
    {
        if(center_atom == "Be")
            // if the center atom is "Be" set the valence electrons to 3
        {
            valence = 3;
        }
        else if(center_atom == "C" || center_atom == "Si")
            // if the center atom is "C" or "Si" set the valence electrons to 4
        {
            valence = 4;
        }
        else if(center_atom == "N" || center_atom == "P" || center_atom == "As")
            // if the center atom is "N", "P' or "As" set the valence eletrons to 5
        {
            valence = 5;
        }
        else if(center_atom == "O" || center_atom == "S" || center_atom == "Se")
            // if the center atom is "O", "S" or "Se" set valence electrons to 6
        {
            valence = 6;
        }
        else if(center_atom == "F" || center_atom == "Cl" || center_atom == "Br" || center_atom == "I")
            // if the center atom is "F", "Cl", "Br" or "I" set valence electrons to 7
        {
            valence = 7;
        }
        else if(center_atom == "Xe")
            // if the center atom is "Xe" set valence electrons to 8
        {
            valence = 8;
        }
        
        // finding the number of left-over lone electrons by taking center valence and subtracting bonding
        lone_electrons = valence - bonding_domains;
        
        // taking the leftover lone electrons and dividing by 2 because they are grouped by 2s
        // this will also discard any extra lone electrons that are unable to create a domain
        electron_domains = int(lone_electrons/2);
        
        if(bonding_domains == 2)
            // checking if there are 2 atoms bonded to center atom
        {
            if(electron_domains == 0)
                // checking if there are 0 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "linear";
            }
            else if(electron_domains == 1)
                // checking if there are 1 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "bent";
            }
            else if(electron_domains == 2)
                // checking if there are 2 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "bent";
            }
            else if(electron_domains == 3)
                // checking if there are 3 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "linear";
            }
        }
        else if(bonding_domains == 3)
            // checking if there are 3 atoms bonded to center atom
        {
            if(electron_domains == 0)
                // checking if there are 0 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "trigonal planar";
            }
            else if(electron_domains == 1)
                // checking if there are 1 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "trigonal pyramidal";
            }
            else if(electron_domains == 2)
                // checking if there are 2 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "T-shaped";
            }
        }
        else if(bonding_domains == 4)
            // checking if there are 4 atoms bonded to center atom
        {
            if(electron_domains == 0)
                // checking if there are 0 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "tetrahedral";
            }
            else if(electron_domains == 1)
                // checking if there are 2 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "seesaw";
            }
            else if(electron_domains == 2)
                // checking if there are 2 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "square planar";
            }
            
        }
        else if(bonding_domains == 5)
            // checking if there are 5 atoms bonded to center atom
        {
            if(electron_domains == 0)
                // checking if there are 0 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "trigonal bipyramidal";
            }
            else if(electron_domains == 1)
                // checking if there are 1 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "square pyramidal";
            }
            
        }
        else if(bonding_domains == 6)
            // checking if there are 6 atoms bonded to center atom
        {
            if(electron_domains == 0)
                // checking if there are 0 lone electron domain(s)
            {
                // setting geometry string to the correct type
                geometry = "octahedral";
            }
        }
        else
            // if the information provided does not fit into the catagories provided
        {
            // set the geometry type to "unknown"
            geometry = "unknown";
        }
        // outputing the sentance structure for output file with the correct center atom, number of binding atoms, and binding atom; along with the calculated geometry.
        outputfile << "The geometrical shape of one " << center_atom << " atom surrounded by " << bonding_domains << " " << binding_atom << " atoms is " << geometry << "." << endl;
        
        inputfile >> center_atom; // inserting the string of the center atom (name)
        inputfile >> binding_atom; // inserting the string of the binding atom (name)
        inputfile >> bonding_domains; // inserting the number of binding atoms / bonding domains
    }
    inputfile.close(); // close the input file
    outputfile.close(); // close the output file
    return 0; // Return 0 for the main funtion; program worked correctly.
}


