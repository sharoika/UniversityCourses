// Name: MAKSIM SHAROIKA
// Student Number: 200446763
// Date: October 26 / 2021

// Filename: 200446763.cpp
// re-editing code for new specifications

// header files used in the program
#include <iostream>
#include <iomanip>
#include <string>

// class declaration for Distance
class Distance
{
  // data members
  private: 
  int feet;
  float inches; 
  public: 
  // constructors
  Distance();
  Distance(int, float);
  // copy constructor 
  Distance(const Distance&);
  // getters & setters
  int getFeet() const;
  float getInches() const;
  void setFeet(int);
  void setInches(float);
  // functions
  float toDecimal() const;
  std::string toString() const;
  // operators
  Distance operator + (Distance d);
  Distance operator - (Distance d);
  Distance& operator = (Distance d);
  Distance& operator += (Distance d);
  Distance& operator -= (Distance d);
  bool operator < (Distance d) const; 
  bool operator > (Distance d) const; 
  bool operator <= (Distance d) const; 
  bool operator >= (Distance d) const; 
  bool operator == (Distance d) const; 
  bool operator != (Distance d) const; 
};

// class declation for Box
class Box
{
  // data members
  private:
  Distance length;
  Distance width;
  Distance height;
  static int count;
  public: 
  // constructors
  Box();
  Box(Distance a, Distance b, Distance c) : length(a), width(b), height(c) {count ++;};
  // copy constructor 
  Box(const Box&);
  // destructor
  ~Box();
  // getters & setters
  Distance getLength() const;
  Distance getWidth() const;
  Distance getHeight() const;
  void setLength(int, float);
  void setWidth(int, float);
  void setHeight(int, float);
  // functions
  float volume() const;
  // static count
  static int getCount();
  // operators
  bool operator < (Box d) const; 
  bool operator > (Box d) const; 
  bool operator <= (Box d) const; 
  bool operator >= (Box d) const; 
  bool operator == (Box d) const; 
  bool operator != (Box d) const; 
  Box& operator = (Box d);
};

// pre-calling input functions used for error checking
int InputInt();
float InputFloat();

// initilizing the static integer
int Box::count = 0;

