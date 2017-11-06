#include"indexer.h"

indexer::indexer()
{}

indexer::~indexer()
{}

const int indexer::size() const
{
	return indexList.size();
}

void indexer::normalize()
{

}

/*
indexer & indexer::operator>>(index_item & item)
{
	index_item* ptr = &item;
	itemList.push_back(ptr);
}
*/
index_item * indexer::operator[](int i) const
{
	return indexList[i];
}