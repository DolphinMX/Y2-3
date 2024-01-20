// Student name: 
// Student ID  : 

/*
	Submission deadline: Thursday, 28 Feb 2019, 2 pm.

	This exercise is on sorting.
	We shall compare the performances of bubble sort, insertion sort, and qsort
	for sorting arrays of cstring and C++ string objects.

	A template (generic) function for insertion sort is given to you.
	You need to define your own compare functions in order to use the template insertionSort function.
	We want to sort an array of string (or cstring) by length, 
	and strings of the same length are sorted by alphabetical order.

	In the second part, you need to design a template function for bubble sort.

	In the third part, you need to define the compare functions required by qsort.

	Observe the performances of the 3 algorithms, and the differences in the computation
	time for sorting arrays of cstring and string.
	You need to understand the reasons behind the differences in performances of the 3 algorithms.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Part-1: Define your compare functions for using the template insertionSort function

// Part-2: Define your template function bubbleSort

// Part-3: Define your compare functions here for using qsort

typedef char* charptr;
int compare_cstring(const charptr& a, const charptr& b)
{
	int L1 = strlen(a);
	int L2 = strlen(b);
	if (L1 != L2)
		return L1 - L2;

	return strcmp(a, b);
}

int compare_string(const string& a, const string& b)
{
	int L1 = a.length();
	int L2 = b.length();
	if (L1 != L2)
		return L1 - L2;

	return a.compare(b);
}

int compare_cstring(const void *a, const void *b)
{
	char **s1 = (char **)a;
	char **s2 = (char **)b;

	int L1 = strlen(*s1);
	int L2 = strlen(*s2);
	if (L1 != L2)
		return L1 - L2;

	return strcmp(*s1, *s2);
}

int compare_string(const void *a, const void *b)
{
	string *s1 = (string *)a;
	string *s2 = (string *)b;

	int L1 = s1->length();
	int L2 = s2->length();
	if (L1 != L2)
		return L1 - L2;

	return s1->compare(*s2);
}


// define your template function for bubbleSort here
template<class Type>
void bubbleSort(Type *x, int n, int (*compare)(const Type&, const Type&))
{
	// Implement the sorting function using the bubble sort algorithm.

	int switched = 1;
	for (int pass = 1; pass < n && switched; pass++)
	{
		switched = 0;
		for (int j = 0; j < n-pass; j++)
			if (compare(x[j], x[j+1]) > 0)
			{
				Type t = x[j];
				x[j] = x[j+1];
				x[j+1] = t;
				switched = 1;
			}
	}
}

template<class Type>
void insertionSort(Type *x, int n, int (*compare)(const Type&, const Type&))
{
	for (int i = 1; i < n; i++)
	{
		Type t = x[i];
		int j;
		for (j = i-1; j >= 0 && compare(x[j], t) > 0; j--)
			x[j+1] = x[j];
		x[j+1] = t;
	}
}

void test_insertionSort(char **a, string *s, int n)
{
	// Sort the list of strings by length, and 
	// strings of the same length are sorted in alphabetical order

	clock_t begin, end;
	double elapsedTime;

	cout << "Insertion sort:\n\n";
	cout << "Sort an array of char*, size = " << n << endl;
	begin = clock();

	// *** add your statement to sort the array a[] using insertionSort
	insertionSort(a, n, compare_cstring);
	end = clock();
	elapsedTime = (double)(end - begin)/CLOCKS_PER_SEC;
	cout << "Elapsed time = " << elapsedTime << " seconds" << endl << endl;	

	cout << "Sort an array of string, size = " << n << endl;
	begin = clock();

	// *** add your statement to sort the array s[] using insertionSort
	insertionSort(s, n, compare_string);
	end = clock();
	elapsedTime = (double)(end - begin)/CLOCKS_PER_SEC;
	cout << "Elapsed time = " << elapsedTime << " seconds" << endl << endl;		

	cout << "\nFirst 5 and last 5 strings in the list:\n\n";
	for (int i = 0; i < 5; i++)
		cout << a[i] << " : " << s[i] << endl;
	cout << endl;
	for (int i = 5; i > 0; i--)
		cout << a[n-i] << " : " << s[n-i] << endl;
}

void test_bubbleSort(char **a, string *s, int n)
{
	// Sort the list of strings by length, and 
	// strings of the same length are sorted in alphabetical order

	clock_t begin, end;
	double elapsedTime;

	cout << "\n------------------------------------------------------\n";
	cout << "Bubble sort:\n\n";
	cout << "Sort an array of char*, size = " << n << endl;
	begin = clock();

	// *** add your statement to sort the array a[] using bubbleSort
	bubbleSort(a, n, compare_cstring);
	end = clock();
	elapsedTime = (double)(end - begin)/CLOCKS_PER_SEC;
	cout << "Elapsed time = " << elapsedTime << " seconds" << endl << endl;	

	cout << "Sort an array of string, size = " << n << endl;
	begin = clock();

	// *** add your statement to sort the array s[] using bubbleSort
	bubbleSort(s, n, compare_string);
	end = clock();
	elapsedTime = (double)(end - begin)/CLOCKS_PER_SEC;
	cout << "Elapsed time = " << elapsedTime << " seconds" << endl << endl;		

	cout << "\nFirst 5 and last 5 strings in the list:\n\n";
	for (int i = 0; i < 5; i++)
		cout << a[i] << " : " << s[i] << endl;
	cout << endl;
	for (int i = 5; i > 0; i--)
		cout << a[n-i] << " : " << s[n-i] << endl;
}

void test_qsort(char **a, string *s, int n)
{
	// Sort the list of strings by length, and 
	// strings of the same length are sorted in alphabetical order.

	clock_t begin, end;
	double elapsedTime;

	cout << "\n------------------------------------------------------\n";
	cout << "qsort:\n\n";
	cout << "Sort an array of char*, size = " << n << endl;
	begin = clock();

	// *** add your statement to sort the array a[] using qsort
	qsort(a, n, sizeof(char *), compare_cstring);
	end = clock();
	elapsedTime = (double)(end - begin)/CLOCKS_PER_SEC;
	cout << "Elapsed time = " << elapsedTime << " seconds" << endl << endl;	

	cout << "Sort an array of string, size = " << n << endl;
	begin = clock();

	// *** add your statement to sort the array s[] using qsort
	qsort(s, n, sizeof(string), compare_string);
	end = clock();
	elapsedTime = (double)(end - begin)/CLOCKS_PER_SEC;
	cout << "Elapsed time = " << elapsedTime << " seconds" << endl << endl;		

	cout << "\nFirst 5 and last 5 strings in the list:\n\n";
	for (int i = 0; i < 5; i++)
		cout << a[i] << " : " << s[i] << endl;
	cout << endl;
	for (int i = 5; i > 0; i--)
		cout << a[n-i] << " : " << s[n-i] << endl;
}

// ---------------------------------------------- other functions given to you

void randomize(char **a, string *s, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = rand() % n;
		char *t = a[i];
		a[i] = a[j];
		a[j] = t;

		string w = s[i];
		s[i] = s[j];
		s[j] = w;
	}
}

char* gen_cstring(int len)
{
	char *t = new char[len+1];
	for (int i = 0; i < len; i++)
		t[i] = 'a' + rand() % 26;
	t[len] = '\0';
	return t;
}

int main()
{		
	srand((unsigned)time(NULL));  // set the seed of the random number generator
	
	int n = 2000;
	char **a = new char*[n];  
	string *s = new string[n];

	for (int i = 0; i < n; i++)	
	{
		int len = 5 + rand() % 15;
		a[i] = gen_cstring(len);
		s[i] = string(a[i]);
	}
	
	test_insertionSort(a, s, n);	

	randomize(a, s, n);	
	test_bubbleSort(a, s, n);
	
	randomize(a, s, n);
	test_qsort(a, s, n);

	system("pause");
	return 0;
}