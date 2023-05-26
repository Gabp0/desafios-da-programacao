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

vector<vector<ll>> g;
ll n;

int minDistance(vector<ll> dist, vector<bool> sptSet)
{
  
    ll min = pinf, min_index;
  
    for (ll v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

vector<ll> dijkstra(ll src)
{
    vector<ll> dist(n); 
    vector<bool> sptSet(n);
    for (ll i = 0; i < n; i++)
        dist[i] = pinf, sptSet[i] = false;
  
    dist[src] = 0;
  
    for (ll count = 0; count < n - 1; count++) {

        int u = minDistance(dist, sptSet);
  
        sptSet[u] = true;
  
        for (ll v = 0; v < n; v++)
            if (!sptSet[v] && g[u][v]
                && dist[u] != pinf
                && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }
  
    return dist;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll m, c, k;
    cin >> n >> m >> c >> k;
    g = vector<vector<ll>>(n, vector<ll>(n, pinf));
    while (m--)
    {
        ll u, v, p;
        cin >> u >> v >> p;
        g[u][v] = p;
        g[v][u] = p;
    }
    vector<ll> dist = dijkstra(k);
}