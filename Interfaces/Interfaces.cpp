#include <iostream>
#include <string>
using namespace std;

class Ibicycle 
{
public:
	virtual void TwistTheWheel() = NULL;
	virtual void Ride() = NULL;
};
class Simple : public Ibicycle 
{
public:
	void TwistTheWheel() override 
	{
		cout << "TwistTheWheel(): Simple : Ibicycle " << endl;
	}
	void Ride() override
	{
		cout << "Ride(): Simple : Ibicycle" << endl;
	}

};
class Human 
{
public:
	void Use(Ibicycle &object) 
	{
		//cout << "Using the role!" << endl;
		object.TwistTheWheel();
		//cout << "GO GO GO!!!" << endl;
		object.Ride();
	}
};
class SuperBicycle : public Ibicycle 
{
public:
	void TwistTheWheel() override 
	{
		cout << "Super Bicycle twisted the wheel!" << endl;
	}
	void Ride() override 
	{
		cout << "I'm a super Bicycle!!!" << endl;
	}
};
class SportBicycle : public Ibicycle 
{
public:
	void TwistTheWheel() override 
	{
		cout << "This is sport bicycle!" << endl;
	}
	void Ride() override 
	{
		cout << "I have started riding a bicycle!!!" << endl;
	}
};
int main()
{
	Human human;
	//Simple test;
	SuperBicycle sb;
	SportBicycle spb;
	human.Use(sb);

	cout << endl << endl;
	Human rider;
	rider.Use(spb);
	
}
