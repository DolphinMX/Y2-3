// Student name: 
// Student ID  : 

/*
	Submission deadline: Sunday, 21 April 2019, 11:59 pm.

	*** Weighting of this exercise is 2 times the weighting of other tutorials. ***

	What you need to do in this exercise:

	1. A Huffman code table is given to you in the file HuffmanCodeTable.txt
	   Format of the data file:
	   line 1 : contains 1 number, which is equal to the number of alphabets
	   lines 2 to n+1 : contain the ASCII code (2 hex digits) of the symbol and the Huffman code

	   You need to write a function to read in the Huffman codes and 
	   create the Huffman tree from the given code table.

	2. An encoded message is given to you in the file CodedMsg.txt
	   A function to read in the encoded message to a bit-vector is given to you.
	   Refer to the pdf file for the organization of the bit-vector.

	   You need to design a function to decode the message and save the decoded message
	   to the char array text[].
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void readCodedMsg(const string& filename, unsigned char *bitVec, int& len)
{
	// Read in the encoded message from the data file to a bit-vector.
	// The encoded message is stored in 1 line in the data file.

	// The bit-vector (bitVec) is an array of unsigned char.
	// len = number of bits in the bit-vector

	unsigned char mask[8] = {1, 2, 4, 8, 16, 32, 64, 128};

	ifstream infile(filename);
	if (!infile.is_open())
	{
		cout << "Error: cannot open " << filename << endl;
		system("pause");
		exit(0);
	}

	len = 0;
	char c;

	// end-of-line delimiter in Windows is '\n'
	// end-of-line delimiter in Mac is "\r\n"
	while ((c = infile.get()) != '\n' && c != '\r')  
	{					
		int byteIndex = len / 8;
		int bitIndex = 7 - len % 8;
		if (len % 8 == 0)
			bitVec[byteIndex] = 0;
		
		if (c == '1')		
			bitVec[byteIndex] = bitVec[byteIndex] | mask[bitIndex];  // bit-wise OR

		len++;
	}
	infile.close();
}

int main()
{		
	string codeTableFile = "HuffmanCodeTable.txt";
	string codedMsgFile = "CodedMsg.txt";

	unsigned char buffer[256];  // 256-byte buffer, up to 2K bits for the coded message
	int len = 0;                // number of bits in the encoded message

	readCodedMsg(codedMsgFile, buffer, len);	

	char text[256];
	text[0] = '\0';

	// Your codes to decode the message and 
	// save the decoded message to the char array text[].

	cout << "Decoded message:\n";
	cout << text << endl << endl;

	system("pause");
	return 0;
}