#include"indexer.h"
#include"sentence_indexer.h"
#include"word_tokenizer.h"
#include"sentence_tokenizer.h"
#include"document.h"
#include"sentence.h"
#include"stopword.h"
#include<algorithm>
#include<string>

using namespace std;

const string SW_FILE = "stopwords.txt";
/**
	Default constructor
*/
sentence_indexer::sentence_indexer()
{}

/**
	Default destructor
*/
sentence_indexer::~sentence_indexer()
{}

/**
	Constructor that creates a new indexer from an @param indexFile
*/
sentence_indexer::sentence_indexer(std::string indexFile)
{
	ifstream ifs(indexFile);
	if(!ifs)
	{
		throw document_exception(indexFile.c_str());
	}
	string line, sen;
	int position;
	vector<string> docNames;

	while (getline(ifs, line)) /*Get document names to read*/
	{
		document doc(line);
		sentence_tokenizer stk(doc.content()); /*Tokenize into sentences*/
		while (stk.hasNextToken())
		{
			position = doc.content().find(stk.getContent()); //Get position of next sentence
			sen = stk.nextToken();
			*this >> new sentence(sen, doc.name(), position); /*Index the sentence*/
		}
	}
}

/**
	Function that queries the indexer with a string @param q for @param n results
*/
vector<query_result> sentence_indexer::query(string q, int n) const
{
	if(q == ""){
		throw query_exception("no question asked :(");
	}
	map<string, double> termWeight = getNormalizedQuery(q); //Get the normalized query vector

	vector<query_result> results = cosineSimilarity(termWeight); //Compare it to all indexed sentences and get the results

	sort(results.begin(), results.end(), operator>); //Sort by score

	unsigned int senCount = 0;
	int numWords = 0;
	vector<query_result>::const_iterator it = results.begin();

	while (it != results.end())
	{
		int sz = it->getItem()->size();
		if (numWords + sz > n) /*Don't add another sentence if word count goes over n*/
			break;
		numWords += sz;
		++senCount;
		++it;
	}

	if (senCount < results.size())
		results.resize(senCount); /*Resize as needed*/
	
	sort(results.begin(), results.end(), sortByPos);

	stable_sort(results.begin(), results.end(), sortByDoc);

	//results are now sorted by document, then pos

	return results;
}

/**
	Function that compares query results by document
*/
const bool sortByDoc(query_result left, query_result right)
{
	return (left.getItem()->name() < right.getItem()->name()); //Compare document names
}

/**
	Function that compares query results by position in document
*/
const bool sortByPos(query_result & left, query_result & right)
{
	return dynamic_cast<sentence*>(left.getItem())->getPos() < dynamic_cast<sentence*>(right.getItem())->getPos(); //Compare positions in documents
}
