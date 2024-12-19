// C++
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (delta == 0)
    {
        double x0 = -b / (2 * a);
        cout << fixed << setprecision(2) << x0 << endl;
    }
    else
    {
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        if (x1 > x2)
        {
            swap(x1, x2);
        }
        cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
    }
    return 0;
}
