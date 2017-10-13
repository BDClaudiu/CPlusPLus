#include "claudiu.h"
#include <iostream>
#include "tester.h"
#include <string>
using namespace std;


Claudiu::Claudiu(string namee,Tester obj) 


	:name(namee),birthObj(obj)

{
	cout << "My name is: " << name << " and i was born on: ";
	birthObj.displayBirth();
	cout << endl;
}

void Claudiu::showBday() 

{
	cout << "My name is: " << name << " and i was born on: ";
	birthObj.displayBirth();
	cout << endl;

}










