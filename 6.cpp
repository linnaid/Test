#include <iostream>
#include <cstring>

typedef int STDateType;

//栈不能用系统默认生成的拷贝构造函数，因为有指针存在；
//所以栈用深拷贝；
class Stack
{
    public:
    Stack(int n = 4)
    {
        _a = (STDateType*)malloc(sizeof(STDateType) * n);
        if(_a == nullptr)
        {
            perror("malloc申请空间失败\n");
            return;
        }
        _capacity = n;
        _top = 0;
    }

    Stack(const Stack& st)
    {
        _a = (STDateType*)malloc(sizeof(STDateType) * st._top);
        if(_a == nullptr)
        {
            perror("malloc申请空间失败\n");
            return;
        }
        memcpy(_a, st._a, sizeof(STDateType) * st._top);
        _top = st._top;
        _capacity = st._capacity;
    }

    ~Stack()
    {
        std::cout << "~Stack()" << std::endl;
    }

    private:
    int* _a;
    int _capacity;
    int _top;
};


int main()
{
    Stack a1(7);
    Stack a2(a1);
    return 0;
}