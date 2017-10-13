#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Stopword
{
public:
	/**
	*Constructs an object used to check if given words are stopwords
	*
	*\param fileName is the name of the stopword list file with one stopword per line
	*/
	Stopword(const string fileName)
	{
		ifstream ifs(fileName);
		
		if (!ifs)
		{
			cerr << "Failed to open " << fileName << endl;
			return;
		}

		string line;

		while (getline(ifs, line))
		{
			swList.push_back(line);
		}

		ifs.close();
	}
	/**
	*Checks if the given \a word is a stopword by comparing it to the vector of stopwords
	*
	*\param word will be identified as a stopword or not
	*\return True if the word is a stopword, false otherwise
	*/
	bool operator()(string word)
	{
		for (vector<string>::const_iterator it = swList.begin(); it != swList.end(); ++it)
		{
			if (*it == word)
				return true;
		}
		return false;
	}
	/**
	*DEBUG
	*/
	friend ostream & operator<<(ostream & os, const Stopword sw)
	{
		//EMPTY FOR NOW
	}

private:
	vector<string> swList; //The list of stopwords read from the stopword file
};
