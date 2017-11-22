#include"abstract_tokenizer.h"
#include"sentence_tokenizer.h"
#include<string>

using namespace std;

/**Default constructor with string params @param content @param delimiters */
sentence_tokenizer::sentence_tokenizer(string content, string delimiters)
	:abstract_tokenizer(content, delimiters)
{}

/** Default destructor*/
sentence_tokenizer::~sentence_tokenizer() {}

/**Checks the next token sentence */
string sentence_tokenizer::peekNextToken()
{
	string text = getContent();
	if (text == "")
		return "";
	size_t pos = 0;
	while (pos < text.length() && !isupper(text.at(pos)))
		++pos;

	size_t delim = text.find_first_of(getDelimiters(), pos);
	while (true)
	{
		if (delim == string::npos)
			return text.substr(pos); //EOF DONE
		size_t found = delim;

		while (found < text.length() && !isalpha(text.at(found)))
			++found;
		if (found == text.length())
			return text.substr(pos); //EOF DONE
		else if (isupper(text.at(found)))
			return text.substr(pos, delim - pos + 1); //UPPERCASE FOUND, DONE
		delim = text.find_first_of(getDelimiters(), found);
	}
}