#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
	int vecSize = 10;
	srand(unsigned(time(NULL)));
	vector<int> vek = {1,5,9,7,9,5,7,5,6};
	for (vector<int> ::iterator it = vek.begin();it != vek.end();++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	vector<int>::iterator it = vek.begin();
	vek.insert(it+4, 499);
	for (vector<int> ::iterator i = vek.begin(); i != vek.end(); ++i)
	{
		cout << *i << ' ';
	}
	

	return 0;
}

