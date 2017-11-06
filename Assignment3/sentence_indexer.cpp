#include "sentence_indexer.h"

using namespace std;

sentence_indexer::sentence_indexer()
{}

sentence_indexer::~sentence_indexer()
{}

void sentence_indexer::normalize()
{
	for(vector<index_item*>::iterator i = itemList.begin(); )
}

indexer & sentence_indexer::operator>>(index_item & item)
{
	addToList(item);
}
