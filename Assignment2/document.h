
#ifndef DOCUMENT_H
#define DOCUMENT_H




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


using namespace std;

//remove this at a later date
typedef  map<string, map<string, unsigned int >> nestedMap;

class Document
{
public:
	Document();
	Document(string docName);
	string namee();

	unsigned int size();
	string contentt();
private:
	string name;
	string content;
	string documentName;

	//remove this on a later date, i just added to make the function work 
	void readDocument(nestedMap& dic, const string documentName);
	

};

#endif



