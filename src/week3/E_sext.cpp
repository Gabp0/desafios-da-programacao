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
    cin >> n >> ws;
    vector<ll> s(n);
    for (auto &i : s)
    {
        cin >> i;
    }
    sort(s.begin(), s.end());

    vector<ll> ab;
    for (auto a : s)
    {
        for (auto b : s)
        {
            ab.push_back(a * b);
        }
    }

    set<ll> abc;
    map<ll, ll> abcR;
    for (auto i : ab)
    {
        for (auto b : s)
        {
            ll v = i + b;
            auto fi = abc.find(v);
            if (fi == abc.end())
            {
                abc.insert(v);
                abcR[v] = 1;
            }
            else
            {
                abcR[v] += 1;
            }
        }
    }

    ll ss = 0;
    for (auto d : s)
    {
        if (d == 0)
        {
            continue;
        }

        for (auto e : s)
        {
            for (auto f : s)
            {
                ll v = (d * f) + (d * e);
                auto it = abc.find(v);
                if (it != abc.end())
                {
                    ss += abcR[v];
                }
            }
        }
    }

    cout << ss << endl;
}