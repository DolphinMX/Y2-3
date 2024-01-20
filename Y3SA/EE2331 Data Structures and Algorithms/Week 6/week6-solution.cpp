#include <iostream>
#include <stdlib.h>

using namespace std;

int* insertion_sort(int* data, int size) {
	for (int i = 1; i < size; i++) {
		int temp = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > temp) {	//Task 3, reverse sort: data[j] < temp 
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = temp;
	}
	return data;
}

int binarySearch1(int data[], int low, int high, int x) {
	int mid;
	int count = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (data[mid] == x) {
			return mid;
		}
		else if (data[mid] > x) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}

int binarySearch2(int data[], int low, int high, int x) {
	int mid;
	mid = (low + high) / 2;
	if (low > high) {
		return -1;
	}
	if (data[mid] == x) {
		return mid; //x has been found
	}
	else if (data[mid] > x) {
		return binarySearch2(data, low, mid - 1, x);
	}
	else {
		return binarySearch2(data, mid + 1, high, x);
	}
}

int main()
{
	int size;
	cout << "\nHow many elements:  ";  cin >> size;

	int* dataArray = new int[size];   // claim the array

	//  ============ generate n random integers  ===================  

	for (int k = 0; k < size; k++)  dataArray[k] = rand();
	cout << "\nGenerated random integers:\n";
	for (int k = 0; k < size; k++) { printf("%d, ", dataArray[k]); }
	printf("\n");

	// =====================InsertionSort===============  

	dataArray = insertion_sort(dataArray, size);


	cout << "integers after sorted:";
	for (int i = 0; i < size; i++)
		cout << dataArray[i] << ", ";
	cout << endl;

	// =====================binary search using loop===============  

	int query;
	cout << "\nQuery number:  ";
	cin >> query;
	cout << "\nThe position of query number:  " << binarySearch1(dataArray, 0, size - 1, query) << endl;

	// =====================binary search using iteration===============  

	cout << "\nThe position of query number:  " << binarySearch2(dataArray, 0, size - 1, query) << endl;

	return 0;
}
