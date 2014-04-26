// DLList.h

#pragma once

#include "DLNode.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>

class DLList
{
	public:
		/*
		*	*********************
		*	*Default Constructor*
		*	*********************
		*	@brief This constructor sets the private members size to 0 and all pointers to NULL;
		*/
		DLList ()
			:count(0), head(NULL), tail(NULL) 
		{

		}
		/*
		*	*********************
		*/
		virtual ~DLList ()
		{
			clear ();
		}
		/*
		*	*********************
		*/
		unsigned int getSize () const
		{
			return count;
		}
		/*
		*	*********************
		*/
		void pushFront (T newContents)
		{
			if(head == NULL)
			{
				head = new DLNode<T>(newContents);
				tail = head;

				count++;
			}
			else if (head)
			{
				DLNode<T>* aNewNode = new DLNode<T>(newContents);
				aNewNode->setNext(head);
				head->setPrevious(aNewNode);
				head = aNewNode;
			
				count++;
			}
		}
		/*
		*	*********************
		*/
		void pushBack (T newContents)
		{
			if (head == NULL)
			{
				pushFront(newContents);
			}

			else
			{
				DLNode<T>* aNewNode = new DLNode<T>(newContents);

				aNewNode->setPrevious(tail);
				tail->setNext(aNewNode);
				tail = aNewNode;
				count++;

			}
		}
		/*
		*	*********************
		*/
		void insert (T newContents)
		{
			if (head == NULL)
			{
				pushFront(newContents);
			}

			else if (newContents <= head->getContents())
			{
				pushFront(newContents);
			}

			else if (count == 1)
			{
				pushBack(newContents);
			}

			else
			{
				DLNode<T>* i = head;
			
				while (i->getNext() != NULL)
				{
					if (i->getNext()->getContents() >= newContents)
					{
						DLNode<T>* aNewNode = new DLNode<T>(newContents);

						aNewNode->setNext(i->getNext());
						aNewNode->setPrevious(i);
						i->setNext(aNewNode);

						count++;

						break;
					}

					i = i->getNext();

					if (i->getNext() == NULL)
					{
						pushBack(newContents);

						break;
					}
				}	
			}
		}
		/*
		*	*********************
		*/
		T getFront () const
		{
			if(head)
			{
				return head->getContents();
			}
			else
			{
				string msg = "LIST EMPTUY";
				throw(msg);
			}
		}
		/*
		*	*********************
		*/
		T getBack () const
		{
			if(head)
			{
				return tail->getContents();
			}
			else
			{
				string msg = "LIST EMPTY";
				throw(msg);
			}
		}
		/*
		*	*********************
		*/
		bool get(T target) const
		{
			if(head)
			{
				if(head->getNext() == NULL)
				{
					if(head->getContents() == target)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else if(head->getContents() == target)
				{
					return true;
				}

				DLNode<T>* iter = head;
				while (iter->getNext() != NULL)
				{
					iter = iter->getNext();
					if(iter->getContents() == target)
					{
						return true;
					}
				}
				return false;
			}
			else
			{
				return false;
			}
		}
		/*
		*	*********************
		*/
		void popFront ()
		{
			if (head)
			{
				if(head->getNext() == NULL)
				{
					delete head;
					head = NULL;
					tail = NULL;
					count = 0;
				}
				else
				{
					DLNode<T>* temp = head;
					head = head->getNext();
					head->setPrevious(NULL);
					delete temp;
					count--;
				}
			}
		}
		/*
		*	*********************
		*/		
		void popBack ()
		{
			if (head)
			{
				if (head->getNext() == NULL)
				{
					popFront();
				}

				else
				{
					DLNode<T>* temp = tail;
					
					tail = tail->getPrevious();
					tail->setNext(NULL);

					delete temp;
					count--;
				}
			}
		}
		/*
		*	*********************
		*/		
		bool removeFirst (T target)
		{
			if (head)
			{
				if (head->getNext() == NULL)
				{
					if (head->getContents() == target)
					{
						popFront();
						return true;
					}
					else
					{
						return false;
					}
				}

				if (head->getContents() == target)
				{
					popFront();
					return true;
				}
				DLNode<T>* iter = head;

				while (iter->getNext() != NULL)
				{
					iter = iter->getNext();

					if (iter->getContents() == target)
					{
						if(iter->getNext() == NULL)
						{
							popBack();
							return true;
						}
						iter->getPrevious()->setNext(iter->getNext());
						iter->getNext()->setPrevious(iter->getPrevious());
						delete iter;
						count--;

						return true;
					}
				}
				return false;
			}
			else
			{
				return false;
			}
		}
		/*
		*	*********************
		*/		
		bool removeAll (T target)
		{
			bool foundOne = false;

			if (head)
			{

				if (head->getNext() == NULL)
				{
					if (head->getContents() == target)
					{
						popFront();
						foundOne = true;
					}
				}

				
				if (head->getContents() == target)
				{
					popFront();
					foundOne = true;
				}
				
				DLNode<T>* iter = head;

				while (iter->getNext() != NULL)
				{
					iter = iter->getNext();
					if (iter->getContents() == target)
					{
						removeFirst(target);
						iter = head;
						foundOne = true;
					}
				}
			}
			return foundOne;
		}
		/*
		*	*********************
		*/		
		void clear ()
		{
			while (head != NULL)
			{
				popFront();
			}
		}
		/*
		*	*********************
		*/
		friend ostream& operator<< (ostream& out, const DLList<T>& src)
		{
			DLNode<T>* iter = src.head;
			if (src.head == NULL)
			{
				out << "";
				return out;
			}
			if (src.head->getNext() == NULL)
			{
				out << src.head->getContents();
				return out;
			}
			while(iter->getNext() != NULL)
			{
				out << iter->getContents();
				iter = iter->getNext();
				if (iter->getNext() != NULL)
					out << ",";	
				else
					out << "," << iter->getContents();			
			}
			return out;
		}

		/* 
		string toString () const
		{
			stringstream ss;
			if (head != NULL)
			{
				for (DLNode<T>* iterator = head; iterator != NULL; iterator = iterator->getNextNode())
				{
					ss << iterator->getContents();

					if (iterator->getNextNode() != NULL)
					{
						ss << ",";
					}
				}
			}
			return ss.str();
		}
		*/

	private:
		unsigned int count;
		DLNode<T>* head;
		DLNode<T>* tail;
};
