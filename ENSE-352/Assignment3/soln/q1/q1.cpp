/** -*-c++-*-
    Project: solution to as3, q1
    Class: ense352
    Programmer: Maksim Sharoika
    Description: 
        Write a function with the prototype
        unsigned f2u(float x);
        which returns an unsigned 32-bit number with the same bit pattern as x.
*/

/**
  Return f as an unsigned, without changing the bit pattern
*/

unsigned f2u(float f)
{
  // create an insigned pointer
  unsigned *pointer;

  // take the unsigned pointer and point it to the first bit
  // of the float of f by taking its address and type casting it
  pointer = ((unsigned *)&f);
  
  // return the new pointer of type unsigned pointing to the old float bits
  return *pointer;
}