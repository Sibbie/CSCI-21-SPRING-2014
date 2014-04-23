// SLNode.h  for pc22

#pragma once

#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>

class SLNode
{
	public:
		SLNode ()
		{
			nextNode = NULL;
			contents = 0;
		}

		SLNode (T contents)
		{
			nextNode = NULL;
			this->contents = contents;
		}

		virtual ~SLNode ()
		{
			nextNode = NULL;
		}

		void setContents (T contents)
		{
			this->contents = contents;
		}

		T getContents () const
		{
			return contents;
		}

		void setNextNode (SLNode* nextNode)
		{
			this->nextNode = nextNode;
		}

		SLNode* getNextNode () const
		{
			return nextNode;
		}

	private:
		SLNode* nextNode;
		T contents;
};