#include "Tokenizer.h"




Tokenizer::Tokenizer() 
{

}



Tokenizer::Tokenizer(string content)

	:content(content)
{


}



Tokenizer::Tokenizer(string content, string delimiters) 
	:content(content), delimiters(delimiters)
{


}


bool Tokenizer::hasNextToken()

{
	return true;
}


string Tokenizer::nextToken()

{

	return "needs a return";
}


//not sure about the syntax here
//	ostream  & operator<<(ostream & os, const Tokenizer tk) { }
