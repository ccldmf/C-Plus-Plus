/*************************************************
º¯ÊıÖ¸ÕëÊ¾Àı
*************************************************/
#include<iostream>

double betsy(int);
double pam(int);

void estimate(int lines,double (*pf) (int));

int main()
{
    using namespace std;
    int code;
    cout << "How many lines of code do you need?";
    cin >> code;
    cout << "Here's Betsy's estimate:" << endl;
    estimate(code, betsy);
    cout << "Here's Pam's estimate:" << endl;
    estimate(code, pam);
    return 0;
}

double betsy(int lines)
{
    return 0.05 * lines;
}

double pam(int lines)
{
    return 0.03 * lines + 0.0004 * lines * lines;
}

void estimate(int lines, double (*pf) (int))
{
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hours(s)" << endl;
}