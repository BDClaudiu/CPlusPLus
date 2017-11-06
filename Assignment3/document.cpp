#include "document.h"
#include "word_tokenizer.h"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

//DO NOT TOUCH

document::document()
	:index_item()
{}

document::document(std::string name)
	:index_item(name)
{
	ifstream ifs(name);
	string line;
	ostringstream oss;
	while (getline(ifs, line)) /*Get lines of text from the document*/
		oss << line;
	setContent(oss.str());
}

document::~document()
{}

const int document::size() const
{
	return content().length();
}

