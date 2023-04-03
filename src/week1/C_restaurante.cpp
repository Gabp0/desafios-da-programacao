#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, e, s, c = 0, a = 0;
    cin >> n >> ws;
    ll t = n;

    vector<pair<ll, ll>> es;

    while (t--)
    {
        cin >> e >> s >> ws;
        es.push_back({e, 1});
        es.push_back({s, -1});
    }

    sort(es.begin(), es.end(), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.first < b.first; });

    for (ll i = 0; i < (2 * n); i++)
    {
        c += es[i].second;
        a = max(a, c);
    }

    cout << a << "\n";
}