// Name: MAKSIM SHAROIKA
// Student Number: 200446763
// Date: September 22 / 2021

// Filename: p4.cpp
// Problem 4: You will use your function overloading concepts to solve 
// this problem. Write six functions in total: three overloaded 
// functions named add and three overloaded functions named multiply. 
// The overloaded versions are for dealing with numbers, character 
// strings, and binary strings, respectively.

// include the string and cout/cin headers to use 
#include <iostream>
#include <string>

// using the standard namespace to avoid namespace calls
using namespace std;

// prototyping functions
// menu to choose operation
int menu();

// different functions to help request the correct type of input and check it
unsigned int MenuInput(int, int);
float InputFloat();
unsigned int InputInt();
string InputBinary();

// binary to int and int to binary functions to use for binary calculations
int binaryToInt(string);
string intToBinary(int);

// the add functions outlined by the assignment
float add(float, float);
string add(string, string);
int add(int, int);

// the multiply functions outlined bt the assignment
float multiply(float, float);
string multiply(string, int);
int multiply(int, int);

// the main funtion of the code
int main()
{
  // declaring the choice integer to help decide which operation is being performed
  int choice = 0;
  // requesting the user to make an informed decision on type of information
  choice = menu();
  // if required floats go down this path to create floats
  if (choice == 1 || choice == 4)
  {
    // declare floats and result
    float float1, float2;
    float result;
    // request float values and inform user
    if (choice == 1)
    {
      cout << "You have chosen float addition." << endl;
      cout << "Please enter your first float: ";
      // use the inputfloat function to verify input
      float1 = InputFloat();
      cout << "Please enter your second float: ";
      // use the inputfloat function to verify input
      float2 = InputFloat();
      // call the add function using floats
      result = add(float1, float2);
    }
    if (choice == 4)
    {
      cout << "You have chosen float multiplication." << endl;
      cout << "Please enter your first float: ";
      // use the inputfloat function to verify input
      float1 = InputFloat();
      cout << "Please enter your second float: ";
      // use the inputfloat function to verify input
      float2 = InputFloat();
      // call the multiply function using floats
      result = multiply(float1, float2);
    }
    // print out the calculated result
    cout << "Your result is : " << result << endl;
  }
  // if required strings go down this path to create strings
  else if (choice == 2 || choice == 5)
  {
    // declare strings, number for multiply, and result
    string string1, string2;
    unsigned int number;
    string result;
    // request the required data from user and notify them with information
    if (choice == 2)
    {
      cout << "You have chosen string addition." << endl;
      cout << "Please enter your first string: ";
      // use getline to get the string
      getline(cin, string1);
      cout << "Please enter your second string: ";
      // use getline to get the string
      getline(cin, string2);
      // call the add function using strings
      result = add(string1, string2);
    }
    if (choice == 5)
    {
      cout << "You have chosen string multiplication." << endl;
      cout << "Please enter your string: ";
      // use getline to get the string
      getline(cin, string1);
      cout << "Please enter the repetition constant: ";
      // use the InputInt() function to verify a correct integer
      number = InputInt();
      // call the add function using string and number
      result = multiply(string1, number);
    }
    // print out the calculated result
    cout << "Your result is : " << result << endl;
  }
  // if required binary go down this path to create all the required varaibles.
  else if (choice == 3 || choice == 6)
  {
    // declare strings, strings numbers, numberesult, and binary result
    string binary1 = "", binary2 = "";
    int bnum1, bnum2;
    int intresult = 0;
    string binaryresult;
    // request the required data from user and notify them with information
    if (choice == 3)
    {
      cout << "You have chosen binary addition." << endl;
      cout << "Please enter your first binary string: ";
      // request an input from the function only containing ones and zeros
      binary1 = InputBinary();
      // change the string to a number of type integer
      bnum1 = binaryToInt(binary1);
      cout << "Please enter your second binary string: ";
      // request an input from the function only containing ones and zeros
      binary2 = InputBinary();
      // change the string to a number of type integer
      bnum2 = binaryToInt(binary2);
      // use a add function with type ints to get the result
      intresult = add(bnum1, bnum2);
      // transfer the result back to binary using the intToBinary function
      binaryresult = intToBinary(intresult);
    }
    if (choice == 6)
    {
      cout << "You have chosen binary multiplcation." << endl;
      cout << "Please enter your first binary string: ";
      // request an input from the function only containing ones and zeros
      binary1 = InputBinary();
      // change the string to a number of type integer
      bnum1 = binaryToInt(binary1);
      cout << "Please enter your second binary string: ";
      // request an input from the function only containing ones and zeros
      binary2 = InputBinary();
      // change the string to a number of type integer
      bnum2 = binaryToInt(binary2);
      // use a add multiply with type ints to get the result
      intresult = multiply(bnum1, bnum2);
      // transfer the result back to binary using the intToBinary function
      binaryresult = intToBinary(intresult);
    }
    // print out the calculated result
    cout << "Your result is : " << binaryresult << endl;
  }
  // return 0 if the program is completed correctly
  return 0;
}

