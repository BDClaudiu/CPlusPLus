#include "sentence.h"
#include "word_tokenizer.h"
#include<string>

using namespace std;

/**
	Default Constructor
*/
sentence::sentence()
	:index_item()
{}

/**
	Default Constructor that takes in a string content, string name and int position as its parameters @param content @param name @param position
*/
sentence::sentence(string content, string name, int position)
	: index_item(name), pos(position)
{
	setContent(content);
}

/**
	Default destructor
*/
sentence::~sentence()
{}

/**
	Function that returns the size of a sentence as int
*/
const int sentence::size() const
{
	word_tokenizer tk(content()); /*Instantiate a word tokenizer with the sentence's content*/
	int size = 0;
	while (tk.hasNextToken())
	{
		++size;
		tk.nextToken();
	}
	return size; /*size == number of tokens*/
}

/**
Function that returns the position within the document
*/
const size_t sentence::getPos() const
{
	return pos;
}
