// C++
// C++
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    if (sum % 2 == 0)
    {
        count++;
    }
    for (int i = k; i < n; i++)
    {
        sum = sum - a[i - k] + a[i];
        if (sum % 2 == 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
