/*************************************************
函数指针示例
C++ Primer Plus(P252/10)
*************************************************/
#include<iostream>
using namespace std;

double calculate(double val1,double val2,double (*pf)(double,double))
{
    return (*pf)(val1,val2);
}

double add(double value1,double value2)
{
    return value1 + value2;
}

double sub(double value1,double value2)
{
    return value1 - value2;
}

double mean(double value1,double value2)
{
    return (value1 + value2) * 2;
}

int main()
{
    double(*pf[3]) (double, double) = { add,sub,mean };     // 函数指针数组，分别指向三个不同的函数
    const char(*String[3]) = { "Add","Sub","Mean" };
    double value1, value2;
    int i;
    cout << "Enter pairs of numbers (q to quit):";
    while (cin >> value1 >> value2)
    {
        for (i = 0; i < sizeof(pf) / sizeof(pf[0]); i++)
        {
            cout << String[i] << "=" <<calculate(value1, value2, pf[i]) << endl;
        }
        cout << "Enter pairs of numbers (q to quit):";
    }
    system("pause");
    return 0;
}

