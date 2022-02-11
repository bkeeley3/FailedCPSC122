/*
    Name: Brady Keeley
    Class: CPSC 122 Section 2
    Date: 2/9/2022
    Assignment: Project 5
    Description: encrypts a plaintext file given in the command line, decrypts the encrypted file
    to a seperate plaintext file given in the command line. All uses a randomly gnerated keys stored
    in a key file designated on the command line. 
*/
#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <time.h>
using namespace std;

void keyGen(string);
char encrypt(char, int, int);
char decrypt (char, int, int);
void fileOpen(fstream& file, string name, char mode);
void fileControl(string, string, string, int);

int ALPHA_VALUES[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
int MI[] = {1, 0, 9, 0, 21, 0, 15, 0, 3, 0, 19, 0, 0, 0, 7, 0, 23, 0, 11, 0, 5, 0, 17, 0, 25};
int main(int argc, char* argv[])
{
    char ch;
    fstream fin;
    fstream fout;
    int mode = atoi(argv[1]);

    if (mode == 0)
    {
        keyGen(argv[2]);
    }
    else if (mode == 1)
    {
        fileControl(argv[2], argv[3], argv[4], mode);
    }
    else if (mode == 2)
    {
        fileControl(argv[2], argv[3], argv[4], mode);
    }
}

/*
Description: Randomly generates 2 integers. 1 in the range: [1-25] 
the other in range [0-12] that is used to choose an alpha value from array ALPHA_VALUES 
prints both to file 
Input: name of key file
Output: returns 2 integers to the file given
*/
void keyGen(string fileName)
{
    fstream fout;
    srand(time(0));     ///seeds so random() does not return same number everytime
    int beta = 1 + random() % 25;
    int alphaIndex = random() % 12;
    int alpha = ALPHA_VALUES[alphaIndex];
    fileOpen(fout, fileName, 'w');
    fout << alpha << endl;
    fout << beta << endl;
    fout.close();
}

/*
Description: retrieves key form file Reads the plaintext and writes it encrypted 
to the encryption fileor reads the encrypted file back to plain text based on the mode
Input: keyFile, file in , file out, mode 
Returns: encrypted or decrypted file depending on mode
*/
void fileControl(string keyFile, string inFile, string outFile, int mode)
{
    fstream key, fin, fout;
    fileOpen(key, keyFile, 'r');
    fileOpen(fin, inFile, 'r');
    fileOpen(fout, outFile, 'w');
    int alpha, beta;
    key >> alpha;
    key >> beta;

    char ch;
    if (mode == 1)
    {
        while (fin.peek() != EOF) ///loops through file while there is no end of line character
        {
            ch = fin.get();
            if (isalnum(ch))
            {
                ch = toupper(ch);
                ch = encrypt(ch, alpha, beta);
            }
            fout.put(ch);
        }
    }
    else if (mode == 2)
    {
        while (fin.peek() != EOF) ///loops through file while there is no end of line character
        {
            ch = fin.get();
            if (isalnum(ch))
            {
                ch = toupper(ch);
                ch = decrypt(ch, alpha, beta); 
            }
            fout.put(ch);
        }
    }
    key.close();
    fin.close();
    fout.close();
}

/*
Description: Encrypts an upper case alphabetic character 
Input: upper case alphabetic character, valid alpha and beta
Returns: encrypted version of ch
*/
char encrypt(char ch, int alpha, int beta)
{
    int letterValue = ch - 65;
    char eChar = (alpha*letterValue + beta) % 26;
    eChar += 65;
    return eChar;
}
/*
Description: Decrypts an upper case alphabetic character 
Input: upper case alphabetic character, valid alpha and beta
Returns: decrypted version of input
*/
char decrypt (char ch, int alpha, int beta)
{
    char dChar;
    int positionValue = ch - 65;
    int mi = MI[alpha-1];
    int i = 0;
    while (((mi*positionValue) - (mi*beta) + (26*i)) < 0)
    {
        i++;
    }
    dChar = ((mi*positionValue) - (mi*beta) + (26*i)) % 26;
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