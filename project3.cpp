/*
  Name: Brady Keeley
  Class: CPSC 122 Section 2 
  Date: 1/28/2022
  Assignment: Project 3
  Description: 
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int atoiMy(char str[]);

int main(int argc, char* argv[])
{
    int num1, num2;
    num1 = atoiMy(argv[1]);     
    num2 = atoiMy(argv[2]);
    int product = num1 * num2;

    ofstream fout;      ///creates fstream object
    fout.open(argv[3]); ///opens file to output to, recieved from command line
    fout << product << endl; ///outputs the product to the file 
}

/*
    Description: Transforms a digit strign stored as a C-string into a an int
    Input: c-string containing digit string
    Output: integer value of digit string
*/
int atoiMy(char str[])
{
    int total = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    for (int x = 0; i > 0; i--, x++)
    {
        total += (str[i-1] - 48) * (pow(10, x));
    }
return total;
}