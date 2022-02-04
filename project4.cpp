/*
    Name: Brady Keeley
    Class: CPSC 122 Section 2
    Date: 2/4/2022
    Assignment: Project 4
    Description: 
*/
#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
using namespace std;

int keyGen();
char encrypt(char, int);
char decrypt (char ch, int key);
void fileOpen(fstream& file, string name, char mode);
int getKey(string);
void fileEncrypt(fstream& in, fstream& out, int key);
void fileDecrypt(fstream& in, fstream& out, int key);

int main(int argc, char* argv[])
{
    char ch;
    fstream fin;
    fstream fout;
    int mode = atoi(argv[1]);
    
    if (mode == 0)
    {
        fileOpen(fout, argv[2], 'w');
        int key = keyGen();
        fout << key;
    }
    else if (mode == 1)
    {
        fileOpen(fin, argv[3], 'r');
        fileOpen(fout, argv[4], 'w');
        fileEncrypt(fin, fout, getKey(argv[2]));
    }
    else if (mode == 2)
    {
        fileOpen(fin, argv[3], 'r');
        fileOpen(fout, argv[4], 'w');
        fileDecrypt(fin, fout, getKey(argv[2]));
    }
}

/*
Description: Randomly generates an integer in the range: [1-25]
Input: none
Output: returns a randomly generated integer in the range [1-25]
*/
int keyGen()
{
    srand(time(0));     ///seeds so random() does not return same number everytime
    int key = random() % 25;
    return key;
}
/*
Description: retrieves the key from the file holding the key
input: name of the key file
output: returns the key from the file
*/
int getKey(string name)
{
    fstream keyGetter;
    int key;
    fileOpen(keyGetter, name, 'r');
    keyGetter >> key;
    return key;
}
/*
Description: Reads the plaintext and writes it encrypted to the encryption file
Input: plaintext file, file to encrypt to, valid key
Returns: encrypted version of plaintext file
*/
void fileEncrypt(fstream& in, fstream& out, int key)
{
    char ch;
    while (in.peek() != EOF)
    {
        ch = in.get();
        if (isalnum(ch))
        {
            ch = toupper(ch);
            ch = encrypt(ch, key);
        }
        out.put(ch);
    }
}
/*
Description: Reads the encrypted file and writes it decrypted to the plaintext file
Input: encrypted file, file to decrypt to, valid key
Returns: decrypted version of encrypted file
*/
void fileDecrypt(fstream& in, fstream& out, int key)
{
    char ch;
    while (in.peek() != EOF)
    {
        ch = in.get();
        if (isalnum(ch))
        {
            ch = toupper(ch);
            ch = decrypt(ch, key);
        }
        out.put(ch);
    }
}
/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
    int letterValue = ch - 65;
    char eChar = (letterValue + key) % 26;
    eChar += 65;
    return eChar;
}
/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt (char ch, int key)
{
    int positionValue = ch - 65;
    char dChar = (positionValue - key + 26) % 26;
    dChar += 65;
    return dChar;
}
/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
*/ 
void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}