// DLNode.h

#pragma once

#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>

class DLNode
{
	public:
		DLNode ()
			:contents(), next(NULL), previous(NULL)
		{}

		DLNode (T newContents)
			:contents(newContents), next(NULL), previous(NULL)
		{}

		virtual ~DLNode ()
		{
			
		}

		void setContents (T newContents)
		{
			this->contents = newContents;
		}

		void setNext (DLNode<T>* newNext)
		{
			this->next = newNext;
		}

		void setPrevious (DLNode<T>* newPrevious)
		{
			this->previous = newPrevious;
		}

		T getContents () const
		{
			return contents;
		}

		DLNode<T>* getNext () const
		{
			return next;
		}

		DLNode<T>* getPrevious () const
		{
			return previous;
		}

	private:
		T contents;
		DLNode<T>* next;
		DLNode<T>* previous;
};

template <>
DLNode<int>::DLNode()
	:contents(0), next(NULL), previous(NULL)
{

}
