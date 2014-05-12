// BSTree.cpp for pc26

#include "BSTree.h"

BSTree::BSTree ()
	:root(NULL), size(0)
{
	
}

BSTree::~BSTree ()
{
	clear();
}

bool BSTree::insert (int newContents)
{
	if (insert(newContents, root))
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool BSTree::remove (int targetData)
{
	return remove(targetData, root);
}

void BSTree::clear ()
{
	clear(root);
}

unsigned int BSTree::getSize () const
{
	return size;
}

void BSTree::inOrder ()
{
	inOrder(root);
}

bool BSTree::insert (int newContents, BSTNode*& node)
{
	if (node == NULL)
	{
		node = new BSTNode(newContents);
		size++;
		return true;
	}

	else if (newContents < node->getContents())
	{
		return insert (newContents, node->getLeftChild());
	}

	else if (newContents > node->getContents())
	{
		return insert (newContents, node->getRightChild());
	}

	else
	{
		return false;
	}

}

bool BSTree::remove (int targetData, BSTNode*& rootPtr)
{
	if(!rootPtr)
	{
		return false;
	}
	else if(targetData < rootPtr->getContents())
	{
		return remove(targetData, rootPtr->getLeftChild());
	}
	else if(targetData > rootPtr->getContents())
	{
		return remove(targetData, rootPtr->getRightChild());
	}
	else
	{
		if(!(rootPtr->getLeftChild()))
		{
			BSTNode* oldRootPtr = rootPtr;
			rootPtr = rootPtr->getRightChild();
			delete oldRootPtr;
		}
		else
		{
			removeMax(rootPtr->getContents(), rootPtr->getLeftChild());
		}
		size--;
		return true;
	}
}

void BSTree::removeMax (int& targetData, BSTNode*& rootPtr)
{
	if(!rootPtr->getRightChild())
	{
		BSTNode* oldRootPtr = rootPtr;
		targetData = rootPtr->getContents();
		rootPtr = rootPtr->getLeftChild();
		delete oldRootPtr;
	}
	else
	{
		removeMax(targetData, rootPtr->getRightChild());
	}
}

void BSTree::clear (BSTNode*& node)
{
	if (node != NULL)
	{
		clear(node->getLeftChild());
		clear(node->getRightChild());
		size--;
		delete node;
		node = NULL;
	}
}

void BSTree::inOrder (BSTNode*& node)
{
	if (node != NULL)
	{
		inOrder (node->getLeftChild());
		cout << node->getContents() << " ";
		inOrder (node->getRightChild());
	}
}
