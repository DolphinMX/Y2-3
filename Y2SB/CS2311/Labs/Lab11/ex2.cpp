#include <iostream>
using namespace std;

void f(int *a, int *b){
   int *c;
   c=a;
   *c=*c+10;
   *b=*b+10;
}

int main() {
   int x=3, y=4;
   int *ptr1;
   ptr1=&x;
   f(ptr1, &y);
   cout<< "x=" << x << endl;
   cout<< "y=" << y << endl;
   cout<<"*ptr1=" << *ptr1 << endl;
   return 0;
}
