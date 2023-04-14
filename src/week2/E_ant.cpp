#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
using ull = unsigned long long;
using ull = long long;
using ld = long double;
long long pinf = 9223372036854775807;
long long minf = -9223372036854775807;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ull t;
    cin >> t >> ws;
    while (t--)
    {
        ull l, n;
        cin >> l >> n;
        vector<ull> v(n);
        for (auto &x : v)
        {
            cin >> x;
        }

        ull mi_t = minf;
        ull ma_t = minf;
        for (auto x : v)
        {
            ull c = min(x, l - x);
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