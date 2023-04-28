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

vector<int> coins = {50, 25, 10, 5, 1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    vector<vector<ull>> dp(30001, vector<ull>(5, 0));

    ll x, y;

    for (int i = 0; i < 5; i++)
    {
        dp[0][i] = 1;
    }

    for (ll i = 1; i < 30001; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
            y = (j >= 1) ? dp[i][j - 1] : 0;
            dp[i][j] = x + y;
        }
    }

    ll n;
    while (cin >> n)
    {
        cout << dp[n][4] << "\n";
    }
}