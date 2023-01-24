// Name: MAKSIM SHAROIKA
// Student Number: 200446763
// Date: September 19 / 2021

// Filename: p3.cpp
// Problem 3: The program should have an array of 12 structures to hold // weather data for an entire year. When the program runs, it should ask // the user to enter data for each month. The program then should 
// display // month-wise min., max. and average temperatures and 
// rainfalls in a table-like. format. In addition, it should display 
// average min. average max. and average mean temperature of the entire // year.

// include iostream for input and output and iomanip for structuing
#include <iostream>
#include <iomanip>

// using standard namespace to avoid namespace calls
using namespace std;

// the given structures 
struct temperature
{
  // temperture with 3 doubles in it
  double maxTemperature;
  double minTemperature;
  double avgTemperature;
};
struct rainfall
{
  // rainfall with 3 ints in it
  int maxRainfall;
  int minRainfall;
  int avgRainfall;
};
struct weather
{
  // eather with rainfall and temperature in it
  rainfall rain;
  temperature temp;
};

// function prototypes 
// inputing the weather data into an array
void inputdata(weather&);

// inputing the data into the array
int inputInt(int, int);
double inputDouble(double, double);

// function to calculate the averages
void calculate(double&, double&, double&, double&, double&, double&, weather[]);

// function to print the table
void printTable(double&, double&, double&, double&, double&, double&, weather[]);

// a function to help structure the table with lines
void divider(int);

// a function to get the name of the month
void monthname(int);

// making sure the input is valid in terms of type
int IntInputCheck();
double DoubleInputCheck();

int main()
{
  // declare all the variables for yealy average and initialize them
  double year_maxTemperature = 0.0;
  double year_minTemperature = 0.0;
  double year_avgTemperature = 0.0;
  double year_maxRainfall = 0.0;
  double year_minRainfall = 0.0;
  double year_avgRainfall = 0.0;

  // declare an array of size 12 (0-11) of weather structs
  weather month[12];

  // for every month (0-11)
  for(int i = 0; i < 12; i++)
  {
    // output the name of the month
    monthname(i);
    // end the line
    cout << endl;
    // call the input data function (get all the data for that month)
    inputdata(month[i]);
  }

  // calculate all of the yearly averages (they are passed by refrence)
  calculate(year_maxTemperature, year_minTemperature, year_avgTemperature, year_maxRainfall, year_minRainfall, year_avgRainfall, month);

  // print out the table containing all of the data
  printTable(year_maxTemperature, year_minTemperature, year_avgTemperature, year_maxRainfall, year_minRainfall, year_avgRainfall, month);
  
  // return 0 and end the program if it is completed correctly
  return 0;
}

// Funtion: inputing the data into the structure of weather passed into fucntion 
void inputdata(weather& month)
{
  // do once and then keep doing if failed to meet constraint
  do
  {
    // request the maximum temperture in the month (use safe input function)
    cout << "Enter the month's maximum temperature (c): ";
    month.temp.maxTemperature = inputDouble(-70.0, 60.0);
    // request the minimum temperture in the month (use safe input function)
    cout << "Enter the month's minimum temperature (c): ";
    month.temp.minTemperature = inputDouble(-70.0, 60.0);
    // request the average temperture in the month (use safe input function)
    cout << "Enter the month's average temperature (c): ";
    month.temp.avgTemperature = inputDouble(-70.0, 60.0);
    // if the low < average < high print out error statement 
    if (!(month.temp.minTemperature <= month.temp.avgTemperature) || !(month.temp.avgTemperature <= month.temp.maxTemperature))
    {
      cout << "Error - Average must be larger than minimum and smaller than maximum, please try again." << endl;
    }
    // if the error statement was print out condition is still the same request user to reinput the data
  } while (!(month.temp.minTemperature <= month.temp.avgTemperature) || !(month.temp.avgTemperature <= month.temp.maxTemperature));
  do
  {
    // request the maximum rainfall in the month (use safe input function)
    cout << "Enter the month's maximum rainfall (mm): ";
    month.rain.maxRainfall = inputInt(1, 25);
    // request the minimum rainfall in the month (use safe input function)
    cout << "Enter the month's minimum rainfall (mm): ";
    month.rain.minRainfall = inputInt(1, 25);
    // request the average rainfall in the month (use safe input function)
    cout << "Enter the month's average rainfall (mm): ";
    month.rain.avgRainfall = inputInt(1, 25);
    if (!(month.rain.minRainfall <= month.rain.avgRainfall) || !(month.rain.avgRainfall <= month.rain.maxRainfall))
    // if the low < average < high print out error statement 
    {
      cout << "Error - Average must be larger than minimum and smaller than maximum, please try again." << endl;
    }
    // if the error statement was print out condition is still the same request user to reinput the data
  } while (!(month.rain.minRainfall <= month.rain.avgRainfall) || !(month.rain.avgRainfall <= month.rain.maxRainfall));
}

