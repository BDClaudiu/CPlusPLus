#include<string>
#include "abstract_tokenizer.h"

using namespace std;

abstract_tokenizer::abstract_tokenizer(string content, string delimiters)
	: content(content), delimiters(delimiters)
{}
abstract_tokenizer::~abstract_tokenizer() { }
const string abstract_tokenizer::getContent() const { return content; }
const string abstract_tokenizer::getDelimiters() const { return delimiters; }
void abstract_tokenizer::setContent(string cont) { content = cont; }
bool abstract_tokenizer::hasNextToken()
{
	if (peekNextToken() == "")
		return false;
	return true;
}
string abstract_tokenizer::nextToken()
{
	string token = peekNextToken();
	size_t pos = getContent().find(token, 0);
	setContent(getContent().substr(pos + token.length()));
	return token;
}