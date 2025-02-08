#include <iostream>
using namespace std;

class Array
{
	int Balance_amount; // this is size of array
	int* AccountNumber; // this is array itself
public:
	Array(int size)
	{
		this->Balance_amount = size;
		AccountNumber = new int[this->Balance_amount];
	}
	Array(Array obj, int size)
	{
		this->Balance_amount = obj.Balance_amount;
	}
	Array(int size, Array obj)
	{
		this->Balance_amount = obj.Balance_amount;
	}
	void setSize(int size)
	{
		this->Balance_amount = size;
	}
	int getSize()
	{
		return this->Balance_amount;
	}
	// this is my copy constructor
	Array(const Array& obj)
	{
		this->Balance_amount = obj.Balance_amount;
		AccountNumber = new int[this->Balance_amount];
		for (int i = 0; i < this->Balance_amount; i++)
		{
			AccountNumber[i] = obj.AccountNumber[i];
		}
	}
	// overloading assigment operator, without this, my code worked, but crashed
	Array& operator=(const Array& obj)
	{
		if (this != &obj)
		{
			delete[] AccountNumber;
			this->Balance_amount = obj.Balance_amount;
			AccountNumber = new int[this->Balance_amount];
			for (int i = 0; i < this->Balance_amount; ++i)
			{
				AccountNumber[i] = obj.AccountNumber[i];
			}
		}
		return *this;
	}
	friend void operator>>(istream&, Array&);
	friend void operator<<(ostream&, Array&);
	friend Array operator *(int a, const Array&);
	friend Array operator *(const Array&, int b);

	~Array()
	{
		delete[] AccountNumber;
	}
};

void operator>>(istream& in, Array& obj)
{
	for (int i = 0; i < obj.Balance_amount; ++i)
	{
		cout << "Enter " << i + 1 << " element:" << endl;
		in >> obj.AccountNumber[i];
	}
}
void operator<<(ostream& out, Array& obj)
{
	for (int i = 0; i < obj.Balance_amount; ++i)
	{
		out << obj.AccountNumber[i] << ' ';
	}
}
Array operator*(int a, const Array& b)
{
	Array c(b.Balance_amount);
	for (int i = 0; i < b.Balance_amount; i++)
	{
		c.AccountNumber[i] = a * b.AccountNumber[i];
	}
	return c;
}
Array operator*(const Array& a, int b)
{
	Array c(a.Balance_amount);
	for (int i = 0; i < a.Balance_amount; i++)
	{
		c.AccountNumber[i] = a.AccountNumber[i] * b;
	}
	return c;
}
int main()
{
	Array a(10);
	Array b(a); // this mean we go to directly to COPY CONSTRUCTOR function
	cout << "Enter " << a.getSize() << " elements for array a: " << endl;
	cin >> a;
	cout << endl << "Your 'a' array elements are: " << endl;
	cout << a;
	cout << endl;
	Array n(10);
	Array m(10);
	n = 2 * a; // overloaded = operator and * operator
	m = a * 3; // overloaded = operator and * operator
	cout << "New 'n' array multiplied by 2: " << endl;
	cout << n;
	cout << endl;
	cout << "New 'm' array multiplied by 3: " << endl;
	cout << m;
	cout << endl;

	return 0;
}
