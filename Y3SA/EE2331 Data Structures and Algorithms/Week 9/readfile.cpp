    // read integers from file and create an array
    ifstream input("test.txt");
    if (!input.is_open()) {
        cout << "Error: cannot open data file" << endl;
        exit(0); //terminate the program
    }
    int size;
    cout << "Number of elements: ";
    input >> size;
    cout << size << endl;
    int* data = new int[size];
    for (int i = 0; i < size; i++) {
        input >> data[i];
    }
    input.close();

