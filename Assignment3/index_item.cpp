#include "index_item.h"
#include "word_tokenizer.h"
#include<string>

using namespace std;

index_item::index_item()
	:text(""), docName("")
{}

index_item::index_item(std::string docName)
	:docName(docName)
{}

index_item::~index_item()
{}

const string index_item::content() const
{
	return text;
}

const string index_item::name() const
{
	return docName;
}

void index_item::setContent(std::string text)
{
	this->text = text;
}
