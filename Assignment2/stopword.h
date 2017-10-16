
#ifndef STOPWORD_H
#define STOPWORD_H

#include <string>
#include <vector>
#include <iostream>

class Stopword
{
public:
	Stopword(const std::string fileName); //Constructor that takes a filename to read stopwords from and store in the vector
	bool operator()(std::string word); //Pass a word to check if it is a stopword
	friend std::ostream & operator<<(std::ostream & os, const Stopword sw); //For debug

private:
	std::vector<std::string> swList; //The list of stopwords read from the stopword file
};


#endif