// Funtion: 
int menu()
{
  // declate the two inputs we are getting from the user as ints
  int operation;
  int input;
  // inform the user of two choices and request input
  cout << "What type of operation would you like to perform?" << endl;
  cout << "1. Addition" << endl;
  cout << "2. Multiplication" << endl;
  cout << "Please enter your coice: ";
  // special function to force the correct input from user
  operation = MenuInput(1, 2);
  // inform the user of three choices and request input
  cout << "What type of inputs would you like to work with?" << endl;
  cout << "1. Floats" << endl;
  cout << "2. Strings" << endl;
  cout << "3. Binary" << endl;
  cout << "Please enter your coice: ";
  // special function to force the correct input from user
  input = MenuInput(1, 3);
  // logic to return the correct "CHOICE" value back into the main function
  if (operation == 1)
  {
    if (input == 1)
    {
      return 1;
    }
    else if (input == 2)
    {
      return 2;
    }
    else if (input == 3)
    {
      return 3;
    }
  }
  // logic to return the correct "CHOICE" value back into the main function
  else if (operation == 2)
  {
    if (input == 1)
    {
      return 4;
    }
    else if (input == 2)
    {
      return 5;
    }
    else if (input == 3)
    {
      return 6;
    }
  }
  return 0;
}

// Funtion: this function informs the user and collects data to decide what actions they want to take
unsigned int MenuInput(int low, int high)
{
  // input has not been checked yet
  bool input_check = false;
  // string for user input
  string user_input;
  // the translated number of string
  int number;
  // while the input has not been checked
  while (input_check == false)
  {
    // get the line of input and store it in the string
    getline(cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse throught the string and check its size for only allowable valyes
      if (int(user_input[i]) < 49 || int(user_input[i]) > 54 || user_input.length() > 1)
      {
        // if not break and output this and request new input
        cout << "Incorrect input - please re-enter: ";
        break;
      }
      else
      {
        // change the string into a numberical valye
        number = stoi(user_input);
        // if the numberical value is between the low and high of the function 
        if (number >= low && number <= high)
        {
          // valid input leave loop
          input_check = true;
        }
        else
        {
          // not good input choice try again recall this loop
           cout << "Incorrect input - please re-enter: ";
        }
      }
    }
  }
  // return the number of "choice" back into the main function
  return number;
}

// Funtion: requesting float input and returning it as float (verifiying it aswell)
float InputFloat()
{
  // input has not been checked yet
  bool input_check = false;
  // the string the user will be inputing into
  string user_input;
  // while the input has not been checked
  while (input_check == false)
  {
    // input the line information into the string
    getline(cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse though the string to make sure all the characters are valid 
      if (int(user_input[i]) < 45 || int(user_input[i]) > 57 || int(user_input[i]) == 47)
      {
        cout << "Incorrect input - please enter a float:";
        break;
      }
      // if we get to the end of the string then make the input valid
      if (i == (user_input.length() - 1))
      {
        input_check = true;
      }
    }
  }
  // return the input with stof as a float format
  return stof(user_input);
}

