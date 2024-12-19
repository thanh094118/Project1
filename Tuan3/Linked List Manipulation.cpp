// C++
#include <bits/stdc++.h>
#include <list>
#include <algorithm>

using namespace std;
bool exists(list<int> &lst, int key)
{
    return find(lst.begin(), lst.end(), key) != lst.end();
}
int main()
{
    int n;
    cin >> n;
    list<int> lst;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        lst.push_back(x);
    }

    string command;
    while (cin >> command && command != "#")
    {
        if (command == "addlast")
        {
            int k;
            cin >> k;
            if (!exists(lst, k))
            {
                lst.push_back(k);
            }
        }
        else if (command == "addfirst")
        {
            int k;
            cin >> k;
            if (!exists(lst, k))
            {
                lst.push_front(k);
            }
        }
    }
}
}
else if (command == "addbefore")
{
    int u, v;
    cin >> u >> v;
    if (exists(lst, v) && !exists(lst, u))
    {
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (*it == v)
            {
                lst.insert(it, u);
                break;
            }
        }
    }
}
else if (command == "remove")
{
    int k;
    cin >> k;
    lst.remove(k);
}
else if (command == "reverse")
{
    lst.reverse();
}
}

for (auto it = lst.begin(); it != lst.end(); ++it)
{
    if (it != lst.begin())
        cout << " ";
    cout << *it;
}
cout << endl;

return 0;
}