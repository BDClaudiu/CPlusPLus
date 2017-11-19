/*
 * index_exception.h
 *
 *  Created on: Nov 18, 2017
 *      Author: David
 */
#include <exception>
#ifndef INDEX_EXCEPTION_H_
#define INDEX_EXCEPTION_H_
class index_exception : public std::exception
{
public:
	index_exception();
	virtual const char* what() const noexcept;
private:
};




#endif /* INDEX_EXCEPTION_H_ */
