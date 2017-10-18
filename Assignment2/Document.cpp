

#include "document.h"
#include "tokenizer.h"

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

//defult constructor that creates an empty document
Document::Document()
	:documentName(""), content("")
{

}

//constructor that accepts a file name and reads the files into the document object
Document::Document(string fname)
	:documentName(fname)
{
	ifstream txtfile(documentName);
	string line;

	while (getline(txtfile, line))
	{
		content.append(line);
	}

	Tokenizer tk(content);

	while (tk.hasNextToken())
	{
		string token = tk.nextToken();
		for (string::iterator it = token.begin(); it != token.end(); ++it)
			*it = tolower(*it); //Convert characters to lower case
		dictionary[token]++;
	}

	txtfile.close();
}

//printing the document name
string Document::name()

{


	return documentName;


}


//gets the size of the string where we stored the content of the txt file
unsigned int Document::size()

{
	return content.size();
}

//do we return the content of the vector or the vector itself? so we can use the vector anywhere we need
string Document::getContent()

{
	return content;
}

map<string, int> Document::mapContent()
{	//delete the cout later, just for testing the size of the dictionaryMap
	cout<<dictionary.size();



	return dictionary;
}

/**
*DEBUG
*/
ostream & operator<<(ostream & os, Document doc)
{
	os << doc.documentName << endl
		<< doc.size() << endl
		<< doc.content << endl;
	return os;
}







