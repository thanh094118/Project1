// C++
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string text;
    while (getline(cin, text))
    {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = toupper(text[i]);
        }
        cout << text << endl;
    }
    return 0;
}
