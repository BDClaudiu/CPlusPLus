#include "movie.h"
#include<sstream>
#include<fstream>
#include<ostream>
#include<iomanip>
#include<string>
#include <regex>
//#include <tr1/regex>
using namespace std;

	/**
	 default constructor
	 */
	movie::movie():index_item(),movieID(0),releaseYear(0)
	{}
	//here we take in a movie name as constructor parameter and search the database for that name
	//if we find that name we copy the whole line in a string
	//then we can use regex to extract what we need (id/name/release date)
	/**
  	  parameterized constructor takes in movie name that takes in string name
  	  @param moviename
	 */
	movie::movie(string name)
			: index_item(name),movieName(name)
	//^^^ can change to shift over name to base class
	{

			string line;
			string databasename = "movie.metadata.tsv";
			ifstream ifs(databasename);

			size_t pos;
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

	/*
	   returns the name of the movie ** probably going to be moved to child class
	 */
	string movie::getName()
	{

		return movieName;
	}

//here we search again like in the default constructor, however we search for movie id, that we parce from the line were we found the movie name
	/*
	 get the content is in child class as well
	 */
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
	/*
	 returns year of the year month day of the release of movie
	 */
	int movie::getReleaseDate()
	{ 
		return releaseYear;
	}


	//regex ([^\s]+) looks for anything untill white space...in our case will return the movie id 
	/**
	  returns the ID of the movie
	 */
	int movie::getID()
	{
		return movieID;
	};
	/**
	  function that returns the size representing words in plot description
	 */
	const int movie::size() const
	{

		return 0;
	}
	//to be removed to test potential use of exception
	void movie::query(std::string movie){
		if(movie != "City of the Dead"){
			const char * movi = movie.c_str();
			throw query_exception(movi);
		}

	}