// Funtion: request input of an integer and make sure is is in correct range
int inputInt(int min, int max)
{
  // declare working variable
  int value;
  // do once and keep doing if condition
  do
  {
    // request correct and cehcked input from function
    value = IntInputCheck();
    // make sure input is in correct range
    if ( (value < min) || (value > max) )
    {
      cout << "Error - Please enter a value between " << min << " and " << max << ", please re-enter:";
    }
    // if input was not in correct range run it again
  }
  while ( (value < min) || (value > max));
  // return the value once out of the loop
  return value;
}

// Funtion: request input of an double and make sure is is in correct range
double inputDouble(double min, double max)
{
  // declare working variable
  double value;
  // do once and keep doing if condition
  do
  {
    // request correct and cehcked input from function
    value = DoubleInputCheck();
    // make sure input is in correct range
    if ( (value < min) || (value > max) )
    {
      cout << "Error - Please enter a value between " << min << " and " << max << ", please re-enter: ";
    }
    // if input was not in correct range run it again
  }
  while ( (value < min) || (value > max));
  // return the value once out of the loop
  return value;
}

// Funtion: calculate all the yearly values given the array of weather
void calculate(double& Tmax, double& Tmin, double& Tavg, double& Rmax, double& Rmin, double& Ravg, weather month[])
{
  // for loop to go through all of the month (0-11)
  for(int i = 0; i < 12; i++)
  {
    // add the max month temp each time to TMax (which is starting at 0)
    Tmax = Tmax + month[i].temp.maxTemperature;
    // add the max month temp each time to Tmin (which is starting at 0)
    Tmin = Tmin + month[i].temp.minTemperature;
    // add the max month temp each time to Tavg (which is starting at 0)
    Tavg = Tavg + month[i].temp.avgTemperature;
    // add the max month rain each time to Rmax (which is starting at 0) we are using doubles because average can have decimal places.
    Rmax = Rmax + double(month[i].rain.maxRainfall);
    // add the max month rain each time to Rmin (which is starting at 0) we are using doubles because average can have decimal places.
    Rmin = Rmin + double(month[i].rain.minRainfall);
    // add the max month rain each time to Rßavg (which is starting at 0) we are using doubles because average can have decimal places.
    Ravg = Ravg + double(month[i].rain.avgRainfall);
  }
  // divide Tmax by 12 (the number of months to get average for year)
  Tmax = (Tmax / 12.0);
  // divide Tmin by 12 (the number of months to get average for year)
  Tmin = (Tmin / 12.0);
  // divide Tavg by 12 (the number of months to get average for year)
  Tavg = (Tavg / 12.0);
  // divide Rmax by 12 (the number of months to get average for year)
  Rmax = (Rmax / 12.0);
  // divide Rmin by 12 (the number of months to get average for year)
  Rmin = (Rmin / 12.0);
  // divide Ravg by 12 (the number of months to get average for year)
  Ravg = (Ravg / 12.0);
  // we dont need to return these values because they are passed in by refrence 
}

