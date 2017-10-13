#include "stopword.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
#include<iomanip>

using namespace std;




//defult constructor with an empty stopword vector
Stopword::Stopword() 

{
	swList;
}

//constructor with a file name
Stopword::Stopword(string file)
	:filename(file), readstopword(swList)
{
	readstopword;
}

//overload operator
bool Stopword:: operator()(string word) 

{
	return true;
}

