// C++
#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
long long pm(long long x, long long y, long long mod)
{
    long long kq = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            kq = (kq * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return kq;
}
void gt(long long fact[], long long invFact[], int n, int mod)
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[n] = pm(fact[n], mod - 2, mod);
    for (int i = n - 1; i >= 1; --i)
    {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    long long fact[n + 1], invFact[n + 1];
    gt(fact, invFact, n, m);
    long long kq = fact[n] * invFact[k] % m * invFact[n - k] % m;
    cout << kq << endl;
    return 0;
}
