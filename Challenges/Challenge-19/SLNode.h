// SLNode.h

#pragma once

#include <string>
#include <cstdlib>
using namespace std;

class SLNode
{
	public:
		SLNode ();
		SLNode (int contents);
		virtual ~SLNode ();
		void setContents (int contents);
		int getContents () const;
		void setNextNode (SLNode* nextNode);
		SLNode* getNextNode () const;

	private:
		SLNode* nextNode;
		int contents;
};
