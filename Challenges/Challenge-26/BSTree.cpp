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
