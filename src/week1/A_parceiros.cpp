#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ull = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ull t;
    string x, y;
    ull fx, fy;
    cin >> t;

    while (t--)
    {
        cin >> x >> y;

        fx = x.back() - 48;
        fy = y.back() - 48;

        if (((fx + fy) % 2) == 0)
        {
            cout << "PARCEIROS\n";
        }
        else
        {
            cout << "NAO PARCEIROS\n";
        }
    }

    // code
}