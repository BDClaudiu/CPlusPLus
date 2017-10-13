#ifndef INDEXERREAL_H
#define INDEXERREAL_H

#include <string>
#include <vector>

using namespace std;

class indexerReal
{
public:indexerReal();
	   int size();
	   int normalize();
	   friend std::ostream & operator<<(std::ostream & os, const indexerReal sw); //For debug

private:
	vector<string> indexList;

};






























#endif