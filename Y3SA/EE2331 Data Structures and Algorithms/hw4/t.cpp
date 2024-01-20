#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <string.h>


using namespace std;


struct Node {
    Node(string record) : data(record), left(NULL), right(NULL) {}
    string data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* _root;
    void insert(Node*& treeNode, const string& data);
    Node* search(Node* treeNode, const string& studentID);

public:
    BST();
    void insert(const string& data) { insert(_root, data); }
    Node* search(const string& studentID) { return search(_root, studentID); }

};

BST::BST() : _root(NULL) {}

void BST::insert(Node*& treeNode, const string& data) {
    if (!treeNode) {
        treeNode = new Node(data);
    }
    else {
        if (data < treeNode->data) {
            insert(treeNode->left, data);
        }
        else {
            insert(treeNode->right, data);
        }
    }
}

Node* BST::search(Node* treeNode, const string& studentID) {
    if (!treeNode) {
        return NULL;
    }
    if (treeNode->data.substr(0, 8) == studentID) {
        return treeNode;
    }
    else if (studentID < treeNode->data.substr(0, 8)) {
        return search(treeNode->left, studentID);
    }
    else {
        return search(treeNode->right, studentID);
    }
}

bool isConvertibleToFloat(const std::string& str) {
    bool result = false;
    try {

        std::stof(str);

        result = true;
    }
    catch (...) {

    }
    return result;
}



int main() {
    
   



    string fileName;
    cout << "Enter the database file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error opening file. Exiting program." << endl;
        return 1;
    }

    BST studentDatabase;

    string line;
    while (getline(inputFile, line)) {
        studentDatabase.insert(line);
    }

    inputFile.close();
    cout << "Database indexing finished."<<endl;

    while (true) {
        cout << "*****Please input one of the following operations: search, insert, over *****"<<endl;
        string operation;
        cin >> operation;

        if (operation == "search") {
            cout << "Your input is <search>. Please input the student ID: ";
            string studentID;
            cin >> studentID;

            Node* result = studentDatabase.search(studentID);
            if (result) {
                string temp;
                stringstream temps(result->data);
                vector<string> search;
                while (getline(temps, temp, ' ')) {

                    search.push_back(temp);
                }
                cout <<"The student with ID "<< search[0]<<" has the following information: "<< search[1]<<" " << search[2] << " " << search[3] << " " << search[4] <<endl;
            }
            else {
                cout << "This ID does not exist." << endl;
            }
        }
        else if (operation == "insert") {
            bool check = true;
            cout << "Your input is <insert>. Please input the student's record: ";
            string record;
            cin.ignore();
            getline(cin, record);
            string s;
            stringstream ss(record);
            vector<string> v;
            while (getline(ss, s, ' ')) {

                v.push_back(s);
            }
            if (v.size()==5) {
                const char* tSID = v[0].c_str();
                for (int i = 0; i < strlen(tSID); i++) {
                    if (!isdigit(tSID[i]))
                        check = false;
                }
                const char* tmajor = v[1].c_str();
                for (int i = 0; i < strlen(tmajor); i++) {
                    if (!isalpha(tmajor[i]))
                        check = false;
                }
                if (!isConvertibleToFloat(v[2])) {
                    check = false;
                }
                const char* tyear = v[4].c_str();
                for (int i = 0; i < strlen(tyear); i++) {
                    if (!isdigit(tyear[i]))
                        check = false;
                }
                if (check) {
                    int SID = stoi(tSID);
                    string major = v[1];
                    float marks = stof(v[2]);
                    string admission = v[3];
                    int year = stoi(tyear);

                    if ((SID < 00000000 || SID>99999999) || (strlen(tSID)!=8))
                        check = false;
                    if (major.length() > 3)
                        check = false;
                    if (marks < 0 || marks>100)
                        check = false;
                    if (admission != "4-year" && admission != "ASI" && admission != "ASII")
                        check = false;
                    if ((year < 0000 || year>9999) || (strlen(tyear) != 4))
                        check = false;
                    


                    if (check) {
                        studentDatabase.insert(record);
                        cout << "The student has been inserted" << endl;
                    }
                    else {
                        cout << "Wrong format" << endl;
                    }
                }
                else {
                    cout << "Wrong format"<< endl;
                }
            }
            else {
                cout << "Wrong format" << endl;
            }
        }
        else if (operation == "over") {
            cout << "Your input is <over>. Bye." << endl;
            break;
        }
        else {
            cout << "Invalid operation. Please enter search, insert, or over." << endl;
        }
    }

    return 0;
}