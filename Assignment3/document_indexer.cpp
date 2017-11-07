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

typedef map<string, map<string, tuple<int, double>>> wordIndexType;

const string SW_FILE = "stopwords.txt";

document_indexer::document_indexer()
{}

document_indexer::~document_indexer()
{
	for (vector<index_item*>::iterator it = indexList.begin();
		it != indexList.end();
		++it)
	{
		delete *it;
	}
}

document_indexer::document_indexer(string indexFile)
{
	ifstream ifs(indexFile);
	string line;
	
	while (getline(ifs, line)) { /*Get document names to read*/
		*this >> new document(line);
	}
}

void document_indexer::normalize()
{
	double N = static_cast<double>(size()); //Total # of documents
	
	for (wordIndexType::iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		double df = static_cast<double>(it->second.size()); //Document Frequency

		for (map<string, tuple<int, double>>::iterator itt = it->second.begin();
			itt != it->second.end();
			++itt)
		{
			double tf = static_cast<double>(get<0>(itt->second)); //Term Frequency

			get<1>(itt->second) = (1 + log(tf))*log(N / df); //Set tf_idf weight
		}
	}

}

void document_indexer::operator>>(index_item* item)
{
	indexList.push_back(item);
	
	word_tokenizer tk(item->content());
	Stopword sw(SW_FILE);
	string word;
	while (tk.hasNextToken())
	{
		word = tk.nextToken();
		for (string::size_type i = 0; i != word.length(); ++i)
			word[i] = tolower(word[i]); //Convert characters to lower case
		++get<0>(wordIndex[tk.nextToken()][item->name()]); //Increment tf
	}

	normalize(); //maybe don't do here, need possibility of exception thrown due to un-normalized indexer
}

vector<query_result> document_indexer::query(string q, int n) //NEEDS EXCEPTION THROWN IF NOT NORMALIZED
{
	double N = size();
	double df;
	word_tokenizer tk(q);
	Stopword sw(SW_FILE);

	map<string, double> termWeight;

	string word;
	while (tk.hasNextToken())
	{
		word = tk.nextToken();
		for (string::size_type i = 0; i != word.length(); ++i)
			word[i] = tolower(word[i]); //Convert characters to lower case
		if (!sw(word) && wordIndex.count(word) == 1) /*Ignore words not contained in the index*/
			++termWeight[word]; //Temporarily use double value to store the term frequency in the query
	}

	for (map<string, double>::iterator it = termWeight.begin();
		it != termWeight.end();
		++it)
	{
		df = wordIndex[it->first].size();
		termWeight[word] = (1 + log(it->second))*log(N / df);
		cout << word << " weight:" << termWeight[word];
	}
	
	//COSINE_SIMILARITY
	vector<query_result> results;
	double num = 0;
	double queryWeightMagnitude = 0;
	double indexWeightMagnitude = 0;
	double indexWeight = 0;
	double score = 0;
	for (int i = 0; i != size(); ++i)
	{
		for (map<string, double>::const_iterator it = termWeight.begin();
			it != termWeight.end();
			++it)
		{
			indexWeight = get<1>(wordIndex[it->first][(*this)[i]->name()]); //CAN CREATE NEW ENTRIES, BUG???
			num += it->second * indexWeight;
			queryWeightMagnitude += pow(it->second, 2);
			indexWeightMagnitude += pow(indexWeight, 2);
		}

		queryWeightMagnitude = sqrt(queryWeightMagnitude);
		indexWeightMagnitude = sqrt(indexWeightMagnitude);

		score = num / queryWeightMagnitude / indexWeightMagnitude;
		results.push_back(query_result((*this)[i], score)); //MIGHT NEED "NEW"
	}

	sort(results.begin(), results.end());
	if(n < results.size())
		results.resize(n);

	return results;
}

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

	string docName;

	//Now iterate through each map entry and print
	for (wordIndexType::const_iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		cout << "| " << setw(maxWordLength) << left << it->first << " |";
		for (unsigned int i = 0; i != size(); ++i)
		{
			docName = (*this)[i]->name();
			if (it->second.find(docName) == it->second.end()) //Print 0 if word has no occurences in this doc
				cout << right << setw(8) << "0  |   0" ;
			else
			{
				cout << left << setw(3) << get<0>(it->second.at(docName)); //Otherwise print # of occurences
				cout << "|";
				cout << right << setw(4) << setprecision(2) << get<1>(it->second.at(docName)); //And weight
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
		docName = (*this)[i]->name();
		total = 0;
		//Get total # words in the doc
		for (wordIndexType::const_iterator it = wordIndex.begin();
			it != wordIndex.end();
			++it)
		{
			if (it->second.count(docName) == 1)
				total += get<0>(it->second.at(docName));
		}
		cout << setw(8) << right << total << "|"; //Assumes column width of 8
	}
	cout << endl << header << endl;
}

void document_indexer::filterStopWords()
{
	Stopword sw(SW_FILE);
	vector<string> swList;

	for (wordIndexType::const_iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		if (sw(it->first))
			swList.push_back(it->first);
	}

	for (vector<string>::iterator it = swList.begin();
		it != swList.end();
		++it)
	{
		wordIndex.erase(*it);
	}
}
