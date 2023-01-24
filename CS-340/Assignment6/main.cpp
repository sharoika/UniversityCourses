// MAKSIM SHAROIKA
// CS340
// ASSIGNMENT 6
// IMPLEMENTING VARIOUS TYPES OF QUICKSORT

// precalling various header files for our program
#include <iostream>
#include <math.h>

// we will be using a standard namespace
using namespace std;

// pre-calling array functions used to help manipulate the environment for
// the sorting algorithm texting such as make, shuffle, copy, and print
void makeArray(int array[], int setting);
void shuffleArray(int array[], int size);
void copyArray(int array1[], int array2[], int size);
void printArray(int array[], int size);

// this is an insertion sort function that recieves an array, a low position
// value a size, and a pointer to a counter variable this then will sort that
// given subarray and increment the counter varaible with each count.
void insertionSort(int array[], int low, int size, int *counter) {
  for (int i = low + 1; i < size + 1; i++) {
    int number = array[i];
    int j = i;
    while ((*counter)++ && j > low && (*counter)++ && array[j - 1] > number) {
      array[j] = array[j - 1];
      j -= 1;
    }
    array[j] = number;
  }
}

// partion key 1->first, 2->middle, 3->second, 4->medium
// this is the partition portion of my solution, this will take an array, the
// first location of it, the second locations, a setting integer, and a counter
// pointer based on the setting a pivot will be chosen which then will be swaped
// to the last entry this finally then will do a partition based on magnitude
// and move the pivot to the right finally the algorithm will also return the
// position of the pivot to the quicksort algorithm
int partitionArray(int array[], int first, int last, int setting,
                   int *counter) {
  int pivot;
  // this will based on the setting swap the correct value with the final value for pivot
  if (setting == 1) {
    // setting one is using the first element
    int tmp = array[first];
    array[first] = array[last];
    array[last] = tmp;
  } else if (setting == 2) {
    // setting two is using the middle element
    int tmp = array[(last + first) / 2];
    array[(last + first) / 2] = array[last];
    array[last] = tmp;
  } else if (setting == 3) {
    //setting three is using the second element
    int tmp = array[first + 1];
    array[first + 1] = array[last];
    array[last] = tmp;
  } else if (setting == 4) {
    // the fourth setting is the most confusing but it basically compares the middle, first,     // and last entry and decides which to use for the algorithm
    int one, two, three;
    one = array[first];
    two = array[(last + first) / 2];
    three = array[last];
    if ((one >= two && one <= three) || (one <= two && one >= three)) {
      // if first is the middle value swap it with the last place
      (*counter)++;
      (*counter)++;
      int tmp = array[first];
      array[first] = array[last];
      array[last] = tmp;
    } else if ((two >= one && two <= three) || (two <= one && two >= three)) {
      // if middle is the middle value swap it with last place
      (*counter)++;
      (*counter)++;
      int tmp = array[(last + first) / 2];
      array[(last + first) / 2] = array[last];
      array[last] = tmp;
      // if none we already have the middle in the last place
    }
  } else {
    // if we for some reason screwed up in the code I wanted to be notified
    cout << "Error, incorrect partition setting.";
    return -1;
  }
  // the pivot value has been moved to the last place so we can use a simple last place
  // as the pivot algorithm to "sort" and partition our array
  pivot = array[last];
  int i = first;
  int j = first;
  // if we find something in the wrong place switch if with j, and increment j while i keeps
  // going forward
  for (int i = first; i < last; i++) {
    if (((*counter)++ && array[i] < pivot)) {
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      j += 1;
    }
  }
  int temp = array[j];
  array[j] = array[last];
  array[last] = temp;
  return j;
}

// partion key 1->first, 2->middle, 3->second, 4->medium
// this is the quicksort portion of the code, it will take an array, a start of it,
// an end of it, and a cutoff parameter, a partition setting parameter, and lastly a counter
// the reason for so many parameters is the idea of modular code, this will now work as a 
// recursive function calling the correct partition due to the given parameter and then 
// calling itself with the same parameters keeping the type of partition and counter pointer
// the same as the previous call
void quickSort(int array[], int start, int end, int cutoff, int partition,
               int *counter) {
  // while we are still in the array
  while (start < end) {
    // if we are within cutoff size
    if (end - start + 1 < cutoff) {
      // we will call an insertion sort algorithm and break
      insertionSort(array, start, end, counter);
      break;
    } else {
      // otherwise we will set the pivot to 0
      int pivot = 0;
      // get the actual pivot based on the correct partition function
      pivot = partitionArray(array, start, end, partition, counter);
      // then call a recursive call depending on the arrays
      if (pivot - start < end - pivot) {
        quickSort(array, start, pivot - 1, cutoff, partition, counter);
        start = pivot + 1;
      } else {
        quickSort(array, pivot + 1, end, cutoff, partition, counter);
        end = pivot - 1;
      }
    }
  }
}

int main() {
  int arrayIncreasing[100];
  int arrayRandom[100];
  int arrayDecreasing[100];

  makeArray(arrayIncreasing, 0);
  // printarray(arrayIncreasing, 100);
  // cout << endl;

  makeArray(arrayRandom, 0);
  shuffleArray(arrayRandom, 100);
  // printarray(arrayRandom, 100);
  // cout << endl;

  makeArray(arrayDecreasing, 1);
  // printarray(arrayDecreasing, 100);
  // cout << endl;

  // a tmp array, and number, and pointer for calculating
  int tmpArray[100];
  int number;
  int *counter = &number;

  cout << "--------------------------------------------------" << endl;
  cout << "Increasing array of 100 elements: " << endl;
  cout << "No Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "FIVE Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "TEN Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "TWENTY Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayIncreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "--------------------------------------------------" << endl;
  cout << "Random array of 100 elements: " << endl;
  cout << "No Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 0, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 0, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 0, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 0, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "FIVE Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 5, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 5, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 5, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 5, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "TEN Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 10, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 10, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 10, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 10, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "TWENTY Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 20, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 20, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 20, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayRandom, 100);
  quickSort(tmpArray, 0, 99, 20, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "--------------------------------------------------" << endl;
  cout << "Decreasing array of 100 elements: " << endl;
  cout << "No Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 0, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "FIVE Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 5, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "TEN Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 10, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "TWENTY Cutoff: " << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 1, counter);
  cout << "Pivot First Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 2, counter);
  cout << "Pivot Middle Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 3, counter);
  cout << "Pivot Second Element Comparisons: " << *counter << endl;
  (*counter) = 0;
  copyArray(tmpArray, arrayDecreasing, 100);
  quickSort(tmpArray, 0, 99, 20, 4, counter);
  cout << "Pivot Medium Element Comparisons: " << *counter << endl;
  cout << "--------------------------------------------------" << endl;
  return 0;
}

// function to create an array
void makeArray(int array[], int setting) {
  if (setting == 0) {
    for (int i = 0; i < 100; i++)
      array[i] = i;
  }
  if (setting == 1) {
    for (int i = 0; i < 100; i++)
      array[i] = (99 - i);
  }
}

// function to shuffle an array randomly
void shuffleArray(int array[], int size) {
  if (size > 1) {
    // we are going to use the clocktime to help with sizing
    int i;
    srand(time(NULL));
    // go thru the array and randomly choose a spot to swap with
    for (i = 0; i < size - 1; i++) {
      // perform the swap
      int j = i + rand() / (RAND_MAX / (size - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

// a function to copy from array2 into array1 index by index
void copyArray(int array1[], int array2[], int size) {
  for (int i = 0; i < size; i++) {
    array1[i] = array2[i];
  }
}

// a function to print out the entire contents of an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}