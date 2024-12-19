#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;
struct Nut
{
    int id;
    vector<Nut *> con;
    Nut(int id) : id(id) {}
};

map<int, Nut *> cay;
Nut *goc = nullptr;

void TạoGoc(int u)
{
    if (cay.find(u) == cay.end())
    {
        goc = new Nut(u);
        cay[u] = goc;
    }
}

void Chen(int u, int v)
{
    if (cay.find(v) != cay.end() && cay.find(u) == cay.end())
    {
        Nut *nutV = cay[v];
        Nut *nutU = new Nut(u);
        nutV->con.push_back(nutU);
        cay[u] = nutU;
    }
}

void Truoc(Nut *nut)
{
    if (!nut)
        return;
    cout << nut->id << " ";
    for (Nut *con : nut->con)
    {
        Truoc(con);
    }
}

void Giua(Nut *nut)
{
    if (!nut)
        return;
    int n = nut->con.size();
    for (int i = 0; i < n / 2; ++i)
    {
        Giua(nut->con[i]);
    }
    cout << nut->id << " ";
    for (int i = n / 2; i < n; ++i)
    {
        Giua(nut->con[i]);
    }
}

void Sau(Nut *nut)
{
    if (!nut)
        return;
    for (Nut *con : nut->con)
    {
        Sau(con);
    }
    cout << nut->id << " ";
}

int main()
{
    string lenh;
    while (cin >> lenh)
    {
        if (lenh == "*")
            break;
        if (lenh == "MakeRoot")
        {
            int u;
            cin >> u;
            TạoGoc(u);
        }
        else if (lenh == "Insert")
        {
            int u, v;
            cin >> u >> v;
            Chen(u, v);
        }
        else if (lenh == "PreOrder")
        {
            if (goc)
            {
                Truoc(goc);
                cout << endl;
            }
        }
        else if (lenh == "InOrder")
        {
            if (goc)
            {
                Giua(goc);
                cout << endl;
            }
        }
        else if (lenh == "PostOrder")
        {
            if (goc)
            {
                Sau(goc);
                cout << endl;
            }
        }
    }
    return 0;
}
