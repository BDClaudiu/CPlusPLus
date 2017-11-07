#include"sentence_indexer.h"
#include<fstream>
#include<iostream>

using namespace std;

//INDEX_FILE opens index.txt file that contains the names of the documents we want to process;
const string INDEX_FILE = "index.txt";

int main()
{
	sentence_indexer idx(INDEX_FILE);
	
	return 0;
}