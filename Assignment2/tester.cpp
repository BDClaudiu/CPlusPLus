#include "tester.h"
#include <iostream>
using namespace std;

Tester::Tester() {

}

Tester::Tester(int a, int b)

	:regVar(a), constvar(b)

{
	total = regVar + constvar;
	
}

Tester::Tester(int d, int m, int y)

	:day(d), month(m),year(y)

{
	
}


void Tester::displayBirth()
{
	cout << day << "/" << month << "/" << year << endl;
}




void Tester::testFunction()
{
	cout << "this is a test" << endl;
}


void Tester::print() {
	cout << "regular var is: " << regVar << " const var is: " << constvar << endl;
	cout << "total is "<<total<<endl;

}