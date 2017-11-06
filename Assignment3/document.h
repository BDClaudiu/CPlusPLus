#ifndef DOCUMENT_H
#define DOCUMENT_H

#include"index_item.h"
#include<string>

//DO NOT TOUCH

class document : public index_item
{
public:
	document();
	document(std::string name);
	virtual ~document();
	const int size() const override;
};

#endif