#include"sentence_indexer.h"
#include"word_tokenizer.h"
#include"sentence_tokenizer.h"
#include"document.h"
#include"sentence.h"

using namespace std;

sentence_indexer::sentence_indexer()
{}

sentence_indexer::~sentence_indexer()
{}

sentence_indexer::sentence_indexer(std::string indexFile)
{
	ifstream ifs(indexFile);
	string line, sen;
	int position;
	vector<string> docNames;

	while (getline(ifs, line)) /*Get document names to read*/
	{
		document doc(line);
		sentence_tokenizer stk(doc.content());
		while (stk.hasNextToken())
		{
			position = doc.content().find(stk.getContent());
			sen = stk.nextToken();
			*this >> new sentence(sen, doc.name(), position);
		}
	}
}

void sentence_indexer::operator>>(index_item* item)
{
	indexList.push_back(item);

	word_tokenizer tk(item->content());
	string word;
	while (tk.hasNextToken())
	{
		word = tk.nextToken();
		//CONTINUE PROGRESS HERE
		for (string::size_type i = 0; i != word.length(); ++i)
			word[i] = tolower(word[i]); //Convert characters to lower case
		++get<0>(wordIndex[word][item->name()]); //Increment tf
	}

	normalize(); //maybe don't do here, need possibility of exception thrown due to un-normalized indexer
}