#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <iostream>

using namespace std;

class Document
{
public:
	Document();
	Document(const string docName);
	string name();
	unsigned int size();
	string content();
	friend ostream & operator<<(ostream & os, const Document doc); //For debug
private:
	string name;
	string content;
};

#endif