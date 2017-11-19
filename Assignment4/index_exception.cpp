/*
 * index_exception.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: David
 */
#include "index_exception.h"
#include <typeinfo>
//tmp return;
index_exception::index_exception(){}

const char * index_exception::what()const noexcept
{

	return "mismatch";
}


