#include "indexerReal.h"

using namespace std;



//defult constructor that creates an empty document
indexerReal::indexerReal()
{
	indexList;
}


//function that returns the number of documents in the index
int indexerReal::size(){
	return indexList.size();
}


//function that computes the weights
int indexerReal::normalize(){
	//need algorithm here
}



/**
*DEBUG
*/
ostream & operator<<(ostream & os, const indexerReal sw)
{
	os << "TEST";
	return os;
}

