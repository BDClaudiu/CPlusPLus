#include "indexerReal.h"
#include "document.h"
#include"indexerReal.h"



#include<map>
#include<vector>

using namespace std;

//defult constructor that creates an empty document
indexerReal::indexerReal()
	:indexList()
{
	indexList;
}

indexerReal::indexerReal(string indexFile)

{
	string line;
	ifstream ifs(indexFile);
	
	Document doc(indexFile);
	while (getline(ifs, line))
	{
		indexList.push_back(doc);
	}
	ifs.close();
}

//function that returns the number of documents in the index
int indexerReal::size(){


	return indexList.size();
}


//function that computes the weights
int indexerReal::normalize(){
	//need algorithm here
	return 0;
}

map<string, int> indexerReal::query() {
	return queryresult;
}

void operator>>(indexerReal  idx, Document doc)
{
	idx.indexList.push_back(doc);
}

/**
*DEBUG
*/
ostream & operator<<(ostream & os, const indexerReal sw)
{
	os << "TEST";
	return os;
}

