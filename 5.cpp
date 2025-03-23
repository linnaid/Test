#include <iostream>

using namespace std;

class Date
{
public:
    //构造函数的使用，无返回值，函数名与类名相同；
    Date()
    {
        _year = 2025;
        _month = 1;
        _day = 21;
    }
    
    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }

     void print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date a1;
    Date a2(2025, 3, 5);
    a1.print();
    a2.print();
    return 0;
}