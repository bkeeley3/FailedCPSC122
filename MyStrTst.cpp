/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

 /*Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 End Test of myDisplay*/

  /*Test of myStrlen
 cout << "***************************************" << endl;
 cout << "*****Test 3 myStrlen*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the length of command line input" << endl;
 cout << str1.myStrlen();
 cout << endl;
 cout << "*****Test 4  myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the length of command line input" << endl;
 cout << str2->myStrlen();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrlen*/

   /*Test of isEqual
 cout << "***************************************" << endl;
 cout << "*****Test 5 isEqual*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1(true) if given string is equal to command line input" << endl;
 cout << str1.isEqual("Hello");
 cout << endl;
 cout << "*****Test 6 isEqual  *****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 1(true) if given string is equal to command line input" << endl;
 cout << str2->isEqual("Hello");
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of isEqual*/

/*Test of concat
 cout << "***************************************" << endl;
 cout << "*****Test 7 concat  *****" << endl;
 cout << "static test" << endl;
 cout << "output should the combination of the given string and command line input" << endl;
 str1.concat(" world!");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 8 concat  *****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should the combination of the given string and command line input" << endl;
 str2->concat(" world!");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of concat*/

 /*Test of myStrcpy
 cout << "***************************************" << endl;
 cout << "*****Test 9 myStrcpy  *****" << endl;
 cout << "static test" << endl;
 cout << "output should be given string that replaced the command line input" << endl;
 str1.myStrcpy("AHH");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 10 myStrcpy  *****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be given string that replaced the command line input" << endl;
 str2->myStrcpy("Woah it worked");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrcpy*/

//Test of find
 cout << "***************************************" << endl;
 cout << "*****Test 11 find  *****" << endl;
 cout << "static test" << endl;
 cout << "output should be beginning index of where the substring was found\nor -1 if substring not found" << endl;
 cout << str1.find("hell");
 cout << endl;
 cout << "*****Test 12 find  *****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be beginning index of where the substring was found\nor -1 if substring not found" << endl;
 cout << str2->find("ell");
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of find

 delete str2;
 return 0;  
}
   
  