// main function
int main() 
{
  // declaring the distances to use in the program to complete all the steps
  Distance d1;
  Distance d2;
  Distance d3;
  Distance d4;

  ////////////
  // part 1.1
  ////////////
  std::cout << "Problem 1: " << std::endl;
  // setting data in practice problem
  d1 = {3, 9};
  d2 = {3, 6};
  // calculating the product and changing to string
  std::cout << "Distance d1: " << d1.toString() << std::endl; 
  std::cout << "Distance d2: " << d2.toString() << std::endl; 
  std::cout << "d1 + d2 = " << (d1+d2).toString() << std::endl;
  std::cout << "d1 - d2 = " << (d1-d2).toString() << std::endl; 
  std::cout << std::endl;
  ////////////
  // part 1.2
  ////////////
  // setting the data to same as practice problem
  d1 = {3, 9};
  d2 = {4, 6};
  // calculating the product and changing to string
  std::cout << "Distance d1: " << d1.toString() << std::endl; 
  std::cout << "Distance d2: " << d2.toString() << std::endl; 
  std::cout << "d1 + d2 = " << (d1+d2).toString() << std::endl;
  std::cout << "d1 - d2 = " << (d1-d2).toString() << std::endl; 
  std::cout << std::endl;

  /////////
  // part 2
  /////////
  std::cout << "Problem 2: " << std::endl;
  // setting the data to same as practice problem
  d1 = {3, 9};
  d2 = {3, 6};
  d3 = {0, 0};
  // outputing that data
  std::cout << "Distance d1: " << d1.toString() << std::endl;
  std::cout << "Distance d2: " << d2.toString() << std::endl;
  // doing a three tier assignment and then outputing to verify
  d3 = d2 = d1;
  std::cout << "After assigning d1 to d2 to d3" << std::endl;
  std::cout << "Distance d1: " << d1.toString() << std::endl; 
  std::cout << "Distance d2: " << d2.toString() << std::endl; 
  std::cout << "Distance d3: " << d3.toString() << std::endl; 
  std::cout << std::endl;

  /////////
  // part 3
  /////////
  std::cout << "Problem 3: " << std::endl;
  d1 = {3, 9};
  d2 = {3, 6};
   // calculating the product and changing to string
  std::cout << "Distance d1: " << d1.toString() << std::endl; 
  std::cout << "Distance d2: " << d2.toString() << std::endl; 
  std::cout << "New value of d2 after d2+=d1 operation: " 
  << (d2+=d1).toString() << std::endl;
  std::cout << std::endl;

  /////////
  // part 4
  /////////
  std::cout << "Problem 4: " << std::endl;
  // setting the data to same as practice problem
  d1 = {3, 9};
  d2 = {3, 6};
  // outputting the data to use to verify
  std::cout << "Distance d1: " << d1.toString() << std::endl; 
  std::cout << "Distance d2: " << d2.toString() << std::endl; 
  // using boolean logic ti describe what is happening
  if (d1 > d2)
  {
    std::cout << "d1 is larger than d2" << std::endl;
  }
  if (d1 < d2)
  {
    std::cout << "d1 is smaller than d2" << std::endl;
  }
  if (d1 == d2)
  {
    std::cout << "d1 is the same as than d2" << std::endl;
  }
  std::cout << std::endl;
  ////////
  //part 5
  ////////
  // this section was restructed from the previous program to function with new operators
  std::cout << "Problem 5: " << std::endl;
  int f1, f2, f3 = 0;
  float i1, i2, i3 = 0;
  // initilizing the four boxes

  // box 1
  std::cout << "Box 1" << std::endl;
  Box box1;
  // requesting the length from user
  std::cout << "Enter the length" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // setting length from input
  box1.setLength(f1, i1);
  // requesting the width from user
  std::cout << "Enter the width" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // setting width from input
  box1.setWidth(f1, i1);
  // requesting the height from user
  std::cout << "Enter the height" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // setting height from input
  box1.setHeight(f1, i1);

  // box 2
  Box box2;
  std::cout << "Box 2" << std::endl;
  // requesting the length from user
  std::cout << "Enter the length" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // setting length from input
  box2.setLength(f1, i1);
  // requesting the width from user
  std::cout << "Enter the width" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // setting width from input
  box2.setWidth(f1, i1);
  // requesting the height from user
  std::cout << "Enter the height" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // setting height from input
  box2.setHeight(f1, i1);

  // box 3
  std::cout << "Box 3 is copied from Box 2." << std::endl;
  // copying the data from box 2 into box 3 using a copy constructor
  Box box3(box2);

  // box 4
  std::cout << "Box 4" << std::endl;
  // requesting the length from user
  std::cout << "Enter the length" << std::endl;
  std::cout << "feet: ";
  f1 = InputInt();
  std::cout << "inches: ";
  i1 = InputFloat();
  // requesting the width from user
  std::cout << "Enter the width" << std::endl;
  std::cout << "feet: ";
  f2 = InputInt();
  std::cout << "inches: ";
  i2 = InputFloat();
  // requesting the height from user
  std::cout << "Enter the height" << std::endl;
  std::cout << "feet: ";
  f3 = InputInt();
  std::cout << "inches: ";
  i3 = InputFloat();
  // using the initilizer 3 parameter constructor
  Box box4(Distance(f1, i1), Distance{f2, i2}, Distance{f3, i3});

  // outputting the number of boxes currently active
  std::cout << std::endl << std::endl << "There are " << Box::getCount() << " Boxes in this program." << std::endl << std::endl;
  /** informing the user **/
  // first box information
  std::cout << "Box 1 dimensions: " <<
  "length = " << box1.getLength().toString() <<
  ", width = " << box1.getWidth().toString() <<
  ", height = " << box1.getHeight().toString() << " and volume = " << box1.volume() <<std::endl;
  // second box information
    std::cout << "Box 2 dimensions: " <<
  "length = " << box2.getLength().toString() <<
  ", width = " << box2.getWidth().toString() <<
  ", height = " << box2.getHeight().toString() << " and volume = " << box2.volume() << std::endl;
  // third box information
    std::cout << "Box 3 dimensions: " <<
  "length = " << box3.getLength().toString() <<
  ", width = " << box3.getWidth().toString() <<
  ", height = " << box3.getHeight().toString() << " and volume = " << box3.volume() << std::endl;
  // fourth box information
    std::cout << "Box 4 dimensions: " <<
  "length = " << box4.getLength().toString() <<
  ", width = " << box4.getWidth().toString() <<
  ", height = " << box4.getHeight().toString() << " and volume = " << box4.volume() << std::endl << std::endl;
  /** if / else statements for same size comparison **/
  // we compare box 1 to all, box 2 to 3 & 4, box 3 to 4. 
  // (this covers all)
  if (box1 == box2)
  {
    std::cout << "Box 1 and Box 2 are equal." << std::endl;
  }
  if (box1 == box3)
  {
    std::cout << "Box 1 and Box 3 are equal." << std::endl;
  }
  if (box1 == box4)
  {
    std::cout << "Box 1 and Box 4 are equal." << std::endl;
  }
  if (box2 == box3)
  {
    std::cout << "Box 2 and Box 3 are equal." << std::endl;
  }
  if (box2 == box4)
  {
    std::cout << "Box 2 and Box 4 are equal." << std::endl;
  }
  if (box3 == box4)
  {
    std::cout << "Box 3 and Box 4 are equal." << std::endl;
  }
  std::cout << std::endl;
  /** if / else statements for the greater function **/
  // we check if calling box is greater than or equal to all the boxes
  // eventually we find one that is which is the largest
  if ( (box1 >= box2) && (box1 >= box3) && (box1 >= box4) )
  {
    std::cout << "The largest box has dimensions: length = " << box1.getLength().toString() << ", width = " << box1.getWidth().toString() << ", height = " << box1.getHeight().toString() << " and volume = " << box1.volume() << std::endl;
  }
  // we check if calling box is greater than or equal to all the boxes
  // eventually we find one that is which is the largest
  else if ( (box2 >= box1) && (box2 >= box3) && (box2 >= box4) )
  {
    std::cout << "The largest box has dimensions: length = " << box2.getLength().toString() << ", width = " << box2.getWidth().toString() << ", height = " << box2.getHeight().toString() << " and volume = " << box2.volume() << std::endl;
  }
  // we check if calling box is greater than or equal to all the boxes
  // eventually we find one that is which is the largest
  else if ( (box3 >= box1) && (box3 >= box2) && (box3 >= box4) )
  {
    std::cout << "The largest box has dimensions: length = " << box3.getLength().toString() << ", width = " << box3.getWidth().toString() << ", height = " << box3.getHeight().toString() << " and volume = " << box3.volume() << std::endl;
  }
  // we check if calling box is greater than or equal to all the boxes
  // eventually we find one that is which is the largest
  else if ( (box4 >= box1) && (box4 >= box1) && (box4 >= box1) )
  {
    std::cout << "The largest box has dimensions: length = " << box4.getLength().toString() << ", width = " << box4.getWidth().toString() << ", height = " << box4.getHeight().toString() << " and volume = " << box4.volume() << std::endl;
  }
  /** if / else statements for the less than function **/
  // we check if calling box is smaller than or equal to all the boxes
  // eventually we find one that is which is the smallest
  if ( (box1 <= box2) && (box1 <= box3) && (box1 <= box4) )
  {
    std::cout << "The smallest box has dimensions: length = " << box1.getLength().toString() << ", width = " << box1.getWidth().toString() << ", height = " << box1.getHeight().toString() << " and volume = " << box1.volume() << std::endl;
  }
  // we check if calling box is smaller than or equal to all the boxes
  // eventually we find one that is which is the smallest
  if ( (box2 <= box1) && (box2 <= box3) && (box2 <= box4) )
  {
    std::cout << "The smallest box has dimensions: length = " << box2.getLength().toString() << ", width = " << box2.getWidth().toString() << ", height = " << box2.getHeight().toString() << " and volume = " << box2.volume() << std::endl;
  }
  // we check if calling box is smaller than or equal to all the boxes
  // eventually we find one that is which is the smallest
  if ( (box3 <= box1) && (box3 <= box2) && (box3 <= box4) )
  {
    std::cout << "The smallest box has dimensions: length = " << box3.getLength().toString() << ", width = " << box3.getWidth().toString() << ", height = " << box3.getHeight().toString() << " and volume = " << box3.volume() << std::endl;
  }
  // we check if calling box is smaller than or equal to all the boxes
  // eventually we find one that is which is the smallest
  if ( (box4 <= box1) && (box4 <= box2) && (box4 <= box3) )
  {
    std::cout << "The smallest box has dimensions: length = " << box4.getLength().toString() << ", width = " << box4.getWidth().toString() << ", height = " << box4.getHeight().toString() << " and volume = " << box4.volume() << std::endl;
  }
  std::cout << std::endl;
  /** ending the lifetime of box objects and then stateing the count again **/
  box3.~Box();
  box4.~Box();
  std::cout << "There are " << Box::getCount() << " Boxes in this program." << std::endl << std::endl;

  ////////
  //part 6
  ////////
  std::cout << "Problem 6: " << std::endl;
  // setting the data to values outlined in the problem
  box1 = {{1,1}, {1,1}, {1,1}};
  box2 = {{2,2}, {2,2}, {2,2}};
  box3 = {{3,3}, {3,3}, {3,3}};
  // outputting all the values of the boxes
  std::cout << "Box1: L: " << box1.getLength().toString() << " W: " << box1.getWidth().toString() << " H: " << box1.getHeight().toString() << std::endl;
  std::cout << "Box2: L: " << box2.getLength().toString() << " W: " << box2.getWidth().toString() << " H: " << box2.getHeight().toString() << std::endl;
  box3 = box2 = box1;
  // using assignment and then outputting all the values of boxes to match output
  std::cout << "After assigning box1 to box2 to box3" << std::endl;
  std::cout << "Box1: L: " << box1.getLength().toString() << " W: " << box1.getWidth().toString() << " H: " << box1.getHeight().toString() << std::endl;
  std::cout << "Box2: L: " << box2.getLength().toString() << " W: " << box2.getWidth().toString() << " H: " << box2.getHeight().toString() << std::endl;
  std::cout << "Box3: L: " << box3.getLength().toString() << " W: " << box3.getWidth().toString() << " H: " << box3.getHeight().toString() << std::endl;
  std::cout << std::endl;

  ////////
  // additional tests
  ////////
  // for this section the answer is in brackets before the output
  // this is to help us understand if the class functions are
  // working as intended
  std::cout << "Additional tests: " << std::endl;
  // setting data to what we want to test with
  box1 = {{3,3}, {3,3}, {3,3}};
  box2 = {{3,3}, {3,3}, {3,3}};
  box3 = {{0,0}, {0,0}, {0,0}};
  box4 = {{7,7}, {7,7}, {7,7}};
  d1 = {3, 9};
  d2 = {3, 9};
  d3 = {0, 0};
  d4 = {7, 7};
  // outputting a chunk of code describing the data we are using for our testing
  // this is the fastest way to do it but is not modular
  // this does not matter since we are just testing operators
  std::cout << "Data for these tests: " << std::endl;
  std::cout << "box1 = {{1,1}, {1,1}, {1,1}}" << std::endl;
  std::cout << "box2 = {{1,1}, {1,1}, {1,1}};" << std::endl;
  std::cout << "box3 = {{0,0}, {0,0}, {0,0}};" << std::endl;
  std::cout << "box4 = {{7,7}, {7,7}, {7,7}};" << std::endl;
  std::cout << "d1 = {3, 9}" << std::endl;
  std::cout << "d2 = {3, 9}" << std::endl;
  std::cout << "d3 = {0, 0}" << std::endl;
  std::cout << "d4 = {7, 7}" << std::endl << std::endl;

  // - operator for distance
  std::cout << "(R=7-6) Distance d1 + d1: " << (d1+d1).toString() << std::endl;
  std::cout << "(R=0-0) Distance d1 - d1: " << (d1-d1).toString() << std::endl;
  // + operator for distance 
  std::cout << "(R=11-4) Distance d1 += d4: " << (d1+=d4).toString() << std::endl;
  std::cout << "(R=3-10) Distance d1 -= d2: " << (d4-=d2).toString() << std::endl;

  // resetting data
  d1 = {3, 9};
  d2 = {3, 9};
  d3 = {0, 0};
  d4 = {7, 7};

  // < operator for distance 
  // case 1 same size
  std::cout << "(O=0) Distance d1 < d1: " << ( d1<d1 ) << std::endl;
  // case 2 smaller
  std::cout << "(O=1) Distance d3 < d1: " << (d3<d1) << std::endl;
  // case 3 bigger
  std::cout << "(O=0) Distance d4 < d1: " << (d4<d1) << std::endl;
  
  // > operator for distance
  // case 1 same size
  std::cout << "(O=0) Distance d1 > d1: " << (d1>d1) << std::endl;  
  // case 2 smaller
  std::cout << "(O=0) Distance d3 > d1: " << (d3>d1) << std::endl;
  // case 3 bigger
  std::cout << "(O=1) Distance d1 > d3: " << (d1>d3) << std::endl;

  // <= operator for distance 
  // case 1 same size
  std::cout << "(O=1) Distance d1 <= d1: " << ( d1<=d1 ) << std::endl;
  // case 2 smaller
  std::cout << "(O=1) Distance d3 <= d1: " << (d3<=d1) << std::endl;
  // case 3 bigger
  std::cout << "(O=0) Distance d4 <= d1: " << (d4<=d1) << std::endl;

  // >= operator for distance 
  // case 1 same size
  std::cout << "(O=1) Distance d1 >= d1: " << (d1>=d1) << std::endl;  
  // case 2 smaller
  std::cout << "(O=0) Distance d3 >= d1: " << (d3>=d1) << std::endl;
  // case 3 bigger
  std::cout << "(O=1) Distance d1 >= d3: " << (d1>=d3) << std::endl;

  // == operator for distance
  // case 1 they are equal
  std::cout << "(O=1) Distance d1 == d1: " << ( d1 == d1 ) << std::endl; 
  // case 2 they are not equal 
  std::cout << "(O=0) Distance d3 == d1: " << (d3 == d1) << std::endl;

  // != operator for distance
  // case 1 they are equal
  std::cout << "(O=0) Distance d1 != d1: " << ( d1 != d1 ) << std::endl;  
  // case 2 they are not equal
  std::cout << "(O=1) Distance d3 != d1: " << (d3 != d1) << std::endl;
  std::cout << std::endl; 

  // < operator for box
  // case 1 same size
  std::cout << "(O=0) Box b1 < b1: " << (box1<box1 ) << std::endl;
  // case 2 smaller
  std::cout << "(O=1) Box b3 < b1: " << (box3<box1) << std::endl;
  // case 3 bigger
  std::cout << "(O=0) Box b4 < b1: " << (box4<box1) << std::endl;

  // > operator for box
  // case 1 same size
  std::cout << "(O=0) Box b1 > b1: " << (box1>box1 ) << std::endl;
  // case 2 smaller
  std::cout << "(O=0) Box b3 > b1: " << (box3>box1) << std::endl;
  // case 3 bigger
  std::cout << "(O=1) Box b4 > b1: " << (box4>box1) << std::endl;

  // <= operator for box 
  // case 1 same size
  std::cout << "(O=1) Box b1 <= b1: " << (box1<=box1 ) << std::endl;
  // case 2 smaller
  std::cout << "(O=1) Box b3 <= b1: " << (box3<=box1) << std::endl;
  // case 3 bigger
  std::cout << "(O=0) Box b4 <= b1: " << (box4<=box1) << std::endl;

  // >= operator for box 
  // case 1 same size
  std::cout << "(O=1) Box b1 >= b1: " << (box1>=box1 ) << std::endl;
  // case 2 smaller
  std::cout << "(O=0) Box b3 >= b1: " << (box3>=box1) << std::endl;
  // case 3 bigger
  std::cout << "(O=1) Box b4 >= b1: " << (box4>=box1) << std::endl;

  // == operator for box
  // case 1 they are equal
  std::cout << "(O=1) Box b1 == b1: " << ( box1 == box1 ) << std::endl; 
  // case 2 they are not equal 
  std::cout << "(O=0) Box b3 == b1: " << ( box3 == box1 ) << std::endl;

  // != operator for box
  // case 1 they are equal
  std::cout << "(O=0) Box b1 != b1: " << ( box1 != box1 ) << std::endl; 
  // case 2 they are not equal 
  std::cout << "(O=1) Box b3 != b1: " << ( box3 != box1 ) << std::endl;

  std::cout << "As a final note, all operations were correct I conclude it is debugged" 
  << std::endl;
}

