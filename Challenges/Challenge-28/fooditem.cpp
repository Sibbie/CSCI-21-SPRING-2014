// fooditem.cpp

#include "fooditem.h"

FoodItem::FoodItem (string name, unsigned int value, unsigned int calories, string unitOfMeasure, float units)
	:Item(name, value)
{
	this->calories = calories;
	this->unitOfMeasure = unitOfMeasure;
	this->units = units;
}

FoodItem::~FoodItem ()
{
	
}

void FoodItem::setCalories (unsigned int calories)
{
	this->calories = calories;
}

void FoodItem::setUnitOfMeasure (string unitOfMeasure)
{
	this->unitOfMeasure = unitOfMeasure;
}

void FoodItem::setUnits (float units)
{
	this->units = units;
}

unsigned int FoodItem::getCalories ()
{
	return this->calories;
}

string FoodItem::getUnitOfMeasure ()
{
	return this->unitOfMeasure;
}

float FoodItem::getUnits ()
{
	return this->units;
}

string FoodItem::toString ()
{
	stringstream ss;

	ss.precision(2);

	ss.setf(ios::fixed, ios::floatfield);

	ss << Item::toString() << ", " << units << " " << unitOfMeasure << ", " << calories << " calories";

	return ss.str();
}
