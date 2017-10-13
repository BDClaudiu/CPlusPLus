
#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Stopword
{
public:
	Stopword(const string fileName); //Constructor that takes a filename to read stopwords from and store in the vector
	bool operator()(string word); //Pass a word to check if it is a stopword
	friend ostream & operator<<(ostream & os, const Stopword sw); //For debug

private:
	vector<string> readstopword; //The list of stopwords read from the stopword file
};


#endif