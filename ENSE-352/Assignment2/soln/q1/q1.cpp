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
        Return the minimum number of bits required to store x as a signed
        2s complement number, where x is a 64-bit signed int.
        Assume 1 <= n <= w
        Example: -1 => 1, 1 => 2, 6 => 4, 127 => 8, -128 => 8, 300 => 10
*/

#include <stdint.h>
#include <limits.h>

using namespace std;

// this function is designed to find the miniimum number of a bits of complement twos
// number will need to store a given x 64 bit integer number
int64_t minimum_2s_comp_bits(int64_t x)
{
  /** these are all values in hex of important binary patterns */
  // 0101010101010101... 
  int64_t A  = 0x5555555555555555;
  // 0011001100110011...
  int64_t B  = 0x3333333333333333;
  // 0000111100001111...
  int64_t C  = 0x0f0f0f0f0f0f0f0f;
  // 8 zeros, 8 ones ...
  int64_t D  = 0x00ff00ff00ff00ff;
  // 16 zeros, 16 ones ...
  int64_t E = 0x0000ffff0000ffff;
  // 32 zeros, 32 ones ...
  int64_t F = 0x00000000ffffffff;
  // this isolates the signed bit at the beginning by shifting it to the right 63 spots
  // then we will use a mask to to remove all the bits to the left of the 64th which moved to 1st
  // 1) it will go from 0101 1010 to 0000 0000 to 0000 0000
  // 2) it will go from 1101 0110 to 1111 1111 to 0000 0001
  int64_t signed_bit = ((x >> 63) & 0x000000001);

  // this will function similar to an if statement if the first part of it is
  // false then the second part will not evlaute at all therefore not happen 
  // if - the signed bit is 1, i.e x was negative
  // then - we want to set the x to its complement form 
  ((signed_bit & 0x00000001) && (x = ~x));

  // this is an algorithm and lines to copy a 1 down the lines 
  // this is done in shifting and the doing an or against the older version
  // 0010 0000 | 0001 0000 = 0011 0000 (shift 1)
  // 0011 0000 | 0000 1100 = 0011 1100 (shift 2)
  // 0011 1100 | 0000 0011 = 0011 1111 (shift 4)
  // as you see the 1 and all digits after it were copied now this is
  // the same thing but up to 32 which would work for any 64 bit number
  int64_t working = x;
  // shift 1 to the left
  working = (working >> 1) | working;
  // shift 2 to the left
  working = (working >> 2) | working;
  // shift 4 to the left
  working = (working >> 4) | working;
  // shift 8 to the left
  working = (working >> 8) | working;
  // shift 16 to the left
  working = (working >> 16) | working;
  // shift 32 to the left
  working = (working >> 32) | working;

  /* these are the operations required to find the hamming weight of the input */
  // put the count of 1's in each two bits into those two bits as a representation:
  // 01 -> 01 | 11 -> 10 | 00 -> 00
  working = (working & A) + ((working >>  1) & A);
  // put the count of 1's in each four bits into those four bits as a representation:
  // 0011 -> 0010 | 1111 -> 0100 | 0111 -> 0011 
  working = (working & B) + ((working >>  2) & B);
  // put the count of 1's in each eight bits into those eight bits as a representation:
  // 01 -> 01 | 11 -> 10 | 00 -> 00
  working = (working & C) + ((working >>  4) & C);
  // put the count of 1's in each sixteen bits into those sixteen bits as a representation:
  // 01 -> 01 | 11 -> 10 | 00 -> 00
  working = (working & D) + ((working >>  8) & D);
  // put the count of 1's in each thirtytwo bits into those thirtytwo bits
  working = (working & E) + ((working >> 16) & E);
  // put the count of 1's in each sixtryfour bits into those sixtyfour bits
  working = (working & F) + ((working >> 32) & F);

  // now that its all 1's we will save the bitcounted from above
  // all the '1's this will return it and store it in count
  int64_t count = working;

  // if 'x' is a signed int with a 0 (positive) we will call a count + 1
  // this is to account for the extra leading bit that is required in front
  // of a positive for example -1 is 1 while 1 would requir 01 
  ((signed_bit & 0x0) && (count = count + 1));

  // finally return the count accounting for a final bit which is lost during previous calculation
  // the hamming algorithm tends to lose one count due to the way the algorithm is setup and called
  return (count + 1);
}