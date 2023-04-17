#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define PN cout << "\n"
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using s = short;
using us = unsigned short;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n;

    map<ll, vector<ll>> ld;
    ll l, d;
    for (ll i = 0; i < n; i++)
    {
        cin >> l >> d;
        ld[d].push_back(l);
    }

    for (auto &v : ld)
    {
        sort(v.yy.begin(), v.yy.end());
    }

    ll td = 0;
    ll i = 0;
    for (auto &v : ld)
    {
        vector<ll> curv = v.yy;
        ll curd = v.xx;
        while (i < curd && !curv.empty())
        {
            td += curv.back();
            curv.pop_back();
            i++;
        }
    }

    cout << td << "\n";
}