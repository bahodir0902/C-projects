#pragma once

#include <iostream>
#include <string>

class Properties
{
	int propertyId, propertyValue, num_of_bath;
	std::string propertyName, propertyType;

public:
	Properties();
	Properties(int, int, int, std::string, std::string);
	void setPropertyId(int);
	int getPropertyId();
	std::string getPropertyName();
	void setPropertyName(std::string);
	std::string getPropertyType();
	void setPropertyType(std::string);
	int getPropertyValue();
	void setPropertyValue(int);
	void set_num_of_bath(int);
	int get_num_of_bath();

	void display();
	double PropertyTax();

	~Properties();
};
