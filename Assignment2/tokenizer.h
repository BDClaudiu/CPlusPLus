#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <iostream>

class Tokenizer
{
public:
	Tokenizer(std::string content, std::string delimiters = " .,!?:;()\""); //Initializes a Tokenizer object that can split strings from the given content using the given delimiters
	bool hasNextToken(); //Checks if there is another token to split in the string
	std::string peekNextToken(); //returns the next token without removing it from the content
	std::string nextToken(); //returns the next token and removes it from the content of the Document
	friend std::ostream & operator<<(std::ostream & os, const Tokenizer tk); //For debug
private:
	std::string content; //the content of the file being worked on
	std::string delimiters; //delimiters (default or chosen with constructor)
};

#endif