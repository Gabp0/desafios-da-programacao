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
    ll n, h;
    cin >> n >> h;
    vector<ll> p(n);
    ll tpls = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        if (h <= 0)
        {
            for (ll j = i; j >= 0; j--)
            {
                if (p[j] > p[i])
                {
                    tpls++;
                }
            }
        }
        h--;
        //print(p);
    }
    cout << tpls << "\n";
}