#include"abstract_tokenizer.h"
#include"sentence_tokenizer.h"
#include<string>

using namespace std;

sentence_tokenizer::sentence_tokenizer(string content, string delimiters)
	:abstract_tokenizer(content, delimiters)
{}

sentence_tokenizer::~sentence_tokenizer() {} //MAY NOT BE NEEDED

string sentence_tokenizer::peekNextToken()
{
	string currentContent = getContent();
	if (currentContent == "")
		return ""; //MAYBE BAD SOLUTION
	size_t pos = currentContent.find_first_not_of(" \t\n"); //Ignore beginning whitespace/delimiters
	size_t firstDelim = currentContent.find_first_of(getDelimiters(), pos);
	size_t found;
	while (true)
	{
		found = currentContent.find_first_not_of(getDelimiters(), firstDelim); /*for edge cases like "...?" :*/
		//ABBREVIATION CHECKING HERE
		if(found == string::npos)
			return currentContent.substr(pos);
		if (!islower(currentContent.at(currentContent.find_first_not_of(" \t\n", found))))
			return currentContent.substr(pos, found - pos);
		firstDelim = currentContent.find_first_of(getDelimiters(), found);
	}
		
}