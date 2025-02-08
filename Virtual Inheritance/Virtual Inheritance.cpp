#include <iostream>
#include <string>
using namespace std;

class Component {
protected:
    string companyName;
public:
	Component(string companyName)
	{
		cout << "Constructor Component called!" << endl;
		this->companyName = companyName;
	}
};
class GPU : public Component 
{
public:
	GPU(string companyName) : Component(companyName)
	{
		cout << "GPU constructor called" << endl;
	}
};
class GRAM : public Component 
{
public:
	GRAM(string companyName) : Component(companyName)
	{
		cout << "Constructor RAM called!" << endl;
	}
};

class GraphicCard : public GPU, public GRAM 
{
public:
	GraphicCard(string GpuCompanyName, string GRAMcompanyName) : GPU(GpuCompanyName), GRAM(GRAMcompanyName)
	{
		cout << "GraphicCard constructor called!" << endl;
	}
};


int main()
{
	GraphicCard Geforce("Nomi", "Brend");
}
