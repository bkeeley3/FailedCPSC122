/*
    Name: Brady Keeley
    Class: CPSC 122 Section 2
    Date: 2/18/2022
    Assignment: Project 6
    Description: encryption of a file using the transposition cipher
*/
#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <ctime>
using namespace std;

void keyGen(string);
void mysterySort(int[][2]);
bool sink(int array[][2], int bottom);
void swap(int array[][2], int first, int last);
char transform(char, int[]);
void fileOpen(fstream& file, string name, char mode);
void fileControl(string, string, string, int);

int ALPH = 26;
int main(int argc, char* argv[])
{

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
    
    return 0;
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
    int key[ALPH] = {0,1,2,3};
    bool used[ALPH] = {false};
    fstream fout;
    int h = 0;
    int pos = 0;
    fileOpen(fout, fileName, 'w');
    while(pos < ALPH)
    {
        while(true)
        {
            srand(time(0));
            h = random() % ALPH;
            if (!used[h])
            {
                key[pos] = h;
                used[h] = true;
                pos++;
                break;
            }
        }
    }
    for (int i = 0; i < ALPH; i++)
    {
        fout << key[i] << " ";
    }
    fout.close();
}
/*
    Sorts the 2D array so there can be decryption
    input: a 2d array
    output: none 
*/
void mysterySort(int array[][2])
{
    bool shift = true;
    int bottom = ALPH - 1;
    while(shift)
    {
        shift = sink(array, bottom);
        bottom--;
    }
}
/*
    checks to see if anythign needs to be shifted in the array
    input: 2d array and the bottome of the array
    output: a bool
*/
bool sink(int array[][2], int bottom)
{
    bool shift = false;
    int cur = 0;
    while(cur < bottom)
    {
        if(array[cur][1] > array[cur+1][1])
        {
            shift = true;
            swap(array, cur, cur+1);
        }
        else
            cur++; 
    }
    return shift;
}

/*
    swaps the values in the given array if they need to be moved
    input: a 2d array, the first value, the second value
    output: none
*/
void swap(int array[][2], int first, int last)
{
    int temp[ALPH][2];

    temp[first][0] = array[first][0];
    temp[first][1] = array[first][1];

    array[first][0] = array[last][0];
    array[first][1] = array[last][1];

    array[last][0] = temp[first][0];
    array[last][1] = temp[first][1];
}

/*
Description: retrieves key form file Reads the plaintext and writes it encrypted 
to the encryption fileor reads the encrypted file back to plain text based on the mode
Input: keyFile, file in , file out, mode 
Returns: encrypted or decrypted file depending on mode
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
	char ch;
    int j = 0;
    int key[ALPH][2];
	int encKey[ALPH]; //holds the encrypted values
	int decKey[ALPH]; //holds the decrypted values
	
	fstream fin;
	fstream keyIn;
	fstream fout;

	fileOpen(keyIn, keyFile, 'r');
    for (int i = 0; i < ALPH; i++)
    {
        keyIn >> j;
        encKey[i] = j;
    }
    keyIn.close();

	if (mode == 1)
    {
        fileOpen(fin, fileIn, 'r');
	    fileOpen(fout, fileOut, 'w');
	
	    while(fin.peek() != EOF)
	    {
		    ch = fin.get();
		
		    if(isalpha(ch))
		    {
			    ch = toupper(ch); //makes characters upper case
			    if(mode == 1)
			    {
                    ch = transform(ch, encKey);
                    fout.put(ch);
			    }
            }
        }
        fin.close();
	    fout.close();
    }
	if(mode == 2)
	{	
		for(int i = 0; i < ALPH; i++)
        {
            key[i][0] = i;
            key[i][1] = encKey[i];
        }
        mysterySort(key);
        for(int i = 0; i < ALPH; i++)
        {
            decKey[i] = key[i][0];
        }
        
        fileOpen(fin, fileIn, 'r');
	    fileOpen(fout, fileOut, 'w');
	    while(fin.peek() != EOF)
	    {
		    ch = fin.get();
		
		    if(isalpha(ch))
		    {
			    ch = toupper(ch); //makes characters upper case
                ch = transform(ch, decKey);
                fout << ch;
            }
        }
        fin.close();
	    fout.close();
	}
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
/*
    Transforms the given character using the given key array
    input: charater, encryption or decryption array
    output: encrypted or decrypted character
*/
char transform(char ch, int encDec[])
{

	int pos = ch - 'A'; //0-25
	pos = encDec[pos]; 
	ch = pos + 'A'; //back to ASCII val
	
	return ch;
}