// distance class functions
// default constructor
Distance::Distance()
{
  feet = 0;
  inches = 0.0;
}

// constructor with 2 parameters 
Distance::Distance(int f, float i)
{
  // error checks incorporated into constructor for extra safty
  while (f > 999 || f < 0)
  {
    std::cout << "Error in feet dimension - please re-enter: ";
    f = InputInt();
  }
  while (i >= 12  || i < 0)
  {
    std::cout << "Error in inches dimension - please re-enter: ";
    i = InputFloat();
  }
  feet = f;
  inches = i;
}

// a copy constructor
Distance::Distance(const Distance& a)
{
  feet = a.getFeet();
  inches = a.getInches();
}

// getter for feet
int Distance::getFeet() const
{
  return feet;
}

// getter for inches
float Distance::getInches() const
{
  return inches; 
}

// setter for feet
void Distance::setFeet(int f)
{
  // error checks incorporated into setter for extra safty
  while (f > 999 || f < 0)
  {
    std::cout << "Error in feet dimension - please re-enter: ";
    f = InputInt();
  }
  feet = f;
}

// setter for inches
void Distance::setInches(float i)
{
  // error checks incorporated into setter for extra safty
  while (i >= 12  || i < 0)
  {
    std::cout << "Error in inches dimension - please re-enter: ";
    i = InputFloat();
  }
  inches = i;
}

