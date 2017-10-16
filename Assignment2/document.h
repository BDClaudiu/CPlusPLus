
#ifndef DOCUMENT_H
#define DOCUMENT_H

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

	//returns the text of the document
	string getContent();

	//retuns a vector (not vector content) that is used in the 2nd constructor
	map<string, int> mapContent();

	friend ostream & operator<<(ostream & os, const Document doc); //For debug


private:
	
	string word;
	//string that contains the txt doc name;
	string documentName;
	//string that stores a txt file content
	string content;
	//map storing words and their occurences
	map<string, int> dictionary;
	//map storing the weight of each word in the document
	map<string, double> weightMap;


};

#endif



