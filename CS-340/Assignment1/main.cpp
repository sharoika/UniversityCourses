// MAKSIM SHAROIKA
// CS340
// main.cpp
// ASSIGNMENT 1

// including libraries
#include <math.h>
#include <iostream>

// pre calling functions
long long assignment1Algorithm(long long n); 

int main() {
  // a flag used to do some control 
  int flag = 0;
  // a integer used to accept input for size
  int n; 
  // large accurate decimal numbers for calculations
  long double timeUsed, result; 
  // variables representing processor usage times 
  clock_t start, finish; 

  // the program while loop
  while(flag != 1)
  {
    // requesting input
    std::cout << "Please enter a value for n:\n"; 
    std::cin >> n; 
    // given - calculates the clock time before, and after the function. 
    start = clock(); 
    result = assignment1Algorithm(n);
    finish = clock(); 
    // type casted time used calculation
    timeUsed = ((long double)(finish - start))/CLOCKS_PER_SEC;
    // outputs based on the requirement of this assignment 
    std::cout << "(i) " << result << std::endl; 
    std::cout << "(ii) " << (long double)n/result << std::endl;
    std::cout << "(iii) " << (long double)n*log2((long double)n)/result << std::endl;
    std::cout << "(iv) " << pow((long double)n, 1.5)/result << std::endl;
    std::cout << "(v) " << timeUsed << std::endl;
    std::cout << "(vi) " << (long double)n/timeUsed << std::endl;
    std::cout << "(vii) " << (long double)n*log2((long double)n)/timeUsed << std::endl;
    std::cout << "(viii) " << pow((long double)n, 1.5)/timeUsed << std::endl << std::endl;
  }
}

// the given function
long long assignment1Algorithm(long long n)
{
  // sum
  long long sum = 0;
  // while i is less than n (n)
  for(long long i=1; i<=n; i++)
  {
    // while j is less then half of itself (log n)
    for(long long j=n; j>1; j=floor(j/2))
    {
      // summing
      sum += 1;
      }
    }
  // return 
  return(sum);
  }
