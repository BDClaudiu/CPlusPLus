#include "movie_indexer.h"
#include"index_item.h"
#include"indexer.h"
#include<algorithm>
#include<sstream>

const std::string SW_FILE = "stopwords.txt";

using namespace std;


/**
	Default constructor
*/
movie_indexer::movie_indexer(){};

/**
	Default destructor
*/
movie_indexer::~movie_indexer(){};

/**
	Constructor that creates a new indexer from movie meta then gets plot info from plot
	@param movieMeta
	@param plot
*/
movie_indexer::movie_indexer(string metaFile, string summaryFile)
{
	ifstream ifs(metaFile);
	string line, name, date, summary, id_string;
	int id = 0;
	map<int, index_item*> idPointerMap;

	while (getline(ifs, line))
	{
		
		stringstream linestream(line);
		//ID
		getline(linestream, id_string, '\t');
		id = stoi(id_string);
		//Freebase ID (temporarily stored in name, but overwritten)
		getline(linestream, name, '\t');
		//Movie name
		getline(linestream, name, '\t');
		//Movie date
		getline(linestream, date, '\t');

		index_item* obj = new movie(id, name, date);
		indexList.push_back(obj);
		idPointerMap[id] = obj;

	}
	
	cout << "Metafile read complete" << endl;

	ifs.close();
	ifstream sumfs(summaryFile);

	while (getline(sumfs, line))
	{
		stringstream linestream(line);
		//ID
		getline(linestream, id_string, '\t');
		id = stoi(id_string);
		//Summary
		getline(linestream, summary);

		idPointerMap[id]->setContent(summary);
		word_tokenizer tk(idPointerMap[id]->content());
		string word;
		while (tk.hasNextToken()) /*Add words from summary to wordIndex*/
		{
			word = tk.nextToken();
			cout << word << endl;
			for (string::size_type i = 0; i != word.length(); ++i)
				word[i] = tolower(word[i]); //Convert characters to lower case
			++get<0>(wordIndex[word][idPointerMap[id]]); //Increment tf
		}
	}

	cout << "Summaryfile read and wordIndex instantiation complete" << endl;

	sumfs.close();
	normalize();
	cout << "Normalization complete" << endl;
};

/*undefined
 *
 */
vector<query_result> movie_indexer::query(string q, int n) const
{
	index_item* movieQuery = *(indexList.begin());
	for (vector<index_item*>::const_iterator it = indexList.begin();
		it != indexList.end();
		++it)
	{
		if ((*it)->name() == q)
		{
			movieQuery = (*it);
			break;
		} /*THROW EXCEPTION HERE IF NO MOVIE FOUND*/
	}
	map<string, double> termWeight = getNormalizedQuery(movieQuery->content()); //Get the normalized query vector

	vector<query_result> results = cosineSimilarity(termWeight); //Compare it to all indexed sentences and get the results
	
	sort(results.begin(), results.end(), operator>); //Sort by score

	/*NEED TO REMOVE FIRST (itself) and ANY EXCESS*/
	vector<query_result> finalResults;
	for (vector<query_result>::const_iterator it = results.begin() + 1;
		it != results.begin() + n + 1;
		++it)
	{
		if (it == results.end()) break;
		finalResults.push_back(*it);
	}

	return finalResults;
};