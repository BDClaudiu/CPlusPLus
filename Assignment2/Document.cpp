

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
	ifstream txtfile(documentName);

	while (txtfile >> word)
	{
		docContent.push_back( word);
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
	return docContent.size();
}

//do we return the content of the vector or the vector itself? so we can use the vector anywhere we need
vector<string> Document::content()

{
	return  docContent;
}



/**
*DEBUG
*/
ostream & operator<<(ostream & os, const Document sw)
{
	os << "TEST";
	return os;
}







