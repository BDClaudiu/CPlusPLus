#ifndef DOCUMENT_INDEXER_H
#define DOCUMENT_INDEXER_H

#include"indexer.h"

class document_indexer : public indexer
{
public:
	document_indexer();
	~document_indexer();
	document_indexer(std::string indexFile);
	void normalize() override;
	void operator>>(index_item* item) override;
	std::vector<query_result> query(std::string q, int n = 10) override;
	void printMatrix() const;
	void filterStopWords();
};

#endif
