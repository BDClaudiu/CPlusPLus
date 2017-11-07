#ifndef ITEM_INDEX_H
#define ITEM_INDEX_H

#include<string>
#include<map>

class index_item
{
public:
	index_item();
	index_item(std::string docName);
	virtual ~index_item();
	virtual const int size() const = 0;
	const std::string content() const;
	const std::string name() const;
protected:
	void setContent(std::string text);
private:
	std::string text;
	std::string docName;
};

#endif
