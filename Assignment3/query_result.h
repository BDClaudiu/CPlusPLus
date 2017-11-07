#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include"index_item.h"
#include<iostream>
#include<fstream>


class query_result
{
public:
	query_result();
	query_result(index_item* item, double sc);
	~query_result();
	friend std::ostream & operator<< (std::ostream & os, const query_result & qr);
	friend const bool operator>(query_result& left, query_result& right);
	friend const bool operator<(query_result& left, query_result& right);
	friend const bool operator>=(query_result& left, query_result& right);
	friend const bool operator<=(query_result& left, query_result& right);
private:
	index_item* doc;
	double score;
};

#endif