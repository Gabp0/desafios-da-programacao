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

int n;
vector<int> coins = {50, 25, 10, 5, 1};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll x;
    while (cin >> x)
    {
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;

        for (auto c : coins)
        {
            for (int i = c; i <= n; i++)
            {
                dp[i] += dp[i - c];
            }
        }
        cout << dp[n] << "\n";
    }
}