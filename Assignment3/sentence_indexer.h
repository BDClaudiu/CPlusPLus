/*
#ifndef SENTENCE_INDEXER_H
#define SENTENCE_INDEXER_H

#include "indexer.h"
#include<vector>
#include<map>
#include<string>

class sentence_indexer: public indexer
{
public:
	sentence_indexer();
	~sentence_indexer();
	void normalize() override;
	indexer& operator>>(index_item& item) override; //Will add to nested map for doc_indexer
	//query() too
private:

};

#endif
*/
