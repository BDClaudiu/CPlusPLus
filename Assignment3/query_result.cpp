#include "query_result.h"
#include<sstream>
#include<iomanip>

using namespace std;

query_result::query_result()
	:doc(nullptr), score(0)
{}

query_result::query_result(index_item * item, double sc)
	:doc(item), score(sc)
{}

query_result::~query_result()
{}

std::ostream & operator<<(std::ostream & os, const query_result & qr)
{
	ostringstream oss;
	oss << "Document: " << qr.doc->name() << " -> " << setprecision(2) << qr.score;
	return os << oss.str();
}

const bool operator>(query_result & left, query_result & right)
{
	return (left.score > right.score);
}

const bool operator<(query_result & left, query_result & right)
{
	return (left.score < right.score);
}

const bool operator>=(query_result & left, query_result & right)
{
	return (left.score >= right.score);
}

const bool operator<=(query_result & left, query_result & right)
{
	return (left.score <= right.score);
}
