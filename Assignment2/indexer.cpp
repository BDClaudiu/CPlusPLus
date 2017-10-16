//COMP345 Assignment #1
//Nicholas Bourbonniere SID 27199600
//Bacisor Claudiu		SID 27735332
//Krasimir Kanev		SID 27848056

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
#include<iomanip>



//header files
#include <math.h> 
#include "document.h"
#include "stopword.h"
#include "Tokenizer.h"




using namespace std;

//INDEX_FILE opens index.txt file that contains the names of the documents we want to process;
const string INDEX_FILE = "index.txt";
//STOPWORDS_FILE contains the stopwords.txt file with the stop words;
const string STOPWORDS_FILE = "stopwords.txt";
//Characters that must be removed from the words;
const string DELIMITERS = " .,!?:;()\"";
typedef  map<string, map<string, unsigned int >> nestedMap;

Indexer::Indexer()
{

}


unsigned int getTotalOccurences(const nestedMap& dictionary, string docName)
{
	unsigned int total = 0;
	for (nestedMap::const_iterator it = dictionary.begin();
		it != dictionary.end();
		++it)
	{
		if (it->second.count(docName) == 1)
			total += it->second.at(docName);
	}
	return total;
}

void printDictionaryTable(const nestedMap& dictionary, const vector<string>& indexVector)
{
	//Get largest word for first column width:
	string::size_type maxWordLength = 5; //Length of "Total"

	for (nestedMap::const_iterator it = dictionary.begin();
		it != dictionary.end();
		++it)
	{
		if (it->first.length() > maxWordLength)
			maxWordLength = it->first.length();
	}

	//Build header:
	string header = "+";
	for (unsigned int i = 0; i != maxWordLength + 2; ++i) //2 for extra space in word column
	{
		header += "-";
	}
	header += "+";

	for (unsigned int i = 0; i != indexVector.size(); ++i)
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
	for (unsigned int i = 0; i != indexVector.size(); ++i)
	{
		docHeaderTitle = "Doc" + to_string(i + 1);
		cout << right << setw(8) << docHeaderTitle << "|";
	}
	cout << endl << header << endl;

	//Now iterate through each map entry and print
	for (nestedMap::const_iterator it = dictionary.begin();
		it != dictionary.end();
		++it)
	{
		cout << "| " << setw(maxWordLength) << left << it->first << " |";
		for (unsigned int i = 0; i < indexVector.size(); ++i)
		{
			cout << right << setw(8);
			if (it->second.find(indexVector[i]) == it->second.end()) //Print 0 if word has no occurences in this doc
				cout << "0";
			else
				cout << it->second.at(indexVector[i]); //Otherwise print # of occurences
			cout << "|";
		}
		cout << endl;
	}
	cout << header << endl;

	//Now print totals:
	cout << "| " << setw(maxWordLength) << left << "Total" << " |";
	for (vector<string>::const_iterator it = indexVector.begin();
		it != indexVector.end();
		++it)
	{
		cout << setw(8) << right << getTotalOccurences(dictionary, *it) << "|"; //Assumes column width of 8
	}
	cout << endl << header << endl;
}

void printLegend(const vector<string>& indexVector)
{
	//Get longest document name for column width:
	unsigned int maxNameLength = 0;
	for (unsigned int i = 0; i != indexVector.size(); ++i)
	{
		if (indexVector[i].length() > maxNameLength)
			maxNameLength = indexVector[i].length();
	}

	//Now print the legend top border:
	string border = "+--------+"; //Width = 8 for Doc# entry
	for (unsigned int i = 0; i != maxNameLength + 2; ++i)
		border += "-";
	border += "+";
	cout << border << endl;

	//Legend contents
	string docTitle;
	for (unsigned int i = 0; i != indexVector.size(); ++i)
	{
		docTitle = "Doc" + to_string(i + 1);
		cout << "| " << left << setw(7) << docTitle << "| " << right << setw(maxNameLength) << indexVector[i] << " |" << endl;
	}
	cout << border << endl;
}

void readDocument(nestedMap& dictionary, const string& docName)
{
	ifstream ifs(docName);
	string line;
	vector<string> tokens; //used for storing tokens delimited by punctuation and whitespace

	while (getline(ifs, line))
	{
		size_t pos = 0;
		size_t found = 0;
		do
		{
			found = line.find_first_of(DELIMITERS, pos);
			string word = line.substr(pos, found - pos);
			tokens.push_back(word);
			pos = found + 1;
		} while (found != string::npos);
	}

	for (vector<string>::iterator word = tokens.begin(); word != tokens.end(); word++)
	{
		if (*word == "")
			continue;
		for (string::size_type j = 0; j != word->length(); ++j)
			(*word)[j] = tolower((*word)[j]); //Convert characters to lower case
		dictionary[*word][docName]++; //Initialises a new entry to 0 and increments to 1, or just increments if the entry exists
	}
	ifs.close();
}

int main()
{
	ifstream fin(INDEX_FILE);
	Stopword sw(STOPWORDS_FILE);
	vector<string> indexVector;
	string line;
	string word;

	while (getline(fin, line)) //Get document names to read
		indexVector.push_back(line);

	fin.close();

	nestedMap dictionary; //This is the map which includes all words and their occurences in each file

	//Read in words from each document:
	for (unsigned int i = 0; i != indexVector.size(); ++i)
		readDocument(dictionary, indexVector[i]);

	cout << "Printing table with stopwords..." << endl;
	printDictionaryTable(dictionary, indexVector);
	cout << endl;

	//Now copy the dictionary and remove the stopwords
	nestedMap dictionary2 = dictionary;
	for (unsigned int i = 0; i != stopWordVector.size(); ++i)
		dictionary2.erase(stopWordVector[i]);

	cout << "Printing table without stopwords..." << endl;
	printDictionaryTable(dictionary2, indexVector);

	//Now print legend
	cout << "Legend:" << endl;
	printLegend(indexVector);


	double n = indexVector.size();
	double termFrequency = dictionary["never"][indexVector[0]];
	double docFrequency = dictionary["never"].size();

	cout << n << " " << termFrequency << "  " << docFrequency << endl;



	double weight = (1 + log(termFrequency))*(log(n / docFrequency));


	cout << "this is my weight: " << weight << endl;

	

	return 0;
}