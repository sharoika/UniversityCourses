// MAKSIM SHAROIKA - 200446763
// Program: main.cpp
// Created: October 3rd / 2022
// This program is designed to implement a heap and special function
// for assignment three at the University of Regina in CS340.

// including IO stream for output and input
#include <iostream>

// this function takes in an array and reads in all entries for its size
void readArray(int *array, int size)
{
  // we will use a cin statement with a loop
  for (int i = 1; i <= size; i++)
  {
    std::cin >> array[i];
  }
}

// this function takes in an array and will read out all entries for size
void printArray(int *a, int size)
{
  // we will sue a cout statement with a loop
  std::cout << std::endl;
  for (int i = 1; i <= size; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

// this will build our heap structure by moving required entries
void perculateDown(int *array, int z, int size)
{
  // this uses the idea that parent * 2 is a child
  int v = array[z];
  int u = 2 * z;
  // this will compare parents to childs and swap if that is required
  while (u <= size)
  {
    // if the child is in scope & bigger then other child move onto other
    if (u < size && array[u + 1] < array[u])
    {
      u = u + 1;
    }
    // if we are "safe" with the statement move on
    if (v < array[u])
    {
      break;
    }
    // if we find a discrepency perform a switch and then move on
    else if (v >= array[u])
    {
      array[u / 2] = array[u];
      u = 2 * u;
    }
  }
  // set the final position we worked to position we started looking at
  array[u / 2] = v;
  return;
}

// function to loop threw all the entries of an array to the middle
// we can go to the middle because the bottom leaves do not matter
// if heap property held for top it should hold for all
void buildHeap(int *array, int size) {
  for (int i = size / 2; i > 0; i--)
  {
    perculateDown(array, i, size);
  }
}

/* THIS FUNCTION CAUSES A MAX HEAP INSTEAD OF A MIN HEAP */
// given function to call a build heap and then call the given ideas
void whatDoIDo(int *array, int size) {
  // build
  buildHeap(array, size);
  std::cout << "MinHeap before becoming a MaxHeap: ";
  printArray(array, size);
  // instead of implementing a perculate down function we are able
  // to accomplish the same reusing the build heap function
  // this is extreamly useful
  for (int j = size; j > 1; j--)
    {
      int tmp = array[j];
      array[j] = array[1];
      array[1] = tmp;
      // the way i coded it i access perculate down thru the build
      // heap function
      buildHeap(array, j-1);
    }
  // print
  printArray(array, size);
  std::cout << std::endl << std::endl;
}

// main contains code to take in the number of elements
// take in the elements for each array
// call the given WhatDoIDo function which builds and manipulates
int main()
{
  int size_a, size_b, size_c = 0;

  // each of these sections just grabs the size of the array and its entries
  // its built to be modular code
  std::cout << "Enter number of elements for array A:";
  std::cin >> size_a;
  int a[size_a];
  std::cout << "Enter " << size_a << " elements for array A:";
  readArray(a, size_a);

  // each of these sections just grabs the size of the array and its entries
  // its built to be modular code
  std::cout << "Enter number of elements for array B:";
  std::cin >> size_b;
  int b[size_b];
  std::cout << "Enter " << size_b << " elements for array B:";
  readArray(b, size_b);

  // each of these sections just grabs the size of the array and its entries
  // its built to be modular code
  std::cout << "Enter number of elements for array C:";
  std::cin >> size_c;
  int c[size_c];
  std::cout << "Enter " << size_c << " elements for array C:";
  readArray(c, size_c);

  // making some room after the data pulls from user
  std::cout << std::endl << std::endl;

  // using the given function in class
  whatDoIDo(a, size_a);
  whatDoIDo(b, size_b);
  whatDoIDo(c, size_c);
}
