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

us n;
vector<ll> av;

ll opt = pinf;

void gen(us i, vector<bool> bv)
{
    if (i == n)
    {
        // cout << "folha"
        //      << "\n";

        // // print the sequences
        // bool last = false;
        // cout << "[ ";
        // for (us i = 0; i < n; i++)
        // {
        //     if (bv[i] == !last)
        //     {
        //         cout << "] [ ";
        //     }
        //     cout << av[i] << " ";
        //     last = bv[i];
        // }
        // cout << "]"
        //      << "\n";

        vector<ll> xs(n, 0);
        us c = 0;
        bool last = false;
        for (us i = 0; i < n; i++)
        {
            if (bv[i] == !last)
            {
                c++;
            }
            xs[c] |= av[i];
        }
        ll s = 0;
        for (auto x : xs)
        {
            // cout << x << " ";
            s ^= x;
        }
        PN;
        if (s < opt)
        {
            opt = s;
        }
        return;
    }

    gen(i + 1, bv);
    if (i > 0)
    {
        bv[i] = true;
        gen(i + 1, bv);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code

    cin >> n;
    av.resize(n);
    for (auto &a : av)
    {
        cin >> a;
    }

    vector<bool> bv(n, false);
    gen(0, bv);
    cout << opt;
    PN;
}