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
	int getID();
	std::vector<int> fullMovieList();
	const int size() const;
private:
	std::string movieName;
	std::string contentOfMovie;
	std::string releaseDateMovie;
	int movieID;
	std::string lineContent;
	std::vector<int> movieNameList;

	void setSummary(std::string summary);
};

#endif
