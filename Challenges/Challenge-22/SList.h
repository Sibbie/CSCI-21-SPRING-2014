// SList.h for pc22

#pragma once

#include "SLNode.h"

#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>

class SList
{
	public:
		SList ()
			:head(NULL), size(0)
		{

		}

		virtual ~SList ()
		{
			clear ();
		}

		void insertHead (T contents)
		{
			if(head == NULL)
			{
				head = new SLNode<T>(contents);

				size++;
			}
			else if (head)
			{
				SLNode<T>* aNextNode = new SLNode<T>(contents);
				aNextNode->setNextNode(head);
				head = aNextNode;
			
				size++;
			}
		}

		void insertTail (T contents)
		{
			if (head == NULL)
			{
				insertHead(contents);
			}

			else
			{
				SLNode<T>* node = new SLNode<T>(contents);
				SLNode<T>* i;

				for (i = head; i->getNextNode() != NULL; i = i->getNextNode())
				{

				}
				i->setNextNode(node);
				size++;

			}
		}

		void removeHead ()
		{
			if (head != NULL)
			{
				if(head->getNextNode() == NULL)
				{
					delete head;
					head = NULL;
					size--;
				}
				else
				{
					SLNode<T>* tempSent = head;
					head = head->getNextNode();
					delete tempSent;
					size--;
				}
			}
		}

		void removeTail ()
		{
			if (head)
			{
				if (head->getNextNode() == NULL)
				{
					removeHead ();
				}

				else
				{
					SLNode<T>* trail = head;
					SLNode<T>* iter = head;

					while (iter->getNextNode() != NULL)
					{
						trail = iter;
						iter = trail->getNextNode();
					}

					delete iter;
					trail->setNextNode(NULL);
					size--;
				}
			}
		}

		void insert (T newContents)
		{
			if (head == NULL)
			{
				insertHead(newContents);
			}

			else if (newContents <= head->getContents())
			{
				insertHead(newContents);
			}

			else if (size == 1)
			{
				insertTail(newContents);
			}

			else
			{
				SLNode<T>* i = head;
			
				while (i->getNextNode() != NULL)
				{
					if (i->getNextNode()->getContents() >= newContents)
					{
						SLNode<T>* newNode = new SLNode<T>(newContents);

						newNode->setNextNode(i->getNextNode());
						i->setNextNode(newNode);

						size++;

						break;
					}

					i = i->getNextNode();

					if (i->getNextNode() == NULL)
					{
						insertTail (newContents);

						break;
					}
				}	
			}
		}

		bool removeFirst (T oldContents)
		{
			if (head)
			{
				if (oldContents == head->getContents())
				{
					removeHead ();

					return true;
				}

				SLNode<T>* i = head;

				while (i->getNextNode() != NULL)
				{
					if (i->getNextNode()->getContents() == oldContents)
					{
						SLNode<T>* del = i->getNextNode();
						i->setNextNode(i->getNextNode()->getNextNode());
						delete del;
						size--;

						return true;
					}

					i = i->getNextNode();
				}
			}
			return false;
		}

		bool removeAll (T target)
		{
			bool foundOne = false;

			if (head)
			{

				if (head->getNextNode() == NULL)
				{
					if (head->getContents() == target)
					{
						removeHead();
						foundOne = true;
					}
				}

				if (head->getContents() == target)
				{
					SLNode<T>* temp = head;
					head = head->getNextNode();
					delete temp;
					size--;
					foundOne = true;
				}

				SLNode<T>* iter = head;
				SLNode<T>* follow = head;

				while (iter->getNextNode() != NULL)
				{
					follow = iter;
					iter = iter->getNextNode();
					if (iter->getContents() == target)
					{
						follow->setNextNode(iter->getNextNode());
						delete iter;
						size--;
						iter = head;
						follow = iter;
						foundOne = true;
					}
				}
			}
			return foundOne;
		}

		void clear ()
		{
			while (head != NULL)
			{
				removeHead();
			}
		}

		unsigned int getSize () const
		{
			return size;
		}

		string toString () const
		{
			stringstream ss;
			if (head != NULL)
			{
				for (SLNode<T>* iterator = head; iterator != NULL; iterator = iterator->getNextNode())
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
	private:
		SLNode<T>* head;
		unsigned int size;
};