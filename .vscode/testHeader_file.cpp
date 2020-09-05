#include <iostream>
#include "MyMathFunction.cpp"
#include "MyMathFunction.h"

using namespace std;

int main(){
int radius;
cout<< "pls inter int for radius"<<endl;
cin >> radius;
double aCircle = areaOfCircle(radius);
double vSphere = volOfSphere(radius);
cout << aCircle<<endl; 
cout << vSphere << endl;
int sum =0, val =1;
while (val<=10)
 ++val;
 cout << val;
	system("pause");
	return 0;

}
