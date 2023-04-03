#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
using ull = unsigned long long;
using ll = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }

    vector<bool> r(n);
    for (auto &&x : r)
    {
        x = false;
    }

    ll rn = 0;
    for (auto &x : v)
    {
        if (r[x - 1])
        {
            r[x] = true;
        }
        else
        {
            r[x - 1] = true;
            r[x] = true;
            rn++;
        }
    }

    cout << rn << "\n";
}