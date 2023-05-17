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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll t;
    cin >> t;
    while (t--)
    {
        ll ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;

        if (ax == bx)
        {
            cout << abs(ay - by) + 1 << "\n";
            continue;
        }
        else if (ay == by)
        {
            cout << abs(ax - bx) + 1 << "\n";
            continue;
        }

        double a = (double)(by - ay) / (double)(bx - ax);
        double b = (double)(ay * bx - by * ax) / (double)(bx - ax);

        ll points = 0;
        for (ll i = min(ax, bx); i <= max(ax, bx); i++)
        {
            if (abs(a * i + b - floor(a * i + b)) < 1e-9)
            {
                points++;
            }
        }

        cout << points << endl;
    }
}