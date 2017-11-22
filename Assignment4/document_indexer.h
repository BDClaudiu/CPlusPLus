#ifndef DOCUMENT_INDEXER_H
#define DOCUMENT_INDEXER_H

#include"indexer.h"
#include<vector>

class document_indexer : public indexer
{
public:
	document_indexer();
	~document_indexer();
	document_indexer(std::string indexFile); //Creates an indexer using the files in indexFile
	std::vector<query_result> query(std::string q, int n = 10) const override; //Queries for most relevant documents
	void printMatrix() const; //Prints the matrix with tf and tf-idf
	void filterStopWords(); //Filters out stopwords
};

#endif
