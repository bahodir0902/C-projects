#include <iostream>
using namespace std;

void function() 
{
    int a, b;
    cout << "Enter Two number, remember, the first number should be more than second number: " << endl;
    cin >> a >> b;
    if (a < b) 
    {
        throw exception("First number must be more than second number!!!");
    }
    else 
    {
        cout << "Everything is okay" << endl;
    }
}
int main()
{
    //function(5, 6);
    try
    {
        function();
    }
    catch (const std::exception &ex)
    {
        cout << "Fatal Error! ";
        cout << ex.what(); 
    }
}

