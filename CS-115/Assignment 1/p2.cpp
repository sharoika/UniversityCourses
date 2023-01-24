// Name: MAKSIM SHAROIKA
// Student Number: 200446763
// Date: September 15 / 2021

// Filename: p2.cpp
// Problem 2: Write recursive definition of a method named Combinations // that takes two integers n and r as parameters and returns the number
// unique combinations of // r items from a group of n items. Number of // combinations C(n,r) for the given parameters n and // r can be 
// computed using the equation: For example, 𝐶(4,3) = 4

// including the headerfile for input and output and strings
#include <iostream>
#include <string>

// using the standard namespace
using namespace std;

// function prototypes
unsigned int Input();
unsigned long Combinations(unsigned int, unsigned int);
unsigned long Factorial(unsigned int);

// main function
int main()
{
  // declaring and assigning starting values to all variables used
  unsigned int n = 0;
  unsigned int r = 0;
  unsigned int c = 0;
  // cout the function of the calculator in this program
  cout << "This calculator will calculate the number of unique possible combinations in groups of n items if there are r items in total." << endl;
  // do one interation and then error check if r (combination) > n (number available)
  do
  {
    // requesting user to input the total number of items 
    cout << "Please enter the TOTAL number of items(n): ";
    n = Input();
    // requesting user to input the number of items in a group
    cout << "Please enter the number of items IN A GROUP(r): ";
    r = Input();
    // if the number of items in a group > than total number have user reinput the data.
    if (r > n)
    {
      cout << "Error the r is bigger than the n - please try again: " << endl;
    }
  } while (r > n);

  // calling the combinations function
  c = Combinations(n, r);

  // returning the output of the combination function with some text
  cout << "The number of possible combinations is: " << c << endl;
  cout << "C(" << n << "," << r << ") = " << c << endl;
  // return 0 if program completes itself
  return 0;
}

// Funtion: makes sure the input is correct for the programs constraints 
unsigned int Input()
{
  // bool to represent if the input has been checked
  bool input_check = false;
  // the input the user has provided
  string user_input;
  // while the input was not checked keep running
  while (input_check == false)
  {
    // get the line from the terminal and store it in a string
    getline(cin, user_input);
    // parse through the string position by position
    for(int i = 0; i < user_input.length(); i++)
    {
      // if the ASCII value isnt a number then flag as error and restart
      if (int(user_input[i]) < 48 || int(user_input[i]) > 57)
      {
        // cout that and error has occured and positive integer was not provided 
        cout << "Incorrect input - please enter an interger:";
        break;
      }
      // if we get to the end of the string
      if (i == (user_input.length() - 1))
      {
        // the string has been checked and is the correct input
        input_check = true;
      }
    }
  }
  // return the numerical string as a integer 
  return stoi(user_input);
}

// Funtion: the combination function that follows given equation
unsigned long Combinations(unsigned int n, unsigned int r)
{
  // declare the value we will be returning
  unsigned long C = 0;
  // fact(n) / (fact(r) * fact(n-r))
  C = ( Factorial(n) ) / ( Factorial(r) * Factorial(n-r) );
  // return the value
  return C;
}

// Funtion: a function to model mathimatical factorial
unsigned long Factorial(unsigned int number)
{
  // start the product at 1
  unsigned long product = 1;
  // multiply it by i as long as i is less greater than 1 (factorial ends at 1)
  for(int i = number; i > 1; i--)
  {
    // product is product * the current value (counting down)
    product = product * i;
  }
  // return the product
  return product;
}