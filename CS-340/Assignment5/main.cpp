// MAKSIM SHAROIKA
// CS340
// ASSIGNMENT 5
// IMPLEMENTING VARIOUS TYPES OF SHELLSORT (SHELL, HIBBARD AND MAKSIM)

// precalling various header files for our program
#include <iostream>
#include <math.h>

// we will be using a standard namespace
using namespace std;

// pre-calling array functions used to help manipulate the environment for
// the sorting algorithm texting such as make, shuffle, copy, and print
void makeArray(int array[], int size);
void shuffleArray(int array[], int size);
void copyArray(int array1[], int array2[], int size);
void printArray(int array[], int size);

// Shell sort using Shell's Gap (...8, 4, 2...)
void ShellGapSort(int array[], int size) 
{
  // set the comparisons to 0
  int comparisons = 0;
  // while our gap is not 0 keep dividing it by 2
  for (int gap = size/2; gap > 0; gap = (gap / 2)) 
  {
    // start at our gap and while we are less than the size keep incrementing it
    for (int i = gap; i < size; i = (i + 1)) 
    {
      // create a temporary refrence to the current index
      int tmp = array[i];
      // set an index variable at 0 which is used to access locations in array
      int index = 0;
      // set the index to i and while it is greater than the gap, and if it greater then tmp
      // the comparisons++ in the boolean is used to actually track when we are doing an entry
      // to entry comparison since we don't go into the loop during each entry / increment
      // decrease the index by the gap if tmp was smaller and there is still room to go
      for (index = i; index >= gap && comparisons++ && array[index - gap] > tmp; index -= gap) 
      {
        // set the array index to that of the gap to the left of it in the array
        array[index] = array[index - gap];
      }
      // then set the index to the tmp which we saved above
      array[index] = tmp;
    }
  }
  // output the number of comparisons that took place during this algorithm
  cout << endl << "Comparisons: " << comparisons << endl;
}

// Shell sort using Hibbards's Gap (...7, 3, 1...)
void HibbardGapSort(int array[], int size) 
{
  // set the comparisons to 0
  int comparisons = 0;
  // i and j are looping variables but are refrenced outside of loop to arrays
  // therefore we want to initilize them outside of the loops
  int i = 0;
  int j = 0;
  // tmp is used to access indexes and store values in the array
  int tmp = 0;
  // a varialble to store the size of the gam depending
  int gap = 0;
  // use the 2^k - 1 idea to calculate the gap conversions drop the variables making
  // the gap change in the correct 15, 7, 3, 1 as it should droping the decimals
  for (gap = pow(2, (int(log(size) / log(2)))) - 1; gap > 0; gap = int(gap / 2)) 
  {
    // for each value at the gap and increment to end of array
    for (i = gap; i < size; i++) 
    {
      // set tmp to that value
      tmp = array[i];
      // check if it needs to be swaped with any behind it by factor of gap loop
      for (j = i; j >= gap; j -= gap) 
      {
        // we are about to compare therefore incremnet by 1
        comparisons++;
        // compare the location backwayds by gap to current
        if (tmp < array[j - gap]) 
        {
          // if needs to be swaped then swap
          array[j] = array[j - gap];
        } 
        // otherwise
        else 
        {
          // break out of the loop / array
          break;
        }
      }
      // set the remaining value to the one that was over written earlier
      array[j] = tmp;
    }
  }
  // output the number of comparisons that took place during this algorithm
  cout << endl << "Comparisons: " << comparisons << endl;
}

// Shell sort using Maksim's Gap (...16, 4, 1...)
void MaksimGapSort(int array[], int size)
{
  // set the comparisons to 0
  int comparisons = 0;
  // while our gap is not 0 keep dividing it by 4
  for (int gap = size/2; gap > 0; gap = (gap / 4)) 
  {
    // start at our gap and while we are less than the size keep incrementing it
    for (int i = gap; i < size; i = (i + 1)) 
    {
      // create a temporary refrence to the current index
      int tmp = array[i];
      // set an index variable at 0 which is used to access locations in array
      int index = 0;
      // set the index to i and while it is greater than the gap, and if it greater then tmp
      // the comparisons++ in the boolean is used to actually track when we are doing an entry
      // to entry comparison since we don't go into the loop during each entry / increment
      // decrease the index by the gap if tmp was smaller and there is still room to go
      for (index = i; index >= gap && comparisons++ && array[index - gap] > tmp; index -= gap) 
      {
        // set the array index to that of the gap to the left of it in the array
        array[index] = array[index - gap];
      }
      // then set the index to the tmp which we saved above
      array[index] = tmp;
    }
  }
  // output the number of comparisons that took place during this algorithm
  cout << endl << "Comparisons: " << comparisons << endl;
}

