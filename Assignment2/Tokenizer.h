

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Tokenizer
{
public:
	Tokenizer();
	vector <string> readDocument(vector<string> documentVector);
		friend ostream & operator<<(ostream & os, const Tokenizer tk); //For debug
private:
	vector<string> content;
	string delimiters;
};

#endif