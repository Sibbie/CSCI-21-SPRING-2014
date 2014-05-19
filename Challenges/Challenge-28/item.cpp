// item.cpp

#include "item.h"

Item::Item (string name, unsigned int value)
{
	this->name = name;
	this->value = value;
}

Item::~Item ()
{
	
}

void Item::setName (string name)
{
	this->name = name;
}

void Item::setValue (unsigned int value)
{
	this->value = value;
}

string Item::getName ()
{
	return this->name;
}

unsigned int Item::getValue ()
{
	return this->value;
}

string Item::toString ()
{
	stringstream ss;

	ss << name << ", $" << value;

	return ss.str();
}
