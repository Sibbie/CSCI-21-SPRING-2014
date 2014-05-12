// BSTree.h for pc26

#pragma once

#include "BSTNode.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class BSTree
{
	public:
		BSTree ();
		virtual ~BSTree ();
		bool insert (int newContents);
		bool remove (int);
		void clear ();
		unsigned int getSize () const;
		void inOrder ();
		bool insert (int newContents, BSTNode*& node);
		bool remove (int, BSTNode*&);
		void removeMax (int&, BSTNode*&);
		void clear (BSTNode*& node);
		void inOrder (BSTNode*& node);
	private:
		BSTNode* root;
		unsigned int size;
};
