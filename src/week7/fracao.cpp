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
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        vector<ll> v;

        while ((n % d) > 0)
        {
            v.push_back(n / d);
            ll a = n % d;
            n = d;
            d = a;
        }
        v.push_back(n / d);
        ll a = n % d;
        n = d;
        d = a;

        if (v.size() == 1)
        {
            cout << "[" << v[0] << "]"
                 << "\n";
            continue;
        }

        cout << "[";
        for (ll i = 0; i < v.size(); i++)
        {
            if (i == 0)
            {
                cout << v[i] << ";";
            }
            else if (i == v.size() - 1)
            {
                cout << v[i];
            }
            else
            {
                cout << v[i] << ",";
            }
        }
        cout << "]"
             << "\n";
    }
}