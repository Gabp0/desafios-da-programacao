#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
#define edge pair<ll, ll>
#define PN // cout << "\n"
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

vector<vector<ll>> adj(2);
vector<bool> visited(2, false);
vector<bool> alive(2, true);
vector<ll> fathers(2, -1);

ll explore(ll u)
{
    // cout << "u == " << u << endl;
    visited[u] = true;

    for (ll v : adj[u])
    {
        // cout << "v == " << v << "\n";
        if (!visited[v] && (v != fathers[u]))
        {
            // cout << "v != fathers[u]\n";
            if (alive[v])
            {
                // cout << "returning " << v << endl;
                return v;
            }

            ll res = explore(v);
            if (res != -1)
            {
                // cout << "returning " << res << endl;
                return res;
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code

    ll q;
    cin >> q;
    ll co = 1;
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            // cout << "x == " << x << endl;
            //  //cout << adj[x].size() << endl;
            adj.push_back(vector<ll>());
            adj[x].push_back(adj.size() - 1);
            adj[adj.size() - 1].push_back(x);
            fathers.push_back(x);
            alive.push_back(true);
        }
        else if (t == 2)
        {
            // cout << "x == dead " << x << endl;
            alive[x] = false;
            visited = vector<bool>(adj.size(), false);
            if (co == x)
            {
                ll last = x;
                // cout << "sco == " << co << "\n";
                co = explore(co);
                while (co == -1)
                {
                    co = explore(fathers[last]);
                    last = fathers[last];
                }
            }
            // cout << "co == " << co << endl;
            cout << co << "\n";
        }
    }
}