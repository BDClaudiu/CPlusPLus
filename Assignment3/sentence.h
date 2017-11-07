#ifndef SENTENCE_H
#define SENTENCE_H

#include"index_item.h"
#include<string>

class sentence : public index_item
{
public:
	sentence();
	sentence(std::string content, std::string name, int position);
	virtual ~sentence();
	const int size() const override;
	const std::string::size_type getPos() const;
private:
	size_t pos;
};

#endif
