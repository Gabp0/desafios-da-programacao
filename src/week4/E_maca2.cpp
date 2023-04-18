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
    vector<pair<char, ll>> pqr(a + b + c);
    for (ll i = 0; i < a; i++)
    {
        cin >> pqr[i].yy;
        pqr[i].xx = 'r';
    }
    for (ll i = a; i < a + b; i++)
    {
        cin >> pqr[i].yy;
        pqr[i].xx = 'g';
    }
    for (ll i = a + b; i < a + b + c; i++)
    {
        cin >> pqr[i].yy;
        pqr[i].xx = 'w';
    }

    sort(pqr.begin(), pqr.end(), [](pair<char, ll> a, pair<char, ll> b)
         { return a.yy < b.yy; });

    ll gt = 0;
    pair<char, ll> cmax;
    char lc = (x > y) ? 'r' : 'g';
    while (((x > 0) || (y > 0)) && !pqr.empty())
    {
        cmax = pqr.back();
        pqr.pop_back();

        if (cmax.xx == 'r')
        {
            if (x > 0)
            {
                gt += cmax.yy;
                x--;
                lc = 'r';
            }
        }
        else if (cmax.xx == 'g')
        {
            if (y > 0)
            {
                gt += cmax.yy;
                y--;
                lc = 'g';
            }
        }
        else if (cmax.xx == 'w')
        {
            if (x == 0)
            {
                if (y > 0)
                {
                    gt += cmax.yy;
                    y--;
                }
            }
            else if (y == 0)
            {
                if (x > 0)
                {
                    gt += cmax.yy;
                    x--;
                }
            }
            else
            {
                if (lc == 'r')
                {
                    gt += cmax.yy;
                    x--;
                }
                else
                {
                    gt += cmax.yy;
                    y--;
                }
            }
        }
    }

    cout << gt << endl;
}