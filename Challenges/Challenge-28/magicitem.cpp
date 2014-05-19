// magicitem.cpp

#include "magicitem.h"

MagicItem::MagicItem (string name, unsigned int value, string description, unsigned int manaRequired)
	:Item(name, value)
{
	this->description = description;
	this->manaRequired = manaRequired;
}

MagicItem::~MagicItem ()
{
	
}

void MagicItem::setDescription (string description)
{
	this->description = description;
}

void MagicItem::setManaRequired (unsigned int manaRequired)
{
	this->manaRequired = manaRequired;
}

string MagicItem::getDescription ()
{
	return this->description;
}

unsigned int MagicItem::getManaRequired ()
{
	return this->manaRequired;
}

string MagicItem::toString ()
{
	stringstream ss;

	ss << Item::toString() << ", " << description << ", requires " << manaRequired << " mana";

	return ss.str();
}
