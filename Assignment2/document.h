
#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <iostream>

using namespace std;

class Document
{
public:
	Document(const string docName); //Reads in the content of a document to a string
	string name(); //returns the file name of the document
	unsigned int size(); //returns the size of the file in characters
	string content(); //returns the string containing the content of the file
	friend ostream & operator<<(ostream & os, const Document doc); //For debug

private:
	string documentName; //file name attribute
	string content; //content of the file in string form

};

#endif



