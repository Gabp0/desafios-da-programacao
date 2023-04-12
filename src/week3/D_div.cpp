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

ll opt = pinf;

void gen(vector<vector<ll>> ss, vector<ll> ps)
{
    if (ps.empty())
    {
        ll xxor = 0;
        cout << "opt" << endl;
        for (auto s : ss)
        {
            if (s.empty())
            {
                continue;
            }
            ll cor = 0;
            for (auto c : s)
            {
                cout << c << " ";
                cor |= c;
            }
            cout << endl;
            xxor &= cor;
        }

        opt = min(xxor, opt);

        return;
    }

    ll e = ps.back();
    ps.pop_back();
    for (auto &s : ss)
    {
        s.push_back(e);
        if (is_sorted(s.rbegin(), s.rend()))
        {
            gen(ss, ps);
        }
        s.pop_back();
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    us n;
    cin >> n;
    vector<ll> av(n);
    for (auto &a : av)
    {
        cin >> a;
    }
    av.reserve(n);

    vector<vector<ll>> ss(n);
    gen(ss, av);
    cout << opt;
    PN;
}