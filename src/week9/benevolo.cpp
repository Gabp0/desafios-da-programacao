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
long long pinf = 1987654321987654321;
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

const int N = 1e5 + 15;

vector<vector<edge>> g(N);
vector<ll> lot;

vector<ll> d(N, pinf), vis(N);
void dijkstra(int src)
{

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

    d[src] = 0;
    Q.push({0, src});

    while (!Q.empty())
    {
        auto [c, u] = Q.top();
        Q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto [v, w] : g[u])
        {

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
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
    ll n;
    cin >> n;
    lot.resize(n);

    // cout << "lendo lot" << endl;
    for (ll i = 0; i < n; i++)
    {
        // cout << "a" << endl;
        cin >> lot[i];
    }

    // cout << "w" << endl;
    ll m;
    cin >> m;
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        --x;
        --y;

        ll w = lot[y] - lot[x];
        g[x].push_back(edge(y, w));
    }

    ll q;
    cin >> q;
    // cout << "djkstra" << endl;
    dijkstra(0);
    // cout << "custo calculado" << endl;
    while (q--)
    {
        ll x;
        cin >> x;
        --x;
        ll lc = d[x];
        if ((lc < 3) || (lc >= pinf))
        {
            cout << "Não, Edsger...\n";
        }
        else
        {
            cout << lc << "\n";
        }
    }
}