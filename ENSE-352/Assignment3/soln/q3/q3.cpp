/** -*-c++-*-
    Project: solution to as3, q3
    Class: ense352
    Programmer: Maksim Sharoika
    Description: 
        Write code for a function mul3div4 that, for 
        integer argument x, computes 3*x/4, but following 
        the bit-level integer coding rules given in assignment 
        1. Your code should replicate the fact the computation 
        3*x can overflow. (That is: exactly duplicate the operation 
        of 3*x/4)
*/

/**
   Returns the result of multiplying x by 3, then dividing by 4.  In
   particular, the multiplication by 3 may overflow, just as when the
   C compiler does it.

   @pre nothing
 */

int mul3div4(int x)
{
    // create a width integer and store the width of x in it
    int width;
    // grab the bitwise width of x and store it in width
    width = sizeof(x) << 3;

    // shifting x one to the left, and then adding an x is the equivalent 
    // saving it as a working int - this allows x to be refrenced correctly
    int working;
    // of multipling by 3 because a shift is multiplciation by 2
    working = (x << 1) + x;

    // create a variable to store a mask in the form of 1000...0000
    int mask;
    // this take 1 and keeps shifting it right the width minus one 
    // since int is 32 bits this would shift it by 31 bits
    mask = 0x1 << (width - 1);

    // using a neg variable as a value to indicate if the current value is negative
    int neg;
    // the working value after multiplication is ANDed with the mask which has 100...000
    // this would now be 100...000 if negative, and 000...000 if positive
    neg = working & mask;

    // this works similar to an if statement if the neg is in the form of 100...000
    // indicating a negative working number from above then we will add 3 to working
    // this is due to negative numbers being rounded in the wrong direction so we 
    // need to bias the dividend toward 0 by doing the below, since our k must be 2
    // k / 4 == (value + 3) / 4 for negative values
    // k / 4 == (value) / 4 for positive values
    (neg & 0x80000000) && (working = working + 3);

    // working shifting 2 to the right is the division by 4, its adjusted earlier with a + 3 if needed
    return working >> 2;
}
