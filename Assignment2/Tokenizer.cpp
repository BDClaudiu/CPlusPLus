#include <string>
#include <iostream>
#include "tokenizer.h"

using namespace std;

Tokenizer::Tokenizer(string content)
	:content(content)
{ }

Tokenizer::Tokenizer(string content, string delimiters)
	:content(content), delimiters(delimiters)
{ }

bool Tokenizer::hasNextToken()
{
	return true; //NOT YET IMPLEMENTED
}

string Tokenizer::nextToken()
{
	string token;
	do
	{
		size_t end = 0;
		end = content.find_first_of(delimiters, 0);
		token = content.substr(0, end);
		content = content.substr(end + 1);
	} while (token == "");
	return token;
}

ostream & operator<<(ostream & os, const Tokenizer tk)
{
	os << "Test";
	return os;
}
