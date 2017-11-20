
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include"movie.h"
#include "index_exception.h"
#include "query_exception.h"
#include<string>

using namespace std;

int main() {
	movie obj("City of the Dead");
	obj.getContent();
	//while we want to look for a movie
	try{
		obj.query("City of the Dad");

	}
	catch(query_exception const & e){
		cout<<e;
	}


			return 0; }
