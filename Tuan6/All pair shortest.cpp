// C++
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> matrix = {
        {0, 9, 7, 2},
        {1, 0, 8, 3},
        {3, 2, 0, 5},
        {5, 8, 12, 0}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
            if (j < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
