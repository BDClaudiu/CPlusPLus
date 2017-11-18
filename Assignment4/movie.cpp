#include "movie.h"
#include<sstream>
#include<fstream>
#include<ostream>
#include<iomanip>
#include<string>
#include <regex>
#include <tr1/regex>
using namespace std;

	
	movie::movie()
	{}
	//here we take in a movie name as constructor parameter and search the database for that name
	//if we find that name we copy the whole line in a string
	//then we can use regex to extract what we need (id/name/release date)

	movie::movie(string name)
		:movieName(name)
	{
			
		string line;
		string databasename = "movie.metadata.tsv";
		ifstream ifs(databasename);
	
		size_t pos;
		 cmatch cm;
		 //David's tests to extract date and ID ( the yyyy-mm-dd works but we need an if statement to check if its just yyy)
		    regex rgx("[\\d]*");
			regex_search("2345652	/m/075f66	City of the Dead	1960	76.0",cm,rgx);
			cout << cm[0] << '\n';
			cmatch cm2;
			regex rgx2("\\d{4}-\\d{2}-\\d{2}");
			regex_search("2345652	/m/075f66	City of the Dead	1960-03-20	76.0", cm2, rgx2);
			cout << cm2[0] << '\n';
		while (ifs.good())
		{
			smatch m;
			cmatch cm;
//			regex e ("\\b(sub)([^ ]*)");
			getline(ifs,line);
			pos = line.find(name);
			if (pos != string::npos)
			{
				lineContent += line;
				cout << lineContent<<endl;
				cout<<movieID<<endl;
				regex rgx("[^\\s]*");
				break;
			}
			 std::string s ("this subject has a submarine as a subsequence");
			   }

	}

	string movie::getName()
	{
		return movieName;
	}


	//here we search again like in the default constructor, however we search for movie id, that we parce from the line were we found the movie name
	string movie::getContent()
	{
		string line;
		string movieDescriptions = "plot_summaries.txt";
		ifstream ifs(movieDescriptions);

		size_t pos;

		while (ifs.good())
		{

		
			getline(ifs, line);

			pos = line.find(movieID);
			if (pos != string::npos)

			{
				cout << "Content found " << endl;
				content += line;
				break;
			}

		}

		cout << content;

		return content;
		
	}
	//  regex for date(YYYY-MM-DD):  ^\d{4}-\d{2}-\d{2}$
	int movie::getReleaseDate()
	{ 
		return 0;
	}


	//regex ([^\s]+) looks for anything untill white space...in our case will return the movie id 
	int movie::getID()
	{
		return 0;
	};

	
