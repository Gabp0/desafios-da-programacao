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

ll n;
vector<vector<ll>> adj;

vector<bool> visited;
vector<ll> sbtree_s;
vector<bool> centroid_m;

ll c = 0;

void explore(ll u)
{
    visited[u] = true;
    c += 1;
    sbtree_s[u] = 1;

    for (ll v : adj[u])
    {

        if (!visited[v] && !centroid_m[v])
        {
            explore(v);
            sbtree_s[u] += sbtree_s[v];
        }
    }
}

int getCentroid(int u)
{
    bool is_centroid = true;
    visited[u] = true;
    ll hc = 0;
    for (ll v : adj[u])
        if (!visited[v] && !centroid_m[v])
        {
            if (sbtree_s[v] > (c / 2))
            {

                is_centroid = false;
            }

            if ((hc == 0) || (sbtree_s[v] > sbtree_s[hc]))
            {
                hc = v;
            }
        }

    if (is_centroid && c - sbtree_s[u] <= c / 2)
    {
        return u;
    }

    return getCentroid(hc);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    cin >> n;
    adj.resize(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited = vector<bool>(n + 1, false);
    sbtree_s = vector<ll>(n + 1, 0);
    centroid_m = vector<bool>(n + 1, false);

    explore(1);
    visited = vector<bool>(n, false);

    cout << getCentroid(1) << "\n";
}