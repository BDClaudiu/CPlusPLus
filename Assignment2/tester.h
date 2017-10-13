
#pragma once
#ifndef  Tester_H
#define Tester_H

class Tester {

public:
	Tester();
	Tester(int a, int b);
	
	void testFunction();
	void print();

	Tester(int d, int m, int y);

	void displayBirth();
protected:

private:


	int regVar;
	int constvar;
	int total;


	//for the tester (int m, int d, int y)
	int day;
	int month;
	int year;


};







#endif //  Tokenizer_H

