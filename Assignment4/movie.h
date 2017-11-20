#ifndef MOVIE_H
#define MOVIE_H


#include<regex>
#include<iostream>
#include<fstream>
#include<string>
#include "index_item.h"
#include "index_exception.h"
#include "document_exception.h"
#include "movie_exception.h"
#include "sentence_exception.h"
#include "query_exception.h"

class movie : index_item
{
public:
	movie();
	movie(std::string movieName);

	std::string getName();
	std::string getContent();
	int getReleaseDate();
	int getID();
	void query(std::string movie) ;
	const int size() const;
private:
	std::string movieName;
	std::string content;
	int movieID;
	// i believe should be changed to string to represent the yyyy-mm-dd
	int releaseYear;
	std::string lineContent;

};

#endif
