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

const int N = 1e5 + 15, oo = 987654321;
#define NEUTRAL oo
#define FACTOR(sz) 1
#define OP(X, Y) min(X, Y)

vector<ll> t(4 * N), lazy(4 * N), sety(4 * N, -1);

void push(int ti, int tl, int tm, int tr)
{
    if (sety[ti] != -1)
    {
        t[ti * 2] = sety[ti] * FACTOR(tm - tl + 1);
        lazy[ti * 2] = 0;
        sety[ti * 2] = sety[ti];
        t[ti * 2 + 1] = sety[ti] * FACTOR(tr - (tm + 1) + 1);
        lazy[ti * 2 + 1] = 0;
        sety[ti * 2 + 1] = sety[ti];
        sety[ti] = -1;
    }
    t[ti * 2] += lazy[ti] * FACTOR(tm - tl + 1);
    lazy[ti * 2] += lazy[ti];
    t[ti * 2 + 1] += lazy[ti] * FACTOR(tr - (tm + 1) + 1);
    lazy[ti * 2 + 1] += lazy[ti];
    lazy[ti] = 0;
}

void set_inclusive(int l, int r, int d,
                   int ti = 1, int tl = 1, int tr = N)
{
    if (l > r)
    {
        return;
    }
    if (l == tl && tr == r)
    {
        t[ti] = ll(d) * FACTOR(tr - tl + 1);
        sety[ti] = d;
        lazy[ti] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    set_inclusive(l, min(r, tm), d, ti * 2, tl, tm);
    set_inclusive(max(l, tm + 1), r, d, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}
void add_inclusive(int l, int r, int d,
                   int ti = 1, int tl = 1, int tr = N)
{
    if (l > r)
    {
        return;
    }
    if (l == tl && tr == r)
    {
        t[ti] += ll(d) * FACTOR(tr - tl + 1);
        lazy[ti] += d;
        return;
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), d, ti * 2, tl, tm);
    add_inclusive(max(l, tm + 1), r, d, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

ll op_inclusive(int l, int r,
                int ti = 1, int tl = 1, int tr = N)
{
    if (l > r)
    {
        return NEUTRAL;
    }
    if (l <= tl && tr <= r)
    {
        return t[ti];
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    return OP(op_inclusive(l, min(r, tm), ti * 2, tl, tm),
              op_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

void build(vector<int> &src,
           int ti = 1, int tl = 1, int tr = N)
{
    if (tl == tr)
    {
        if (tl < src.size())
        {
            t[ti] = src[tl];
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll n, q;
    cin >> n >> q;
    vector<int> bars(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> bars[i];
    }

    build(bars);

    while (q--)
    {
        int op;
        ll i, j;
        cin >> op >> i >> j;
        if (op == 1)
        {
            ll k;
            cin >> k;

            add_inclusive(i, j, k);
        }
        else if (op == 2)
        {
            cout << op_inclusive(i, j) << "\n";
        }
    }
}