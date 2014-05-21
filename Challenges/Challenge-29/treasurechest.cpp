// treasurechest.cpp

#include "treasurechest.h"

void TreasureChest::addItem (const Item& newItem)
{
	chest.push_back(newItem);
}

void TreasureChest::insertItem (const Item& newItem, unsigned int position)
{
	if(position < chest.size())
	{
		chest.insert(chest.begin()+position, newItem);
	}

	else
		addItem(newItem);
}

const Item* TreasureChest::getItem (unsigned int position)
{
	if(position < chest.size())
	{
		return &chest[position];
	}
	else
		return NULL;
}

Item TreasureChest::removeItem (unsigned int position) throw (string)
{
	if(position < chest.size())
	{
		Item tempItem = chest[position];

		chest.erase(chest.begin()+position);

		return tempItem;
	}

	else
		throw string("ERROR: attempting remove at invalid position");
}

void TreasureChest::clear ()
{
	chest.clear();
}

bool TreasureChest::empty () const
{
	return chest.empty();
}

unsigned int TreasureChest::getSize () const
{
	return chest.size();
}

void TreasureChest::sortByName ()
{
	std::sort (chest.begin(), chest.end(), compareItemsByName);
}

void TreasureChest::sortByValue ()
{
	std::sort (chest.begin(), chest.end(), compareItemsByValue);
}

void TreasureChest::sortByQuantity ()
{
	std::sort (chest.begin(), chest.end(), compareItemsByQuantity);
}

ostream& operator<< (ostream& outs, const TreasureChest& src)
{
	for(unsigned int i=0; i < src.chest.size(); i++)
	{
		outs << src.chest[i].name;

		if(i<src.chest.size()-1)
		{
			outs << ",";
		}
	}

	return outs;
}

//===================================

bool compareItemsByName (const Item& lsrc, const Item& rsrc)
{
	return lsrc.name < rsrc.name;
}

bool compareItemsByValue (const Item& lsrc, const Item& rsrc)
{
	return lsrc.value < rsrc.value;
}

bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc)
{
	return lsrc.quantity < rsrc.quantity;
}
