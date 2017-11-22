//COMP345 Assignment #3 (Part 2)
//Nicholas Bourbonniere SID 27199600
//Bacisor Claudiu		SID 27735332
//Krasimir Kanev		SID 27848056

#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include"document_indexer.h"
#include"document.h"

using namespace std;

//INDEX_FILE opens index.txt file that contains the names of the documents we want to process;
const string INDEX_FILE = "index.txt";
/*
int main()
{
	try
	{
		document_indexer idx(INDEX_FILE);


		string userQuery;
		do
		{
			try{
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
			}
			catch(query_exception const & e){
				cout<<e<<endl;
				continue;
			}
		}
		while (true);
	}
	catch(document_exception const & e)
	{
		cout<<e;
	}

}*/
