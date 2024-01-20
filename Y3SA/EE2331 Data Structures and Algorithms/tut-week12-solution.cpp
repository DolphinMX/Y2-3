//   test driver for heap, ignores index 0

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;


void heap_insert(vector<int>& data, int pos) {
	int k = data[pos]; // the element to be insert
	int i = pos;
	int parent = i / 2;
	while (i > 1 && data[parent] < k) {
		data[i] = data[parent];
		i = parent;
		parent = i / 2;
	}
	data[i] = k;
}


void heapify(vector<int>& data, int i) {
	cout << "heapify(data, " << i << ")" << endl;
	int l = i * 2 + 0;
	int r = i * 2 + 1;
	int largest;
	if (l <= data.size() - 1 && data[l] > data[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= data.size() - 1 && data[r] > data[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(data[i], data[largest]);
		heapify(data, largest);
	}
}


int main()
{
	int size;
	cout << endl << "How many elements in the input array: ";  cin >> size;
	vector<int> dataArray(size + 1);   // get array of right size (with invisible 0th element)
	vector<int> dataArray2(size + 1);

	// fill array -- fill 0th element but don't show it.
	for (int k = 0; k < size + 1; k++) { dataArray2[k] = dataArray[k] = rand() % 100; }
	cout << "Input array:\n";
	for (int k = 1; k < size + 1; k++)
		cout << dataArray[k] << " ";
	cout << endl;

	// ============= implement your code here or call it as a function======

	// build a heap for dataArray using insertion
	for (int k = 1; k < size + 1; k++)
		heap_insert(dataArray, k);

	//show heap
	cout << "Heap built from the input array using insertion:\n";
	for (int k = 1; k < size + 1; k++)
		cout << dataArray[k] << " ";
	cout << endl;


	//build a heap for dataArray2 using heapify
	for (int k = (size)/2; k >= 1; k -= 1)
		heapify(dataArray2, k);

	//show heap
	cout << "Heap built from the input array using heapify:\n";
	for (int k = 1; k < size + 1; k++)
		cout << dataArray2[k] << " ";
	cout << endl;

}


