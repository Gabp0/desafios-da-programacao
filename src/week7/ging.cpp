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

void print(vector<vector<ll>> m, string s = "")
{
    cout << s << ":\n";
    for (auto v : m)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

const ll M = 1e9 + 7;

vector<vector<ll>> comb_table;
ll comb_min = 0;

ll comb(ll n, int k)
{
    ll res = comb_table[k - 1][n - comb_min];

    if (res == 0)
    {
        if (k == 1)
        {
            res = n;
        }
        else if (n == 0 || n == 1)
        {
            res = 1;
        }

        else if (n == comb_min)
        {
            res = (comb(n, k - 1) * (n - (k - 1))) % M;
        }
        else
        {
            if (n > 3)
            {
                res = ((comb(n - 1, k) * n) / (n - k)) % M;
            }
            else
            {
                res = (comb(n, k - 1) * (n - (k - 1))) % M;
            }
        }

        comb_table[k - 1][n - comb_min] = res;
    }

    return res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, c;
    cin >> n >> c;

    vector<ll> b(n);
    ll max_b = 0;
    ll min_b = pinf;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        max_b = max(max_b, b[i]);
        min_b = min(min_b, b[i]);
    }

    vector<cord> cr(c);
    vector<ll> cr_num(n, 0);
    for (ll i = 0; i < c; i++)
    {
        cin >> cr[i].xx >> cr[i].yy;
        cr[i].xx--;
        cr[i].yy--;
        cr_num[cr[i].yy]++;
    }

    comb_table = vector<vector<ll>>(n, vector<ll>(max_b - min_b + 1, 0));
    comb_min = min_b;
    comb(min_b, 1);
    // print(fact);

    ll res = 1;
    for (ll i = 0; i < n; i++)
    {
        ll tmp = comb(b[i], n - cr_num[i]);
        //print(comb_table, "comb_table");
        res = (res * tmp) % M;
    }

    cout << res << "\n";
}