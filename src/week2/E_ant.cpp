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
    ll t;
    cin >> t >> ws;
    while (t--)
    {
        ll l, n;
        cin >> l >> n;
        vector<ll> v(n);
        for (auto &x : v)
        {
            cin >> x;
        }

        ll mi_t = minf;
        ll ma_t = minf;
        for (auto x : v)
        {
            ll c = min(x, l - x);
            if (c > mi_t)
            {
                mi_t = c;
            }

            c = max(x, l - x);
            if (c > ma_t)
            {
                ma_t = c;
            }
        }

        cout << mi_t << " " << ma_t << "\n";
    }
}