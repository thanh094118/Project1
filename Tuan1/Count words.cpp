// C++
#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string text;
    int sotu = 0;
    while (getline(cin, text))
    {
        istringstream iss(text);
        string tu;
        while (iss >> tu)
        {
            sotu++;
        }
    }
    cout << sotu << endl;

    return 0;
}
