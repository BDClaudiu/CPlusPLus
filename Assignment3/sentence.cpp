#include "sentence.h"
#include "word_tokenizer.h"
#include<string>

using namespace std;

sentence::sentence()
	:index_item()
{}

sentence::sentence(std::string content, std::string name, int position)
	: index_item(name)
{
	
}

sentence::~sentence()
{}

const int sentence::size() const
{
	word_tokenizer tk(content());
	int size = 0;
	while (tk.hasNextToken())
	{
		++size;
		tk.nextToken();
	}
	return size;
}

const size_t sentence::getPos() const
{
	return pos;
}
