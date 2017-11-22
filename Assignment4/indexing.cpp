//COMP345 Assignment #3 (Part 1)
//Nicholas Bourbonniere SID 27199600
//Bacisor Claudiu		SID 27735332
//Krasimir Kanev		SID 27848056

#include<fstream>
#include<iostream>
#include<string>
#include"document_indexer.h"
#include"document.h"

using namespace std;

//INDEX_FILE opens index.txt file that contains the names of the documents we want to process;
const string INDEX_FILE = "index.txt";
//STOPWORDS_FILE contains the stopwords.txt file with the stop words;
const string STOPWORDS_FILE = "stopwords.txt";
/*
int main()
{
	try{
	document_indexer idx(INDEX_FILE);

	idx.printMatrix();

	idx.filterStopWords();

	idx.printMatrix();
	}
	catch(document_exception const & e)
	{
		cout<<e<<endl;
	}
	while (true);
	return 0;
}
*/
