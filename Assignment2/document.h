#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

using namespace std;

class Document
{
public:
	Document();
	Document(string docName);
	string name();
	unsigned int size();
	string content();
private:
	string name;
	string content;
};

#endif