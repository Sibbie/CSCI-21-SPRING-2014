// BSTNode.h

#pragma once

#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class BSTNode
{
	public:
		BSTNode ();
		BSTNode (int newContents);

		virtual ~BSTNode ();

		void setContents (int);

		int getContents () const;
		int& getContents ();

		void setLeftChild (BSTNode*);
		void setRightChild (BSTNode*);

		BSTNode* getLeftChild () const;
		BSTNode*& getLeftChild ();

		BSTNode* getRightChild () const;
		BSTNode*& getRightChild ();


	private:
		BSTNode* leftChild;
		BSTNode* rightChild;
		int contents;
};
