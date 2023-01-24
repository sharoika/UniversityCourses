// -*- c++ -*_

/**
    Project: 
      integer manipulation 
    Class: 
      ense352
    Programmer: 
      Maksim Sharoika
    Date: 
      2022-9-25
    Description:
      Write C (or C++ if you like) functions that evaluate to 1 when the given 
      conditions are true, and to 0 when they are false. The following are the 
      four required prototypes, and the conditions
*/

#include <limits.h>              // for INT_MIN, etc

// given function for a
// Any bit of x equals 0.
int a(int x)
{
    /** 
    having a well sized value of 1's in bits:
    for ~0 : ~[0000 0000 0000 0000] = [1111 1111 1111 1111]
    changing the value of 0 to 1 to allow for comparison:
    for ~x : ~[1010 1010 1010 1010] = [0101 0101 0101 0101]
    lastly logically logic if there is a 0 in x, which is currently a 1. 
    */
    return (~0 && ~x);
}

// given function for d
// Any bit of x equals 1.
int b(int x)
{
    /** 
    having a well sized value of 1's in bits:
    for ~0 : ~[0000 0000 0000 0000] = [1111 1111 1111 1111]
    for x : [1010 1010 1010 1010]
    lastly logically logic if there is a 1 in x with the use of the ~0
    */
    return (x && ~0);
}

// given function for c
// Any bit in the LSB of x equals 0.
int c(int x)
{
    // first we find the shift that is needed to isolate the LSB (maxsize - 8bits)
    int shft_size = ((sizeof(x) << 3)-8);
    // we get a arc_x which is just an inverting all bits in x with the next line
    int ARC_X = ~(x);
    // next we first logic AND the LSB with 0xFF which will leave 1's which were inverted from 0's above and shift
    int pushed = ((ARC_X & 0xFF) << (shft_size));
    // lastly we check if any 1's are present with a ~0 (1's represent 0's currently)
    return (pushed && ~0);
}

// given function for d
// Any bit in the MSB of x equals 1.
int d(int x)
{
    // first i find the value of bits in x so I am able to shift properly without affecting last byte
    int shft_size = ((sizeof(x) << 3)-8); 
    // now I shift 1111 1111 to the left equal to the number of bytes minus 8 bits to keep 1111 1111
    int MSB = 0xFF << shft_size;
    // now I compare 1111 1111 0000 ... 0000 to x for example: 1000 0000 1010 ... 1010] would be true
    return (MSB && x);
}