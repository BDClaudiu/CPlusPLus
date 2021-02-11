#ifndef INDEXERREAL_H
#define INDEXERREAL_H

#include <string>
#include <vector>
#include "document.h"

using namespace std;

class indexerReal
{
public: 
		indexerReal();
		indexerReal(string indexFile);
		int size();
		int normalize();
		map<string, int> query();
		friend std::ostream & operator<<(std::ostream & os, const indexerReal sw); //For debug
		friend void operator>>(indexerReal idx, Document doc);
private:
		vector<Document> indexList;
		map<string, int>queryresult;

};



#endif