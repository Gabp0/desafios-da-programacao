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
    for (ll i = 0; i < t; i++)
    {
        string s;
        cin >> s;

        ll g = 0;
        us c = 0;
        for (auto &b : s)
        {
            if (!c && (b == '_'))
            {
                g++;
                c = 3;
            }

            if (c)
            {
                c--;
            }
        }

        cout << "Caso " << i + 1 << ": " << g << "\n";
    }
}