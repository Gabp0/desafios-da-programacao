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

    // code
    ull n, m, e, j;
    vector<ull> a;
    vector<ull> b;

    while (cin >> n >> ws)
    {
        m = n >> 1;

        for (int i = 0; i < n; i++)
        {
            cin >> j >> ws;
            a.push_back(j);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> j >> ws;
            b.push_back(j);
        }

        e = 0;
        for (int i = 0; i < m; i++)
        {
            e += abs((a.at(i) + a.at(n - i - 1)) - b[i]);
        }
        cout << e << "\n";

        a.clear();
        b.clear();
    }
}