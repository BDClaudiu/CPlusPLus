
#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>

using namespace std;

class Stopword
{
public:
	Stopword();
	Stopword(string fileName); //Constructor that takes a filename to read stopwords from and store in the vector
	bool operator()(string word); //Pass a word to check if it is a stopword
//	friend std::ostream & operator<<(std::ostream & os, const Stopword sw); //For debug
private:
	vector<string> swList; //The list of stopwords read from the stopword file
	string filename;
	string line;
	
};


#endif