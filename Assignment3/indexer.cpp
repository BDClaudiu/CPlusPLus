#include"indexer.h"
#include<map>

using namespace std;

typedef map<string, map<string, tuple<int, double>>> wordIndexType;

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
	double N = static_cast<double>(size()); //Total # of documents

	for (wordIndexType::iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		double df = static_cast<double>(it->second.size()); //Document Frequency

		for (map<string, tuple<int, double>>::iterator itt = it->second.begin();
			itt != it->second.end();
			++itt)
		{
			double tf = static_cast<double>(get<0>(itt->second)); //Term Frequency

			get<1>(itt->second) = (1 + log(tf))*log(N / df); //Set tf_idf weight
		}
	}
}

index_item * indexer::operator[](int i) const
{
	return indexList[i];
}