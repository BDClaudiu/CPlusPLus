#ifndef MOVIE_H
#define MOVIE_H


#include<regex>
#include<iostream>
#include<fstream>
#include<string>


class movie
{
public:
	movie();
	movie(std::string movieName);

	std::string getName();
	std::string getContent();
	int getReleaseDate();
	int getID();

private:
	std::string movieName;
	std::string content;
	int releaseYear;
	int movieID;
	std::string lineContent;
};

#endif
