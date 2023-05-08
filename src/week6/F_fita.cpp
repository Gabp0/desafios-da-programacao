#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define cord pair<ll, ll>
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

vector<ll> ti;
ll n;
void add(ll i, ll delta)
{
    for (; i < n + 1; i += i & (-i))
        ti[i] += delta;
}
int get(ll i)
{
    ll ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += ti[i];
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll q;
    cin >> n >> q;
    vector<ll> t(n + 1);
    ti = vector<ll>(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> t[i];
        add(i, 1);
    }

    char op;
    ll h = 1;
    while (q--)
    {

        cin >> op;

        if (op == 'm')
        {
            ll d;
            cin >> d;
            h += d;
        }
        else if (op == 'd')
        {
            ll pos = get(h);
            t[pos] = 0;
            add(h, 1);
            h++;
        }
        else if (op == 'q')
        {
            cout << t[get(h)] << '\n';
        }

        // cout << "\n";
        // print(t, "t");
        // print(ti, "ti");
        // cout << "h: " << get(h) << endl;
    }
}