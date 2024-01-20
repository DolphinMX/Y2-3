#include <iostream>
#include <fstream>
#include <string>
#include<limits>
#include<algorithm>

using namespace std;

// tree node, including left and right pointers, data
struct Node {
    Node(int studentID, string major, float grade, string admissionType, int year)
    : studentID(studentID), major(major), grade(grade), admissionType(admissionType), year(year), left(nullptr), right(nullptr) {}
    
    int studentID;
    float grade;  // New entry for grade
    string major;
    string admissionType;
    int year;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* _root;
    void insert(Node*& treeNode, int studentID, const string& major, float grade, const string& admissionType, int year);
    Node* search(Node* treeNode, int studentID);
    void deleteBST(Node* treeNode);
    void printInOrder(Node* treeNode);
    
public:
    BST();
    ~BST();
    void insert(int studentID, const string& major, float grade, const string& admissionType, int year) {
        insert(_root, studentID, major, grade, admissionType, year);
    }
    Node* search(int studentID) { return search(_root, studentID); }
    void deleteBST() { deleteBST(_root); }
    void printInOrder() { printInOrder(_root); }
};

BST::BST() : _root(nullptr) {}

void BST::insert(Node*& treeNode, int studentID, const string& major, float grade, const string& admissionType, int year) {
    if (!treeNode) {
        treeNode = new Node(studentID, major, grade, admissionType, year);
        //cout << "Inserted: " << studentID << " " << major << " " << grade << " " << admissionType << " " << year << endl;
    }
    else {
        if (studentID < treeNode->studentID) {
            insert(treeNode->left, studentID, major, grade, admissionType, year);
        }
        else {
            insert(treeNode->right, studentID, major, grade, admissionType, year);
        }
    }
}

Node* BST::search(Node* treeNode, int studentID) {
    if (!treeNode) {
        return nullptr;
    }
    if (treeNode->studentID == studentID) {
        return treeNode;
    }
    else if (studentID < treeNode->studentID) {
        return search(treeNode->left, studentID);
    }
    else {
        return search(treeNode->right, studentID);
    }
}

void BST::deleteBST(Node* treeNode) {
    if (!treeNode) {
        return;
    }
    Node* curTreeNode = treeNode;
    Node* leftTreeNode = treeNode->left;
    Node* rightTreeNode = treeNode->right;
    delete(curTreeNode);
    deleteBST(leftTreeNode);
    deleteBST(rightTreeNode);
}

BST::~BST() {
    deleteBST(_root);
}

void BST::printInOrder(Node *treeNode){
    if (!treeNode) {
        return;
    }
    printInOrder(treeNode->left);
    cout << treeNode->studentID << " " << treeNode->major << " " << treeNode->grade << " " << treeNode->admissionType << " " << treeNode->year << endl;
    printInOrder(treeNode->right);
}

int main() {
    string filename;
    cout << "Please enter your file name: ";
    cin >> filename;
    
    ifstream inputfile(filename);
    
    if (!inputfile) {
        cerr << "Error opening file. Exiting program." << endl;
        return 1;
    }
    
    BST studentDatabase;
    
    int studentID, year;
    float grade;
    string major, admissionType;
    
    while (inputfile >> studentID >> major >> grade >> admissionType >> year) {
        studentDatabase.insert(studentID, major, grade, admissionType, year);
    }
    
    //cout << "In-order traversal after insertions:" << endl;
    //studentDatabase.printInOrder();
    
    inputfile.close();
    
    while (true) {
        cout << "Enter operation (search/insert/over): ";
        string operation;
        cin >> operation;
        
        if (operation == "search") {
            cout << "Enter student ID: ";
            cin >> studentID;
            
            Node* result = studentDatabase.search(studentID);
            if (result != 0) {
                cout << "Record found: " << result->studentID << " " << result->major << " " << result->grade << " " << result->admissionType << " " << result->year << endl;
            }
            else {
                cout << "This ID does not exist." << endl;
            }
        }
        else if (operation == "insert") {
            cout << "Enter student ID, major, grade, admission type, and year: ";
            cin >> studentID >> major >> grade >> admissionType >>year;
            
            if (cin.fail() || to_string(studentID).length() != 8 || major.length() > 3 || !all_of(major.begin(), major.end(), ::isalpha) || any_of(major.begin(), major.end(), ::islower) || grade < 0 || grade > 100 || (admissionType != "4-year" && admissionType != "ASI" && admissionType != "ASII") || to_string(year).length() != 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wrong format. Please enter valid input." << endl;
            }
            else {
                studentDatabase.insert(studentID, major, grade, admissionType, year);
                cout << "Record inserted successfully." << endl;
            }
        }
        else if (operation == "over") {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid operation. Please enter search, insert, or over." << endl;
        }
    }
    
    return 0;
}
