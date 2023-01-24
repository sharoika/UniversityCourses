// Name: MAKSIM SHAROIKA
// Student Number: 200446763
// Date: September 14 / 2021

// Filename: p1.cpp
// Problem 1: Using a repetition construct display the following on the screen (warm-up problem). 

// including the headerfile for input and output
#include <iostream>

// using the standard namespace to make cout easier
using namespace std;

// the line standard line length in the terminal
const int lineLength = 80;

// function prototypes
void spaces(int) ;
void lines(int, char);

// main function
int main()
{
  // calling each line with the respective letter and spacing
  lines(0, 'L');
  lines(3, 'O');
  lines(7, 'O');
  lines(11, 'P');
  lines(7, 'O');
  lines(3, 'O');
  lines(0, 'L');
  // return 0 if program completes itself
  return 0;
}

// Funtion: Takes in input for number of spaces to produce
void spaces(int number)
{
  for (int i = 0; i < number; i++)
  {
    cout << " ";
  }
}

// Function: Takes in character and the amount of space beetween the letters and prints them out
void lines(int middleSpaceNumber, char Letter)
{
  // initilize the numbber of spaces on the side variable 
  int side_spaces = 0;
  // condition for if only 1 letter should be printed
  if (middleSpaceNumber < 1)
  {
    // going to be the number of spaces (digits - letters) divided by half
    side_spaces = ((lineLength - 1)/2);
    // print out that amount of spaces
    spaces(side_spaces);
    // print out the letter
    cout << Letter;
    // print out that amount of spaces
    spaces(side_spaces);
  }
  // condition for when 2 letters printed with space in between 
  else
  {
    // going to be the number of spaces (digits - letters) divided by half
    side_spaces = ((lineLength - (middleSpaceNumber + 2))/2);
    // print out that amount of spaces
    spaces(side_spaces);
    // print out the letter
    cout << Letter;
    // print out the number of middle spaces given
    spaces(middleSpaceNumber);
    // print out the letter
    cout << Letter;
    // print out that amount of spaces
    spaces(side_spaces);
  }
  // end the line because the function is per line
  cout << endl;
}