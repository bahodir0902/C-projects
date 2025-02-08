#include <iostream>
#include <string>
#include "Property.h"

Properties::Properties()
{
	propertyId = 0;
	propertyValue = 0;
	num_of_bath = 0;
}

Properties::Properties(int id, int value, int num, std::string name, std::string type)
{
	this->propertyId = id;
	this->propertyValue = value;
	this->num_of_bath = num;
	this->propertyName = name;
	this->propertyType = type;
}

void Properties::display()
{
	std::cout << "Property id: " << propertyId << std::endl
		<< "Property Value: " << propertyValue << std::endl
		<< "Property Name: " << propertyName << std::endl
		<< "Property type: " << propertyType << std::endl
		<< "Number of bathrooms: " << num_of_bath << std::endl;
}

double Properties::PropertyTax()
{
	return 0.8 * propertyValue;
}

void Properties::setPropertyId(int id)
{
	this->propertyId = id;
}

void Properties::setPropertyValue(int value)
{
	this->propertyValue = value;
}

void Properties::set_num_of_bath(int num)
{
	this->num_of_bath = num;
}

void Properties::setPropertyName(std::string name)
{
	this->propertyName = name;
}

void Properties::setPropertyType(std::string type)
{
	this->propertyType = type;
}

int Properties::getPropertyId()
{
	return propertyId;
}

int Properties::getPropertyValue()
{
	return propertyValue;
}

int Properties::get_num_of_bath()
{
	return num_of_bath;
}

std::string Properties::getPropertyName()
{
	return propertyName;
}

std::string Properties::getPropertyType()
{
	return propertyType;
}

Properties::~Properties()
{
	std::cout << "The destructor is working!!!" << std::endl;
}

int main()
{
	Properties object;
	int value;
	std::cout << "Hello! Firstly, set a property value: ";
	std::cin >> value;
	object.setPropertyValue(value);
	double tax = object.PropertyTax();
	std::cout << "\nYour tax rate is: " << tax << std::endl;

	Properties test(10, 50, 3, "Name", "Property");
	test.display();
	return 0;
}
