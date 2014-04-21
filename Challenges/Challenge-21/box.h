// Box.h

#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>

class Box
{
	public:
		Box()
		{

		}
		Box (T newContents)
			:contents(newContents)
		{
			
		}

		T getContents ()
		{
			return contents;
		}

		void setContents (T newContents)
		{
			contents = newContents;
		}

		friend ostream& operator<< (ostream& out, Box in)
		{
			out << in.getContents();
			return out;
		}

	private:
		T contents;
};
