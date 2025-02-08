 

#include <iostream>
#include <cmath>
#define PI 3.1415
using namespace std;
void Calc_area(double a) 
{
	double result = PI * a * a;
	cout << "The area of a circle is: " << result << endl << endl;
}
void Calc_area(int a, int b) {
	int result = a * b;
	cout << "The area of a rectangle is: " << result << endl << endl;
}
void Calc_area(double a, double b, double c) 
{
	double half_perimeter = (a + b + c) / 2;
	double result = pow(half_perimeter * (a - half_perimeter) * (b - half_perimeter) * (c - half_perimeter), 0.5);
	cout << "The area of a triangle with different sides is: " << result << endl << endl;
}
void Calc_area(int a) 
{
	int result = a * a;
	cout << "The area of square with the side " << a << " is: " << result << endl << endl;
}
void circumference(double a) 
{
	double result = 2 * PI * a;
	cout << "The circumference of a circle is: " << result << endl << endl;
}
void circumference(int a, int b) 
{
	int result = 2 * (a + b);
	cout << "The perimeter of a rectangle is: " << result << endl << endl;
}
void circumference(int a, int b,int c) 
{
	int result = a + b + c;
	cout << "The length of sides of triangle is: " << result << endl << endl;
}
void circumference(int a) 
{
	int result = 4 * a;
	cout << "The length of sides of square is: " << result << endl << endl;
}
void max_num(int a, int b, int c) 
{
	int  max;
	if (a > b) 
	{
		if (a > c)
			max = a;
		else
			max = c;
	}
	else 
	{
		if (b > c)
			max = b;
		else
			max = c;
	}
	cout << "The maximum integer among three numbers is: " << max << endl << endl;
}
void max_num(double a, double b, double c)
{
	double  max;
	if (a > b) {
		if (a > c)
			max = a;
		else
			max = c;
	}
	else {
		if (b > c)
			max = b;
		else
			max = c;
	}
	cout << "The maximum float-point number among three numbers is: " << max << endl << endl;
}
template <typename T>
void max_num(T a, T b, T c)
{
	T  max;
	if (a > b) {
		if (a > c)
			max = a;
		else
			max = c;
	}
	else {
		if (b > c)
			max = b;
		else
			max = c;
	}
	cout << "The maximum number among three numbers is: " << max << endl << endl;
}
void display() 
{
	cout << endl << "1. Program 1 " << endl
		<< "2. Program 2 " << endl
		<< "3. Program 3 " << endl
		<< "4. Program 4 " << endl
		<< "5. Exit " << endl;
		
}
void text_area() 
{
	cout << endl << "1. 1 double number calculates the area of circle " << endl
		<< "2. 2 integers to calculate the area of rectangle " << endl
		<< "3. 3 double numbers to calculate the area of scalene triangle " << endl
		<< "4. 1 integer to calculate the area of square " << endl
		<< "5. Back to main menu" << endl;
}
void circum_text() 
{
	cout << "1. one double variable to calculate the circumference of circle " << endl
		<< "2. 2 integers to calculate the the perimeter of rectangle" << endl
		<< "3. 3 integers to calculate the length of scalene triangle " << endl
		<< "4. 1 integer to calculate the lenght of square " << endl
		<< "5. Back to main menu " << endl;
		
}
void max_text() 
{
	cout << "1.  3 integers to find the maximum number among these numbers" << endl
		<< "2. 3 double numbers to find the maximum number among these numbers " << endl
		<< "3. Back to main menu " << endl;
}
void template_text()
{
	cout << "1.Enter any variable in any type to find the maximum number " << endl
		<< "2. Back to main menu" << endl;
}
int main()
{
	int a, t = 1, u = 1, u1 = 2, u2 = 3, u3 = 4;
	double r,c,d,e,r1, l1, p1, o1,l2, p2, o2;
	int c1,d1,e1, h, g,s, h1, g1, s1, l, p, o, max1, max2, max3;
	while (t != 0) 
	{
		cout << "Enter a program you want: ";
		display();
		cin >> a;
		switch (a) 
		{
		case 1:			
			int temp;
			while (u != 0) {
				text_area();
				cin >> temp;
				switch (temp)
				{
				case 1:
					cout << "input radius: "; cin >> r;
					Calc_area(r);
					break;
				case 2:
					cout << "Enter the borders of rectangle a and b: ";
				    cin >> h >> g;
					Calc_area(h, g);
					break;
				case 3:
					cout << "enter 3 double numbers to calculate the area of scalene triangle " << endl;
					cin >> c >> d >> e;
					Calc_area(c, d, e);
					break;
				case 4:
					cout << "Enter the side of square in integer: " << endl;
					cin >> s;
					Calc_area(s);
					break;
				default:
					u = 0;
					break;
				}
			}
			break;
		case 2:
			int temp1;
			while (u1 != 0) {
				circum_text();
				cin >> temp1;
				switch (temp1)
				{
				case 1:
					cout << "input the radius of circle: "; cin >> r1;
					circumference(r1);
					break;
				case 2:
					cout << "Enter the borders of rectangle a and b: ";
					cin >> h1 >> g1;
					circumference(h1, g1);
					break;
				case 3:
					cout << "enter 3 integer numbers to calculate the length of scalene triangle " << endl;
					cin >> c1 >> d1 >> e1;
					Calc_area(c1, d1, e1);
					break;
				case 4:
					cout << "Enter the side of square in integer: " << endl;
					cin >> s1;
					circumference(s1);
					break;
				default:
					u1 = 0;
					break;
				}
			}
			break;
			
		case 3:
			int temp2;
			while (u2 != 0)
			{
				max_text();
				cin >> temp2;
				switch (temp2)
				{
				case 1:
					cout << "Enter 3 integers: "; cin >> l >> p >> o;
					max_num(l, p, o);
					break;
				case 2:
					cout << "Enter 3 float point numbers: "; cin >> l1 >> p1 >> o1;
					max_num(l1, p1, o1);
					break;
				default:
					u2 = 0;
					break;
				}
			}
			break;
		case 4:
			int temp3;
			while (u3 != 0)
			{
				template_text();
				cin >> temp3;
				switch (temp3)
				{
				case 1:
					cout << "Enter 3 numbers: "; cin >> l2 >> p2 >> o2;
					max_num<double>(l2, p2, o2);
					break;
				default:
					u3 = 0;
					break; 
				}
			}
			break;
		default:
			t = 0;
			break;
		}
	}
	return 0;
}

