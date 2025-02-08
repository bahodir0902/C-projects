#include <iostream>
using namespace std;

class car 
{
public:
	car()
	{
		cout << "Car constructor called!" << endl;
	}
	void Drive() 
	{
		cout << "I'm driving a car!!!" << endl; 
	}
	~car()
	{
		cout << "Car destructor called!" << endl;
	}
};
class Airplane 
{
public:
	Airplane()
	{
		cout << "Airplane constructor called!" << endl;
	}
	void Fly() 
	{
		cout << "I'm flying in a plane!!!" << endl;
	}
	~Airplane()
	{
		cout << "Airplane destructor called!" << endl;
	}
};
class FlyingCar : public car, public Airplane 
{
public:
	FlyingCar()
	{
		cout << "FlyingCar constructor called!" << endl;
	}
	void Mix() 
	{
		cout << "I can do everything!!!" << endl;
	}
	~FlyingCar()
	{
		cout << "FlyingCar destructor called!" << endl;
	}
};
int main()
{
	FlyingCar flc;
	flc.Mix();
}
