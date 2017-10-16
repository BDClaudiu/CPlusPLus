#include <string>
#include <iostream>
#include "tokenizer.h"

using namespace std;

/**
*Constructs an object used to split words (tokens) out of a string
*
*\param content is the string where the tokens will be taken from
*\param delimiters is a string of chosen delimiters to use,  .,!?:;()" being the default ones
*/
Tokenizer::Tokenizer(string content, string delimiters)
	:content(content), delimiters(delimiters)
{ }

/**
*Check if the \a Tokenizer object has another token to split
*
*\return True is there is another token available, False if not
*/
bool Tokenizer::hasNextToken()
{
	if (peekNextToken() == "")
		return false;
	return true;
}

/**
*Checks the next token in the given \a content without actually removing it
*
*\return the next token in \a content, or an empty string if there is no token
*/
string Tokenizer::peekNextToken()
{
	size_t pos = 0;
	size_t found = content.find_first_of(delimiters, pos);
	while (pos == found) /*while the current character is still a delimiter*/
	{
		++pos;
		found = content.find_first_of(delimiters, pos);
		/*increment and check again*/
	}
	return content.substr(pos, found - pos); /*If the character position has skipped ahead, there must be a token we can split and return*/
}

/**
*Gives the next token and \b removes it from the object's \a content
*
*\return the next token in \a content
*/
string Tokenizer::nextToken()
{
	string token = peekNextToken();
	size_t pos = content.find(token, 0);
	content = content.substr(pos + token.length());
	return token;
}

ostream& operator<<(ostream & os, const Tokenizer tk)
{
	os << "Tokenizer object has the following content to split:" << endl 
		<< content << endl 
		<< "Using the following delimiters: " << delimiters << endl;
	return os;
}
