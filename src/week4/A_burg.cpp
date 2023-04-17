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
    ll t;
    cin >> t;
    while (t--)
    {
        ll p, h, f, d, c;
        cin >> p >> h >> f >> d >> c;

        // AcCheddar: Custa D, e é feito com dois pães, cheddar e um hambúrguer de carne.
        // AcChicken: Custa C, e é feito com dois pães e um filete de frango.

        ll profit = 0;
        if (d > c)
        {
            while (h && p > 1)
            {
                profit += d;
                h--;
                p -= 2;
            }
            while (f && p > 1)
            {
                profit += c;
                f--;
                p -= 2;
            }
        }
        else
        {
            while (f && p > 1)
            {
                profit += c;
                f--;
                p -= 2;
            }
            while (h && p > 1)
            {
                profit += d;
                h--;
                p -= 2;
            }
        }
        cout << profit << "\n";
    }
}