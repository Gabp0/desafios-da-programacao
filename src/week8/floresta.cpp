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

vector<vector<char>> grid;

void print_grid(vector<vector<char>> grid)
{
    for (auto i : grid)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int neighbourhood8(cord pixel)
{
    ll x = pixel.xx;
    ll y = pixel.yy;
    ll count = 0;

    for (ll i = x - 1; i <= x + 1; i++)
    {
        for (ll j = y - 1; j <= y + 1; j++)
        {
            if (grid[i][j] == '0')
                count++;
        }
    }
    return count;
}

int neighbourhood4(cord pixel)
{
    ll x = pixel.xx;
    ll y = pixel.yy;
    ll count = 0;

    if (grid[x - 1][y] == '0')
        count++;
    if (grid[x + 1][y] == '0')
        count++;
    if (grid[x][y - 1] == '0')
        count++;
    if (grid[x][y + 1] == '0')
        count++;

    return count;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, m, t;
    cin >> n >> m >> t;
    grid = vector<vector<char>>(n + 2, vector<char>(m + 2, '9'));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    //print_grid(grid);

    vector<vector<char>> new_grid;
    while (t--)
    {
        new_grid = grid;
        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                char pixel = grid[i][j];
                switch (pixel)
                {
                case '1':
                    if (neighbourhood8({i, j}) >= 1)
                    {
                        new_grid[i][j] = '0';
                    }
                    break;
                case '2':
                    if (neighbourhood4({i, j}) >= 1)
                    {
                        new_grid[i][j] = '0';
                    }
                    break;
                case '3':
                    if (neighbourhood4({i, j}) >= 2)
                    {
                        new_grid[i][j] = '0';
                    }
                    break;
                case '4':
                    if (neighbourhood4({i, j}) >= 3)
                    {
                        new_grid[i][j] = '0';
                    }
                    break;
                }
            }
        }
        grid = new_grid;
        //print_grid(grid);
    }

    ll burning = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (grid[i][j] == '0')
            {
                burning++;
            }
        }
    }
    cout << burning << "\n";
}