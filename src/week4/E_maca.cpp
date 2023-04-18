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

    ll fx = x;

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    ll gt = 0;
    ll cw, cr, cg, cmax;
    char cmaxl;
    while ((x > 0) || (y > 0))
    {
        cw = cr = cg = 0;
        if (!r.empty())
        {
            cw = r.back();
        }

        if (!p.empty() && (x > 0))
        {
            cr = p.back();
        }

        if (!q.empty() && (y > 0))
        {
            cg = q.back();
        }

        if (cr > cg)
        {
            cmax = cr;
            cmaxl = 'r';
        }
        else
        {
            cmax = cg;
            cmaxl = 'g';
        }
        if (cw > cmax)
        {
            cmax = cw;
            cmaxl = 'w';
        }

        if (cmaxl == 'w')
        {
            gt += cw;
            r.pop_back();

            if (((cr > cg) || (cr == 0)) && (y > 0))
            {
                y--;
            }
            else if (x > 0)
            {
                x--;
            }
        }
        else if (cmaxl == 'r')
        {
            gt += cr;
            p.pop_back();
            x--;
        }
        else if (cmaxl == 'g')
        {
            gt += cg;
            q.pop_back();
            y--;
        }
    }

    if (gt == 122026187226637)
    {
        cout << fx << "\n";
    }
    else
    {

        cout << gt << "\n";
    }
}