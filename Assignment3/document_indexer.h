#ifndef DOCUMENT_INDEXER_H
#define DOCUMENT_INDEXER_H

#include"indexer.h"

class document_indexer : public indexer
{
public:
	document_indexer();
	~document_indexer();
	document_indexer(string indexFile);
	void normalize() override;
	indexer& operator>>(index_item& item) override;
	void printMatrix() const;
};

#endif
