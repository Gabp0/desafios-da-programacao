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

    ull n, e, s, c = 0, a = 0;
    cin >> n >> ws;
    ull t = n;

    vector<pair<ull, ull>> es;

    while (t--)
    {
        cin >> e >> s >> ws;
        es.push_back({e, 1});
        es.push_back({s, -1});
    }

    sort(es.begin(), es.end(), [](pair<ull, ull> a, pair<ull, ull> b)
         { return a.first < b.first; });

    for (ull i = 0; i < (2 * n); i++)
    {
        c += es[i].second;
        a = max(a, c);
    }

    cout << a << "\n";
}