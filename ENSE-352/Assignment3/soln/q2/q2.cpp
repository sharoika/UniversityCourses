/** -*-c++-*-
    Project: solution to as3, q2
    Class: ense352
    Programmer: Maksim Sharoika
    Description: 
        The function should compute x/2k with correct rounding 
        (round toward 0), and it should follow the bit-level integer 
        coding rules given in assignment 1.
*/

/**
   Return x/2**k with correct truncation toward 0.
   @pre 0 <= k < w-1.
 */

int divide_power2(int x, int k)
{
    // create an integer called tmp
    int tmp;
    // tmp will be either all 1's or all 0's depending on current signed bit of x
    tmp = x >> ((sizeof(x) << 3) - 1);

    // now we create a mask integer
    int mask;
    // we will push tmp to the left and fill it with zero's therefore it will either
    // be 11...0000 or 00...0000 depending if the sign bit was a 0 or 1 of x to begin
    mask = tmp << k;

    // now we create an integer called afterMask to hold our calculation afterwards
    int afterMask;
    // we will bitwise AND tmp which is currently all 0's or all 1's with the complement mask
    // example: x=111000 (-8) k=2
    // tmp=111111 mask=111100 therefore ~mask=000011 and therefore afterMask=000011
    afterMask = tmp & ~mask; 

    // then we will clean it using a results integer
    int result;
    // afterMask=000011 we OR it with start x=111000 therefore result=111011
    // then we have to shift to the right two bits which will give us 
    // result=111110 (-2)
    result = (x + afterMask) >> k;

    // finally we will return the result
    return result;
}