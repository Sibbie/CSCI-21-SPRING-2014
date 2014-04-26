/*
 * PROGRAM Projcet 3
 * PROGRAM DESCRIPTION
 *
 * PROGRAMMER Sebastian Rollins Brenton
 * Date created: 4-3-2014
 * Last date modified: 4-25-2014
 *
 * SOURCES USED
 */
#include "DLList.h"
#include "DLNode.h"

#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool processFile(string fileName);

int main(int argc, char* argv[])
{	
	string fileName;
	if(argc >= 2)
	{
		fileName = argv[1];
	}
	else
	{
		cout << "Syntax is \"project3 <filename>\"" << endl;
		return 1;
	}
	if(!processFile(fileName))
		cout << "FILE NOT FOUND. Make sure you type the entire file name correctly" << endl;
	return 0;
}

bool processFile (string fileName)
{
	stringstream ss;
	ifstream fin(fileName.c_str());
	if (fin.good())
	{
		int newContents = 0;
		int target = 0;
		DLList<int>* intTestList1 = NULL;
		intTestList1 = new DLList<int>();
		string arg;
		string msg;
		string nextLine;
		int temp = 0;
		while (getline(fin, nextLine))
		{
			switch (nextLine[0])
			{
				case '#':
					break;
				case 'C':
					if(intTestList1 == NULL)
						intTestList1 = new DLList<int>();
					if (intTestList1->getSize() != 0)
						intTestList1->clear();
					intTestList1 = new DLList<int>();
					cout << "LIST CREATED" << endl;
					break;
				case 'X':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else
					{
						intTestList1->clear();
						cout << "LIST CLEARED" << endl;
					}
					break;
				case 'D':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}				
					else
					{
						cout << "LIST DELETED" << endl;
						intTestList1->clear();
						intTestList1 = NULL;				
					}
					break;
				case 'I':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else
					{
						arg = nextLine.substr(2);
						ss << arg << " ";
						ss >> newContents;
						cout << "VALUE " << newContents <<" INSERTED" << endl;
						intTestList1->insert(newContents);
					}
					break;
				case 'F':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else
					{							
						arg = nextLine.substr(2);
						ss << arg << " ";
						ss >> newContents;
						cout << "VALUE " << newContents<< " ADDED TO HEAD" << endl;
						intTestList1->pushFront(newContents);
					}
					break;
				case 'B':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else
					{
						arg = nextLine.substr(2);
						ss << arg << " ";
						ss >> newContents;
						cout << "VALUE " << newContents<< " ADDED TO TAIL" << endl;
						intTestList1->pushBack(newContents);
					}
					break;
				case 'A':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else
					{
						try {
							temp = intTestList1->getFront();
								cout << "VALUE " << temp << " AT HEAD" << endl;
							} catch (string msg) {
							cout << msg << endl;
							}
					}
					break;
				case 'Z':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else
					{				
						try {
							temp = intTestList1->getBack();
								cout << "VALUE " << temp << " AT TAIL" << endl;
							} catch (string msg) {
							cout << msg << endl;			
							}
					}
					break;
				case 'T':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else if (intTestList1->getSize() == 0)
						cout << "LIST EMPTY" << endl;
					else
					{
						intTestList1->popFront();
						cout << "REMOVED HEAD" << endl;
					}				
					break;
				case 'K':
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else if (intTestList1->getSize() == 0)
					{
						cout << "LIST EMPTY" << endl;
					}
					else
					{
						intTestList1->popBack();
						cout << "REMOVED TAIL" << endl;
					}	
					break;
				case 'E':	
					arg = nextLine.substr(2);
					ss << arg << " ";
					ss >> target;				
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else if(intTestList1->removeAll(target))
					{
						cout << "VALUE " << target << " ELIMINATED" << endl;
					}
					else
					{
						cout << "VALUE " << target << " NOT FOUND" << endl;
					}
					break;
				case 'R':
					arg = nextLine.substr(2);
					ss << arg << " ";
					ss >> target;				
					if(intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else if(intTestList1->removeFirst(target))
					{
						cout << "VALUE " << target << " REMOVED" << endl;
					}
					else
					{
						cout << "VALUE " << target << " NOT FOUND" << endl;
					}
					break;
				case 'G':
					arg = nextLine.substr(2);
					ss << arg << " ";
					ss >> target;
					if (intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}
					else if(intTestList1->get(target))
					{
						cout << "VALUE " << target << " FOUND" << endl;
					}
					else
					{
						cout << "VALUE " << target << " NOT FOUND" << endl;
					}				
					break;
				case 'N':
					if (intTestList1 == NULL)
						cout << "MUST CREATE LIST INSTANCE" << endl;
					else
						cout << "LIST SIZE IS " << intTestList1->getSize() << endl;
					break;
				case 'P':
					if (intTestList1 == NULL)
					{
						cout << "MUST CREATE LIST INSTANCE" << endl;
					}			
					else if (intTestList1->getSize() == 0)
					{
						cout << "LIST EMPTY" << endl;
					}
					else
					{
						cout << *intTestList1 << endl;	
					}
					break;				
				default:
					break;
			}
			nextLine = "";
			newContents = 0;
			target = 0;
			ss.str("");
		}
		fin.close();
		return true;
	}
	else
	{
		return false;
	}
}
