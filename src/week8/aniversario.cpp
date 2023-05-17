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

ll explore(ll u)
{
    visited[u] = true;
    ll c = 1;
    for (ll v : adj[u])
        if (!visited[v])
            c += explore(v);
    return c;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    visited = vector<bool>(n, false);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll components = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components++;
            explore(i);
        }
    }

    cout << components << "\n";
    // print(visited, "visited");
}