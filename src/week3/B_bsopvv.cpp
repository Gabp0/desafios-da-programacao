#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define PN cout << "\n"
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
    ll qn = n * n;

    ll tt = 0;
    for (ll a = 1; a <= n / 3; a++)
    {
        for (ll b = a; b <= ((n - a) << 2); b++)
        {
            ll c = n - b - a;
            if (c < b)
            {
                break;
            }
            if (((a * a + b * b + c * c) <= qn) && (a + b + c == n))
            {
                tt++;
            }
        }
    }
    cout << tt;
    PN;
}