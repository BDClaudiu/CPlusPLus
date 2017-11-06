#ifndef INDEXER_H
#define INDEXER_H

#include "index_item.h"
#include<vector>
#include<map>
#include<string>

class indexer
{
public:
	indexer();
	~indexer();
	virtual const int size() const;
	virtual void normalize();
	virtual indexer& operator>>(index_item& item) = 0;
	index_item* operator[](const int i) const;
	//query() too
protected:
	std::vector<index_item*> indexList;
	std::map<std::string, std::map<std::string, std::tuple<int, double>>> wordIndex; //HELPER FUNCTIONS TO ACCESS TUPLE ELEMENTS???
};

#endif