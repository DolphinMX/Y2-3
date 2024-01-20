#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void quicksort(vector<int>& data, int p, int r) {
	if (p < r) {	// if p >= r, it is the base case, do nothing
		// choose the new pivot
		
		// index of the middle
		int middle = p + ((r - p + 1) / 2);

		int pivot;
		// find the median between first, last and middle element
		if ((data[p] <= data[r] && data[p] >= data[middle]) or (data[p] >= data[r] && data[p] <= data[middle])) {
			pivot = p;
		}
		else if ((data[r] <= data[p] && data[r] >= data[middle]) or (data[r] >= data[p] && data[r] <= data[middle])) {
			pivot = r;
		}
		else {
			pivot = middle;
		}

		//print out the called function
		cout << "quicksort(data, " << p << ", " << r << ")" << endl;
		cout << "p = " << p << ", r = " << r << ", pivot = " << data[pivot] << endl;

		//switch the pivot to the first position
		swap(data[pivot], data[p]);

		//partition, sort in decreasing order
		pivot = p;
		int low = p;
		int high = r;
		while (low < high) {
			while (data[low] >= data[pivot] && low < r) low++;	//decreasing order
			while (data[high] < data[pivot] && high > p) high--;	//decreasing order
			if (low < high) swap(data[low], data[high]);
		}
		if (data[pivot] < data[high])	// swap pivot with high
			swap(data[pivot], data[high]);
		int q = high;
		quicksort(data, p, q - 1);
		quicksort(data, q + 1, r);
	}
	else {
		cout << "quicksort(data, " << p << ", " << r << ")" << endl;
		cout << "p = " << p << ", r = " << r << endl;
	}
}

int main() {
	vector<int> data;
	int size;


	// read in file
	ifstream input("test1.txt");
	if (!input.is_open()) {
		cout << "Error: cannot open data file" << endl;
		exit(0); //terminate the program
	}

	cout << "Number of elements: ";
	input >> size;

	for (int i = 0; i < size; i++) {
		int x;
		input >> x;
		data.push_back(x);
	}
	input.close();

	// print the list
	cout << "List before sort:" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << " ";
	}
	cout << endl << endl;

	// quick sort
	quicksort(data, 0, data.size() - 1);

	cout << endl;
	// print the sorted list
	cout << "List after sort:" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	return 0;
}


