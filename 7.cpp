#include <iostream>

//C++的运算符重载：

class Date
{
public:
    Date(int year = 2006, int month = 1, int day = 5)
    {
        _year = year;
        _month = month;
        _day = day;
    }
//private:
    int _year;
    int _month;
    int _day;
};

bool operator<(const Date& d1, const Date& d2)
{
    if(d1._year < d2._year)
    {
        return true;
    }
    else if(d1._year == d2._year && d1._month < d2._month)
    {
        return true;
    }
    else if(d1._year == d2._year && d1._month == d2._month && d1._day < d2._day)
    {
        return true;
    }
    else
    return false;
}

int main()
{
    Date a1(2025, 3, 23);
    Date a2(2005, 7, 6);
    Date d1(a1);

    //拷贝构造：
    Date d2 = a1;
    //赋值运算符的重载：
    a1 = a2;

    int i = 2, j = 1;
    //内置类型系统可以直接比较，因为比较简单
    bool ret1 = i < j;
    std::cout << ret1 << std::endl;

    //自己定义的类要自己比较
    bool ret2 = operator<(a1,a2);
    std::cout << ret2 << std::endl;
    //或者也可以这样写
    bool ret3 = a1 < a2;

    return 0;
}