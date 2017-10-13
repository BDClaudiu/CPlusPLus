#include "Tokenizer.h"
#include<vector>




Tokenizer::Tokenizer()
{

}


vector <string> Tokenizer :: readDocument(vector<string> vectorContent)

{
	
	vector<string> tokens; //used for storing tokens delimited by punctuation and whitespace

	for (vector<string>::iterator word = vectorContent.begin(); word != vectorContent.end(); word++)
	{

	while (getline(ifs, line))
	{
		size_t pos = 0;
		size_t found = 0;
		do
		{
			found = line.find_first_of(" .,!?:;()\"", pos);
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




/**
*DEBUG
*/
ostream & operator<<(ostream & os, const Tokenizer sw)
{
	os << "TEST";
	return os;
}