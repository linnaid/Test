#include <iostream>

using namespace std;

class Stack
{
    public:
    int a = 3;
    int e = 10;
    char b;
    private:
    int Add(int c = 1, int d = 2)
    {
        return c + d;
    }
    public:
    void Addd()
    {
        cout << Add(a,e) << endl;
    }
};

int main()
{
    Stack am;
    cin >> am.a;
    cin >> am.b;
    //cout << Add(am.a, am.b) << endl;
    //private使得这里不能访问此函数
    cout << am.a <<" " << am.b << endl;
    am.Addd();
    return 0;
}