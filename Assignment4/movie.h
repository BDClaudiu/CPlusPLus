#ifndef MOVIE_H
#define MOVIE_H


#include "movie_exception.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"word_tokenizer.h"
#include "index_item.h"

class movie : public index_item
{
public:
	movie();
	movie(int movieID, std::string movieName, std::string releaseDateMovie);

	std::string getName();
	std::string getContent();
	std::string getReleaseDate();
	long getID();
	std::vector<long> fullMovieList();
	const int size() const;
private:
	std::string movieName;
	std::string contentOfMovie;
	std::string releaseDateMovie;
	long longmovieID;
	std::string lineContent;
	std::vector<long> movieNameList;

	void setSummary(std::string summary);
};

#endif
