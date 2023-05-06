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

void print(vector<ll> v, string s = "")
{
    cout << s << ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, m;
    cin >> n >> m;
    multiset<ll> h;
    multiset<ll, greater<ll>>::iterator lb;
    vector<ll> t(m);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        h.insert(-x);
    }
    for (auto &i : t)
    {
        cin >> i;
    }

    for (auto i : t)
    {
        lb = h.lower_bound(-i);
        if (lb != h.end())
        {
            cout << -(*lb) << "\n";
            h.erase(lb);
        }
        else
        {
            cout << "-1\n";
        }
    }
}