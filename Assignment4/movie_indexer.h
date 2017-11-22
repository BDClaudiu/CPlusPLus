#ifndef MOVIE_INDEXER_H
#define MOVIE_INDEXER_H

#include"indexer.h"
#include"movie.h"
#include"movie_exception.h"

class movie_indexer : public indexer
{
public:
	movie_indexer();
	~movie_indexer();
	movie_indexer(std::string metaFile, std::string summaryFile); //Creates an indexed set of movies from the files in indexFile
	std::vector<query_result> query(std::string q, int n = 5) const override; //Queries for the most relevant movies up to n words, sorted
};
#endif