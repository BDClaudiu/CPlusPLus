#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include"document_indexer.h"
#include"document.h"

using namespace std;

//INDEX_FILE opens index.txt file that contains the names of the documents we want to process;
const string INDEX_FILE = "index.txt";

int main()
{
	document_indexer idx(INDEX_FILE);
	string userQuery;
	do
	{
		cout << "Please input a query to process:" << endl;
		getline(cin, userQuery);
		if (userQuery == "\0")
			return 0;
		vector<query_result> results = idx.query(userQuery);

		for (vector<query_result>::const_iterator it = results.begin();
			it != results.end();
			++it)
		{
			cout << *it << endl;
		}


	} while (true);
}