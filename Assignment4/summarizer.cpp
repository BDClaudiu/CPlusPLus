//COMP345 Assignment #3 (Part 3)
//Nicholas Bourbonniere SID 27199600
//Bacisor Claudiu		SID 27735332
//Krasimir Kanev		SID 27848056

#include"sentence_indexer.h"
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

//INDEX_FILE opens index.txt file that contains the names of the documents we want to process;
const string INDEX_FILE = "index.txt";
//TOPIC_FILE opens the file containing the topic required for the essay to be generated
const string TOPIC_FILE = "q3.txt";
/*
int main()
{
	sentence_indexer idx(INDEX_FILE);

	ifstream ifs(TOPIC_FILE);
	string line;
	ostringstream oss;
	while (getline(ifs, line))
		oss << line;
	string topic = oss.str();

	vector<query_result> results = idx.query(topic, 200);
	ostringstream oss2;
	for (vector<query_result>::const_iterator it = results.begin();
		it != results.end();
		++it)
	{
		oss2 << it->getItem()->content() << "\n";
	}
	
	string essay = oss2.str();
	cout << essay;

	while (true);
	return 0;
}
*/