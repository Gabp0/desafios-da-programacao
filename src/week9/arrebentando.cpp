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

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> rep;

void mark_component(ll u, ll r)
{
    if (vis[u] == true)
    {
        return;
    }
    vis[u] = true;
    rep[u] = r;
    for (int v : adj[u])
    {
        mark_component(v, r);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, m, k;
    cin >> n >> m >> k;

    adj.resize(n + 1);
    vis.resize(n + 1, false);
    rep.resize(n + 1);

    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll c = 0;
    ll max_comp = 0;
    for (ll u = 1; u < n + 1; u++)
    {
        if (vis[u] == false)
        {
            mark_component(u, u);
            c++;
            max_comp = u;
        }
    }

    while (k--)
    {
        ll a, b;
        cin >> a >> b;
        // cout << "a: " << a << " b: " << b << endl;

        adj[a].erase(remove(adj[a].begin(), adj[a].end(), b), adj[a].end());
        adj[b].erase(remove(adj[b].begin(), adj[b].end(), a), adj[b].end());

        // print(vis, "before clear");
        vis.clear();
        vis.resize(n + 1, false);
        // print(vis, "after clear");
        mark_component(a, ++max_comp);
        mark_component(b, ++max_comp);

        //print(rep, "rep ");

        ll c = 0;
        for (ll i = 1; i <= n; i++)
        {
            //cout << rep[i] << " - " << rep[i-1] << endl;
            if (rep[i] != rep[i-1])
            {
                c++;
            }
        }

        //print(rep);
        cout << c << " ";
    }
    cout << "\n";
}