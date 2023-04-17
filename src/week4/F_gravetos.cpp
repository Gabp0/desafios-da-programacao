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
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());

    ll m;
    if ((n % 2) == 0)
    {
        m = v[n / 2 - 1];
    }
    else
    {
        m = v[n / 2];
    }

    ll c = 0;
    for (auto x : v)
    {
        c += abs(x - m);
    }
    cout << c << "\n";
}