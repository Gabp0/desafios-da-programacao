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

void print(vector<bool> v, string s = "")
{
    cout << s << ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<vector<ll>> adj;
vector<bool> visited;

ll max_depth = 0;
ll max_node = 0;

ll explore(ll u, ll d)
{
    if (d > max_depth)
    {
        max_depth = d;
        max_node = u;
    }

    visited[u] = true;
    ll c = 1;
    for (ll v : adj[u])
        if (!visited[v])
            c += explore(v, d + 1);
    return c;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n;
    cin >> n;
    adj.resize(n + 1);
    visited = vector<bool>(n + 1, false);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    explore(1, 0);
    visited = vector<bool>(n + 1, false);
    explore(max_node, 0);

    cout << max_depth << "\n";
}