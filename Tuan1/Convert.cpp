// C++
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    if (s.size() != 8 || s[2] != ':' || s[5] != ':')
    {
        cout << "INCORRECT" << std::endl;
        return 0;
    }
    string hh_str = s.substr(0, 2);
    string mm_str = s.substr(3, 2);
    string ss_str = s.substr(6, 2);
    int hh, mm, ss;
    istringstream(hh_str) >> hh;
    istringstream(mm_str) >> mm;
    istringstream(ss_str) >> ss;
    if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59)
    {
        std::cout << "INCORRECT" << std::endl;
        return 0;
    }
    int total_seconds = hh * 3600 + mm * 60 + ss;
    cout << total_seconds << std::endl;
    return 0;
}
