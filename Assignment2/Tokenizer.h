#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <iostream>

/*
The design of this class can definitely change, but for now I have based it on the StringTokenizer class in Java
C++ already has something similar in stringstream, so this should be used in the functions of this class instead of the old code used for splitting tokens
We can replace the old code with stringstreams later on
*/
class Tokenizer
{
public:
	Tokenizer(std::string content); //Creates a tokenizer with the content of a file from Document class, so that we can split the tokens in this file
	Tokenizer(std::string content, std::string delimiters = " .,!?:;()\""); //Same as above, but using specified delimiters
	bool hasNextToken(); //Checks if there is another token to split in the string
	std::string nextToken(); //returns the next token and removes it from the content of the Document
	friend std::ostream & operator<<(std::ostream & os, const Tokenizer tk); //For debug
private:
	std::string content; //the content of the file being worked on
	std::string delimiters; //delimiters (default or chosen with constructor)
};

#endif