#ifndef SENTENCE_INDEXER_H
#define SENTENCE_INDEXER_H

#include "indexer.h"
#include<vector>

class sentence_indexer: public indexer
{
public:
	sentence_indexer();
	~sentence_indexer();
	sentence_indexer(std::string indexFile); //Creates an indexed set of sentences from the files in indexFile
	std::vector<query_result> query(std::string q, int n = 500) const override; //Queries for the most relevant sentences up to n words, sorted
	friend const bool sortByDoc(query_result left, query_result right); //Used to sort the results
	friend const bool sortByPos(query_result& left, query_result& right); //Used to sort the results
};

#endif
