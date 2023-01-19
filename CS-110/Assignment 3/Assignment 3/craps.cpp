/**
 Student Name: MAKSIM SHAROIKA
 Student Number: 200446763
 Assignment: Assignment 3
 Program Name: craps.cpp
 Date Written: March 12 2021
 Problem Statement: Create a simulation game of "craps" a popular casino game
 Input: There is no user input, there is a random seed generated based on time for every run.
 Output: Each run will be output  into the terminal alongside the run rolls, the sum of the dice and if you "craped" out goes until the end.
*/
/**
 Main Algorithm:
 Generate a random seed based on time.
 Roll two dice.
 Sum up the dice.
 If the sum is 2, 3, or 12 you lose, if the sum is 7 or 11 you win, otherwise the point is set to the sum and the game continues.
 You continue rolling until you either get a 7 and lose or get the point number and win.
 Program output lose or win messege.
 Program ends.
 */
/**
 Variables:
 integer - die1 : the integer that is rolled by the first die.
 integer - die2 : the integer that is rolled by the second die.
 integer - sum : the sum of both the die once they are rolled.
 integer - point_value : if the point is set then it will be held in this variable.
 bool - game : if the game is running or if it ended.
 bool - point : if we have entered the "point" phase of the game. 
 */
/**
 Program limitations: none, it follows the rules of craps does not allow for a lot of user interaction.
 */

#include <iostream> // include standard terminal input and output

using namespace std; // this program is using a standard namespace environment

void GetRoll(int &num); // prototype for the GetRoll function
int CalcSum(int num1, int num2); // prototype for the CalcSum function
void PrintRoll(int num1, int num2, int local_sum); // prototype for the PrintRoll function

int main() // main function for the program
{
    int die1 = 0; // integer for the value of the first die
    int die2 = 0; // integer for the value of the second die
    int sum = 0; // integer for the sum value of both of the dice
    int point_value = 0; // the value of the point if established
    bool game = true; // the boolean that states if the game is running
    bool point = false; // the boolean that states if the game has entered point
    
    srand((unsigned) time(0)); // setting a random seed for the program based on time
    
    while(game) // while the game is "true" run the loops
    {
        GetRoll(die1); // roll a value for the first die
        GetRoll(die2); // roll a value for the second die
        
        sum = CalcSum(die1, die2); // add up the first die and the second die for a sum
        
        PrintRoll(die1, die2, sum); // call the function to print the dice and the sum of them to terminal
        
        if(sum == 2 || sum == 3 || sum == 12) // losing criteria if the sum is 2, 3, 12
        {
            cout << "You lose"; // print out "you lose" to the screen
            game = false; // end the game
        }
        else if(sum == 7 || sum == 11) // winning criteria if the sum is 7, 11
        {
            cout << "You win" << endl; // print out "you win" to the screen
            game = false; // end the game
        }
        else
            // the game goes into point
        {
            point = true; // set the point boolean to true
            point_value = sum; // set the point integer to the value rolled previously
            cout << "point is " << point_value << endl; // output the value of the point along
            while(point) // loop for while the point is established and game has not ended
            {
                GetRoll(die1); // roll die one
                GetRoll(die2); // roll die two
                
                sum = CalcSum(die1, die2); // calculate the sum of die one and die two
                
                PrintRoll(die1, die2, sum); // call the function to print the dice and the sum of them to terminal
                
                if(sum == 7) // losing criteria if the sum is 7
                {
                    cout << "You lose" << endl; // print out "you lose" to the screen
                    point = false; // end the point
                    game = false; // end the game
                }
                else if(sum == point_value)
                {
                    cout << "You win" << endl; // print out "you win" to the screen
                    point = false; // end the point
                    game = false; // end the game
                }
                
            }
        }
    }
    cout << endl; // create a new line before the program ends
    return 0; // return 0 of main function
}

void GetRoll(int &num) // pass by refrence to change the die value
{
    num = int(rand() % 6 + 1);
    // use the rand command and remainder of division by 6 to get a remainder between 0-5
    // add 1 to it to get ratio between 1-6 which is the possible values on a die
}

int CalcSum(int num1, int num2) // pass by value because we dont care to change die number
{
    int local_sum; // integer to calculate the sum within function
    local_sum = num1 + num2; // calculating the sum
    return local_sum; // returning the calculated sum
}

void PrintRoll(int num1, int num2, int local_sum) // pass by value because we dont care to change any of them
{
    cout << "You rolled " << num1 << " + " << num2 << " = " << local_sum << endl;
    // print out the two die numbers alongside the calculated sum
}
