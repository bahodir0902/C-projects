#include <iostream>
using namespace std;

class shape 
{
public:
	virtual void area() = 0;
	virtual void area(double, double) = 0;
	virtual void area(int) = 0;
	virtual void area(double) = 0;
	virtual void area(int,int) = 0;
};

class rectangle : public shape
{
public:
	void area(double a, double b) override
	{
		cout << "Rectangle Area: " << a * b << endl;
	}
};

class square : public shape 
{

public:
	void area(int a) 
	{
		cout << "Square Area: " << a * a << endl;
	}
};

class circle : public shape 
{
public:
	void area(double r) 
	{
		cout << "Circle Area: " << 3.14 * r * r << endl;
	}
};

class triangle : public shape {
public:
	void area(int a, int b) 
	{
		cout << "Triangle Area: " << 0.5 * a * b << endl;
	}
};

int main()
{
	rectangle r;
	r.area(10, 20);
	return 0;
}

