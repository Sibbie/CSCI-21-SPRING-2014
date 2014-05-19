// item.h

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class Item
{
	public:
		Item (string name = "item", unsigned int value = 0);
		
		virtual ~Item ();

		void setName (string name);
		void setValue (unsigned int value);

		string getName ();
		unsigned int getValue ();

		string toString ();

	private:
		string name;
		unsigned int value;
	
};
