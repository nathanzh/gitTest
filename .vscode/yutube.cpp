#include <iostream>
#include <string>
using namespace std;

class MyBase {
    int _i;
public:
MyBase(int i): _i(i){}
	
	void p (){cout << _i;}
};
class MyDerived:  public MyBase{
    float _f;
public:
	MyDerived(float f, int i)
    : _f(f), MyBase(i)
    {
	
	}
    void printfload (){ cout << _f;}
	
};



int main()
{

    MyDerived d(1.111111111f,2 );
    d.p();
    d.printfload();

	string y;
	getline (cin,y); 
    system("pasue");
	return 0;
	
	
}