// function for distance value to decimal from two variables into one
float Distance::toDecimal() const
{
  // using a temporary variable
  float decimal; 
  decimal = float(feet) + (inches / 12.0);
  return decimal; 
}

// function to change distance to a string
std::string Distance::toString() const
{
  // using strings to structure the data in the object correctly
  std::string temp_full = ""; 
  std::string temp_feet = std::to_string(feet); 
  std::string temp_inches = std::to_string(inches); 
  if(temp_inches.find('.'))
    {
      // removes any trailing zeros for the inches when in the output
      temp_inches = temp_inches.substr(0, temp_inches.find_last_not_of('0')+1);
      if(temp_inches.find('.') == temp_inches.size()-1)
      {
          temp_inches = temp_inches.substr(0, temp_inches.size()-1);
      }
    }
    // returns the correct strjng
  temp_full = temp_feet + "\'-" + temp_inches +"\""; 
  if( feet >= 0 && inches >= 0)
  {
    return temp_full; 
  }
  else
  {
    return "Error: negative distance";
  }
}

Distance Distance::operator + (Distance d)
{
  // using a temp distance to add the feet and inches and return
  Distance temp;
  temp.feet = feet + d.feet;
  temp.inches = inches + d.inches;
  if (temp.inches >= 12)
  {
    // this is here incase the inches go above 12 we want to change it to a foot
    temp.feet++;
    temp.inches = temp.inches - 12;
  }
  // return the temp
  return temp;
}