int main() {
  // creating three variables to refrence size to avoid any errors
  int size10 = 10;
  int size100 = 100;
  int size1000 = 1000;

  // create three array objects that will hold our main arrays
  int array10[size10];
  int array100[size100];
  int array1000[size1000];

  // put values into those arrays and then shuffle them (part of make)
  makeArray(array10, size10);
  makeArray(array100, size100);
  makeArray(array1000, size1000);

  // output the shuffled array of 10 to the terminal
  cout << "Created and shuffled array of 10: ";
  printArray(array10, size10);
  cout << endl;

  // output the shuffled array of 100 to the terminal
  cout << "Created and shuffled array of 100: ";
  printArray(array100, size100);
  cout << endl;

  // output the shuffled array of 1000 to the terminal
  cout << "Created and shuffled array of 1000: ";
  printArray(array1000, size1000);
  cout << endl;

  // create three tmp array that will keep holding copies of main so algorithms sort same
  int tmp_10[size10];
  int tmp_100[size100];
  int tmp_1000[size1000];

  // just some cleanup text to make it look more readable
  cout << "Output array functions disables due to size." << endl; 
  cout << endl << "--------------------" << endl;
  cout << "Sorting with array of 10: " << endl << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_10, array10, size10);
  cout << "ShellGapSort: ";
  ShellGapSort(tmp_10, size10);
  // printArray(tmp_10, size10);
  cout << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_10, array10, size10);
  cout << "HibbardGapSort: ";
  HibbardGapSort(tmp_10, size10);
  // printArray(tmp_10, size10);
  cout << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_10, array10, size10);
  cout << "MaksimGapSort: ";
  MaksimGapSort(tmp_10, size10);
  // printArray(tmp_10, size10);

  // more cleaup textj just to make stuff more readable
  cout << "--------------------" << endl;
  cout << "Sorting with array of 100: " << endl << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_100, array100, size100);
  cout << "ShellGapSort: ";
  ShellGapSort(tmp_100, size100);
  // printArray(tmp_100, size100);
  cout << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_100, array100, size100);
  cout << "HibbardGapSort: ";
  HibbardGapSort(tmp_100, size100);
  // printArray(tmp_100, size100);
  cout << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_100, array100, size100);
  cout << "MaksimGapSort: ";
  MaksimGapSort(tmp_100, size100);
  // printArray(tmp_100, size100);

  // more cleaup textj just to make stuff more readable
  cout << "--------------------" << endl;
  cout << "Sorting with array of 1000: " << endl << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_1000, array1000, size1000);
  cout << "ShellGapSort: ";
  ShellGapSort(tmp_1000, size1000);
  // printArray(tmp_1000, size1000);
  cout << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_1000, array1000, size1000);
  cout << "HibbardGapSort: ";
  HibbardGapSort(tmp_1000, size1000);
  // printArray(tmp_1000, size1000);
  cout << endl;

  // copy the main array into tmp and then sort using the correct algorithm
  copyArray(tmp_1000, array1000, size1000);
  cout << "MaksimGapSort: ";
  MaksimGapSort(tmp_1000, size1000);
  // printArray(tmp_1000, size1000);
  cout << "--------------------";

  // return 0 if the program ended with no errors
  return 0;
}

// function to create an array with entries from 0 to one, each has the value of its index
void makeArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    array[i] = i;
  }
  // then we call a shuffle function to shuffle the array since we are testing sorting
  shuffleArray(array, size);
}

// function to shuffle an array randomly
void shuffleArray(int array[], int size) 
{
  if (size > 1) 
  {
    // we are going to use the clocktime to help with sizing
    int i;
    srand(time(NULL));
    // go thru the array and randomly choose a spot to swap with
    for (i = 0; i < size - 1; i++) 
    {
      // perform the swap
      int j = i + rand() / (RAND_MAX / (size - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

// a function to copy from array2 into array2 index by index
void copyArray(int array1[], int array2[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    array1[i] = array2[i];
  }
}

// a function to print out the entire contents of an array
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    cout << array[i] << " ";
  }
  cout << endl;
}