// C++
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.length() != 10)
    {
        cout << "INCORRECT" << endl;
        return 0;
    }
    if (s[4] != '-' || s[7] != '-')
    {
        cout << "INCORRECT" << endl;
        return 0;
    }
    string year_str = s.substr(0, 4);
    string month_str = s.substr(5, 2);
    string day_str = s.substr(8, 2);
    int year, month, day;
    stringstream(year_str) >> year;
    stringstream(month_str) >> month;
    stringstream(day_str) >> day;
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        cout << "INCORRECT" << endl;
        return 0;
    }
    cout << year << " " << month << " " << day << endl;
    return 0;
}
