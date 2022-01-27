/*
  Name: Brady Keeley
  Class: CPSC 122 Section 2 
  Date: 1/26/2022
  Assignment: Project 1
  Description: Prints a specified number if prime numbers in a specific number of coloums determined by the user
*/

#include <iostream>
using namespace std;

void display(int,int);
bool isPrime(int); 
void error(int);

int main(int argc, char*argv[])
{
  int nums, cols;

  nums = atoi(argv[1]); ///retrieves the amount of numbers to be displayed from the command line
  cols = atoi(argv[2]); ///retrieves the amount of coloums to display the numbers across from the command line
  if (nums < 1)
    error(1);
  if (cols < 1)
    error(2);

  display(nums,cols);
  cout << endl;
  return 0;
} 

/*
  Description: Loops over all necessary candidate primes, invoking isPrime 
  on each, displaying in column fashion those that are prime
  input: integer, totalPrimes, indicating the number of primes to display; 
  integer cols, indicating over how many columns the primes are to be displayed
*/
void display(int totalPrimes, int cols)
{
  int ct = 1;
  int value = 0; 
  while (ct <= totalPrimes)
  {
    if (isPrime(value))
    {
      cout << value << '\t';
      //if (ct % cols == cols - 1)  //start counting from 0
      if (ct % cols == 0)  //start counting from 1
      cout << endl;
      ct++;
      value++;
    }
    else
    {
      value++;
    }
  }
}
 
/*
  Description: Determines whether input integer is prime
  Input: integer whose primality is to be judged
  Returns: true if num is prime, false otherwise
*/
bool isPrime(int num)
{
  bool prime = false;
 
  if (num % 2 == 0)///if else structure to sort and assign prime or not prime 
  {
    if (num == 2) /// hard code checking for single didget primes in each if statement
      prime = true;
    else
      prime = false;
  }
  else if (num % 3 == 0)
  {
    if (num == 3)
      prime = true;
    else
      prime = false;
  }
  else if (num % 5 == 0)
  {
    if (num == 5)
      prime = true;
    else
      prime = false;
  }
  else if (num % 7 == 0)
  {
    if (num == 7)
      prime = true;
    else
      prime = false;
  }
  else if (num % 9 == 0)
  {
    prime = false;
  }      
  else
  {
    prime = true;
  }
  return prime;
}

/*
  checks to make sure inputs are integers that are greater than or equal to 1
  Input: int that pertains to a certian case, 1 for numbers, and 2 for columns
  Output: if error is found it prints to the user what was wrong
*/
void error(int code) 
{
  if (code == 1)
  {
    cout <<  "Numbers displayed must be >= 1" << endl;
    exit(EXIT_FAILURE);
  }
  if (code == 2)
  {
    cout <<  "Columns must be >= 1" << endl;
    exit(EXIT_FAILURE);
  }
}
