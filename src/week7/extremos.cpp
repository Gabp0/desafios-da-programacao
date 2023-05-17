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

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
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

        // if (ax == bx)
        // {
        //     cout << abs(ay - by) + 1 << "\n";
        //     continue;
        // }
        // else if (ay == by)
        // {
        //     cout << abs(ax - bx) + 1 << "\n";
        //     continue;
        // }

        ll u = abs(by - ay);
        ll b = abs(bx - ax);

        cout << gcd(u, b) + 1 << "\n";
    }
}