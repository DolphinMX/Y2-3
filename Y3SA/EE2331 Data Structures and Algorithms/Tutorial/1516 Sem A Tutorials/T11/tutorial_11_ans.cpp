// Student name:
// Student ID  :

/* This exercise is on the use of insertion sort and the qsort() function available in the C stdlib.
An unsorted array of registrations will be generated by the program code given to you. The order of records 
is defined by ascending courseCode order and records with the same courseCode records are ordered by 
studentId in decending order.

 You are asked to add your codes to
 1. use qsort() to sort the array by courseCode (ascending) and studentId (descending)
 2. use insertion sort to sort the array by courseCode (ascending) and studentId (descending)
 
 */

#include <iostream>
#include <sstream>	//stringstream
#include <iomanip>  //setw()
#include <cstdlib>


using namespace std;

//----------------------------------------------- class prepared for you

// Course registration information can be represented by a record of <courseCode, studentId>.

class Registration {
    
    // this function is not a member
    friend ostream& operator<<(ostream& os, Registration& r);
    
private:
    string courseCode;
    int studentId;
public:
    // constructors with initialization list
    Registration() : courseCode(""), studentId(0) {};
    Registration(string c, int s) : courseCode(c), studentId(s) {};
    
    // getters for returning private fields
    string getCourseCode() {
        return courseCode;
    }
    
    int getStudentId() {
        return studentId;
    }
    
    // setter
    void registerCourse(string c, int s) {
        courseCode = c;
        studentId = s;
    }
    
    
};


//----------------------------------------------- functions prepared for you
ostream& operator<<(ostream& os, Registration& r)
{
    stringstream s;
    s << r.courseCode << "-" << r.studentId;
    os << s.str();
    return os;
}

void initArray(Registration* A, int n)
{
  
    int j, s , c = 0;
    string prefix[] = {"AC", "BA", "CS", "EE", "GE", "MA"};
    int i = 0;
    while(i < n)
    {
        j = rand() % 6;
        c = rand() % 3 + 2010;
        string ccode = prefix[j] + std::to_string(static_cast<long long>(c));   
        s = rand() % 10 + 50001;
        A[i++].registerCourse(ccode, s);
    }
}

void printArray(Registration* A, int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(15) << A[i] << ",";
    cout << endl;
}

//----------------------------------------------- functions implemented by you

// Compare function for registrations. The order is ascending courseCode order 
// and for the same courseCodes decending studentId order.
int compareRegistration(const void *a, const void *b)
{
    Registration *d1 = (Registration *)a;
    Registration *d2 = (Registration *)b;
    
    if ( d1->getCourseCode() != d2->getCourseCode() ) {
        return  d1->getCourseCode().compare(d2->getCourseCode());
    }
    
    return d2->getStudentId() - d1->getStudentId();
    
}

// Insertion sort for sorting the registrations with compare function.
void insertionSort(Registration *x, unsigned n, int (*compare)(const void*, const void*)) {
    int j;
    for (int i = 1; i < n; i++) {
        Registration t = x[i];
        j = i-1;
        while (j >= 0 && compare(&x[j], &t) > 0) {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = t;
        
    }
}

int main()
{
    cout << "Exercise on sorting object arrays" << endl << endl;
    
    int n;
    cout << "Enter number of records: ";  // try values between 40 to 60
    cin >> n;
    
    Registration* A = new Registration[n];
    initArray(A, n);
    cout <<"Unsorted records:"<< endl;
    printArray(A, n);
    
    cout <<"Sorted records with qsort:"<< endl;
    qsort(A, n, sizeof(Registration), compareRegistration); // Add qsort here
    printArray(A, n);


	A = new Registration[n];
    initArray(A, n);
    cout <<"Unsorted records:"<< endl;
    printArray(A, n);
    
    cout <<"Sorted records with insertion sort:"<< endl;
    insertionSort(A, n, compareRegistration); // Add insertion sort here
    printArray(A, n);
    
    system("pause");
    return 0;
}