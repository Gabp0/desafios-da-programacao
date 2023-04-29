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
    cout << "\n";
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, k, c;
    cin >> n >> k >> c;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    vector<ll> mins(n - c + 1);
    for (ll i = 0; i < (n - c) + 1; i++)
    {
        ll cmin = 0;
        for (ll j = 0; j < c; j++)
        {
            cmin += v[i + j];
        }
        mins[i] = cmin;
    }

    while (k--)
    {
        // print(mins, "mins");
        ll cmini = min_element(mins.begin(), mins.end()) - mins.begin();
        for (ll i = cmini; i < cmini + c; i++)
        {
            v[i] = pinf;
        }

        for (ll i = 0; i < (n - c) + 1; i++)
        {
            ll cmin = 0;
            for (ll j = 0; j < c; j++)
            {
                cmin = ((v[i + j] == pinf) || (cmin == pinf)) ? pinf : (v[i + j] + cmin);
            }
            mins[i] = cmin;
        }

        // print(v, "v");
    }

    // print(v, "v");
    ll sum = 0;
    for (auto i : v)
    {
        sum += (i != pinf) ? i : 0;
    }
    cout << sum << "\n";

    // 20 2 8
    //-1907 -5882 8805 -8084 7294 -7144 -3290 -3868 55 -6183 -8487 2842 -7281 -3329 -4495 -4075 -454 9463 -4356 9504
}