/*
 * index_exception.h
 *
 *  Created on: Nov 18, 2017
 *      Author: David
 */
#include <exception>
#include <iostream>
#include <stdexcept>
#ifndef INDEX_EXCEPTION_H_
#define INDEX_EXCEPTION_H_
class index_exception : public std::exception
{
public:
	index_exception();
	const char* what() const noexcept override;
private:
};




#endif /* INDEX_EXCEPTION_H_ */
