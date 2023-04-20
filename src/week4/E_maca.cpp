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

void print(vector<ll> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    PN;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    for (auto &i : p)
    {
        cin >> i;
    }
    for (auto &i : q)
    {
        cin >> i;
    }
    for (auto &i : r)
    {
        cin >> i;
    }

    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(r.rbegin(), r.rend());

    vector<ll> ord(p.begin(), p.begin() + x);
    vector<ll> ogn(q.begin(), q.begin() + y);
    ord.insert(ord.end(), ogn.begin(), ogn.end());
    sort(ord.rbegin(), ord.rend());

    ll i_wh = 0;
    while ((i_wh < r.size()) && (ord[ord.size() - 1 - i_wh] < r[i_wh]))
    {
        i_wh++;
    }

    ll gt = 0;
    for (ull i = 0; i <= (ord.size() - 1 - i_wh); i++)
    {
        gt += ord[i];
    }
    for (ll i = 0; i < i_wh; i++)
    {
        gt += r[i];
    }

    cout << gt << "\n";
}