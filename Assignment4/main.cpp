
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include"movie.h"
#include<string>
#include "query_exception.h"
#include "movie_exception.h"
using namespace std;

int main() {

try{
	movie obj("Taxi Blues");

	cout << obj.getID() << endl;
	cout << obj.getName() << endl;
	cout<<obj.getReleaseDate()<<endl;
	cout << "Movie content: " << endl;
	cout << obj.getContent();

	cout << "---------------------------------------------" << endl;

	cout<<obj.fullMovieList().size()<<endl;
	cout << obj.fullMovieList()[81739] << endl;
}
catch(movie_exception &e){
	cout<<e;
}
	return 0; }
