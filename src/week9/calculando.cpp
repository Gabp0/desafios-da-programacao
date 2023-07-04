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

vector<ll> csr_cost;
vector<ll> fathers;
ll n, csr;

vector<vector<edge>> g;
// vector<ll> lot;

vector<ll> d, vis;
void dijkstra(int src)
{

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

    for (int i = 0; i <= csr; i++)
    {
        Q.push({d[i], i});
    }

    while (!Q.empty())
    {
        auto [c, u] = Q.top();
        Q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        //cout << "evaluating " << u << endl;
        for (auto [v, w] : g[u])
        {
            //cout << "   " << v << " " << w << endl;
            if (d[v] > d[u] + w)
            {
                if (v > csr)
                {
                    // cout << "   updating " << v << " from " << d[v] << " to " << d[u] + w << endl;
                    d[v] = d[u] + w;
                    fathers[v] = u;
                }
                Q.push({d[v], v});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll m, k;
    cin >> n >> m >> csr >> k;
    csr--;
    string out = "";

    g = vector<vector<edge>>(n);
    fathers = vector<ll>(n, -1);
    d = vector<ll>(n, pinf);
    vis = vector<ll>(n, false);

    csr_cost = vector<ll>(csr + 1, 0);
    while (m--)
    {
        ll u, v, p;
        cin >> u >> v >> p;
        out += to_string(u) + to_string(v) + to_string(p) + "|";
        g[u].push_back(edge(v, p));
        g[v].push_back(edge(u, p));

        if ((abs(u - v) == 1) && (u <= csr) && (v <= csr))
        {
            csr_cost[max(u, v)] = p;
        }
    }

    d[csr] = 0;
    fathers[csr] = -1;
    for (int i = csr - 1; i >= 0; i--)
    {
        d[i] = d[i + 1] + csr_cost[i + 1];
        fathers[i] = i + 1;
    }
    // print(d, "d");

    dijkstra(csr);

    // print(d, "d");
    // print(fathers, "fathers");

    cout << d[k] << endl;
}