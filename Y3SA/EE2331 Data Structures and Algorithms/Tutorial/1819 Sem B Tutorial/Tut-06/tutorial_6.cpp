// Student name: 
// Student ID  : 

/*
	Submission deadline: Thursday, 7 March 2019, 2 pm.

	Part-1 is on simple linked list operation.

	Part-2:
	A video content provider maintains a daily log of the clients' streaming requests.
	Each log record contains 3 data fields (timestamp, video ID, client's IP address).
	The company wants to find out the top 10 most popular videos in each day,
	i.e. the 10 videos with the largest view count in the daily log.

	The function to read in the data from the log file is given to you.

	Implement the functions getTop10MostPopular() and updateTop10().
	The results are stored in a linked list.
	Since items ranked 10 and 11 have the same view count, the linked list contains 11 items.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

struct logRec
{
	long long timestamp;
	string vid;           // video ID
	string clientIP;      // IP address of client
};

struct viewRec
{
	string vid;     // video ID
	int viewCount;  // number of times the video is viewed (appears in log file)
};

template<class Type>
struct node
{
	Type info;
	node<Type> *link;
};

// --------------------------------------------- functions to be implemented by you

void findLongestNonNegSubSeq(const node<int> *list)
{
	const node<int> *start = nullptr;  
	// start points to first node of the longest subsequence with non-negative values

	int maxLen = 0;  // length of the longest subsequence with non-negative values


	// Your codes
	

	cout << "Longest subsequence with non-negative values:\n";
	if (start != nullptr) 
	{		
		p = start;
		for (int i = 0; i < maxLen - 1; i++)
		{
			cout << p->info << ", ";
			p = p->link;
		}
		cout << p->info << endl;
	}
	else	
		cout << "empty subsequence\n";
	
}


void updateTop10(node<viewRec>*& top10, const string& vid, int count)
{
	// top10 is the pointer pointing to the first node of the linked list.
	// Nodes in the linked list are sorted by viewCount in descending order.
	
	// Determine if (vid, count) is to be added to the linked list or not.
	// You can only traverse the linked list in 1 direction.

	// If (vid, count) is added to the linked list, 
	// determine if some existing items need to be removed.

	// You need to keep track of the rank of the current node when traversing the linked list.

	
}

node<viewRec>* getTop10MostPopular(logRec *list, int n)
{
	// You may sort the input list by vid using qsort.
	// This will facilitate the counting of the number of times that each video is viewed.

	node<viewRec> *top10 = nullptr;  // linked list for holding the result


	// Use a loop to find out the viewCount of each video.
	// Call updateTop10List to process the item (vid, viewCount).


	return top10;
}

// --------------------------------------------- functions given to you
template<class Type>
void printList(node<Type> *list) 
{
	cout << "List: ";
    node<Type> *p = list;
    while (p != nullptr) 
	{
        cout << p->info << ", ";
        p = p->link;
    }
    cout << endl;
}

node<int>* createNode(int info) 
{
	node<int> *p = new node<int>;   
	p->info = info;
	p->link = nullptr;
	return p;
}

node<int>* gen_intList(int n)
{
	node<int> *list = nullptr;	

	if (n > 0)
	{
		list = createNode(rand() % 49);
		node<int> *p = list;
		for (int i = 1; i < n; i++)
		{		
			int k = 1 + rand() % 49;
			if (rand() % 11 < 3)
				k *= -1;

			p->link = createNode(k);
			p = p->link;
		}
	}
	return list;
}


void readData(string filename, logRec*& list, int& n)
{
	// Date file format:
	// First line contains the value of n (number of records).
	// Each video record (timestamp, vid, clientIP) is stored in 1 line.
	// Data fields are separated by comma (without white-space char).

	ifstream infile(filename);
	if (!infile.is_open())
	{
		cout << "Error: cannot open data file" << endl;
		system("pause");
		exit(0);
	}

	string line;
	getline(infile, line);
	n = stoi(line);  // string to int
	list = new logRec[n];

	for (int i = 0; i < n; i++)
	{
		getline(infile, line);
		int k = line.find(",");
		list[i].timestamp = stoll(line.substr(0,k));  // string to long long
		
		int j = k + 1;
		k = line.find(",", j);
		list[i].vid = line.substr(j, k-j);
		list[i].clientIP = line.substr(k+1);
	}

	infile.close();
}

void part_2()
{
	string filename = "videoData.txt";
	int n;
	logRec *list;

	readData(filename, list, n);

	node<viewRec> *top10 = getTop10MostPopular(list, n);

	cout << "\n----------------------------------------------\n\n";
	cout << "Part-2:\n\n";
	cout << "Top 10 most popular (video ID : view count)\n";
	node<viewRec> *p = top10;
	while (p != nullptr)
	{
		cout << p->info.vid << " : " << p->info.viewCount << endl;
		p = p->link;
	}
	cout << endl;
}

void part_1()
{
	cout << "Part-1:\n";

	srand((unsigned)time(NULL));

	for (int i = 1; i <= 3; i++)
	{
		cout << "\n*** Test " << i << " ***\n";
		int n = 10 + rand() % 7;
		node<int> *listA = gen_intList(n);
		printList(listA);
		cout << endl;
		findLongestNonNegSubSeq(listA);
	}
}

int main()
{	
	part_1();
	part_2();

	system("pause");
	return 0;
}