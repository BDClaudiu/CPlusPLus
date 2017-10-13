

#include "document.h"

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
#include<iomanip>
#include <math.h> 

typedef  map<string, map<string, unsigned int >> nestedMap;
using namespace std;
const string DELIMITERS = " .,!?:;()\"";
//defult constructor that creates an empty document
Document::Document() 
{
	ofstream d("Document.txt");
	d << "";
	d.close();
}

//constructor that accepts a file name and reads the files into the document object
Document::Document(string fname)

	:documentName(fname)
{


	ifstream ifs(documentName);
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



	 //Initialises a new entry to 0 and increments to 1, or just increments if the entry exists
	//	dictionary[*word][documentName]++;

	//  !!! need to remove the map and store the words in a string !!!
	// content<<words go here!!
	}
	ifs.close();



	
}

//printing the document name
string Document::namee()

{	
	return documentName;

}


//gets the size of the string where we stored the content of the txt file
unsigned int Document::size() 

{

	 return content.size();

}

//gets the content of the string where we stored the txt file
string Document::contentt()

{
	return  content;
}



//ignore this , i just used it as reference
void Document :: readDocument(nestedMap& dictionary, const string documentName)

{
	ifstream ifs(documentName);
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
		dictionary[*word][documentName]++; //Initialises a new entry to 0 and increments to 1, or just increments if the entry exists
	}
	ifs.close();
}






