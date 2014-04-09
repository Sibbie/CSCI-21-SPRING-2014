//SLNode.cpp

#include "SLNode.h"
#include <cstdlib>

SLNode::SLNode ()
:nextNode(NULL), contents(0)
{}

SLNode::SLNode (int contents)
:nextNode(NULL), contents(contents)
{
	//this->contents = contents;
}

SLNode::~SLNode ()
{
	nextNode = NULL;
}

void SLNode::setContents (int contents)
{
	this->contents = contents;
	//(*this).contents = contents;
}

int SLNode::getContents () const
{
	return contents;
}

void SLNode::setNextNode (SLNode* nextNode)
{
	this->nextNode = nextNode;
}

SLNode* SLNode::getNextNode () const
{
	return nextNode;
}
