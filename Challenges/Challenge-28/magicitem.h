// magicitem.h

#pragma once

#include "item.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class MagicItem: public Item
{
	public:
		MagicItem (string name = "magicitem", unsigned int value = 0, string description = "no description", unsigned int manaRequired = 0);
		
		virtual ~MagicItem ();
		
		void setDescription (string description);
		void setManaRequired (unsigned int manaRequired);
		
		string getDescription ();
		unsigned int getManaRequired ();
		
		string toString ();

	private:
		string description;
		unsigned int manaRequired;

};
