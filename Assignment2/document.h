
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



class Document
{
public:
	//defult constructor
	Document();

	//constructor that takes a txt file name and stores its contents into a vector
	Document(string docName);

	//returns the txt file name that is used by the 2nd constructor
	string name();

	//returns the size of the vector belonging to the 2nd constructor
	unsigned int size();


	//retuns a vector (not vector content) that is used in the 2nd constructor
	vector<string> content();

	friend ostream & operator<<(ostream & os, const Document doc); //For debug


private:
	
	string word;
	//string that contains the txt doc name;
	string documentName;
	//vector that stores a txt file content
	vector <string> docContent;

};

#endif



