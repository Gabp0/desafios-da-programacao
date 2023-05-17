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
vector<bool> visited;
vector<ll> dist;
vector<ll> pred;
vector<ll> path;

ll start_n = 0, end_n = 0;

bool explore(ll u)
{
    visited[u] = true;
    dist[u] = 0;

    queue<ll> q;
    q.push(u);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                pred[v] = u;
                if (v == end_n)
                {
                    ll i = v;
                    while (i != -1)
                    {
                        path.push_back(i);
                        i = pred[i];
                    }
                    reverse(path.begin(), path.end());
                    return true;
                }

                q.push(v);
            }
    }

    return false;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, m;
    cin >> n >> m;
    cord start_c, end_c;

    vector<vector<pair<char, ll>>> lab(n, vector<pair<char, ll>>(m, {'#', -1}));
    vector<cord> cords;
    ll vnum = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            lab[i][j].xx = a;
            if (a != '#')
            {
                lab[i][j].yy = vnum;
                adj.push_back(vector<ll>());

                if ((i > 0) && (lab[i - 1][j].xx != '#'))
                {
                    adj[lab[i][j].yy].push_back(lab[i - 1][j].yy);
                    adj[lab[i - 1][j].yy].push_back(lab[i][j].yy);
                }

                if ((j > 0) && (lab[i][j - 1].xx != '#'))
                {
                    adj[lab[i][j].yy].push_back(lab[i][j - 1].yy);
                    adj[lab[i][j - 1].yy].push_back(lab[i][j].yy);
                }

                if ((i < n - 1) && (lab[i + 1][j].xx != '#'))
                {
                    adj[lab[i][j].yy].push_back(lab[i + 1][j].yy);
                    adj[lab[i + 1][j].yy].push_back(lab[i][j].yy);
                }

                if ((j < m - 1) && (lab[i][j + 1].xx != '#'))
                {
                    adj[lab[i][j].yy].push_back(lab[i][j + 1].yy);
                    adj[lab[i][j + 1].yy].push_back(lab[i][j].yy);
                }

                if (a == 'A')
                {
                    start_c = {i, j};
                    start_n = vnum;
                }
                else if (a == 'B')
                {
                    end_c = {i, j};
                    end_n = vnum;
                }

                cords.push_back({i, j});
                vnum++;
            }
        }
    }

    visited = vector<bool>(vnum, false);
    dist = vector<ll>(vnum, pinf);
    pred = vector<ll>(vnum, -1);

    if (explore(start_n))
    {
        cout << "YES\n"
             << path.size() - 1 << "\n";

        for (size_t i = 1; i < path.size(); i++)
        {
            if (cords[path[i]].xx == cords[path[i - 1]].xx)
            {
                if (cords[path[i]].yy > cords[path[i - 1]].yy)
                {
                    cout << "R";
                }
                else
                {
                    cout << "L";
                }
            }
            else
            {
                if (cords[path[i]].xx > cords[path[i - 1]].xx)
                {
                    cout << "D";
                }
                else
                {
                    cout << "U";
                }
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}