// Funtion: takes the data of all the yearlies and the array to print it all out
void printTable(double& Tmax, double& Tmin, double& Tavg, double& Rmax, double& Rmin, double& Ravg, weather month[])
{
  // clear the line a line to start the table
  cout << endl;
  // top divider
  divider(80);
  cout << endl;
  // print out the headers with the correct lining up not to spill over
  cout << setw(11) << "Month |";
  cout << setw(11) << " Max Temp |";
  cout << setw(11) << " Min Temp |";
  cout << setw(11) << " Avg Temp |";
  cout << setw(11) << " Max Rain |";
  cout << setw(11) << " Min Rain |";
  cout << setw(11) << " Avg Rain |" << endl;
  // bottom divider
  divider(80);
  cout << endl;
  // for each month (0-11)
  for(int i = 0; i < 12; i++)
  {
    // print out the month name
    monthname(i);
    // print out the structured month max temp
    cout << setw(8) << setprecision(2) << month[i].temp.maxTemperature << setw(3) << "C |";
    // print out the structured month min temp
    cout << setw(8) << setprecision(2) << month[i].temp.minTemperature << setw(3) << "C |";
    // print out the structured month avg temp
    cout << setw(8) << setprecision(2) << month[i].temp.avgTemperature << setw(3) << "C |";
    // print out the structured month max rain
    cout << setw(7) << setprecision(2) << month[i].rain.maxRainfall << setw(4) << "mm |";
    // print out the structured month min rain
    cout << setw(7) << setprecision(2) << month[i].rain.minRainfall << setw(4) << "mm |";
    // print out the structured month avg rain
    cout << setw(7) << setprecision(2) << month[i].rain.avgRainfall << setw(4) << "mm |";
    // the bottom divider to end section
    cout << endl;
    divider(80);
    cout << endl;
  }
  // print out the calculated yearly maximum temperature
  cout << "The average yearly maximum temperature was: " << Tmax << "C" << endl;
  // print out the calculated yearly minimum temperature
  cout << "The average yearly minimum temperature was: " << Tmin << "C" << endl;
  // print out the calculated yearly average temperature
  cout << "The average temperature was: " << Tavg << "C" << endl;
  // print out the calculated yearly maximum rainfall
  cout << "The average yearly maximum rainfall was: " << Rmax << "mm" << endl;
  // print out the calculated yearly minimum rainfall
  cout << "The average yearly minimum rainfall was: " << Rmin << "mm" << endl;
  // print out the calculated yearly average rainfall
  cout << "The average rainfall was: " << Ravg << "mm" << endl;
}

// Funtion: divider function uses for loop
void divider(int i)
{
  // the passed in paramater is the numver of '-' to make
  for(int j = 0; j < i; j++)
  {
    // a good number we use in this program is 80 because that is a generic terminal size
    cout << "-";
  }
}

// Funtion: input in the month number from array and the name associated with in (i would have added a string to the structures but we couldnt change them)
void monthname(int i)
{
  // they are strucuted to appear nicely within the program
  if (i == 0)
  {
    // number zero is january
    cout << setw(11) << "January:";
  }
  if (i == 1)
  {
    // number one is february
    cout << setw(11) << "February:";
  }
  if (i == 2)
  {
    // number two is march
    cout << setw(11) << "March:";
  }
  if (i == 3)
  {
    // number three is april
    cout << setw(11) << "April:";
  }
  if (i == 4)
  {
    // number four is may
    cout << setw(11) << "May:";
  }
  if (i == 5)
  {
    // number five is june
    cout << setw(11) << "June:";
  }
  if (i == 6)
  {
    // number siz is july
    cout << setw(11) << "July:";
  }
  if (i == 7)
  {
    // number seven is august
    cout << setw(11) << "August:";
  }
  if (i == 8)
  {
    // number eight is september
    cout << setw(11) << "September:";
  }
  if (i == 9)
  {
    // number nine is october
    cout << setw(11) << "October:";
  }
  if (i == 10)
  {
    // number ten is november
    cout << setw(11) << "November:";
  }
  if (i == 11)
  {
    // number eleven is devember
    cout << setw(11) << "December:";
  }
}

// Funtion: take in an input as string and return it as an int to avoid errors
int IntInputCheck()
{
  // input has not been checked yet
  bool input_check = false;
  // the string that will hold the input
  string user_input;
  // while not checked
  while (input_check == false)
  {
    // get the input line and store it in the string
    getline(cin, user_input);
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse throught the string and make sure all the values are numbers
      if (int(user_input[i]) < 48 || int(user_input[i]) > 57)
      {
        // if a number does not work send an error and break the look
        cout << "Incorrect input - please enter a positive interger:";
        break;
      }
      // if it is correct then input check is true and return value
      if (i == (user_input.length() - 1))
      {
        input_check = true;
      }
    }
  }
  // return a stoi version of the user_input string
  return stoi(user_input);
}

// Funtion: take in an input as string and return it as a double to avoid errors
double DoubleInputCheck()
{
  // input has not been checked yet
  bool input_check = false;
  // the string that will hold the input
  string user_input;
  // while not checked
  while (input_check == false)
  {
    getline(cin, user_input);
    // get the input line and store it in the string
    for(int i = 0; i < user_input.length(); i++)
    {
      // parse throught the string and make sure all the values are numbers
      if (int(user_input[i]) < 45 || int(user_input[i]) > 57 || int(user_input[i]) == 47)
      {
        // if a number does not work send an error and break the look
        cout << "Incorrect input - please enter a double:";
        break;
      }
      // if it is correct then input check is true and return value
      if (i == (user_input.length() - 1))
      {
        input_check = true;
      }
    }
  }
  // return a stod version of the user_input string
  return stod(user_input);
}