Distance Distance::operator - (Distance d)
{
  // using a temp distance to subtract the feet and inches and return
  Distance temp;
  temp.feet = feet - d.feet;
  temp.inches = inches - d.inches;
  if (temp.inches < 0)
  {
    // if inches becomes negative we will take a value from the feet to fix it
    // there is a stop gap in another location in the program icase of error
    temp.feet--;
    temp.inches = temp.inches + 12;
  }
  return temp;
}

Distance& Distance::operator = (Distance d)
{
  // assignment operator for the distance class
  feet = d.feet;
  inches = d.inches;
  return *this;
}

Distance& Distance::operator += (Distance d)
{  
  // this operation is a simple way of doing feet = feet + d.feet
  feet = feet + d.feet;
  inches = inches + d.inches;
  if (inches >= 12)
  {
    // uses the same logic to keep output / return logical 
    feet++;
    inches = inches - 12;
  }
  return *this;
}

Distance& Distance::operator -= (Distance d)
{
  // this operation is a simple way of doing feet = feet - d.feet
  feet = feet - d.feet;
  inches = inches - d.inches;
  if (inches < 0)
  {
    // uses the same logic to keep output / return logical 
    feet--;
    inches = inches + 12;
  }
  return *this;
}

bool Distance::operator < (Distance d) const
{
  // logic statements that describe the situation is relation to data members
  if (feet < d.feet)
  {
    return true;
  }
  else if (feet == d.feet && inches < d.inches)
  {
    return true; 
  }
  else
  {
    return false;
  }
}

