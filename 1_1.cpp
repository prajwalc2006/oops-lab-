#include <iostream>
using namespace std;
void SwapRef(int & a, int & b) { int t = a; a = b; b = t; }
void SwapPto (int* a, int* b) { int t = *a; *a = *b; *b = t; }
int main(){
int x = 10 , y = 20;
SwapRef(x,y);
cout << "After swap Ref: x = " << x << " y = " << y << endl;
SwapPto(&x, &y);
cout << "After swap ptr: x = " << x << " y = " << y << endl;
int & alias= x;
cout<<"x via alias= "<< x << endl;
return 0;
}