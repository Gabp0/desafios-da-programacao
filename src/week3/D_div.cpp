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
    us n;
    cin >> n;
    vector<ll> av(n);
    for (auto &a : av)
    {
        cin >> a;
    }

    for (us i = 0; i < n; i++)
    {
        for (us j = i; j < n; j++)
        {
            for (us k = i; k <= j; k++)
            {
                cout << av[k] << " ";
            }
            PN;
        }
    }
}