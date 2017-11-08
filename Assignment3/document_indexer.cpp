#include"document.h"
#include"document_indexer.h"
#include"word_tokenizer.h"
#include"index_item.h"
#include"stopword.h"
#include"query_result.h"
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>

using namespace std;

typedef map<string, map<index_item*, tuple<int, double>>> wordIndexType;

const string SW_FILE = "stopwords.txt";

/**
	Default Constructor
*/
document_indexer::document_indexer()
{}

/**
	Destructor
*/
document_indexer::~document_indexer()
{}

/**
	Constructor that accepts a new index.txt @param indexFile
*/
document_indexer::document_indexer(string indexFile)
{
	ifstream ifs(indexFile);
	string line;
	
	while (getline(ifs, line)) { /*Get document names to read*/
		*this >> new document(line);
	}
}

/**
	Function that queries the indexer with a string @param q for @param n results
*/
vector<query_result> document_indexer::query(string q, int n) const
{
	
	map<string, double> termWeight = getNormalizedQuery(q); //Get the normalized query vector

	vector<query_result> results = cosineSimilarity(termWeight); //Compare it to all indexed documents and get the results

	sort(results.begin(), results.end(), operator>);
	if(n < results.size()) /*Sort and resize as needed*/
		results.resize(n);

	return results;
}

/**
	Function that displays the document matrix
*/
void document_indexer::printMatrix() const
{
	//Get largest word for first column width:
	string::size_type maxWordLength = 5; //Length of "Total"

	for (wordIndexType::const_iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		if (it->first.length() > maxWordLength)
			maxWordLength = it->first.length();
	}

	//Build header:
	string header = "+";
	for (unsigned int i = 0; i != maxWordLength + 2; ++i) //+ 2 for extra space in word column
	{
		header += "-";
	}
	header += "+";

	for (unsigned int i = 0; i != size(); ++i)
	{
		header += "--------+"; //column width = 8
	}

	//Now print the table
	cout << header << endl << "| ";
	for (unsigned int i = 0; i != maxWordLength; ++i)
	{
		cout << " ";
	}
	cout << " |";

	string docHeaderTitle;
	for (unsigned int i = 0; i != size(); ++i)
	{
		docHeaderTitle = "Doc" + to_string(i + 1);
		cout << right << setw(8) << docHeaderTitle << "|";
	}
	cout << endl << header << endl;

	index_item* doc;

	//Now iterate through each map entry and print
	for (wordIndexType::const_iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		cout << "| " << setw(maxWordLength) << left << it->first << " |";
		for (unsigned int i = 0; i != size(); ++i)
		{
			doc = (*this)[i];
			if (it->second.find(doc) == it->second.end()) //Print 0 if word has no occurences in this doc
				cout << right << setw(8) << "0  |   0" ;
			else
			{
				cout << left << setw(3) << get<0>(it->second.at(doc)); //Otherwise print # of occurences
				cout << "|";
				cout << right << setw(4) << setprecision(2) << get<1>(it->second.at(doc)); //And if-idf weight
			}
			
			cout << "|";
		}
		cout << endl;
	}
	cout << header << endl;

	//Now print totals:
	unsigned int total;
	cout << "| " << setw(maxWordLength) << left << "Total" << " |";
	for (unsigned int i = 0; i != size(); ++i)
	{
		index_item* doc = (*this)[i];
		total = 0;
		//Get total # words in the doc
		for (wordIndexType::const_iterator it = wordIndex.begin();
			it != wordIndex.end();
			++it)
		{
			if (it->second.count(doc) == 1)
				total += get<0>(it->second.at(doc));
		}
		cout << setw(8) << right << total << "|"; //Assumes column width of 8
	}
	cout << endl << header << endl;
}

/**
	Function that removes the stop words from the indexer
*/
void document_indexer::filterStopWords()
{
	Stopword sw(SW_FILE);
	vector<string> swList;

	for (wordIndexType::const_iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		if (sw(it->first))
			swList.push_back(it->first); /*Get list of stopwords in the wordIndex*/
	}

	for (vector<string>::iterator it = swList.begin();
		it != swList.end();
		++it)
	{
		wordIndex.erase(*it); /*Then remove them one by one*/
	}
}
