#include <iostream>
#include <ctime>
using namespace std;

class Points {
private:
    int x, y;
public:
    Points()
    {
        x = 0;
        y = 0;
    }
    Points(int valueX, int valueY)
    {
        this->x = valueX;
        this->y = valueY;
    }
    int GetX()
    {
        return x;
    }
    int GetY() 
    {
        return y;
    }
    bool operator ==(const Points& other)
    {
        if (this->x == other.x && this->y == other.y)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    void showValues() 
    {
        cout << x << ' ' << y << endl;
    }
    Points operator + (const Points &other)
    {
        Points newObj;
        newObj.x = this->x + other.x;
        newObj.y = this->y + other.y;
        return newObj;
    }
    Points & operator ++() // prefix increment overloading
    {
        this->x = this->x+1;
        this->y = this->y+1;
        return *this;
    }
    Points& operator ++(int value)  // postfix increment overloading, however we do'nt give any parameter here!
    {
        this->x = this->x + 1;
        this->y = this->y + 1;
        return *this;
    }
    Points& operator --() // prefix decrement overloading
    {
        this->x = this->x - 1;
        this->y = this->y - 1;
        return *this;
    }
    Points& operator --(int value)  // postfix decrement overloading, however we do'nt give any parameter here!
    {
        this->x = this->x - 1;
        this->y = this->y - 1;
        return *this;
    }
};
class test 
{
private:
    int *arr;
    int Size;
    bool alreadyThere = false;
    int randomValue;
public:
    test(int size, int &valueEnd) 
    {
        cout << "Simple constructor has been called" << ' ' << this << endl;
        this->Size = size;
        this->arr = new int[size];
        if(valueEnd >= size)
        {
            for (int i = 0; i < size; )
            {
                randomValue = rand() % valueEnd;
                alreadyThere = false;
                for (int j = 0; j < i; j++)
                {
                    if (arr[j] == randomValue)
                    {
                        alreadyThere = true;
                        break;
                    }
                }
                if (!alreadyThere)
                {
                    arr[i] = randomValue;
                    i++;
                }
            }
        }
        else
        {
            cout << "Critical error! Try again re-entering valueEnd more than actual array size!" << endl << endl;;
        }
        
        
    }
   test &operator = (const test& other)
    {
        cout << "operator = overloaded!" << ' ' << this << endl;
        this->Size = other.Size;
        if (this->arr != nullptr) 
        {
            delete[] this->arr;
        }
        this->arr = new int[other.Size];

        for (int i = 0; i < other.Size; i++)
        {
            this->arr[i] = other.arr[i];
        }
        return *this;
    }
   
    void showArray(int size) 
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    test(const test& other)
    {
        cout << "The copy construcotr has been called" << ' ' << this << endl;
        this->Size = other.Size;
        this->arr = new int[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    int& operator[](int index) 
    {
        return arr[index];
    }

    ~test()
    {
        cout << "Destructor has been called" << ' ' << this << endl;
        arr = nullptr;
        delete[] arr;
    }
};


int  main()
{
    //static int x = 2;
    
    
    
    
    int value = 20;
    srand(time(NULL));

    test a(value, value);
    a.showArray(value);
    cout << endl << a[17] << endl;
   /* test b(a);
    b.showArray(value);
    
    test c(value, value);
    c.showArray(value);

    c = a = b;
    c.showArray(value);*/

    /*Points obj(8, 6);
    Points obj1(4,3);
    //obj.Set(4, 9);
    bool result = obj == obj1;
    cout << result << endl;;

    Points obj2 = obj + obj1;
    obj2++;
    obj2.showValues();
    Points q(18,34);
    ++q;
    q.showValues();
    Points temp = obj2 + q;
    temp--;
    temp.showValues();*/

    return 0;
}
