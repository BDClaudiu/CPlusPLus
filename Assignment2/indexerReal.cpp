#include "indexerReal.h"
#include "document.h"

using namespace std;



//defult constructor that creates an empty document
indexerReal::indexerReal(string indexFile)
{
	ifstream ifs(indexFile);
	string line;
	while (getline(ifs, line))
	{
		indexVector.push_back(Document doc(line));
		
	}
	ifs.close();
}


//function that returns the number of documents in the index
int indexerReal::size(){
	return indexVector.size();
}


//function that computes the weights
void indexerReal::normalize()
{
	
}

void operator>>(Indexer idx, Document doc)
{
	idx->indexVector.push_back(doc);
}



/**
*DEBUG
*/
ostream & operator<<(ostream & os, const indexerReal idx)
{
	os << "TEST";
	return os;
}

