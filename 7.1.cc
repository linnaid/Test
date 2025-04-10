#include <iostream>
#include <cassert>

//C++的运算符重载：
//一般类内的变量均为私有，所以要把运算符重载写入类内；


//重载操作符必须有一个类类型的参数
//错误-eg.
// int operator+(int x, int y)
// {
//     return x - y;
// }



class Date
{
public:
    Date(int year = 2006, int month = 1, int day = 5)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void print()
    {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

    //注意这样写的话，有三个参数被传入，因为类内函数有隐含的this指针传入；
    //bool operator<(const Date& d1, const Date& d2)
    //只用传入一个参数即可；
    bool operator<(const Date& x)
    {
        if(_year < x._year)
        {
            return true;
        }
        else if(_year == x._year && _month < x._month)
        {
            return true;
        }
        else if(_year == x._year && _month == x._month && _day < x._day)
        {
            return true;
        }
        else
        return false;
    }


    int GetMonthDay(int year, int month)
    {
        assert(month > 0 && month < 13);
        static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if((year % 4 == 0 && year % 100 != 0) && (month == 2))
        {
            return 29;
        }
        else
        {
            return monthDayArray[month];
        }
    }

    Date operator+=(const Date& x)
    {

    }

    //运算符重载的前置++和后置++：

    //d1++;
    //d1.operator++();
    //出了函数作用域后d1还在，所以用引用返回(&);
    Date& operator++()
    {
        *this += 1;
        return;

    }

    //++d1;
    //d1.operator++(1)
    Date operator++(int i)
    {
        //后置++返回++之前的值
        //所以调用拷贝构造；
        Date tmp(*this);

        *this += 1;

        return tmp;
    }
    //赋值运算符重载：
    //用于两个已经存在的对象之间拷贝;
    void operator=(const Date& x)
    {
        _year = x._year;
        _month = x._month;
        _day = x._day;
    }

    bool operator==(const Date* x)
    {
        return _day == x->_day && _month == x->_month && _year == x->_year;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date a1(2025, 3, 23);
    Date d1(a1);
    Date a2(2005, 7, 6);

    //赋值运算符重载：
    d1 = a2;
    //或者：
    d1.operator=(a2);


    //自己定义的类要自己比较
    bool ret2 = a1.operator<(a2);
    std::cout << ret2 << std::endl;
    //或者也可以这样写:
    bool ret3 = a1 < a2;

    return 0;
}
