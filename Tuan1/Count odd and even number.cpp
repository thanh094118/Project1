// C++
#include <bits/stdc++.h>
using namespace std;
#include <vector>
int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    int oddCount = 0, evenCount = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
        if (numbers[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    cout << oddCount << " " << evenCount << std::endl;

    return 0;
}
