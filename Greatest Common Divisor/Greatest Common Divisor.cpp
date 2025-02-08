//Greatest common divisor
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


void swap(int &m, int &n)
{
    int temp = m;
    m = n;
    n = temp;
}
int gcd(int m, int n)
{
    if (m < n)
    {
        swap(m, n);
    }
    if (fmod(m,n) == 0)
    {
        return n;
    }
    return gcd(n, m % n);

}

int main()
{
    int m, n, remainder = 0;
    cout << "Enter Two numbers: " << endl;
    cin >> m >> n;
    if (m < n)
    {
        swap(m, n);
    } 
    link:
    remainder = fmod(m, n);
    if (remainder == 0) 
    {
        cout << "The greatest common divisor is: " << n << endl;;
    }
    else 
    {
        m = n;
        n = remainder;
        goto link;
    }



    cout << gcd(m, n) << ' ' << endl;

    return 0;
}

