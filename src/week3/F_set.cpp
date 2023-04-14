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
    ll n;
    cin >> n >> ws;
    vector<ll> ss(n);
    for (auto &i : ss)
    {
        cin >> i;
    }
    sort(ss.begin(), ss.end());

    set<ll> rc;
    for (us i = 1; i < n - 1; i++)
    {
        ll d = ss[i] / ss[i - 1];
        if ((ss[i + 1] % d) == 0)
        {
            rc.insert(d);
        }
    }

    set<ll> cs;
    for (auto r : rc)
    {
        vector<ll> pg1(n + 1);
        pg1[0] = (ss.front() > 1) ? ss.front() / r : 1;
        for (us i = 1; i < n + 1; i++)
        {
            pg1[i] = pg1[i - 1] * r;
        }

        vector<ll> pgn(n + 1);
        pgn[0] = ss.front();
        for (us i = 1; i < n + 1; i++)
        {
            pgn[i] = pgn[i - 1] * r;
        }

        vector<ll> diff(n + 1);
        auto it = set_difference(pg1.begin(), pg1.end(), ss.begin(), ss.end(), diff.begin());
        diff.resize(it - diff.begin());
        if (diff.size() == 1)
        {
            cs.insert(diff[0]);
        }

        diff.clear();
        diff.resize(n + 1);
        it = set_difference(pgn.begin(), pgn.end(), ss.begin(), ss.end(), diff.begin());
        diff.resize(it - diff.begin());
        if (diff.size() == 1)
        {
            cs.insert(diff[0]);
        }
    }

    for (auto c : cs)
    {
        cout << c << "\n";
    }
}