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

ll n, m;
vector<vector<ll>> g;
vector<string> names;
vector<vector<ll>> d;

void floydwarshall(void)
{
    for (int u = 0; u < n; u++)
        d[u][u] = 0;
    for (int m = 0; m < n; m++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                d[u][v] = min(d[u][v], d[u][m] + d[m][v]);
}

vector<ll> dd, fathers;
vector<bool> vis;
void dijkstra(int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push({0, src});
    dd[src] = 0;
    while (!Q.empty())
    {
        auto [c, u] = Q.top();
        Q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        // cout << "evaluating " << u << endl;
        for (auto v : g[u])
        {
            // cout << "   " << v << endl;
            // cout << "      " << dd[v] << " " << dd[u] + 1 << endl;
            if (dd[v] > dd[u] + 1)
            {
                // cout << "      " << v << " " << dd[v] << " " << dd[u] + 1 << endl;
                dd[v] = dd[u] + 1;
                fathers[v] = u;
                Q.push({dd[v], v});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    cin >> n >> m;

    g = vector<vector<ll>>(n);
    d = vector<vector<ll>>(n, vector<ll>(n, pinf));
    dd = vector<ll>(n, pinf);
    vis = vector<bool>(n, false);
    fathers = vector<ll>(n, -1);

    while (m--)
    {
        string a, b;
        cin >> a >> b;

        ll ai = find(names.begin(), names.end(), a) - names.begin();
        ll bi = find(names.begin(), names.end(), b) - names.begin();
        ll prev_size = names.size();

        if (ai == prev_size)
        {
            names.push_back(a);
            ai = names.size() - 1;
        }
        if (bi == prev_size)
        {
            names.push_back(b);
            bi = names.size() - 1;
        }

        g[ai].push_back(bi);
        d[ai][bi] = 1;
    }

    floydwarshall();

    // for (auto i : d)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    struct path
    {
        string a, b;
        ll ai, bi;
        ll dist;
    };
    vector<struct path> dists;

    double avg_dist = 0;
    double count = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (d[i][j] == 0 || d[i][j] == pinf)
                continue;

            avg_dist += d[i][j];
            count++;
            dists.push_back({names[i], names[j], i, j, d[i][j]});
        }
    }
    avg_dist /= count;

    sort(dists.begin(), dists.end(), [](struct path a, struct path b)
         {
            if (a.dist == b.dist)
            {
                if (a.a == b.a)
                    return a.b < b.b;

                return a.a < b.a; 
            }

            return a.dist < b.dist; });

    ll mid = (ll)(ceil(count / 2) - 1);
    if (mid < 0)
        mid = 0;

    ll a = dists[mid].ai;
    ll b = dists[mid].bi;
    dijkstra(a);
    // print(fathers, "fathers");

    vector<ll> path;
    while (b != -1)
    {
        path.push_back(b);
        b = fathers[b];
    }
    reverse(path.begin(), path.end());

    cout << avg_dist << "\n";
    for (auto i : path)
    {
        cout << names[i] << " ";
    }
    cout << "\n";
}