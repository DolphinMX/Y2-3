//Student name:
//Student ID  :

/* 
	Implement the function prefix_to_postfix(string& prefix, string& postfix). 
	The function converts a prefix string to postfix format.
	
	Examples:
		(prefix)				(postfix)
		+*AB/CD					AB*CD/+
		+-*$ABCD//EF+GH			AB$C*D-EF/GH+/+
		+D/E+$*ABCF				DEAB*C$F+/+
		/-*A+BCD-E+FG			ABC+*D-EFG+-/
*/

// For those who want to challenge yourself, you can also try to implement 
// the function postfix_to_prefix(string& postfix, string& prefix).
// Read in the postfix expressions from postfix.txt, and convert them to
// prefix format.

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

struct stackItem 
{	
	char symb;
	int count;
};


bool isOperator(char c)
{
   return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}


/*
	A string object differs from a C-string (array of char) in that it is not terminated by '\0'.

	The member function length() returns the length of the string object.
	You can access a character in the string object by the subscript operator, e.g. prefix[i].
	
*/
void prefix_to_postfix(string& prefix, string& postfix)
{
	//Convert the input prefix expression to postfix format

	postfix = prefix;   //initialize the postfix string to the same length of the prefix string

	stack<stackItem> S;
	stackItem x;
	int k = 0;	//index for accessing char of the postfix string

	for (int i=0; i < prefix.length(); i++)  //process each char in the prefix string from left to right
	{
		char c = prefix[i];

		//Implement the body of the for-loop		

	}
}


int main()
{	
	ifstream infile("prefix.txt");
	if (!infile.is_open())
	{
		cout << "Error: cannot open data file" << endl;
		system("pause");
		exit(0);
	}

	string postfix_string, prefix_string;


	while (getline(infile, prefix_string))  //read in one line from infile
	{
		prefix_to_postfix(prefix_string, postfix_string);

		cout << "prefix  : " << prefix_string << endl;
		cout << "postfix : " << postfix_string << endl << endl;
	}
	infile.close();

	system("pause");
	exit(0);
}