#ifndef INDEXER_H
#define INDEXER_H

#include "index_item.h"
#include "query_result.h"
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
	virtual void operator>>(index_item* item) = 0;
	index_item* operator[](const int i) const;
	virtual std::vector<query_result> query(std::string q, int n) = 0;
protected:
	std::vector<index_item*> indexList;
	std::map<std::string, std::map<std::string, std::tuple<int, double>>> wordIndex; //HELPER FUNCTIONS TO ACCESS TUPLE ELEMENTS???
};

#endif