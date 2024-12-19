#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i)
    {
        if (seen.find(A[i]) != seen.end())
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
            seen.insert(A[i]);
        }
    }
    return 0;
}
