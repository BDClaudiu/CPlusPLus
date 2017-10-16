#ifndef INDEXERREAL_H
#define INDEXERREAL_H

#include <string>
#include <vector>
#include "document.h"

using namespace std;

class indexerReal
{
public:
	indexerReal(string indexFile);
	int size();
	int normalize();
	friend void operator>>(Indexer idx, Document doc);
	friend std::ostream & operator<<(std::ostream & os, const indexerReal sw); //For debug

private:
	vector<Document> indexVector;

};






























#endif