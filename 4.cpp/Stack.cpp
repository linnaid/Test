#include "Stack.h"
#include <iostream>

using namespace std;

// void Stack::init(int c = 4)
// {
//     cin >> _a >> _b;
//     cout << _a + _b + c << endl;
// }

//不同类域可定义同名函数与变量
class Queue
{
    void init(int c = 0)
    {}
};

class num
{
    void init(int c = 0)
    {}
};

//this指针
/*
class Date
{
    int _year;
    int _month;
    int _day;

    public:
    void init(int year, int month, int day)
    {
        // cin >> year >> month >> day;
        _year = year;
        _month = month;
        _day = day;
    }

    void print()
    {
        cout << _year << " " << _month << " " << _day << endl;
    }
};

int main()
{
    Date d1;
    Date d2;
    d1.init(2025, 3, 1);
    d2.init(2025, 1, 5);

    d1.print();
    d2.print();

    return 0;
}
*/

