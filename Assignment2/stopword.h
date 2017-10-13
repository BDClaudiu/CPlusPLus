#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Stopword
{
public:
	Stopword();
	Stopword(const string fileName);
	bool operator()(string word);
	friend ostream & operator<<(ostream & os, const Stopword sw); //For debug
private:
	Vector<string> swList;
};

#endif