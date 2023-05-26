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
// long long pinf = 9223372036854775807;
long long pinf = 1987654321987654321;
long long minf = -9223372036854775807;

void print(vector<vector<ll>> m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++)
        {
            if (m[i][j] >= pinf)
            {
                cout << "oo ";
            }
            else
            {
                cout << setw(2) << setfill('0') << m[i][j] << " ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

void print(vector<ll> v, string s = "")
{
    cout << s << ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

ll maxel(vector<ll> v)
{
    ll m = -pinf;
    for (auto e : v)
    {
        if ((e > m) && (e < pinf))
        {
            m = e;
        }
    }
    return m;
}

ll minel(vector<ll> v)
{
    ll m = pinf;
    for (auto e : v)
    {
        if ((e < m) && (e > 0))
        {
            m = e;
        }
    }
    return m;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(n, pinf));
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        if ((d[u][v] != pinf) || (d[v][u] != pinf))
        {
            //cout << "u : "  << u << "v : " << v <<  "differ \n";
            d[u][v] = min(min(d[u][v], w), d[v][u]);
            d[v][u] = d[u][v];
        } else {
            d[u][v] = w;
            d[v][u] = w;
        }
    }

    for (ll u = 0; u < n; u++)
        d[u][u] = 0;

    for (ll m = 0; m < n; m++)
        for (ll u = 0; u < n; u++)
            for (ll v = 0; v < n; v++)
            {
                d[u][v] = min(d[u][v], d[u][m] + d[m][v]);
                //d[v][u] = d[u][v];
            }

    //print(d);

    ll min_dist = pinf;
    for (ll j = 0; j < n; j++)
    {
        ll max_distl = -pinf;
        for (ll i = 0; i < n; i++)
        {
            max_distl = max(max_distl, d[i][j]);
        }
        //cout << "mdl = " << max_distl << endl;
        min_dist = min(max_distl, min_dist);
    }

    cout << min_dist << "\n";
}