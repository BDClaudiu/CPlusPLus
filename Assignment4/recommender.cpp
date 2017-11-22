//COMP345 Assignment #3 (Part 3)
//Nicholas Bourbonniere SID 27199600
//Bacisor Claudiu		SID 27735332
//David

#include"movie_indexer.h"
#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

//Metadata file
const string METADATA_FILE = "movie_data/movie.metadata.tsv";
//Plot summary file
const string SUMMARY_FILE = "movie_data/plot_summaries.txt";

int main()
{
	movie_indexer idx(METADATA_FILE, SUMMARY_FILE); //Initialize indexer with database files
	
	string userQuery;
	do
	{
		cout << "Please input a query to process:" << endl;
		getline(cin, userQuery);
		if (userQuery == "\0")
			return 0;
		vector<query_result> results = idx.query(userQuery);

	} while (true);
}