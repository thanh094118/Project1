// C++
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    char term;
    cin >> term;
    string truyvan;
    while (cin >> truyvan)
    {
        if (truyvan == "***")
            break;
        if (truyvan == "find-max")
        {
            cout << *max_element(s.begin(), s.end()) << endl;
        }
        else if (truyvan == "find-min")
        {
            cout << *min_element(s.begin(), s.end()) << endl;
        }
        else if (truyvan == "sum")
        {
            cout << accumulate(s.begin(), s.end(), 0) << endl;
        }
        else if (truyvan == "find-max-segment")
        {
            int i, j;
            cin >> i >> j;
            cout << *max_element(s.begin() + (i - 1), s.begin() + j) << endl;
        }
    }
    return 0;
}
