#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char students[10][10] = {"James", "Iverson", "Wade", "Jordan", "George", "Curry", "Westbrook", "Durant", "Kobe",
						"Harden"};
	char course[6][20] = {"Mathematics", "English", "Data structures", "C++ Programming", "Internet", "Java Programming"};

	char stu_course[10][20];

	int seed;
	cout << "Enter the seed for random number generation: ";
	cin >> seed;
	srand(seed); // this sets the seed of random number generation

	// Randomly assign a course to a student
	for (int i = 0; i < 10; i++) {
		strcpy(stu_course[i],course[rand() % 6]);
		// You can use the following line to check the assigned course
		cout << students[i] << " registers " << stu_course[i] << endl;
	}

	cout << endl;


	// TODO: count the number of registrations for each course
	//	     print the course list in descending order according to the number of registrations
	//       print the registered students' names for each course and students' names should be sorted in ascending alphabetical order.



	return 0;
}