bool Distance::operator > (Distance d) const
{
  // logic statements that describe the situation is relation to data members
  if (feet > d.feet)
  {
    return true;
  }
  else if (feet == d.feet && inches > d.inches) 
  {
    return true; 
  }
  else
  {
    return false;
  }
}

bool Distance::operator <= (Distance d) const
{
  // logic statements that describe the situation is relation to data members
  if (feet < d.feet)
  {
    return true;
  }
  else if (feet == d.feet && inches <= d.inches)
  {
    return true; 
  }
  else
  {
    return false;
  }
}

bool Distance::operator >= (Distance d) const
{
  // logic statements that describe the situation is relation to data members
  if (feet > d.feet)
  {
    return true;
  }
  else if (feet == d.feet && inches >= d.inches)
  {
    return true; 
  }
  else
  {
    return false;
  }
}

bool Distance::operator == (Distance d) const
{  
  // logic statements that describe the situation is relation to data members
  if (feet == d.feet && inches == d.inches)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Distance::operator != (Distance d) const
{
  // logic statements that describe the situation is relation to data members
  if (feet != d.feet || inches != d.inches)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// box class functions
// default constructor
Box::Box()
{
  length = {0, 0}; 
  width = {0, 0}; 
  height = {0, 0}; 
  // making sure to add to the static int
  count++;
}

// a copy constructor
Box::Box(const Box& a)
{
  length = a.getLength();
  width = a.getWidth();
  height = a.getHeight();
  // making sure to add to the static int
  count++;
}

// a destructor and a negative count
Box::~Box()
{
  // when called we want to decrement that static int
  count--;
}

// a getter for length
Distance Box::getLength() const
{
  return length; 
}

// a getter for width
Distance Box::getWidth() const
{
  return width;
}

// a getter for height
Distance Box::getHeight() const
{
  return height;
}

// a setter for length using two parameters used for a distance class
// this can be done in many ways the assignment was not clear
void Box::setLength(int f, float i)
{
  length.setFeet(f);
  length.setInches(i);
}

// a setter for width
// same as above this can be done in many ways I chose parameters for
// distance
void Box::setWidth(int f, float i)
{
  width.setFeet(f);
  width.setInches(i);
}

// a setter for height
// same as above this can be done in many ways I chose parameters for
// distance
void Box::setHeight(int f, float i)
{
  height.setFeet(f);
  height.setInches(i);
}

// a function to display a boxes volume
float Box::volume() const
{
  // we use a temporary float of v to store the data
  float v;
  // using member functions of to decimal to get values
  v = length.toDecimal() * width.toDecimal() * height.toDecimal();
  return v;
}

// a function to get the total count of box objects
int Box::getCount()
{
  // returns static int for count
  return count;
}

// input validations functions for Int and Float used a similar structure 
// for assignmnet 1 and it worked wonders. 
int InputInt()
{
  // input has not been checked yet
  bool input_check = false;
  int tempValue = 0;
  // the string the user will be inputing into
  std::string user_input;
  // while the input has not been checked
  while (input_check == false)
  {
    // input the line information into the string
    getline(std::cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse though the string to make sure all the characters are valid 
      if (int(user_input[i]) < 48 || int(user_input[i]) > 57)
      {
        std::cout << "Incorrect input for feet - please enter a positive integer: ";
        break;
      }
      // if we get to the end of the string then make the input valid
      if (i == (user_input.length() - 1))
      {
        tempValue = stoi(user_input);
        if (tempValue > 999 || tempValue < 0)
        {
          std::cout << "Incorrect input for feet - please enter a value between 0 and 1000: ";
          break;
        }
        else
        {
          input_check = true;
        }
      }
    }
  }
  // return the input with stoi as a int format
  return tempValue;
}

float InputFloat()
{
  // input has not been checked yet
  bool input_check = false;
  float tempValue = 0;
  // the string the user will be inputing into
  std::string user_input;
  // while the input has not been checked
  while (input_check == false)
  {
    // input the line information into the string
    getline(std::cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse though the string to make sure all the characters are valid 
      if (int(user_input[i]) < 46 || int(user_input[i]) > 57 || int(user_input[i]) == 47)
      {
        std::cout << "Incorrect input for inches - please enter a positive float:";
        break;
      }
      // if we get to the end of the string then make the input valid
      if (i == (user_input.length() - 1))
      {
        tempValue = stof(user_input);
        if (tempValue >= 12 || tempValue < 0)
        {
          std::cout << "Incorrect input for inches - please enter a value between 0 and 12: ";
          break;
        }
        else
        {
          input_check = true;
        }
      }
    }
  }
  // return the input with stof as a float format
  return tempValue;
}

bool Box::operator < (Box d) const
{
  // logic statements that describe the situation is relation to volume function
  if (volume() < d.volume())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Box::operator > (Box d) const
{  
  // logic statements that describe the situation is relation to volume function
  if (volume() > d.volume())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Box::operator <= (Box d) const
{
  // logic statements that describe the situation is relation to volume function
  if (volume() <= d.volume())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Box::operator >= (Box d) const
{
  // logic statements that describe the situation is relation to volume function
  if (volume() >= d.volume())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Box::operator == (Box d) const
{
  // logic statements that describe the situation is relation to volume function
  if (volume() == d.volume())
  {
    return true;
  }
  else
  {
    return false;
  }
} 

bool Box::operator != (Box d) const
{
  // logic statements that describe the situation is relation to volume function
  if (volume() != d.volume())
  {
    return true;
  }
  else
  {
    return false;
  }
}

Box& Box::operator = (Box d)
{
  // this is an assignment function that is able to assign two boxes to each other with thier respective data members 
  length = d.length;
  width = d.width;
  height = d.height;
  return *this;
}