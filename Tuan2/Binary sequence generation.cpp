// C++
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
void gn(int n)
{
    int total = 1 << n;
    for (int i = 0; i < total; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cout << ((i >> j) & 1);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    gn(n);
    return 0;
}
