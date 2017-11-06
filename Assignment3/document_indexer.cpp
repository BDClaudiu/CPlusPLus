#include"document.h"
#include"document_indexer.h"
#include"word_tokenizer.h"
#include"index_item.h"
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

typedef map<string, map<string, tuple<int, double>>> wordIndexType;

document_indexer::document_indexer()
{}

document_indexer::~document_indexer()
{}

document_indexer::document_indexer(string indexFile)
{
	ifstream ifs(indexFile);
	string line;

	while (getline(ifs, line)) /*Get document names to read*/
		*this >> document(line);
}

void document_indexer::normalize()
{
	float N = size(); //Total # of documents
	
	for (wordIndexType::iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		float df = it->second.size(); //Document Frequency

		for (map<string, tuple<int, double>>::iterator itt = it->second.begin();
			itt != it->second.end();
			++itt)
		{
			float tf = get<0>(itt->second); //Term Frequency

			get<1>(itt->second) = (1 + log(tf))*log(N / df); //Set tf_idf weight
		}
	}

}

indexer & document_indexer::operator>>(index_item & item)
{
	indexList.push_back(&item);
	
	word_tokenizer tk(item.content());
	while (tk.hasNextToken())
		++get<0>(wordIndex[tk.nextToken()][item.name()]); //Increment tf

	normalize(); //Compute tf-idf weights
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
	string tuple;

	//Now iterate through each map entry and print
	for (wordIndexType::const_iterator it = wordIndex.begin();
		it != wordIndex.end();
		++it)
	{
		cout << "| " << setw(maxWordLength) << left << it->first << " |";
		for (unsigned int i = 0; i != size(); ++i)
		{
			docName = (*this)[i]->name();
			cout << right << setw(8);
			if (it->second.find(docName) == it->second.end()) //Print 0 if word has no occurences in this doc
				cout << "0";
			else
			{
				tuple = get<0>(it->second.at(docName)); //Otherwise print # of occurences
				tuple += " / ";
				tuple += get<1>(it->second.at(docName)); //And weight
				cout << tuple;
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
