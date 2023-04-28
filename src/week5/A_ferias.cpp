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
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> v(n + 1);
    for (auto &x : v)
    {
        cin >> get<0>(x) >> get<1>(x) >> get<2>(x);
    }

    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0][0] = get<0>(v[0]);
    dp[0][1] = get<1>(v[0]);
    dp[0][2] = get<2>(v[0]);

    for (int i = 1; i < n; i++)
    {
        ll a = get<0>(v[i]);
        ll b = get<1>(v[i]);
        ll c = get<2>(v[i]);

        dp[i][0] = max(dp[i - 1][1] + a, dp[i - 1][2] + a);
        dp[i][1] = max(dp[i - 1][0] + b, dp[i - 1][2] + b);
        dp[i][2] = max(dp[i - 1][0] + c, dp[i - 1][1] + c);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
}