
#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>

using namespace std;

class Stopword
{
public:
	Stopword();
	Stopword(string fileName);
	bool operator()(string word);
private:
	vector<string> swList;
	string filename;
	vector<string> readstopword;
};


#endif