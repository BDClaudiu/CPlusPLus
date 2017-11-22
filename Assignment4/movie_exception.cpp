/*
 * movie_exception.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: David
 */
#include "movie_exception.h"
/*
  @param e
  constructor that takes in movie name
 */
movie_exception::movie_exception(const char* e):index_exception(e),id(0){};
/*
  @param id
  constructor that takes in ID
 */
movie_exception::movie_exception(int& id):index_exception()
{
	this->id = id;
};
/*
 * @param os
 * @param e
 * outputs the exception and the problem related to movie
 * if takes in id prints id
 * else it prints the movie name
 */
std::ostream & operator<<(std::ostream &os, const movie_exception &e)
{
	if(e.id>0)
	std::cout<< "there an problem in movie ID "<<e.id ;
	else
		std::cout<< "there an problem in movie "<<e.what();
	return os;
};



