#include <iostream>
#include <math.h>
//#include <sys/time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// short integer random number generator from stdlib
int rand(void); 

int main()
{ 
  int size=1000;
  //cout << endl << "How many elements in the input array ";  cin >> size;


  for(int i=0; i<size; i++)
    {

      //generate ID
      for(int j=0; j<=7; j++)
	cout<<rand()%10;

      cout<<" ";

      //generate major
      int major=rand()%6;
      switch (major) {
      case 0:
	cout<<"CDE";
	break;
      case 1:
	cout<<"CS";
	break;
      case 2:
	cout<<"INF";
	  break;
      case 3:
	cout<<"BMS";
	break;
      case 4:
	cout<<"MNE";
	break;
      case 5:
	cout<<"CHM";
	break;
   
      }


      cout<<" ";

      //generate gpa
      int gpa=40+rand()%55;
      float score = (float)(rand()%100)/100;
      printf("%.2f",gpa+score);

      cout<<" ";

      //generate admission type
      int credit=rand()%10;
      switch (credit){
	//case <= 7:
	//cout<<"direct";
	//break;
      case 8:
	cout<<"ASI";
	break;
      case 9:
	cout<<"ASII";
	break;
      default:
	cout<<"4-year";
      }
      cout<<" ";

      //admission year
      int year = 2017+(int)rand()%5;
      cout<<year<<endl;
      
    }
}


