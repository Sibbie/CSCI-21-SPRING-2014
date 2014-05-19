// fooditem.h


#pragma once

#include "item.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class FoodItem: public Item
{
	public:
		FoodItem (string name = "fooditem", unsigned int value = 0, unsigned int calories = 0, string unitOfMeasure = "nounits", float units = 0.00);
		
		virtual ~FoodItem ();

		void setCalories (unsigned int calories);
		void setUnitOfMeasure (string unitOfMeasure);
		void setUnits (float units);

		unsigned int getCalories ();
		string getUnitOfMeasure ();
		float getUnits ();

		string toString ();

	private:
		unsigned int calories;
		string unitOfMeasure;
		float units;
};
