#include <iostream>

//类的默认成员函数：
//--------------------------------------------------


using namespace std;


//需要析构函数来free掉动态分配的内存空间；
// class Stack
// {
// };
//日期类无需析构；栈类需要；
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

    //析构函数的使用，无返回值，无参数；
    //函数名是在类名前加一个'~'；
    ~Date()
    {
        //析构函数会在对象生命周期结束时自动调用；
        std::cout << "~Date" << std::endl;
    }

    //拷贝构造函数
    //第一个参数是自身类型的引用；
    Date(const Date& d)//必须是自身类类型的*引用*，不能传值传参(eg.Date d是错误的，会报错)；
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

private:
    int _year;
    int _month;
    int _day;
};

//调用此函数时要先调用拷贝构造函数；
void func(Date d)
{}


// int main()
// {
//     Date a1;//无参数时不能加"()"；
//     Date a2(2025, 3, 5);    
//     Date a3(a2);
//     a1.print();
//     a2.print();
//     a3.print();

//     //顺序：1.Date(Date& d);2.void func(Date d);
//     func(a3);
//     return 0;
// }


