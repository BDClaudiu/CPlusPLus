

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
 #include <iostream>

using namespace std;

class Tokenizer
 {
	public:
		Tokenizer();
		Tokenizer(string content);
		Tokenizer(string content, string delimiters);
		bool hasNextToken();
		string nextToken();
	//	friend ostream & operator<<(ostream & os, const Tokenizer tk); //For debug
		private:
			string content;
			string delimiters;
			};

#endif