#ifndef SENTENCE_H
#define SENTENCE_H

#include"index_item.h"
#include<string>

class sentence : public index_item
{
public:
	sentence();
	sentence(std::string content, std::string name, int position); //Constructor with sentence text, containing document name and char offset in document
	virtual ~sentence();
	const int size() const override; //Size in number of words
	const std::string::size_type getPos() const; //Getter for char offset in document
private:
	size_t pos;
};

#endif
