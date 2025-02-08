#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string path = "MyExample.txt";
    ofstream example;
    example.open(path);
    if (example.is_open()) 
    {
        cout << "File opened succesfully!" << endl;
        string data; cout << "Enter please some data to file " << path << endl;
        cin >> data;
        //example << "File opened succesfully via " << path << " file" << endl;
        example << data;
    }
    else 
    {
        cout << "Error while opening " << path << " file" << endl;
    }
    example.close();

    cout << endl << endl;

    ifstream input;
    input.open(path);
    if (input.is_open())
    {
        cout << "File " << path << " opened succesfully! " << endl;
        char ch;
        while (input.get(ch)) 
        {
            input >> ch;
            cout << ch;
        }
    }
    else
    {
        cout << "Error while opening a file " << path << endl;
    }
    input.close();
}

