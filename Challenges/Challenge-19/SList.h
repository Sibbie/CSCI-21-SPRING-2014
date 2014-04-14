// SList.h

#pragma once

#include "SLNode.h"

#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class SList
{
	public:
		SList ();
		
		virtual ~SList ();
		
		void insertHead (int contents);
		void removeHead ();
		
		void insertTail (int contents);
		void removeTail ();
		
		void clear ();
		
		unsigned int getSize () const;
		
		string toString () const;

	private:
		SLNode* head;
		unsigned int size;
};
