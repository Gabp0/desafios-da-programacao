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

void print(list<ll> v, string s = "")
{
    cout << s << ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<ll> v, string s = "", ll n = 0)
{
    if (n == 0)
    {
        n = v.size();
    }

    cout << s << ": ";
    for (ll i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

list<ll> pre_order;
vector<ll> last_son(1e5 + 1, -1);
vector<ll> father(1e5 + 1, -1);

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code

    ll q;
    cin >> q;

    ll crown = 1;
    pre_order.push_back(crown);

    last_son[crown] = crown;
    father[crown] = -1;

    ll last = 1;
    while (q--)
    {
        // print(pre_order, "pre_order");
        // print(last_son, "last_son", 10);
        // print(father, "father", 10);
        // cout << "\n";

        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            auto pos = find(pre_order.begin(), pre_order.end(), last_son[x]);
            pre_order.insert(next(pos), ++last);
            last_son[x] = last;
            last_son[last] = last;
            father[last] = x;
        }
        else if (t == 2)
        {
            auto x_pos = find(pre_order.begin(), pre_order.end(), x);

            if (father[x] != -1)
            {
                last_son[father[x]] = (*prev(x_pos) == father[x]) ? *prev(x_pos) : -1;
            }

            pre_order.erase(x_pos);

            if (x == crown)
            {
                crown = *(pre_order.begin());
            }
            cout << crown << '\n';
        }
    }
}