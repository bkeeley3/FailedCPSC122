#include <iostream>
using namespace std;

#include "MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
    length = strlen(strIn);
    str = new char[length + 1];
    strcpy(str, strIn);
}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
    delete []str; 
}

void MyString::myDisplay()
{
    cout << str << endl;
}

//Returns length of string
int MyString::myStrlen()
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}

//checks if strIn is equal to string object
bool MyString::isEqual(char const* strIn)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == strIn[i])
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

//concatenates 2 strings
void MyString::concat(char const* strIn)
{
    int j = 0;
    while(str[j] != '\0')
    {
        j++;
    }
    int i = 0;
    while(strIn[i] != '\0')
    {
        str[j] = strIn[i];
        i++;
        j++;
    }
    str[j] = '\0';
}

//coppies the inputted sting to the string object
void MyString::myStrcpy(char const* strIn)
{
    int idx = 0;
    while(strIn[idx] != '\0')
    {
        str[idx] = strIn[idx];
        idx++;
    }
    str[idx] = '\0';
}

//returns first index of substring if found in the string
int MyString::find(char const* strIn)
{
    int idx = 0;
    bool sub = true;
    while(str[idx] != '\0')
    {
        if(str[idx] == strIn[0])
        {
            sub = MyString::isSub(strIn, idx);
            if (sub == true)
            {
                return idx;
            }
        }
        idx++;
    }
    return -1;
}

//checks the if the substring is in the string from the index given
bool MyString::isSub(char const* strIn, int idx)
{
    int i = 0;
    while(strIn[i] != '\0')
    {
        if(strIn[i] != str[idx])
        {
            return false;
        }
        i++;
        idx++;
    }
    return true;
}