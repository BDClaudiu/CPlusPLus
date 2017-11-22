#include "document.h"
#include "word_tokenizer.h"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

/**
	Default Constructor
*/
document::document()
	:index_item()
{}

/**
	Default constructor that takes in a new document.txt @param name
*/
document::document(string name)
	:index_item(name)
{
	ifstream ifs(name); /*Open the document to read in the content*/
	string line;
	ostringstream oss;
	while (getline(ifs, line)) /*Get lines of text from the document*/
		oss << line;
	setContent(oss.str());
	ifs.close();
}

/**
	Default destructor
*/
document::~document()
{}

/**
	Returns the size of a document (in chars)
*/
const int document::size() const
{
	return content().length();
}

