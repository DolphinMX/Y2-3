//Student name:
//Student ID  :


/*
Your task:

Implement the member/non-member functions for the class record. DO NOT modify
the function signatures given to you but you can define additional private member
functions as you need.

*/

#ifndef	RECORD_H
#define RECORD_H

#include <stack>
#include <iostream>
#include "linkedListType.h"

using namespace std;

// ----------------------------------------class declaration

class record
{
private:

	string id;							// id of jumper
	string name;						// name of jumper
	int max_result;						// the best result of jumper
	linkedListType<int> results;		// internal linked-list for storing results (oldest result first)

public:
	record();								// default constructor
	record(const record& other);			// copy constructor
	record(const string& id, const string& name, const int& init_result);		// constructor, initialize new record with the given values
	void addResult(int result);				// add new result
	record& createTeam(record& other);  	// create a team record from *this and other record
	int getMax();							// return max_result
	string getName();						// return name

											// overload the assignment operator
	const record& operator= (const record& other);

	// determine which record has higher ranking
	// first compare the max_result values, if they are the same, ranking is defined by the average value of results
	// return 0 if *this == other
	// return 1 if *this > other
	// return -1 if *this < other
	int compare(record& other);

	// print a record
	// since the results are stored in oldest first order, you need to print them in reverse order
	friend ostream& operator<<(ostream& os, record& n);
};

// ----------------------------------------class implementation

record::record() : id("N0000"), name("anonymous"), max_result(0) { }

record::record(const record& other) {
	max_result = other.max_result;
	name = other.name;
	id = other.id;
	results = other.results;
}

int record::getMax() {
	return max_result;
}

string record::getName() {
	return name;
}

const record& record::operator= (const record& other) {
	if (this != &other) {
		max_result = other.max_result;
		name = other.name;
		id = other.id;
		results = other.results;
	}
	return *this;
}

//--------------------------------- add your implementations below

// Constructor, initialize new record with the given values
record::record(const string& id, const string& name, const int& init_result) {
	this->id = id;
	this->name = name;
	this->max_result = init_result;
	this->results.insert(init_result);


}

// Add new result to the end of results list
void record::addResult(int result) {
	this->results.insert(result);
	if (this->max_result < result) {
		this->max_result = result;
	}


}

// Create a team record.
// New record is formed by combining two jumpers' record - *this and other.
// The new record is returned by reference.
record& record::createTeam(record& other) {

	record *combineteam = new record();

	if (this->max_result >= other.max_result)
	{
		combineteam->name = this->name + other.name;
		combineteam->id = this->id + other.id;
	}
	else
	{
		combineteam->name = other.name + this->name;
		combineteam->id = other.id + this->id;
	}

	linkedListIterator<int>a = this->results.begin();
	linkedListIterator<int>b = other.results.begin();
	linkedListIterator<int>c = this->results.end();
	linkedListIterator<int>d = other.results.end();


	int a_count = this->results.length();
	int b_count = other.results.length();
	int suma = 0;
	int sumb = 0;
	if (*a != NULL)
	{
		suma += *a;
		++a;
	}
	if (*b != NULL)
	{
		sumb += *b;
		++b;
	}

	int ava = suma / a_count;
	int avb = sumb / b_count;

	while (*c != NULL&&*d != NULL)
	{
		if (*c>*d)
		{
			combineteam->results.insert(*c);
			++c;
			++d;
		}
		else if (*c<*d)
		{
			combineteam->results.insert(*d);
			++c;
			++d;
		}

		else if (*c == *d)
		{

			if (ava < avb)
			{
				combineteam->results.insert(*d);
				++c;
				++d;
			}
			else {
				combineteam->results.insert(*c);
				++c;
				++d;
			}
		}
	}

	return *combineteam;
}

// Define ranking of the two jumpers.
// Return 0 if *this has same rank as other.
// Return 1 if *this has higher rank than other.
// Return -1 if *this has lower rank than other.
int record::compare(record& other) {/*

	linkedListIterator<int> A1 = this->results.begin();

	linkedListIterator<int> B1 = other.results.begin();
	linkedListIterator<int> C1 = this->results.begin();

	linkedListIterator<int> D1 = other.results.begin();

	int a_count = this->results.length();
	int b_count = other.results.length();
	int suma = 0;
	int sumb = 0;

	if (*A1 != NULL) {
		suma += *A1;
		++A1;
	}

	if (*B1 != NULL) {
		sumb += *B1;
		++B1;

	}
	int ava = suma / a_count;
	int avb = sumb / b_count;

	if (*A1 > *B1)
	{
		return 1;
	}
	else if (*A1 < *B1)
	{
		return-1;
	}
	else if (*A1 == *B1)
	{
		if (ava > avb) {
			return 1;
		}
		else if (ava < avb) {
			return -1;
		}
		else return 0;

	}

	*/



	// Output record as a string.
	// Printing format: id name max_result: [result_latest ... result_oldest]
	// e.g. N123 john 180: [90 180 40]
	ostream& operator<<(ostream& os, record n) {
		
		os << n.id << "" << n.name << "" << n.max_result << ":" << "[";
		stack<int> stackResult;
		linkedListIterator<int>linkItr = n.results.begin();
		while (linkItr != NULL)
		{
			stackResult.push(*linkItr);
			++linkItr;
		}
		while (!stackResult.empty()) {
			os << stackResult.top() << " ";
			stackResult.pop();
		}
		os << "\b" << "]" << endl;


		return os;

	}

#endif