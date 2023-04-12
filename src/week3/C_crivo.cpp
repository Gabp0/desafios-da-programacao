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

ll a, b, si;

void gen(vector<ll> s, vector<ll> pn)
{
    if (pn.empty())
    {
        if (!s.empty())
        {
            ll cpn = 1;
            for (auto p : s)
            {
                cpn *= p;
            }
            ll f = (a % cpn == 0) ? a : a + (cpn - a % cpn);
            ll l = (b % cpn == 0) ? b : b - (b % cpn);
            ll mn = ((l - f) / cpn) + 1;
            si -= ((s.size() % 2) == 1) ? mn : -mn;
        }

        return;
    }

    ll c = pn.back();
    pn.pop_back();
    gen(s, pn);
    s.push_back(c);
    gen(s, pn);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    us n;

    cin >> a >> b;
    cin >> n;

    vector<ll> pn(n);
    for (auto &p : pn)
    {
        cin >> p;
    }

    si = b - a + 1;

    vector<ll> s;
    gen(s, pn);

    cout << si;
    PN;
}