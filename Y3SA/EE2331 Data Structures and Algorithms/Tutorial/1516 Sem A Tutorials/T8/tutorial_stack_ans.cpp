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
	int k = 0;

	for (int i=0; i < prefix.length(); i++)  //process each char in the prefix string from left to right
	{
		char c = prefix[i];
		if (isOperator(c))
		{
			x.count = 0;
			x.symb = c;
			S.push(x);
		}
		else
		{
			postfix[k++] = c;
			while (!S.empty())
			{
				S.top().count++;
				if (S.top().count == 2)
				{
					postfix[k++] = S.top().symb;
					S.pop();
				}
				else
					break;
			}
		}
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


	while (getline(infile, prefix_string))
	{
		prefix_to_postfix(prefix_string, postfix_string);

		cout << "prefix  : " << prefix_string << endl;
		cout << "postfix : " << postfix_string << endl << endl;
	}

	system("pause");
	exit(0);
}