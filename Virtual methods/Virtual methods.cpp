
#include <iostream>
#include <string>
using namespace std;

class Message 
{
private:
	string msg;
	char symb1, symb2;
public:
	Message(string msg) 
	{
		this->msg = msg;
	}
	virtual string GetMsg()
	{
		return msg;
	} 
};
class FigureMsg : public Message 
{
public:
	FigureMsg(string msg):Message(msg)
	{

	}
	string GetMsg() override
	{
		return "[" + ::Message::GetMsg() + "]";
	}
};
class Printer 
{
public:
	void Print(Message& msg) 
	{
		cout << msg.GetMsg() << endl;
	}
};
int main()
{

	FigureMsg test("Shut up! Go to your lessons!!!");
	Printer print;
	print.Print(test);
}
