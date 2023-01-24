/**
    Project: 
      word shuffleing bit maniupulation. 
    Class: 
      ense352
    Programmer: 
      Maksim Sharoika
    Date: 
      2022-9-25
    Description:
      Given words x and y of type T, assumed to be integral types of 16,
      32, or 64-bits in size, return a word composed of the MSB and LSB x,
      and the remaining bytes taken from y.
      For 32-bit operands x = 0x89ABCDEF and y = 0x76543210,
      this would give 0x895432EF. 
      For 16-bit operands x = 0x5555 and y = 0x1234 this would give
      0x5555 (because there’s no remaining bytes after the MSB/LSB
      are extracted).
*/

// given template of typename T
template <typename T>
// given function for shuffle words
T shuffle_words(T x, T y) 
{
  // a calculation of the bitsize of the typename T
  int T_size = sizeof(T) << 3;
     
  // creating a typename varaible result for the final solution
  T result = y;  

  // creating a hex for cleaning up :   [1111 1111 1111 1111]                 
  T blank = 0xFF;     

  // MSB usees cleanup hex, shifted to left untill :   [1111 1111 0000 0000 0000 0000]         
  T MSB = (blank << (T_size-8)); 

  // LSB uses clenup hex, with no shift which is equal to the currenty 8 bits of: [1111 1111]
  T LSB = (blank);       

  /** 
  removal of result's MSB :
  [1010 1010 1010 1010 1010 1010] & [0000 0000 1111 1111 1111 1111] = [0000 0000 1010 1010 1010 1010]
  */
  result = result & ~(MSB);    

  /** 
  removal of sults's LSB :
  [1010 1010 1010 1010 1010 1010] & [1111 1111 1111 1111 0000 0000] = [1010 1010 1010 1010 0000 0000]
  */
  result = result & ~(LSB);      

  /** 
  isolation of x's MSB :
  [1010 1010 1010 1010 1010 1010] & [1111 1111 0000 0000 0000 0000] = [1010 1010 0000 0000 0000 0000]
  */
  T MSBx = x & MSB;

  /** 
  isolation of x's LSB :
  [1010 1010 1010 1010 1010 1010] & [0000 0000 0000 0000 1111 1111] = [000 0000 0000 0000 1010 1010]
  */
  T LSBx = x & LSB;

  /**
  result calculation using OR login, knowing MSBx is only MSB of x, LSBx is LSB of y, 
  and result is missing its MSB and LSB :
  [0000 0000 1010 1010 0000 0000] | [1010 1010 0000 0000 0000 0000] | [0000 0000 0000 0000 1010 1010]
  = [000 0000 0000 0000 1111 1111]
  */
  result = result | MSBx | LSBx;

  // returnign the calculated result
  return result;
}