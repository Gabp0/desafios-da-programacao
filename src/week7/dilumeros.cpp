#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define edge pair<ll, ll>
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
    cout << endl;
}

const ll M = 1e9 + 7;
ll fast_pow(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    ll res = fast_pow(a, b / 2);
    res = (res * res) % M;
    if (b % 2)
        res = (res * a) % M;
    return res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n < 10)
        {
            cout << n << '\n';
            continue;
        }

        ll d = (fast_pow(10, n / 9) - 1) + (fast_pow(10, n / 9) * (n % 9));
        cout << d % M << '\n';
    }
}