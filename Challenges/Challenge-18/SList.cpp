// SList.cpp

#include "SList.h"

SList::SList ()
:head(NULL), size(0)
{

}

SList::~SList ()
{
	clear ();
}

void SList::insertHead (int contents)
{
	SLNode* aNextNode = new SLNode(contents);
	aNextNode->setNextNode(head);
	head = aNextNode;

	size++;
}

void SList::removeHead ()
{
	if (head != NULL)
	{
		SLNode* tempSent = head;
		head = head->getNextNode();
		delete tempSent;

		size--;
	}
}

void SList::clear ()
{
	while (head != NULL)
	{
		removeHead();
	}
}

unsigned int SList::getSize () const
{
	return size;
}

string SList::toString () const
{
	stringstream ss;
	if (head != NULL)
	{
		for (SLNode* iterator = head; iterator != NULL; iterator = iterator->getNextNode())
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
