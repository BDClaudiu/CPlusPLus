#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <iostream>

using namespace std;

/*
The design of this class can definitely change, but for now I have based it on the StringTokenizer class in Java
C++ already has something similar in stringstream, so this should be used in the functions of this class instead of the old code used for splitting tokens
We can replace the old code with stringstreams later on
*/
class Tokenizer
{
public:
	Tokenizer();
	Tokenizer(string content); //Creates a tokenizer with the content of a file from Document class, so that we can split the tokens in this file
	Tokenizer(string content, string delimiters); //Same as above, but using specified delimiters
	bool hasNextToken(); //Checks if there is another token to split in the string
	string nextToken(); //returns the next token and removes it from the content of the Document
	friend ostream & operator<<(ostream & os, const Tokenizer tk); //For debug
private:
	string content; //the content of the file being worked on
	string delimiters; //delimiters (default or chosen with constructor)
};

#endif