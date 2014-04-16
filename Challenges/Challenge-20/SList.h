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
		void insertTail (int contents);
		
		void removeTail ();
		void removeHead ();
		
		void insert (int newContents);
		
		bool removeFirst (int oldContents);
		
		void clear ();
		
		unsigned int getSize () const;
		
		string toString () const;

	private:
		SLNode* head;
		unsigned int size;
};
