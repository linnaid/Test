#include <iostream>

using namespace std;

class Date
{
public:
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

private:
    int _year;
    int _month;
    int _day;
};