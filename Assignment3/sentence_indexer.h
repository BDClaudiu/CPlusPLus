#ifndef SENTENCE_INDEXER_H
#define SENTENCE_INDEXER_H

#include "indexer.h"
#include<vector>

class sentence_indexer: public indexer
{
public:
	sentence_indexer();
	~sentence_indexer();
	sentence_indexer(std::string indexFile);
	void operator>>(index_item * item) override;
	//query() too
private:

};

#endif
