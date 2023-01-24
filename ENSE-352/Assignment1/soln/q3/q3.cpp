#include<stdio.h>

/**
    Project: 
      word maniupulation
    Class: 
      ense352
    Programmer: 
      Maksim Sharoika
    Date: 
      2022-9-25
    Description:
      Implement a function which rotates a word left by n-bits, and
      returns that rotated value.  Assume 0 <= n < w
*/

// given function for this problem
unsigned rotate_left(unsigned x, int n)
{
    // we move the word by n to the left
    // [1100 1100 1000 1000 1000 1000 1000 1000] = [1000 1000 1000 1000 1000 1000 0000 0000]
    unsigned left = (x << n);
    // we move the word by (32-n) to the right
    // [1100 1100 1000 1000 1000 1000 1000 1000] = [0000 0000 0000 0000 0000 0000 1100 1100]
    unsigned right = (x >> (32 - n));
    // return the OR of the both, because we know the locations which shifted at at 0
    // therefore if we perform an OR operation it will take whats comping from the unshifted digits.
    // [1000 1000 1000 1000 1000 1000 0000 0000] | [0000 0000 0000 0000 0000 0000 1100 1100]
    // = [1000 1000 1000 1000 1000 1000 1100 1100]
    return (left)|(right);
}