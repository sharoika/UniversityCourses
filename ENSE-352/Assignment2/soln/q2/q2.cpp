// -*- c++ -*_

/**
    Project: 
      integer manipulation 
    Class: 
      ense352
    Programmer: 
      Maksim Sharoika
    Date: 
      2022-10-01
    Description:
        Addition that saturates to TMin or TMax 
        int16_t saturating_add(int16_t x, int16_t y);
*/

#include <stdint.h>
#include <limits.h>

/* two definitions for the maximum and minimum of a 16 bit integer */
#define Tmax 32767
#define Tmin -32768

// this function will add an x and a y parameter and watch for overflow and correct it to Tmax or Tmin
int16_t saturating_add(int16_t x, int16_t y)
{
    // find the bit size of the int16_t inputs
    int size = sizeof(x) << 3;

    // summing up x and y into a new integer called sum
    int sum = x + y; 

    // creating a MSB mask but making an int with a singular 1 in the LSB and shifting it to the MSB
    // we shift it from the right to the left from 0001 to 1000
    int MSBmask = 0x1 << (size - 1);

    // using the mask on x, y, and sum we are able to find the MSB in each one of them
    int MSBx = x & MSBmask;
    int MSBy = y & MSBmask;
    int MSBsum = sum & MSBmask; 

    // we use posOverflow as a flag value for positive overflow
    // if the MSB in x is 0, and the MSB in y is 0, but the MSB in sum is 1
    // then we know there was positive overflow
    int posOverflow =  MSBsum & ~MSBx & ~MSBy;

    // we use negOverflow as a flag value for negative overflow
    // if the MSB in x is 1, and the MSB in y is 1 but that same MSB position in sum is 0
    // then we know there was negative overflow
    int negOverflow = ~MSBsum & MSBx & MSBy;

    // if the posOverflow is true the statement will evaluate sum=Tmax is true therefore this
    // statement with function simialr to an if - if posOverflow is not true, then it will not
    // evalaute the second half of the statement
    ((posOverflow) && (sum = Tmax));

    // if the negOverflow is true the statement will evaluate sum=Tmin is true therefore this
    // statement with function simialr to an if - if negOverflow is not true, then it will not
    // evalaute the second half of the statement
    ((negOverflow) && (sum = Tmin));

    // return the sum that we calcalculated from the tw, or if it was overwritten by Tmin or Tmax
    return sum;
}