// Funtion: requesting integer input and returning it as integer  (verifiying it aswell)
unsigned int InputInt()
{
  // input has not been checked yet
  bool input_check = false;
  // the string the user will be inputing into
  string user_input;
  // while the input has not been checked
  while (input_check == false)
  {
    // input the line information into the string
    getline(cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse though the string to make sure all the characters are valid 
      if (int(user_input[i]) < 48 || int(user_input[i]) > 57)
      {
        cout << "Incorrect input - please enter an interger:";
        break;
      }
      // if we get to the end of the string then make the input valid
      if (i == (user_input.length() - 1))
      {
        input_check = true;
      }
    }
  }
  // return the input with stoi as a int format
  return stoi(user_input);
}

// Funtion: requesting a binary input and returning it as a string  (verifiying it aswell)
string InputBinary()
{  
  // input has not been checked yet
  bool input_check = false;
  // the string the user will be inputing into
  string user_input = "";
  // while the input has not been checked
  while (input_check == false)
  {
    // input the line information into the string
    cin.clear();
    getline(cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse though the string to make sure all the characters are valid 
      if (i == int((user_input.length()) - 1))
      {
        // if we get to the end return true as the input
        input_check = true;
      }
      else if (int(user_input[i]) < 48 || int(user_input[i]) > 49)
      {
        cout << "Incorrect input - please enter a binary string consisting on only 0's and 1's (cant start with 0):";
        // if the input is an incorrect format redo the loop and inform the user
        break;
      }
    }
  }
  // if correct return the string which should only be consisting of 0's and 1's
  return user_input;
}

// Funtion: transfering a binary string into an int value
int binaryToInt(string binary)
{
  // int value for the value of the string in integer form, and place for the value of the place of that digit
  int value = 0;
  int place = 1;
  for (int j = 1; j < binary.length(); j++)
  {
    // calculate the largest possible place of the binary string (the most left point)
    place = place * 2;
  }
  for(int i = 0; i < binary.length(); i++)
  {
    // now move from left to right always adding the place we are looking at
    if (int(binary[i]) == 49)
    {
      value = value + place;
      // we go for the whole string and keep adding onto the value
    }
    place = place / 2;
    // half the place by two because that is the power system of binary
  }
  // once we parsed the whole string return the calculated value
  return value; 
}

// Funtion: transfering an int value into a bianry string
string intToBinary(int num)
{
  // start a string and the place of 1
  string holder = "";
  int place = 1;
  while(num >= place)
  {
    // while our number has not been fully used up keep increasing place to find the largest possible place vlaue
    place = place * 2;
  }
  // divide place by 1 because the largest place value is too big for the num to fit in
  place = place / 2;
  while (num != 0 || place > 1)
  {
    // while the number is no 0 (fully used up)
    if (num >= place)
    {
      // if the number is bigger than place than add a one to the string and subtract the value we just removed
      holder = holder + "1";
      num = num - place;
    }
    else 
    {
      // we cannot subtract the value therefore it is a smaller one so we put 0 and move on
      holder = holder + "0";
    }
    // keep dividing place value by two because that is the system
    place = place / 2;
    // when the num is = and the place is already at 1 we need to put it another 0 for the ones place because the loop is about to exit and we still have not looked at it
    if (place == 1 && num == 0)
    {
      holder = holder + "0";
    }
  }
  // return the string of binary to the calling function
  return holder;
}

// Funtion: take two floats and return the multiplcation of them
float add(float one, float two)
{
  float result = 0.00;
  result = one + two;
  return result;
}

// Funtion: take two strings and concatiante thenm together and return that string
string add(string one, string two)
{
  string result = "";
  result = one + two;
  return result;
}

// Funtion: take two ints (for binary once translated) add them and return the value
int add(int one, int two)
{
  int result = 0;
  result = one + two;
  return result;
}

// Funtion: take two floats multiply them together and return the value
float multiply(float one, float two)
{  
  float result = 0.00;
  result = one * two;
  return result;
}

// Funtion: take one string and one in and use a for loop to create a new string with mutliplys of first string
string multiply(string one, int num)
{
  string result = "";
  for(int i = 0; i < num; i++)
  {
    result = result + one;
  }
  return result;
}

// Funtion: multiply two ints together (for binary after we have translated into ints)
int multiply(int one, int two)
{
  int result = 0;
  result = one * two;
  return result;
}