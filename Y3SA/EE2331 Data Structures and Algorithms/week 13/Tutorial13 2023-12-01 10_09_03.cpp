#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isMaxHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[leftChild] > arr[i])
            return false;

        if (rightChild < n && arr[rightChild] > arr[i])
            return false;
    }
    return true;
}

int main() {
    string fileName;
    cout << "Enter the input file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    vector<int> arr;
    int num;

    while (inputFile >> num) {
        arr.push_back(num);
    }

    inputFile.close();

    if (isMaxHeap(arr))
        cout << "Yes, it is a heap." << endl;
    else
        cout << "This is not a heap." << endl;

    return 0;
}