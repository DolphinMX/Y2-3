// Student name: 
// Student ID  : 

// Submission deadline: Thursday, 24 Jan 2019, 14:00
// Upload your program file (tutorial_1.cpp) to Canvas.
// Late submission or submission not revcieved via Canvas will not be graded.

/*
	Part-1:	Count the number of words in the input char array.
	A word is a continuous sequence of non-white space characters.
	White-space characters include 'space', tab '\t', newline '\n', and carriage return '\r'.

	You may use the C library function isspace() in your answer.

	Part-2: Print the words in the input array, one word per line.

*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int wordCount(const char text[])
{
	// Return the number of words in the array text[].

	int count = 0;
	bool ws = true;   // ws stands for white-space

	for (int i = 0; text[i] != '\0'; i++)  // '\0' = end of string delimiter
	{
		if (isspace(text[i]))
			ws = true;
		else
		{
			if (ws)  // transition from white-space to non-white space char
				count++;
			ws = false;
		}			
	}
	return count;
}

int wordCount(const char text[], int lenThreshold)
{
	// Return the number of words (with length >= lenThreshold) in the array text[].

	int count = 0;
	int len = 0;  
	bool done = false;

	for (int i = 0; !done; i++)
	{
		if (isspace(text[i]) || text[i] == '\0')  // end of a word
		{
			if (len >= lenThreshold)
				count++;
			len = 0;
			if (text[i] == '\0')
				done = true;
		}
		else
			len++;	
	} 
	return count;
}

void printArraySegment(const char *str, int len)
{
	for (int i = 0; i < len; i++)
		cout << str[i];
}

void printWords(const char text[])
{	
	// Print the words in text[], one word per line.

	cout << "Words in the input array:" << endl;

	int start = 0;
	int len = 0; 
	bool done = false;

	for (int i = 0; !done; i++)
	{
		if (isspace(text[i]) || text[i] == '\0')
		{
			if (len > 0)
			{
				printArraySegment(text+start, len);
				cout << endl;
				//string word(text+start, len);
				//cout << word << endl;
			}
			len = 0;
			if (text[i] == '\0')
				done = true;
		}
		else
		{
			if (len == 0)
				start = i;
			len++;
		}
	}
}

int main()
{		
	char text1[] = "  EE2331 Data  Structures \t and Algorithms Tutorial 1 ";
	char text2[] = "For a user's perspective, a keyboard consists of keys that can be pressed and released to type text.";

	cout << "Part-1: wordCount" << endl << endl;

	cout << "text1[] :\n" << text1 << endl << endl;
	int wc1 = wordCount(text1);
	cout << "Word count = " << wc1 << endl << endl;

	int lenThreshold = 5;
	int wc2 = wordCount(text1, lenThreshold);
	cout << "Word count (lenThreshold = " << lenThreshold << ") = " << wc2 << endl << endl;

	cout << "text2[] :\n" << text2 << endl << endl;
	wc1 = wordCount(text2);
	cout << "Word count = " << wc1 << endl << endl;

	wc2 = wordCount(text2, lenThreshold);
	cout << "Word count (lenThreshold = " << lenThreshold << ") = " << wc2 << endl << endl;
	
	cout << "--------------------------------------------\n";
	cout << "Part-2: printWords" << endl << endl;
	printWords(text2);	

	system("pause");
	return 0;
}